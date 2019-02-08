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

struct SignedFirmwareStatusNotification.req
{
    SCHEMA_ENUM(StatusType,\
        CertificateVerified,\
        Downloaded,\
        DownloadFailed,\
        Downloading,\
        DownloadScheduled,\
        DownloadPaused,\
        Idle,\
        InstallationFailed,\
        Installing,\
        Installed,\
        InstallRebooting,\
        InstallScheduled,\
        InstallVerificationFailed,\
        InvalidSignature,\
        InvalidCertificate,\
        RevokedCertificate,\
        PublishFailed,\
        SignatureVerified);
    using StatusTypeEnum=schema_enum_value<StatusType>;

    int requestId;
    StatusTypeEnum status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "requestId", requestId);
        cereal::nvp(archive, "status", status);
    }
};



} } 
