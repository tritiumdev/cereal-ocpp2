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

struct SecurityEventNotificationRequest
{
    static const char* action() { return "SecurityEventNotification"; }

    SCHEMA_ENUM(Type,\
        FirmwareUpdated,\
        FailedToAuthenticateAtCsms,\
        CsmsFailedToAuthenticate,\
        SettingSystemTime,\
        StartupOfTheDevice,\
        ResetOrReboot,\
        SecurityLogWasCleared,\
        ReconfigurationOfSecurityParameters,\
        MemoryExhaustion,\
        InvalidMessages,\
        AttemptedReplayAttacks,\
        TamperDetectionActivated,\
        InvalidFirmwareSignature,\
        InvalidFirmwareSigningCertificate,\
        InvalidCsmsCertificate,\
        InvalidChargingStationCertificate,\
        InvalidTLSVersion,\
        InvalidTLSCipherSuite);
    using TypeEnum=schema_enum_value<Type>;

    schema_date_time timestamp;
    TypeEnum type;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "timestamp", timestamp);
        cereal::nvp(archive, "type", type);
    }
};



} } 

