#pragma once

/**
*
* This file is auto generated using this exact command:
*     ../../generator/16/schema-to-cpp-header.py
*     --input-dir=../../schemas/16
*     --namespace=lgpl3
*     --namespace=ocpp16
*     --include=<cereal/types/vector.hpp>
*     --include="../cereal/cereal_ext.hpp"
*     --include="../cereal/schema_enum.hpp"
*     --include="../cereal/schema_string.hpp"
*     --include="../cereal/schema_array.hpp"
*     --include="../cereal/schema_date_time.hpp"
*
*/

#include "./common.hpp"

namespace lgpl3 { namespace ocpp16 { 

struct IdTagInfo
{
    SCHEMA_ENUM(Status,\
        Accepted,\
        Blocked,\
        Expired,\
        Invalid,\
        ConcurrentTx);
    using StatusEnum=schema_enum_value<Status>;

    StatusEnum status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "status", status);
    }
};

struct LocalAuthorizationListEntry
{
    schema_string<20> idTag;
    optional<IdTagInfo> idTagInfo;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "idTag", idTag);
        cereal::nvp(archive, "idTagInfo", idTagInfo);
    }
};

struct SendLocalListRequest
{
    static const char* action() { return "SendLocalList"; }

    SCHEMA_ENUM(UpdateType,\
        Differential,\
        Full);
    using UpdateTypeEnum=schema_enum_value<UpdateType>;

    int listVersion;
    optional<schema_array<LocalAuthorizationListEntry,65536,0>> localAuthorizationList;
    UpdateTypeEnum updateType;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "listVersion", listVersion);
        cereal::nvp(archive, "localAuthorizationList", localAuthorizationList);
        cereal::nvp(archive, "updateType", updateType);
    }
};



} } 

