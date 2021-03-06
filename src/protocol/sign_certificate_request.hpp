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

struct SignCertificateRequest
{
    static const char* action() { return "SignCertificate"; }

    SCHEMA_ENUM(TypeOfCertificate,\
        ChargingStationCertificate,\
        V2GCertificate);
    using TypeOfCertificateEnum=schema_enum_value<TypeOfCertificate>;

    schema_string<800> csr;
    optional<TypeOfCertificateEnum> typeOfCertificate;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "csr", csr);
        cereal::nvp(archive, "typeOfCertificate", typeOfCertificate);
    }
};



} } 

