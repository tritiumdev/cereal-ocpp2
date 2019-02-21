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

struct ChargingProfile
{
    SCHEMA_ENUM(ChargingProfileKindType,\
        Absolute,\
        Recurring,\
        Relative);
    using ChargingProfileKindTypeEnum=schema_enum_value<ChargingProfileKindType>;

    SCHEMA_ENUM(ChargingProfilePurposeType,\
        ChargePointMaxProfile,\
        TxDefaultProfile,\
        TxProfile);
    using ChargingProfilePurposeTypeEnum=schema_enum_value<ChargingProfilePurposeType>;

    SCHEMA_ENUM(RecurrencyKindType,\
        Daily,\
        Weekly);
    using RecurrencyKindTypeEnum=schema_enum_value<RecurrencyKindType>;

    int chargingProfileId;
    ChargingProfileKindTypeEnum chargingProfileKind;
    ChargingProfilePurposeTypeEnum chargingProfilePurpose;
    ChargingSchedule chargingSchedule;
    optional<RecurrencyKindTypeEnum> recurrencyKind;
    int stackLevel;
    optional<int> transactionId;
    optional<schema_date_time> validFrom;
    optional<schema_date_time> validTo;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingProfileId", chargingProfileId);
        cereal::nvp(archive, "chargingProfileKind", chargingProfileKind);
        cereal::nvp(archive, "chargingProfilePurpose", chargingProfilePurpose);
        cereal::nvp(archive, "chargingSchedule", chargingSchedule);
        cereal::nvp(archive, "recurrencyKind", recurrencyKind);
        cereal::nvp(archive, "stackLevel", stackLevel);
        cereal::nvp(archive, "transactionId", transactionId);
        cereal::nvp(archive, "validFrom", validFrom);
        cereal::nvp(archive, "validTo", validTo);
    }
};

struct RemoteStartTransactionRequest
{
    static const char* action() { return "RemoteStartTransaction"; }

    optional<ChargingProfile> chargingProfile;
    optional<int> connectorId;
    schema_string<20> idTag;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingProfile", chargingProfile);
        cereal::nvp(archive, "connectorId", connectorId);
        cereal::nvp(archive, "idTag", idTag);
    }
};



} } 

