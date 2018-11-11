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

struct CustomerInformationRequest
{
    schema_boolean clear;
    optional<CertificateHashDataType> customerCertificate;
    optional<schema_string<64>> customerIdentifier;
    optional<IdTokenType> idToken;
    schema_boolean report;
    int requestId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "clear", clear);
        cereal::nvp(archive, "customerCertificate", customerCertificate);
        cereal::nvp(archive, "customerIdentifier", customerIdentifier);
        cereal::nvp(archive, "idToken", idToken);
        cereal::nvp(archive, "report", report);
        cereal::nvp(archive, "requestId", requestId);
    }
};



} } 

