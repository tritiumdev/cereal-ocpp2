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

struct StatusNotificationRequest
{
    static const char* action() { return "StatusNotification"; }

    SCHEMA_ENUM(ConnectorStatus,\
        Available,\
        Occupied,\
        Reserved,\
        Unavailable,\
        Faulted);
    using ConnectorStatusEnum=schema_enum_value<ConnectorStatus>;

    int connectorId;
    ConnectorStatusEnum connectorStatus;
    int evseId;
    schema_date_time timestamp;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "connectorId", connectorId);
        cereal::nvp(archive, "connectorStatus", connectorStatus);
        cereal::nvp(archive, "evseId", evseId);
        cereal::nvp(archive, "timestamp", timestamp);
    }
};



} } 

