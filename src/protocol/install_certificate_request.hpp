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

struct InstallCertificateRequest
{
    static const char* action() { return "InstallCertificate"; }

    SCHEMA_ENUM(CertificateTypeType,\
        V2GRootCertficate,\
        MORootCertificate,\
        CSOSubCA1,\
        CSOSubCA2,\
        CSMSRootCertificate,\
        ManufacturerRootCertificate);
    using CertificateTypeTypeEnum=schema_enum_value<CertificateTypeType>;

    schema_string<800> certificate;
    CertificateTypeTypeEnum certificateType;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "certificate", certificate);
        cereal::nvp(archive, "certificateType", certificateType);
    }
};



} } 

