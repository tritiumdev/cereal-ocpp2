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

struct ChangeConfigurationRequest
{
    static const char* action() { return "ChangeConfiguration"; }

    schema_string<50> key;
    schema_string<500> value;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "key", key);
        cereal::nvp(archive, "value", value);
    }
};



} } 

