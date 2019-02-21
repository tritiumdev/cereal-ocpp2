#pragma once

/**
*
* This file is auto generated using this exact command:
*     ../../generator/20/schema-to-cpp-header2.py
*     --input-dir=../../schemas/20
*     --namespace=lgpl3
*     --namespace=ocpp20
*     --include=<cereal/types/vector.hpp>
*     --include="../cereal/cereal_ext.hpp"
*     --include="../cereal/schema_enum.hpp"
*     --include="../cereal/schema_string.hpp"
*     --include="../cereal/schema_array.hpp"
*     --include="../cereal/schema_date_time.hpp"
*
*/

#include "./common.hpp"

namespace lgpl3 { namespace ocpp20 { 

SCHEMA_ENUM(SetVariableStatusEnum,\
    Accepted,\
    Rejected,\
    InvalidValue,\
    UnknownComponent,\
    UnknownVariable,\
    NotSupportedAttributeType,\
    OutOfRange,\
    RebootRequired);
using SetVariableStatusEnumType=schema_enum_value<SetVariableStatusEnum>;

struct SetVariableResultType
{
    SetVariableStatusEnumType attributeStatus;
    optional<AttributeEnumType> attributeType;
    ComponentType component;
    VariableType variable;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "attributeStatus", attributeStatus);
        cereal::nvp(archive, "attributeType", attributeType);
        cereal::nvp(archive, "component", component);
        cereal::nvp(archive, "variable", variable);
    }
};

struct SetVariablesResponse
{
    schema_array<SetVariableResultType,65536,1> setVariableResult;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "setVariableResult", setVariableResult);
    }
};



} } 

