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
*
*/

#include <cereal/types/vector.hpp>
#include "../cereal/cereal_ext.hpp"
#include "../cereal/schema_enum.hpp"
#include "../cereal/schema_string.hpp"
#include <vector>
#include "./common.hpp"

namespace lgpl3 { namespace ocpp20 { 

SCHEMA_ENUM(UpdateEnum,\
    Differential,\
    Full);
using UpdateEnumType=schema_enum_value<UpdateEnum>;

struct AuthorizationData
{
    IdTokenType idToken;
    optional<IdTokenInfoType> idTokenInfo;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "idToken", idToken);
        cereal::nvp(archive, "idTokenInfo", idTokenInfo);
    }
};

struct SendLocalListRequest
{
    optional<std::vector<AuthorizationData>> localAuthorizationList;
    UpdateEnumType updateType;
    int versionNumber;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "localAuthorizationList", localAuthorizationList);
        cereal::nvp(archive, "updateType", updateType);
        cereal::nvp(archive, "versionNumber", versionNumber);
    }
};



} } 

