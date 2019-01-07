# Purpose

The src directory provides an example of working code that can be compiled and
prodded.

# Sub Directory Summary

A brief description of the contents of each subdirectory.

## protocol

This directory contains the automatically generated cereal based expression of
the OCPP 2.0 specification. It is generated in an automated fashion by running
the following command within the protocol directory itself:

  ../../generator/scripts/schema-to-cpp-header2.py
    --input-dir=../../schemas  
    --namespace=lgpl3
    --namespace=ocpp20
    --include="<cereal/types/vector.hpp>"  
    --include="\"../cereal/cereal_ext.hpp\""  
    --include="\"../cereal/schema_enum.hpp\""
    --include="\"../cereal/schema_string.hpp\""
    --include="\"../cereal/schema_array.hpp\""
    --include="\"../cereal/rfc_3339.hpp\""

## cereal

This directory contains extensions and additions to the cereal namespace that
are used as part of the automated generation of the serialization library
contained in this project. Note this code makes use of
std::experimental::optional to deal with the optional nature of some fields in
the OCPP 2.0 specification.

## time

Contains code mostly pertaining to parsing rfc3339 formatted time strings -
the underlying time point class is intended to be the basis of all time based
logic of any derived client/server code.

## example

This directory contains some simple examples showing basic serialization and how it
works. 

# Compiling

All examples and (soon to be) unit tests are compiled using compile-tools - See
https://github.com/Zomojo/compiletools.


## Dependencies

Please install these dependencies.

### Debian

pip install compile-tools

apt-get install libcereal-dev libstdc++-6-dev libboost-test1.62-dev

Note libstdc++-6-dev is for std::experimental::optional
Note libboost-test1.62-dev is the version of the boost unit testing framework used authors. Other versions may works also.
