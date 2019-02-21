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

SCHEMA_ENUM(n15118EVCertificateStatusEnum,\
    Accepted,\
    Failed);
using n15118EVCertificateStatusEnumType=schema_enum_value<n15118EVCertificateStatusEnum>;

struct CertificateChainType
{
    schema_string<800> certificate;
    optional<schema_array<schema_string<800>, 4, 1>>> childCertificate;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "certificate", certificate);
        cereal::nvp(archive, "childCertificate", childCertificate);
    }
};

struct Get15118EVCertificateResponse
{
    CertificateChainType contractSignatureCertificateChain;
    schema_string<5500> exiResponse;
    CertificateChainType saProvisioningCertificateChain;
    n15118EVCertificateStatusEnumType status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "contractSignatureCertificateChain", contractSignatureCertificateChain);
        cereal::nvp(archive, "exiResponse", exiResponse);
        cereal::nvp(archive, "saProvisioningCertificateChain", saProvisioningCertificateChain);
        cereal::nvp(archive, "status", status);
    }
};



} } 

