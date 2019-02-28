
import os
import sys

def create(magic, **kwargs):
    #print(kwargs)
    class_to_make  = globals()[magic]
    obj = class_to_make(**kwargs)
    return obj

def digit_prefix(s):
    if s[0].isdigit(): return "n" + s
    else: return s

def optional(string, required):
    if (not required):
        return "optional<%s>" %string
    else: 
        return string

def ref_to_type(ref):
    return ref.split("/")[-1]

def munge_enum(s, sep="    "):
    #s = s.replace("-", "_1_")
    #s = s.replace(".", "_2_")
    #s = s.replace(" ", "_3_")
    s = s.replace(",", ",\\\n%s" %sep)
    return s

def upper_first(s):
    return s[0].upper()+s[1:]

class Object:
    def __init__(self, **kwargs):
        self.__dict__.update( kwargs )
        self.struct_depends = []
        self.payload = ""
        self.__do_work()

    def __do_work(self):
        output_struct_top="struct %s\n" %self.name
        output_struct_top += "{\n"
        request_name = self.request_name()
        if (request_name):
            output_struct_top += "    static const char* action() { return \"%s\"; }\n" %request_name
            output_struct_top += "\n"

        output_struct_bot = ""
        for name, desc in sorted(self.attributes["properties"].items()):
            name = digit_prefix(name)
            required = name in self.attributes["required"] if "required" in self.attributes.keys() else False
            if len(desc) == 0:
                output_struct_bot += "    %s %s;\n" %(optional("std::string", required), name)
            elif "$ref" in desc:
                member_struct = ref_to_type(desc["$ref"])
                # hacky filter just for enum types
                if member_struct.find("EnumType") == -1: 
                    self.struct_depends.append(member_struct)
                output_struct_bot += "    %s %s;\n" %(optional(digit_prefix(member_struct),required), name)
            elif desc["type"] == "string":
                if "maxLength" in desc.keys():
                    output_struct_bot += "    %s %s;\n" %(optional("schema_string<%i>" %desc["maxLength"], required), name)
                elif "format" in desc.keys() and desc["format"] == "date-time":
                    output_struct_bot += "    %s %s;\n" %(optional("schema_date_time", required), name)
                elif "enum" in desc.keys():
                    enum_name=digit_prefix(upper_first(name) + "Enum")
                    output_struct_top += self.__enum_payload(enum_name, desc)
                    output_struct_bot += "    %s %s;\n" %(optional(enum_name,required), name)
                else:
                    raise Exception("unknown string type")
            elif desc["type"] == "array":
                try: min_items = desc["minItems"]
                except: min_items = 0

                try: max_items = desc["maxItems"]
                except: max_items = 65536

                if "$ref" in desc["items"].keys():
                    member_struct = ref_to_type(desc["items"]["$ref"])
                    # hacky filter just for enum types
                    if member_struct.find("EnumType") == -1: 
                        self.struct_depends.append(member_struct)
                    output_struct_bot += "    %s %s;\n" %(optional("schema_array<%s,%i,%i>" \
                            %(ref_to_type(member_struct),max_items,min_items),required), name)
                elif desc["items"]["type"] == "string":
                    if "maxLength" in desc["items"].keys():
                        output_struct_bot += "    %s %s;\n" %(optional("schema_array<schema_string<%i>, %i, %i>>" \
                                %(desc["items"]["maxLength"],max_items,min_items),required), name)
                    else:
                        raise Exception("Unknown string type in array")
                elif "enum" in desc.keys():
                    enum_name=digit_prefix(upper_first(name) + "Enum")
                    output_struct_top += self.__enum_payload(enum_name, desc)
                    output_struct_bot += "    %s %s;\n" %(optional(enum_name,required), name)
                elif "type" in desc["items"].keys():
                    if desc["items"]["type"] == "integer":
                        output_struct_bot += "    %s %s;\n" %(optional("schema_array<int,%i,%i>" %(max_items,min_items), required), name)
                    elif desc["items"]["type"] == "number":
                        output_struct_bot += "    %s %s;\n" %(optional("schema_array<double,%i,%i>" %(max_items,min_items), required), name)
                    else:
                        raise Exception("unhandled type array output: %s" %desc["items"]["type"])
                else:
                    raise Exception("unhandled array output")
            elif desc["type"] == "integer":
               output_struct_bot += "    %s %s;\n" %(optional("int",required), name)
            elif desc["type"] == "number":
               output_struct_bot += "    %s %s;\n" %(optional("double",required), name)
            elif desc["type"] == "boolean":
               output_struct_bot += "    %s %s;\n" %(optional("schema_boolean",required), name)
            else:
                raise Exception("unknown!")

        output_struct_bot += "\n"

        output_struct_bot += "    template<typename Archive>\n"
        output_struct_bot += "    void serialize(Archive& archive)\n"
        output_struct_bot += "    {\n"
        for name in sorted(self.attributes["properties"].keys()):
            output_struct_bot += "        cereal::nvp(archive, \"%s\", %s);\n" %(name, digit_prefix(name))
        output_struct_bot += "    }\n"
        output_struct_bot += "};\n\n"

        self.payload = output_struct_top + output_struct_bot

    def request_name(self):
        """
        Returns a valid string if self.name is determined to be the
        name of a request, otherwise returns an empty string.
        This is for packing the Action in the call request, in the 
        RPC framework.
        """
        if self.name[-7:] == "Request": return self.name[:-7]
        return ""

    def __enum_payload(self, enum_name, desc):
        ret = ""
        ret += "    SCHEMA_ENUM(%s,\\\n        %s);\n" %(enum_name[:-4], munge_enum(",".join(desc["enum"]), "        "))
        ret += "    using %s=schema_enum_value<%s>;\n" %(enum_name,enum_name[:-4])
        ret += "\n"
        return ret
 
     

