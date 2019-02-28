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

struct GetCompositeScheduleResponse
{
    SCHEMA_ENUM(Status,\
        Accepted,\
        Rejected);
    using StatusEnum=schema_enum_value<Status>;

    optional<ChargingSchedule> chargingSchedule;
    optional<int> connectorId;
    optional<schema_date_time> scheduleStart;
    StatusEnum status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingSchedule", chargingSchedule);
        cereal::nvp(archive, "connectorId", connectorId);
        cereal::nvp(archive, "scheduleStart", scheduleStart);
        cereal::nvp(archive, "status", status);
    }
};



} } 

