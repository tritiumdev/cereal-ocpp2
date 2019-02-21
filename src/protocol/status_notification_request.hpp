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

struct StatusNotificationRequest
{
    static const char* action() { return "StatusNotification"; }

    SCHEMA_ENUM(ConnectorStatusType,\
        Available,\
        Occupied,\
        Reserved,\
        Unavailable,\
        Faulted);
    using ConnectorStatusTypeEnum=schema_enum_value<ConnectorStatusType>;

    int connectorId;
    ConnectorStatusTypeEnum connectorStatus;
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

