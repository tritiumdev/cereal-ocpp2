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

SCHEMA_ENUM(GetInstalledCertificateStatusEnum,\
    Accepted,\
    NotFound);
using GetInstalledCertificateStatusEnumType=schema_enum_value<GetInstalledCertificateStatusEnum>;

struct GetInstalledCertificateIdsResponse
{
    optional<schema_array<CertificateHashDataType,65536,1>> certificateHashData;
    GetInstalledCertificateStatusEnumType status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "certificateHashData", certificateHashData);
        cereal::nvp(archive, "status", status);
    }
};



} } 

