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

struct NotifyCustomerInformationRequest
{
    static const char* action() { return "NotifyCustomerInformation"; }

    schema_string<512> data;
    schema_date_time generatedAt;
    optional<int> requestId;
    int seqNo;
    schema_boolean tbc;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "data", data);
        cereal::nvp(archive, "generatedAt", generatedAt);
        cereal::nvp(archive, "requestId", requestId);
        cereal::nvp(archive, "seqNo", seqNo);
        cereal::nvp(archive, "tbc", tbc);
    }
};



} } 

