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

SCHEMA_ENUM(MonitoringCriterionEnum,\
    ThresholdMonitoring,\
    DeltaMonitoring,\
    PeriodicMonitoring);
using MonitoringCriterionEnumType=schema_enum_value<MonitoringCriterionEnum>;

struct GetMonitoringReportRequest
{
    optional<std::vector<ComponentVariableType>> componentVariable;
    optional<std::vector<MonitoringCriterionEnumType>> monitoringCriteria;
    optional<int> requestId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "componentVariable", componentVariable);
        cereal::nvp(archive, "monitoringCriteria", monitoringCriteria);
        cereal::nvp(archive, "requestId", requestId);
    }
};



} } 

