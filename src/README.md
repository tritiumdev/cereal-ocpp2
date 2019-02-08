# Purpose

The src directory provides an example of working code that can be compiled and
prodded.

# Sub Directory Summary

A brief description of the contents of each subdirectory.

## protocol

This directory contains the automatically generated cereal based expression of
the OCPP 2.0 specification. It is generated in an automated fashion by running 
the generator script - see generator/scripts/schema-to-cpp-header2.py. The command
that was run to generate the source code is always captured in a comment inside
the generated code - look at for example protocol/common.hpp to get the idea.

Note that the generator script takes care to ensure compilation is alway successful,
and that the code is generated in a minimalistic fashion. For example code is only
placed in protocol/common.hpp if it used in more than one request or response.
Otherwise, code or objects specific to a request or response are found only in the 
corresponding protocol header that makes use of them.

## protocol16ext

As in the protocol directory (see notes above), but the code here is generated
based on the OCPP 1.6J security related extensions.

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

pip install compiletools

apt-get install libcereal-dev libstdc++-6-dev libboost-test1.62-dev

Note libstdc++-6-dev is for std::experimental::optional
Note libboost-test1.62-dev is the version of the boost unit testing framework used authors. Other versions may works also.
