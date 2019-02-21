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

SCHEMA_ENUM(GetVariableStatusEnum,\
    Accepted,\
    Rejected,\
    UnknownComponent,\
    UnknownVariable,\
    NotSupportedAttributeType);
using GetVariableStatusEnumType=schema_enum_value<GetVariableStatusEnum>;

struct GetVariableResultType
{
    GetVariableStatusEnumType attributeStatus;
    optional<AttributeEnumType> attributeType;
    optional<schema_string<1000>> attributeValue;
    ComponentType component;
    VariableType variable;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "attributeStatus", attributeStatus);
        cereal::nvp(archive, "attributeType", attributeType);
        cereal::nvp(archive, "attributeValue", attributeValue);
        cereal::nvp(archive, "component", component);
        cereal::nvp(archive, "variable", variable);
    }
};

struct GetVariablesResponse
{
    schema_array<GetVariableResultType,65536,1> getVariableResult;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "getVariableResult", getVariableResult);
    }
};



} } 

