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
*     --include="../cereal/schema_date_time.hpp"
*
*/

#include "./common.hpp"

namespace lgpl3 { namespace ocpp20 { 

struct PublishFirmwareStatusNotificationRequest
{
    SCHEMA_ENUM(StatusType,\
        Downloaded,\
        DownloadFailed,\
        Downloading,\
        DownloadScheduled,\
        DownloadPaused,\
        PublishFailed,\
        Published,\
        InvalidChecksum,\
        ChecksumVerified);
    using StatusTypeEnum=schema_enum_value<StatusType>;

    optional<schema_array<schema_string<512>, 65536, 1>>> location;
    StatusTypeEnum status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "location", location);
        cereal::nvp(archive, "status", status);
    }
};



} } 

