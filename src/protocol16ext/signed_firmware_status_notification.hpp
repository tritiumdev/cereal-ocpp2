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

struct SignedFirmwareStatusNotificationRequest
{
    static const char* action() { return "SignedFirmwareStatusNotification"; }

    SCHEMA_ENUM(Status,\
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
    using StatusEnum=schema_enum_value<Status>;

    int requestId;
    StatusEnum status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "requestId", requestId);
        cereal::nvp(archive, "status", status);
    }
};



} } 

