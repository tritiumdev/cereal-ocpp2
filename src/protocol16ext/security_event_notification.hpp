#pragma once

/**
*
* This file is auto generated using this exact command:
*     ../../generator/scripts/schema-to-cpp-header2.py
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

struct SecurityEventNotificationRequest
{
    schema_date_time timestamp;
    schema_string<50> type;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "timestamp", timestamp);
        cereal::nvp(archive, "type", type);
    }
};



} } 

