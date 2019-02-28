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

struct InstallCertificateRequest
{
    static const char* action() { return "InstallCertificate"; }

    SCHEMA_ENUM(CertificateType,\
        V2GRootCertficate,\
        MORootCertificate,\
        CSOSubCA1,\
        CSOSubCA2,\
        CSMSRootCertificate,\
        ManufacturerRootCertificate);
    using CertificateTypeEnum=schema_enum_value<CertificateType>;

    schema_string<800> certificate;
    CertificateTypeEnum certificateType;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "certificate", certificate);
        cereal::nvp(archive, "certificateType", certificateType);
    }
};



} } 

