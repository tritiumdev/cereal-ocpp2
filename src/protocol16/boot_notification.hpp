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

struct BootNotificationRequest
{
    static const char* action() { return "BootNotification"; }

    optional<schema_string<25>> chargeBoxSerialNumber;
    schema_string<20> chargePointModel;
    optional<schema_string<25>> chargePointSerialNumber;
    schema_string<20> chargePointVendor;
    optional<schema_string<50>> firmwareVersion;
    optional<schema_string<20>> iccid;
    optional<schema_string<20>> imsi;
    optional<schema_string<25>> meterSerialNumber;
    optional<schema_string<25>> meterType;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargeBoxSerialNumber", chargeBoxSerialNumber);
        cereal::nvp(archive, "chargePointModel", chargePointModel);
        cereal::nvp(archive, "chargePointSerialNumber", chargePointSerialNumber);
        cereal::nvp(archive, "chargePointVendor", chargePointVendor);
        cereal::nvp(archive, "firmwareVersion", firmwareVersion);
        cereal::nvp(archive, "iccid", iccid);
        cereal::nvp(archive, "imsi", imsi);
        cereal::nvp(archive, "meterSerialNumber", meterSerialNumber);
        cereal::nvp(archive, "meterType", meterType);
    }
};



} } 

