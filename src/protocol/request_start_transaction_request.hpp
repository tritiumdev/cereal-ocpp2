#pragma once

/**
*
* This file is auto generated using this exact command:
*     ../../generator/scripts/schema-to-cpp-header2.py
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

struct RequestStartTransactionRequest
{
    optional<ChargingProfileType> chargingProfile;
    optional<int> evseId;
    IdTokenType idToken;
    int remoteStartId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingProfile", chargingProfile);
        cereal::nvp(archive, "evseId", evseId);
        cereal::nvp(archive, "idToken", idToken);
        cereal::nvp(archive, "remoteStartId", remoteStartId);
    }
};



} } 

