#pragma once

/**
*
* This file is auto generated using this exact command:
*     ../../generator/20/schema-to-cpp-header2.py
*     --input-dir=../../schemas/16ext
*     --namespace=lgpl3
*     --namespace=ocpp16ext
*     --include=<cereal/types/vector.hpp>
*     --include="../cereal/cereal_ext.hpp"
*     --include="../cereal/schema_enum.hpp"
*     --include="../cereal/schema_string.hpp"
*     --include="../cereal/schema_array.hpp"
*     --include="../cereal/schema_date_time.hpp"
*
*/

#include "./common.hpp"

namespace lgpl3 { namespace ocpp16ext { 

SCHEMA_ENUM(MessageTriggerEnum,\
    BootNotification,\
    LogStatusNotification,\
    FirmwareStatusNotification,\
    Heartbeat,\
    MeterValues,\
    SignChargePointCertificate,\
    StatusNotification);
using MessageTriggerEnumType=schema_enum_value<MessageTriggerEnum>;

struct ExtendedTriggerMessageRequest
{
    static const char* action() { return "ExtendedTriggerMessage"; }

    optional<int> connectorId;
    MessageTriggerEnumType requestedMessage;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "connectorId", connectorId);
        cereal::nvp(archive, "requestedMessage", requestedMessage);
    }
};



} } 

