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
*
*/

#include <cereal/types/vector.hpp>
#include "../cereal/cereal_ext.hpp"
#include "../cereal/schema_enum.hpp"
#include "../cereal/schema_string.hpp"
#include <vector>
#include "./common.hpp"

namespace lgpl3 { namespace ocpp20 { 

struct SetVariableDataType
{
    optional<AttributeEnumType> attributeType;
    schema_string<1000> attributeValue;
    ComponentType component;
    VariableType variable;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "attributeType", attributeType);
        cereal::nvp(archive, "attributeValue", attributeValue);
        cereal::nvp(archive, "component", component);
        cereal::nvp(archive, "variable", variable);
    }
};

struct SetVariablesRequest
{
    std::vector<SetVariableDataType> setVariableData;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "setVariableData", setVariableData);
    }
};



} } 

