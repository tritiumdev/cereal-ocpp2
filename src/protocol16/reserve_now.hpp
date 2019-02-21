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

struct ReserveNowRequest
{
    static const char* action() { return "ReserveNow"; }

    int connectorId;
    schema_date_time expiryDate;
    schema_string<20> idTag;
    optional<schema_string<20>> parentIdTag;
    int reservationId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "connectorId", connectorId);
        cereal::nvp(archive, "expiryDate", expiryDate);
        cereal::nvp(archive, "idTag", idTag);
        cereal::nvp(archive, "parentIdTag", parentIdTag);
        cereal::nvp(archive, "reservationId", reservationId);
    }
};



} } 

