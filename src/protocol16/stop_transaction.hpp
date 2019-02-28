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

struct TransactionDataEntry
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

struct StopTransactionRequest
{
    static const char* action() { return "StopTransaction"; }

    SCHEMA_ENUM(Reason,\
        EmergencyStop,\
        EVDisconnected,\
        HardReset,\
        Local,\
        Other,\
        PowerLoss,\
        Reboot,\
        Remote,\
        SoftReset,\
        UnlockCommand,\
        DeAuthorized);
    using ReasonEnum=schema_enum_value<Reason>;

    optional<schema_string<20>> idTag;
    int meterStop;
    optional<ReasonEnum> reason;
    schema_date_time timestamp;
    optional<schema_array<TransactionDataEntry,65536,0>> transactionData;
    int transactionId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "idTag", idTag);
        cereal::nvp(archive, "meterStop", meterStop);
        cereal::nvp(archive, "reason", reason);
        cereal::nvp(archive, "timestamp", timestamp);
        cereal::nvp(archive, "transactionData", transactionData);
        cereal::nvp(archive, "transactionId", transactionId);
    }
};



} } 

