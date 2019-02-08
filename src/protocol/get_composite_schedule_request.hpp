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

struct GetCompositeScheduleRequest
{
    SCHEMA_ENUM(ChargingRateUnitType,\
        W,\
        A);
    using ChargingRateUnitTypeEnum=schema_enum_value<ChargingRateUnitType>;

    optional<ChargingRateUnitTypeEnum> chargingRateUnit;
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

