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

SCHEMA_ENUM(APNAuthenticationEnum,\
    CHAP,\
    NONE,\
    PAP,\
    AUTO);
using APNAuthenticationEnumType=schema_enum_value<APNAuthenticationEnum>;

SCHEMA_ENUM(OCPPInterfaceEnum,\
    Wired0,\
    Wired1,\
    Wired2,\
    Wired3,\
    Wireless0,\
    Wireless1,\
    Wireless2,\
    Wireless3);
using OCPPInterfaceEnumType=schema_enum_value<OCPPInterfaceEnum>;

SCHEMA_ENUM(OCPPTransportEnum,\
    JSON,\
    SOAP);
using OCPPTransportEnumType=schema_enum_value<OCPPTransportEnum>;

SCHEMA_ENUM(OCPPVersionEnum,\
    OCPP12,\
    OCPP15,\
    OCPP16,\
    OCPP20);
using OCPPVersionEnumType=schema_enum_value<OCPPVersionEnum>;

SCHEMA_ENUM(VPNEnum,\
    IKEv2,\
    IPSec,\
    L2TP,\
    PPTP);
using VPNEnumType=schema_enum_value<VPNEnum>;

struct APNType
{
    schema_string<512> apn;
    APNAuthenticationEnumType apnAuthentication;
    optional<schema_string<20>> apnPassword;
    optional<schema_string<20>> apnUserName;
    optional<schema_string<6>> preferredNetwork;
    optional<int> simPin;
    optional<schema_boolean> useOnlyPreferredNetwork;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "apn", apn);
        cereal::nvp(archive, "apnAuthentication", apnAuthentication);
        cereal::nvp(archive, "apnPassword", apnPassword);
        cereal::nvp(archive, "apnUserName", apnUserName);
        cereal::nvp(archive, "preferredNetwork", preferredNetwork);
        cereal::nvp(archive, "simPin", simPin);
        cereal::nvp(archive, "useOnlyPreferredNetwork", useOnlyPreferredNetwork);
    }
};

struct VPNType
{
    optional<schema_string<20>> group;
    schema_string<255> key;
    schema_string<20> password;
    schema_string<512> server;
    VPNEnumType type;
    schema_string<20> user;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "group", group);
        cereal::nvp(archive, "key", key);
        cereal::nvp(archive, "password", password);
        cereal::nvp(archive, "server", server);
        cereal::nvp(archive, "type", type);
        cereal::nvp(archive, "user", user);
    }
};

struct NetworkConnectionProfileType
{
    optional<APNType> apn;
    int messageTimeout;
    schema_string<512> ocppCsmsUrl;
    OCPPInterfaceEnumType ocppInterface;
    OCPPTransportEnumType ocppTransport;
    OCPPVersionEnumType ocppVersion;
    optional<VPNType> vpn;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "apn", apn);
        cereal::nvp(archive, "messageTimeout", messageTimeout);
        cereal::nvp(archive, "ocppCsmsUrl", ocppCsmsUrl);
        cereal::nvp(archive, "ocppInterface", ocppInterface);
        cereal::nvp(archive, "ocppTransport", ocppTransport);
        cereal::nvp(archive, "ocppVersion", ocppVersion);
        cereal::nvp(archive, "vpn", vpn);
    }
};

struct SetNetworkProfileRequest
{
    static const char* action() { return "SetNetworkProfile"; }

    int configurationSlot;
    NetworkConnectionProfileType connectionData;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "configurationSlot", configurationSlot);
        cereal::nvp(archive, "connectionData", connectionData);
    }
};



} } 

