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
*     --include="../cereal/rfc3339_string.hpp"
*
*/

#include <cereal/types/vector.hpp>
#include "../cereal/cereal_ext.hpp"
#include "../cereal/schema_enum.hpp"
#include "../cereal/schema_string.hpp"
#include "../cereal/rfc3339_string.hpp"
#include <vector>
#include "./common.hpp"

namespace lgpl3 { namespace ocpp20 { 

struct SecurityEventNotificationRequest
{
    SCHEMA_ENUM(TypeType,\
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
    using TypeTypeEnum=schema_enum_value<TypeType>;

    date_time timestamp;
    TypeTypeEnum type;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "timestamp", timestamp);
        cereal::nvp(archive, "type", type);
    }
};



} } 

