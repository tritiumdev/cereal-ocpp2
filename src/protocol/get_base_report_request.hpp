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

struct GetBaseReportRequest
{
    SCHEMA_ENUM(ReportBaseType,\
        ConfigurationInventory,\
        FullInventory,\
        SummaryInventory);
    using ReportBaseTypeEnum=schema_enum_value<ReportBaseType>;

    ReportBaseTypeEnum reportBase;
    int requestId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "reportBase", reportBase);
        cereal::nvp(archive, "requestId", requestId);
    }
};



} } 
