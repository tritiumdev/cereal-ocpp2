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

SCHEMA_ENUM(LogEnum,\
    DiagnosticsLog,\
    SecurityLog);
using LogEnumType=schema_enum_value<LogEnum>;

struct LogParametersType
{
    optional<schema_date_time> latestTimestamp;
    optional<schema_date_time> oldestTimestamp;
    schema_string<512> remoteLocation;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "latestTimestamp", latestTimestamp);
        cereal::nvp(archive, "oldestTimestamp", oldestTimestamp);
        cereal::nvp(archive, "remoteLocation", remoteLocation);
    }
};

struct GetLogRequest
{
    static const char* action() { return "GetLog"; }

    LogParametersType log;
    LogEnumType logType;
    int requestId;
    optional<int> retries;
    optional<int> retryInterval;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "log", log);
        cereal::nvp(archive, "logType", logType);
        cereal::nvp(archive, "requestId", requestId);
        cereal::nvp(archive, "retries", retries);
        cereal::nvp(archive, "retryInterval", retryInterval);
    }
};



} } 

