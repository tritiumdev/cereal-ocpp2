#pragma once

/**
*
* This file is auto generated using this exact command:
*     ../../generator/scripts/schema-to-cpp-header2.py
*     --input-dir=../../schemas/schemas
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

struct GetVariableDataType
{
    optional<AttributeEnumType> attributeType;
    ComponentType component;
    VariableType variable;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "attributeType", attributeType);
        cereal::nvp(archive, "component", component);
        cereal::nvp(archive, "variable", variable);
    }
};

struct GetVariablesRequest
{
    schema_array<GetVariableDataType,65536,1> getVariableData;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "getVariableData", getVariableData);
    }
};



} } 

