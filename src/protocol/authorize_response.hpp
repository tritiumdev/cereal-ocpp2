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

SCHEMA_ENUM(CertificateStatusEnum,\
    Accepted,\
    SignatureError,\
    CertificateExpired,\
    CertificateRevoked,\
    NoCertificateAvailable,\
    CertChainError,\
    ContractCancelled);
using CertificateStatusEnumType=schema_enum_value<CertificateStatusEnum>;

struct AuthorizeResponse
{
    optional<CertificateStatusEnumType> certificateStatus;
    optional<schema_array<int,65536,1>> evseId;
    IdTokenInfoType idTokenInfo;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "certificateStatus", certificateStatus);
        cereal::nvp(archive, "evseId", evseId);
        cereal::nvp(archive, "idTokenInfo", idTokenInfo);
    }
};



} } 

