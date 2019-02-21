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

struct ClearChargingProfileType
{
    optional<ChargingProfilePurposeEnumType> chargingProfilePurpose;
    optional<int> id;
    optional<int> stackLevel;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingProfilePurpose", chargingProfilePurpose);
        cereal::nvp(archive, "id", id);
        cereal::nvp(archive, "stackLevel", stackLevel);
    }
};

struct ClearChargingProfileRequest
{
    static const char* action() { return "ClearChargingProfile"; }

    optional<ClearChargingProfileType> chargingProfile;
    optional<int> evseId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingProfile", chargingProfile);
        cereal::nvp(archive, "evseId", evseId);
    }
};



} } 

