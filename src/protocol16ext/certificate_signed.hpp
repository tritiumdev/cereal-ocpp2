#pragma once

/**
*
* This file is auto generated using this exact command:
*     ../../generator/20/schema-to-cpp-header2.py
*     --input-dir=../../schemas/16ext
*     --namespace=lgpl3
*     --namespace=ocpp16ext
*     --include=<cereal/types/vector.hpp>
*     --include="../cereal/cereal_ext.hpp"
*     --include="../cereal/schema_enum.hpp"
*     --include="../cereal/schema_string.hpp"
*     --include="../cereal/schema_array.hpp"
*     --include="../cereal/schema_date_time.hpp"
*
*/

#include "./common.hpp"

namespace lgpl3 { namespace ocpp16ext { 

struct CertificateSignedRequest
{
    static const char* action() { return "CertificateSigned"; }

    schema_array<schema_string<5500>, 65536, 1>> cert;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "cert", cert);
    }
};



} } 

