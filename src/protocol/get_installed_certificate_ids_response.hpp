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

