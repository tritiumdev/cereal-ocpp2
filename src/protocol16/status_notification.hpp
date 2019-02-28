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

struct StatusNotificationRequest
{
    static const char* action() { return "StatusNotification"; }

    SCHEMA_ENUM(ErrorCode,\
        ConnectorLockFailure,\
        EVCommunicationError,\
        GroundFailure,\
        HighTemperature,\
        InternalError,\
        LocalListConflict,\
        NoError,\
        OtherError,\
        OverCurrentFailure,\
        PowerMeterFailure,\
        PowerSwitchFailure,\
        ReaderFailure,\
        ResetFailure,\
        UnderVoltage,\
        OverVoltage,\
        WeakSignal);
    using ErrorCodeEnum=schema_enum_value<ErrorCode>;

    SCHEMA_ENUM(Status,\
        Available,\
        Preparing,\
        Charging,\
        SuspendedEVSE,\
        SuspendedEV,\
        Finishing,\
        Reserved,\
        Unavailable,\
        Faulted);
    using StatusEnum=schema_enum_value<Status>;

    int connectorId;
    ErrorCodeEnum errorCode;
    optional<schema_string<50>> info;
    StatusEnum status;
    optional<schema_date_time> timestamp;
    optional<schema_string<50>> vendorErrorCode;
    optional<schema_string<255>> vendorId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "connectorId", connectorId);
        cereal::nvp(archive, "errorCode", errorCode);
        cereal::nvp(archive, "info", info);
        cereal::nvp(archive, "status", status);
        cereal::nvp(archive, "timestamp", timestamp);
        cereal::nvp(archive, "vendorErrorCode", vendorErrorCode);
        cereal::nvp(archive, "vendorId", vendorId);
    }
};



} } 

