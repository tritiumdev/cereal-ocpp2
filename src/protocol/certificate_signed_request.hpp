#pragma once

/**
*
* This file is auto generated using this exact command:
*     ../../generator/scripts/schema-to-cpp-header2.py
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

struct CertificateSignedRequest
{
    static const char* action() { return "CertificateSigned"; }

    SCHEMA_ENUM(TypeOfCertificateType,\
        ChargingStationCertificate,\
        V2GCertificate);
    using TypeOfCertificateTypeEnum=schema_enum_value<TypeOfCertificateType>;

    schema_array<schema_string<800>, 65536, 1>> cert;
    optional<TypeOfCertificateTypeEnum> typeOfCertificate;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "cert", cert);
        cereal::nvp(archive, "typeOfCertificate", typeOfCertificate);
    }
};



} } 

