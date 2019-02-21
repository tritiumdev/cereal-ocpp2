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

#include <cereal/types/vector.hpp>
#include "../cereal/cereal_ext.hpp"
#include "../cereal/schema_enum.hpp"
#include "../cereal/schema_string.hpp"
#include "../cereal/schema_array.hpp"
#include "../cereal/schema_date_time.hpp"
#include <vector>

namespace lgpl3 { namespace ocpp16ext { 

template<typename Type>
using optional=cereal::optional<Type>;

template<std::size_t MaxSize, std::size_t MinSize=1>
using schema_string=cereal::schema_string<MaxSize, MinSize>;

template<typename Type, std::size_t MaxSize, std::size_t MinSize=1>
using schema_array=cereal::schema_array<Type,MaxSize, MinSize>;

template<typename SchemaSet>
using schema_enum_value=cereal::schema_enum_value<SchemaSet>;

using schema_date_time=cereal::schema_data_time;

using schema_boolean=cereal::schema_boolean;

SCHEMA_ENUM(HashAlgorithmEnum,\
    SHA256,\
    SHA384,\
    SHA512);
using HashAlgorithmEnumType=schema_enum_value<HashAlgorithmEnum>;

struct CertificateHashDataType
{
    HashAlgorithmEnumType hashAlgorithm;
    schema_string<128> issuerKeyHash;
    schema_string<128> issuerNameHash;
    schema_string<40> serialNumber;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "hashAlgorithm", hashAlgorithm);
        cereal::nvp(archive, "issuerKeyHash", issuerKeyHash);
        cereal::nvp(archive, "issuerNameHash", issuerNameHash);
        cereal::nvp(archive, "serialNumber", serialNumber);
    }
};



} } 

