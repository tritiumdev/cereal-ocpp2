#pragma once

/**
*
* This file is auto generated using this exact command:
*     ../../generator/scripts/schema-to-cpp-header2.py
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

struct InstallCertificate.req
{
    SCHEMA_ENUM(CertificateTypeType,\
        CentralSystemRootCertificate,\
        ManufacturerRootCertificate);
    using CertificateTypeTypeEnum=schema_enum_value<CertificateTypeType>;

    schema_string<5500> certificate;
    CertificateTypeTypeEnum certificateType;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "certificate", certificate);
        cereal::nvp(archive, "certificateType", certificateType);
    }
};



} } 

