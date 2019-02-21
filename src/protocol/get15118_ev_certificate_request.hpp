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

struct Get15118EVCertificateRequest
{
    static const char* action() { return "Get15118EVCertificate"; }

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

