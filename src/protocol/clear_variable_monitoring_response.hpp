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

SCHEMA_ENUM(ClearMonitoringStatusEnum,\
    Accepted,\
    Rejected,\
    NotFound);
using ClearMonitoringStatusEnumType=schema_enum_value<ClearMonitoringStatusEnum>;

struct ClearMonitoringResultType
{
    int id;
    ClearMonitoringStatusEnumType status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "id", id);
        cereal::nvp(archive, "status", status);
    }
};

struct ClearVariableMonitoringResponse
{
    schema_array<ClearMonitoringResultType,65536,1> clearMonitoringResult;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "clearMonitoringResult", clearMonitoringResult);
    }
};



} } 