class Enum:
    def __init__(self, **kwargs):
        self.__dict__.update( kwargs )
        self.payload = ""
        self.__do_work()

    def __do_work(self):
        self.payload += "SCHEMA_ENUM(%s,\\\n    %s);\n" %(self.name[:-4], munge_enum(",".join(self.attributes["enum"])))
        self.payload += "using %s=schema_enum_value<%s>;\n\n" %(self.name,self.name[:-4])
    
class Scheme:
    def __init__(self, **kwargs):
        self.__dict__.update( kwargs )
        self.objects = []
        self.enums = []


class HeaderFile:
    def __init__(self, output_file, namespace=[], include=[]):
        self.file = open(output_file, "w")
        self.namespace = namespace
        self.include = include

    def write_header(self):

        self.file.write("#pragma once\n\n")

        self.file.write("/**\n")
        self.file.write("*\n")
        self.file.write("* This file is auto generated using this exact command:\n")
        for arg in sys.argv:
            self.file.write("*     %s\n" %arg)
        self.file.write("*\n")
        self.file.write("*/\n\n")
        for include in self.include:
            self.file.write("#include %s\n" %include)

        self.file.write("\n")

        for namespace in self.namespace:
            self.file.write("namespace %s { " %namespace) 
        self.file.write("\n\n")
    
    def write_using(self):

        self.file.write("template<typename Type>\n")
        self.file.write("using optional=cereal::optional<Type>;\n\n")
        self.file.write("template<std::size_t MaxSize, std::size_t MinSize=1>\n");
        self.file.write("using schema_string=cereal::schema_string<MaxSize, MinSize>;\n\n")
        self.file.write("template<typename Type, std::size_t MaxSize, std::size_t MinSize=1>\n");
        self.file.write("using schema_array=cereal::schema_array<Type,MaxSize, MinSize>;\n\n")
        self.file.write("template<typename SchemaSet>\n")
        self.file.write("using schema_enum_value=cereal::schema_enum_value<SchemaSet>;\n\n")
        self.file.write("using schema_date_time=cereal::schema_data_time;\n\n")
        self.file.write("using schema_boolean=cereal::schema_boolean;\n\n")


    def write(self, payload):
        self.file.write(payload)



    def write_footer(self):
        self.file.write("\n\n")
        for namespace in self.namespace:
           self.file.write("} ");
        self.file.write("\n\n")









