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

struct SetMonitoringDataType
{
    ComponentType component;
    optional<int> id;
    int severity;
    optional<schema_boolean> transaction;
    MonitorEnumType type;
    double value;
    VariableType variable;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "component", component);
        cereal::nvp(archive, "id", id);
        cereal::nvp(archive, "severity", severity);
        cereal::nvp(archive, "transaction", transaction);
        cereal::nvp(archive, "type", type);
        cereal::nvp(archive, "value", value);
        cereal::nvp(archive, "variable", variable);
    }
};

struct SetVariableMonitoringRequest
{
    static const char* action() { return "SetVariableMonitoring"; }

    schema_array<SetMonitoringDataType,65536,1> setMonitoringData;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "setMonitoringData", setMonitoringData);
    }
};



} } 

