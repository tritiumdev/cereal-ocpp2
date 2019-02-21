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

struct UpdateFirmwareRequest
{
    static const char* action() { return "UpdateFirmware"; }

    std::string  location;
    optional<double> retries;
    schema_date_time retrieveDate;
    optional<double> retryInterval;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "location", location);
        cereal::nvp(archive, "retries", retries);
        cereal::nvp(archive, "retrieveDate", retrieveDate);
        cereal::nvp(archive, "retryInterval", retryInterval);
    }
};



} } 
