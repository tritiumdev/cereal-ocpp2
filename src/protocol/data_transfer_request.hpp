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

struct DataTransferRequest
{
    static const char* action() { return "DataTransfer"; }

    optional<std::string> data;
    optional<schema_string<50>> messageId;
    schema_string<255> vendorId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "data", data);
        cereal::nvp(archive, "messageId", messageId);
        cereal::nvp(archive, "vendorId", vendorId);
    }
};



} } 

