#!/usr/bin/python3

import argparse
import json
import re
import ocpp2_schema
import sys
import os
import glob

def camel_to_underscore(name):
    s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', name)
    return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower()

parser = argparse.ArgumentParser()
parser.add_argument("--input", action="append", default=[],
                            help="input json schema")
parser.add_argument("--input-dir", default=None,
                            help="input directory containing *.json files... auto detects schema")
parser.add_argument("--common-header", type=str, default="common.hpp",
                            help="output c++ (common) header")
parser.add_argument("--namespace", action="append",default=[],
                            help="namespaces, in order")
parser.add_argument("--include", action="append",default=[],
                            help="header includes... e.g <vector>, \"foo.hpp\"")

args = parser.parse_args()


if args.input_dir:
    args.input.extend(glob.glob("%s/*.json" %args.input_dir))
    args.input = sorted(args.input)

# this is not technically always needed...TODO
args.include.append("<vector>")



schemes={}
for input_file in args.input:
    
    # note the 1:... weird utf foo at start of string
    input_str = " ".join([line.strip() for line in open(input_file).readlines()])[1:]
    schema = json.loads(input_str)
    
    scheme = ocpp2_schema.Scheme()
    
    master_name = schema["$id"].split(":")[-1]
    # 1.6 ext related..
    master_name = master_name.replace(".req", "Request")
    master_name = master_name.replace(".conf", "Response")

    if "properties" not in schema.keys(): schema["properties"] = {}

    candidates = [] 
    if schema["type"] == "object":
        scheme.objects.append(ocpp2_schema.create("Object", name=master_name, attributes=schema, master=master_name))
        candidates.extend([[name,attributes] for name,attributes in schema["properties"].items()])
    else:
        raise Exception("unexpected type in schema")
    
    if "definitions" in schema.keys():
        candidates = [[name,attributes] for name,attributes in schema["definitions"].items()]
    
    # here we recursively traverse the schema tree, collecting all the bona fide objects and enums
    master_enum_added=False
    while len(candidates):
        name,attributes = candidates[0]
        candidates = candidates[1:]
        if len(attributes) == 0: continue;
    
        if "$ref" in attributes: continue
        if attributes["type"] == "string":
            if "enum" in attributes.keys():
                if name[-8:] == "EnumType":
                    scheme.enums.append(ocpp2_schema.create("Enum", name=ocpp2_schema.digit_prefix(name), attributes=attributes))
                elif name == "status":
                    # this one is weird - it's as though the schema providers have an anomalous inconsistency 
                    pass
                else:
                    pass
            else: pass 
        elif attributes["type"] == "object":
            scheme.objects.append(ocpp2_schema.create("Object", name=name, attributes=attributes, master=None))
            candidates.extend([[name,attributes] for name,attributes in attributes["properties"].items()])
        elif attributes["type"] == "array":
            # hmmm...
            pass
        elif attributes["type"] == "integer":
            pass
        elif attributes["type"] == "number":
            pass
        elif attributes["type"] == "boolean":
            pass
        else:
            raise  Exception("Unhandled type: %s" %attributes["type"])
    
    scheme.enums = sorted(scheme.enums,  key = lambda l:l.name)

    schemes[input_file] = scheme
    

common_enums={}
for input_file,scheme in sorted(schemes.items()):
    for e in scheme.enums:
        try:
            common_enums[e.payload].append(scheme)
        except:
            common_enums[e.payload] = [scheme]

common_objects={}
for input_file,scheme in schemes.items():
    for o in scheme.objects:
        try:
            common_objects[o.payload].append([o,scheme])
        except:
            common_objects[o.payload] = [[o,scheme]]

common_payloads={}
common_objects_depends={}
 
 
for k,v in common_objects.items():
    if (len(v)) > 1:
        common_payloads[v[0][0].name] = k
        for obj,scheme in v:
            try:
                common_objects_depends[obj.name] |= obj.struct_depends
            except:
                common_objects_depends[obj.name] = set(obj.struct_depends)

            to_remove = [ o for o in scheme.objects if o.payload == k ]
            for x in to_remove:
                scheme.objects.remove(x)

common_file = ocpp2_schema.HeaderFile(args.common_header, args.namespace, args.include)
common_file.write_header()
common_file.write_using()
for k,v in sorted(common_enums.items()):
    if (len(v)) > 1:
        for scheme in v:
            to_remove = [ e for e in scheme.enums if e.payload == k ]
            for x in to_remove:
                scheme.enums.remove(x)
        
        common_file.write(k)

while len(common_objects_depends):
    action = False
    for k,s in sorted(common_objects_depends.items()):
        if not len(s):
            action = True
            common_file.write(common_payloads[k])
            common_objects_depends.pop(k, None)
            break

    if not action:
        raise Exception("Logic failure when writing common objects")
    
    for unused,s in common_objects_depends.items():
        try:
            s.remove(k)
        except: pass


common_file.write_footer()

args.include = ["\"./common.hpp\""]
   
for input_file,scheme in sorted(schemes.items()):
    
    output_file = os.path.basename(input_file).split("_")[0]
    # this next split is only necessary for 1.6 extensions
    output_file = output_file.split(".")[0]
    output_file = camel_to_underscore(output_file) + ".hpp"
        
    output_file = ocpp2_schema.HeaderFile(output_file, args.namespace, args.include)
    output_file.write_header()
    
    name_to_struct={}
    struct_depends={}
    for o in scheme.objects:
        struct_depends[o.name] = [name for name in o.struct_depends if name not in common_payloads.keys()]
        name_to_struct[o.name] = o.payload
    
    for e in scheme.enums:
        output_file.write(e.payload)

    # Dependency ordering loop
    while len(name_to_struct):
        l = len(name_to_struct)
        for name, payload in sorted(name_to_struct.items()):
            if len(struct_depends[name]) == 0:
                for key, value in struct_depends.items():
                    struct_depends[key] = list(filter(lambda a: a != name, value))
                output_file.write(payload)
                name_to_struct.pop(name, None)
                break;
        if l == len(name_to_struct):
            raise Exception("dependency ordering logic failed %s" %name_to_struct)
    
    output_file.write_footer()
 
    
