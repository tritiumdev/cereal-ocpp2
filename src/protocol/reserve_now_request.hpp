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

SCHEMA_ENUM(ConnectorEnum,\
    cCCS1,\
    cCCS2,\
    cG105,\
    cTesla,\
    cType1,\
    cType2,\
    s309-1P-16A,\
    s309-1P-32A,\
    s309-3P-16A,\
    s309-3P-32A,\
    sBS1361,\
    sCEE-7-7,\
    sType2,\
    sType3,\
    Other1PhMax16A,\
    Other1PhOver16A,\
    Other3Ph,\
    Pan,\
    wInductive,\
    wResonant,\
    Undetermined,\
    Unknown);
using ConnectorEnumType=schema_enum_value<ConnectorEnum>;

struct ReservationType
{
    optional<ConnectorEnumType> connectorCode;
    EVSEType evse;
    schema_date_time expiryDateTime;
    int id;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "connectorCode", connectorCode);
        cereal::nvp(archive, "evse", evse);
        cereal::nvp(archive, "expiryDateTime", expiryDateTime);
        cereal::nvp(archive, "id", id);
    }
};

struct ReserveNowRequest
{
    static const char* action() { return "ReserveNow"; }

    optional<IdTokenType> groupIdToken;
    IdTokenType idToken;
    ReservationType reservation;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "groupIdToken", groupIdToken);
        cereal::nvp(archive, "idToken", idToken);
        cereal::nvp(archive, "reservation", reservation);
    }
};



} } 

