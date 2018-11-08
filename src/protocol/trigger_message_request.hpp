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
*
*/

#include <cereal/types/vector.hpp>
#include "../cereal/cereal_ext.hpp"
#include "../cereal/schema_enum.hpp"
#include "../cereal/schema_string.hpp"
#include <vector>
#include "./common.hpp"

namespace lgpl3 { namespace ocpp20 { 

SCHEMA_ENUM(MessageTriggerEnum,\
    BootNotification,\
    LogStatusNotification,\
    FirmwareStatusNotification,\
    Heartbeat,\
    MeterValues,\
    SignChargingStationCertificate,\
    SignV2GCertificate,\
    StatusNotification,\
    TransactionEvent);
using MessageTriggerEnumType=schema_enum_value<MessageTriggerEnum>;

struct TriggerMessageRequest
{
    optional<EVSEType> evse;
    MessageTriggerEnumType requestedMessage;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "evse", evse);
        cereal::nvp(archive, "requestedMessage", requestedMessage);
    }
};



} } 

