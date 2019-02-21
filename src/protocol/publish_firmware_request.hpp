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

struct PublishFirmwareRequest
{
    static const char* action() { return "PublishFirmware"; }

    schema_string<32> checksum;
    schema_string<512> location;
    optional<int> retries;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "checksum", checksum);
        cereal::nvp(archive, "location", location);
        cereal::nvp(archive, "retries", retries);
    }
};



} } 

