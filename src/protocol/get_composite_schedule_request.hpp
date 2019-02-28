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

struct GetCompositeScheduleRequest
{
    static const char* action() { return "GetCompositeSchedule"; }

    SCHEMA_ENUM(ChargingRateUnit,\
        W,\
        A);
    using ChargingRateUnitEnum=schema_enum_value<ChargingRateUnit>;

    optional<ChargingRateUnitEnum> chargingRateUnit;
    int duration;
    int evseId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingRateUnit", chargingRateUnit);
        cereal::nvp(archive, "duration", duration);
        cereal::nvp(archive, "evseId", evseId);
    }
};



} } 

