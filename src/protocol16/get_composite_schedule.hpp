#pragma once

/**
*
* This file is auto generated using this exact command:
*     ../../generator/16/schema-to-cpp-header.py
*     --input-dir=../../schemas/16
*     --namespace=lgpl3
*     --namespace=ocpp16
*     --include=<cereal/types/vector.hpp>
*     --include="../cereal/cereal_ext.hpp"
*     --include="../cereal/schema_enum.hpp"
*     --include="../cereal/schema_string.hpp"
*     --include="../cereal/schema_array.hpp"
*     --include="../cereal/schema_date_time.hpp"
*
*/

#include "./common.hpp"

namespace lgpl3 { namespace ocpp16 { 

struct GetCompositeScheduleRequest
{
    static const char* action() { return "GetCompositeSchedule"; }

    SCHEMA_ENUM(ChargingRateUnit,\
        A,\
        W);
    using ChargingRateUnitEnum=schema_enum_value<ChargingRateUnit>;

    optional<ChargingRateUnitEnum> chargingRateUnit;
    int connectorId;
    int duration;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingRateUnit", chargingRateUnit);
        cereal::nvp(archive, "connectorId", connectorId);
        cereal::nvp(archive, "duration", duration);
    }
};



} } 

