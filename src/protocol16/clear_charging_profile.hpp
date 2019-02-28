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

struct ClearChargingProfileRequest
{
    static const char* action() { return "ClearChargingProfile"; }

    SCHEMA_ENUM(ChargingProfilePurpose,\
        ChargePointMaxProfile,\
        TxDefaultProfile,\
        TxProfile);
    using ChargingProfilePurposeEnum=schema_enum_value<ChargingProfilePurpose>;

    optional<ChargingProfilePurposeEnum> chargingProfilePurpose;
    optional<int> connectorId;
    optional<int> id;
    optional<int> stackLevel;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingProfilePurpose", chargingProfilePurpose);
        cereal::nvp(archive, "connectorId", connectorId);
        cereal::nvp(archive, "id", id);
        cereal::nvp(archive, "stackLevel", stackLevel);
    }
};



} } 

