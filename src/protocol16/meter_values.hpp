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

struct MeterValueEntry
{
    schema_array<SampledValueEntry,65536,0> sampledValue;
    schema_date_time timestamp;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "sampledValue", sampledValue);
        cereal::nvp(archive, "timestamp", timestamp);
    }
};

struct MeterValuesRequest
{
    static const char* action() { return "MeterValues"; }

    int connectorId;
    schema_array<MeterValueEntry,65536,0> meterValue;
    optional<int> transactionId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "connectorId", connectorId);
        cereal::nvp(archive, "meterValue", meterValue);
        cereal::nvp(archive, "transactionId", transactionId);
    }
};



} } 

