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

struct SetNetworkProfileResponse
{
    SCHEMA_ENUM(StatusType,\
        Accepted,\
        Rejected,\
        Failed);
    using StatusTypeEnum=schema_enum_value<StatusType>;

    StatusTypeEnum status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "status", status);
    }
};



} } 

