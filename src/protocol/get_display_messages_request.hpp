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

struct GetDisplayMessagesRequest
{
    static const char* action() { return "GetDisplayMessages"; }

    SCHEMA_ENUM(Priority,\
        AlwaysFront,\
        InFront,\
        NormalCycle);
    using PriorityEnum=schema_enum_value<Priority>;

    SCHEMA_ENUM(State,\
        Charging,\
        Faulted,\
        Idle,\
        Unavailable);
    using StateEnum=schema_enum_value<State>;

    optional<schema_array<int,65536,1>> id;
    optional<PriorityEnum> priority;
    int requestId;
    optional<StateEnum> state;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "id", id);
        cereal::nvp(archive, "priority", priority);
        cereal::nvp(archive, "requestId", requestId);
        cereal::nvp(archive, "state", state);
    }
};



} } 

