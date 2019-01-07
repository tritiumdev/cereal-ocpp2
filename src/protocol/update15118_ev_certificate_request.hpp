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
*     --include="../cereal/rfc3339_string.hpp"
*
*/

#include "./common.hpp"

namespace lgpl3 { namespace ocpp20 { 

struct Update15118EVCertificateRequest
{
    optional<schema_string<50>> n15118SchemaVersion;
    schema_string<5500> exiRequest;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "15118SchemaVersion", n15118SchemaVersion);
        cereal::nvp(archive, "exiRequest", exiRequest);
    }
};



} } 

