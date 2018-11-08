#pragma once

/**
*
* This file is auto generated using this exact command:
*     ../../generator/scripts/schema-to-cpp-header2.py
*     --input-dir=../../schemas/schemas
*     --namespace=lgpl3
*     --namespace=ocpp20
*     --include=<cereal/types/vector.hpp>
*     --include="../cereal/cereal_ext.hpp"
*     --include="../cereal/schema_enum.hpp"
*     --include="../cereal/schema_string.hpp"
*
*/

#include <cereal/types/vector.hpp>
#include "../cereal/cereal_ext.hpp"
#include "../cereal/schema_enum.hpp"
#include "../cereal/schema_string.hpp"
#include <vector>
#include "./common.hpp"

namespace lgpl3 { namespace ocpp20 { 

struct FirmwareType
{
    optional<date_time> installDateTime;
    schema_string<512> location;
    date_time retrieveDateTime;
    optional<schema_string<800>> signature;
    optional<schema_string<800>> signingCertificate;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "installDateTime", installDateTime);
        cereal::nvp(archive, "location", location);
        cereal::nvp(archive, "retrieveDateTime", retrieveDateTime);
        cereal::nvp(archive, "signature", signature);
        cereal::nvp(archive, "signingCertificate", signingCertificate);
    }
};

struct UpdateFirmwareRequest
{
    FirmwareType firmware;
    int requestId;
    optional<int> retries;
    optional<int> retryInterval;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "firmware", firmware);
        cereal::nvp(archive, "requestId", requestId);
        cereal::nvp(archive, "retries", retries);
        cereal::nvp(archive, "retryInterval", retryInterval);
    }
};



} } 

