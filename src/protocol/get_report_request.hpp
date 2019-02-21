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

SCHEMA_ENUM(ComponentCriterionEnum,\
    Active,\
    Available,\
    Enabled,\
    Problem);
using ComponentCriterionEnumType=schema_enum_value<ComponentCriterionEnum>;

struct GetReportRequest
{
    static const char* action() { return "GetReport"; }

    optional<schema_array<ComponentCriterionEnumType,4,1>> componentCriteria;
    optional<schema_array<ComponentVariableType,65536,1>> componentVariable;
    optional<int> requestId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "componentCriteria", componentCriteria);
        cereal::nvp(archive, "componentVariable", componentVariable);
        cereal::nvp(archive, "requestId", requestId);
    }
};



} } 

