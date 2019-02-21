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

struct GetDiagnosticsRequest
{
    static const char* action() { return "GetDiagnostics"; }

    std::string  location;
    optional<int> retries;
    optional<int> retryInterval;
    optional<schema_date_time> startTime;
    optional<schema_date_time> stopTime;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "location", location);
        cereal::nvp(archive, "retries", retries);
        cereal::nvp(archive, "retryInterval", retryInterval);
        cereal::nvp(archive, "startTime", startTime);
        cereal::nvp(archive, "stopTime", stopTime);
    }
};



} } 

