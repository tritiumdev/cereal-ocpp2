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

SCHEMA_ENUM(SetMonitoringStatusEnum,\
    Accepted,\
    UnknownComponent,\
    UnknownVariable,\
    UnsupportedMonitorType,\
    Rejected,\
    OutOfRange,\
    Duplicate);
using SetMonitoringStatusEnumType=schema_enum_value<SetMonitoringStatusEnum>;

struct SetMonitoringResultType
{
    ComponentType component;
    optional<int> id;
    int severity;
    SetMonitoringStatusEnumType status;
    MonitorEnumType type;
    VariableType variable;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "component", component);
        cereal::nvp(archive, "id", id);
        cereal::nvp(archive, "severity", severity);
        cereal::nvp(archive, "status", status);
        cereal::nvp(archive, "type", type);
        cereal::nvp(archive, "variable", variable);
    }
};

struct SetVariableMonitoringResponse
{
    schema_array<SetMonitoringResultType,65536,1> setMonitoringResult;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "setMonitoringResult", setMonitoringResult);
    }
};



} } 

