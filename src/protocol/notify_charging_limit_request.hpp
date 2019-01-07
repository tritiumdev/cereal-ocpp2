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

struct ChargingLimitType
{
    ChargingLimitSourceEnumType chargingLimitSource;
    optional<schema_boolean> isGridCritical;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingLimitSource", chargingLimitSource);
        cereal::nvp(archive, "isGridCritical", isGridCritical);
    }
};

struct NotifyChargingLimitRequest
{
    ChargingLimitType chargingLimit;
    optional<schema_array<ChargingScheduleType,65536,1>> chargingSchedule;
    optional<int> evseId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingLimit", chargingLimit);
        cereal::nvp(archive, "chargingSchedule", chargingSchedule);
        cereal::nvp(archive, "evseId", evseId);
    }
};



} } 

