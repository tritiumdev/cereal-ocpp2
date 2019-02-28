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

struct PublishFirmwareStatusNotificationRequest
{
    static const char* action() { return "PublishFirmwareStatusNotification"; }

    SCHEMA_ENUM(Status,\
        Downloaded,\
        DownloadFailed,\
        Downloading,\
        DownloadScheduled,\
        DownloadPaused,\
        PublishFailed,\
        Published,\
        InvalidChecksum,\
        ChecksumVerified);
    using StatusEnum=schema_enum_value<Status>;

    optional<schema_array<schema_string<512>, 65536, 1>>> location;
    StatusEnum status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "location", location);
        cereal::nvp(archive, "status", status);
    }
};



} } 

