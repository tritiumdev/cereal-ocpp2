#!/usr/bin/python3

import argparse
import json
import re
import ocpp2_schema
import sys

def camel_to_underscore(name):
    s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', name)
    return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower()


parser = argparse.ArgumentParser()
parser.add_argument("--input", type=str,
                            help="input json schema")
parser.add_argument("--output", type=str,
                            help="output c++ header")
parser.add_argument("--namespace", action="append",default=[],
                            help="namespaces, in order")
parser.add_argument("--include", action="append",default=[],
                            help="header includes... e.g <vector>, \"foo.hpp\"")

args = parser.parse_args()

# this is not technically always needed...TODO
args.include.append("<vector>")


# note the 1:... weird utf foo at start of string
input_str = " ".join([line.strip() for line in open(args.input).readlines()])[1:]
schema = json.loads(input_str)


output_file = ocpp2_schema.HeaderFile(args.output, args.namespace, args.include)
output_file.write_header()
output_file.write_using()

scheme = ocpp2_schema.Scheme()

candidates = []
master_name = schema["$id"].split(":")[-1]
if "properties" not in schema.keys(): schema["properties"] = {}

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

for e in scheme.enums:
    output_file.write(e.payload)

name_to_struct={}
struct_depends={}
for o in scheme.objects:
    struct_depends[o.name] = o.struct_depends
    name_to_struct[o.name] = o.payload

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
        raise Exception("dependency ordering logic failed")

output_file.write_footer()



