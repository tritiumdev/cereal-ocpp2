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
*     --include="../cereal/schema_array.hpp"
*     --include="../cereal/schema_date_time.hpp"
*
*/

#include "./common.hpp"

namespace lgpl3 { namespace ocpp20 { 

struct AuthorizeRequest
{
    optional<schema_array<OCSPRequestDataType,4,1>> n15118CertificateHashData;
    optional<schema_array<int,65536,1>> evseId;
    IdTokenType idToken;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "15118CertificateHashData", n15118CertificateHashData);
        cereal::nvp(archive, "evseId", evseId);
        cereal::nvp(archive, "idToken", idToken);
    }
};



} } 

