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

struct InstallCertificateRequest
{
    static const char* action() { return "InstallCertificate"; }

    SCHEMA_ENUM(CertificateType,\
        CentralSystemRootCertificate,\
        ManufacturerRootCertificate);
    using CertificateTypeEnum=schema_enum_value<CertificateType>;

    schema_string<5500> certificate;
    CertificateTypeEnum certificateType;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "certificate", certificate);
        cereal::nvp(archive, "certificateType", certificateType);
    }
};



} } 

