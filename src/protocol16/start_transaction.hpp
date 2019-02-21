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

struct StartTransactionRequest
{
    static const char* action() { return "StartTransaction"; }

    int connectorId;
    schema_string<20> idTag;
    int meterStart;
    optional<int> reservationId;
    schema_date_time timestamp;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "connectorId", connectorId);
        cereal::nvp(archive, "idTag", idTag);
        cereal::nvp(archive, "meterStart", meterStart);
        cereal::nvp(archive, "reservationId", reservationId);
        cereal::nvp(archive, "timestamp", timestamp);
    }
};



} } 

