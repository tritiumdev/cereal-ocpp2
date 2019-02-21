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

SCHEMA_ENUM(MonitoringCriterionEnum,\
    ThresholdMonitoring,\
    DeltaMonitoring,\
    PeriodicMonitoring);
using MonitoringCriterionEnumType=schema_enum_value<MonitoringCriterionEnum>;

struct GetMonitoringReportRequest
{
    static const char* action() { return "GetMonitoringReport"; }

    optional<schema_array<ComponentVariableType,65536,1>> componentVariable;
    optional<schema_array<MonitoringCriterionEnumType,3,1>> monitoringCriteria;
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

