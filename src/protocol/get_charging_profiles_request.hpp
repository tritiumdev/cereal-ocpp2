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

struct ChargingProfileCriterionType
{
    optional<schema_array<ChargingLimitSourceEnumType,4,1>> chargingLimitSource;
    optional<schema_array<int,65536,1>> chargingProfileId;
    optional<ChargingProfilePurposeEnumType> chargingProfilePurpose;
    optional<int> stackLevel;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingLimitSource", chargingLimitSource);
        cereal::nvp(archive, "chargingProfileId", chargingProfileId);
        cereal::nvp(archive, "chargingProfilePurpose", chargingProfilePurpose);
        cereal::nvp(archive, "stackLevel", stackLevel);
    }
};

struct GetChargingProfilesRequest
{
    static const char* action() { return "GetChargingProfiles"; }

    ChargingProfileCriterionType chargingProfile;
    optional<int> evseId;
    optional<int> requestId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingProfile", chargingProfile);
        cereal::nvp(archive, "evseId", evseId);
        cereal::nvp(archive, "requestId", requestId);
    }
};



} } 

