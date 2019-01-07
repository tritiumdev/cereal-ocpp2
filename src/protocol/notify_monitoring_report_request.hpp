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
*     --include="../cereal/rfc3339_string.hpp"
*
*/

#include "./common.hpp"

namespace lgpl3 { namespace ocpp20 { 

struct MonitoringDataType
{
    ComponentType component;
    VariableType variable;
    schema_array<VariableMonitoringType,65536,1> variableMonitoring;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "component", component);
        cereal::nvp(archive, "variable", variable);
        cereal::nvp(archive, "variableMonitoring", variableMonitoring);
    }
};

struct NotifyMonitoringReportRequest
{
    date_time generatedAt;
    schema_array<MonitoringDataType,65536,1> monitor;
    optional<int> requestId;
    int seqNo;
    schema_boolean tbc;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "generatedAt", generatedAt);
        cereal::nvp(archive, "monitor", monitor);
        cereal::nvp(archive, "requestId", requestId);
        cereal::nvp(archive, "seqNo", seqNo);
        cereal::nvp(archive, "tbc", tbc);
    }
};



} } 

