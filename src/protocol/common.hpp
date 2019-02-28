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

#include <cereal/types/vector.hpp>
#include "../cereal/cereal_ext.hpp"
#include "../cereal/schema_enum.hpp"
#include "../cereal/schema_string.hpp"
#include "../cereal/schema_array.hpp"
#include "../cereal/schema_date_time.hpp"
#include <vector>

namespace lgpl3 { namespace ocpp20 { 

template<typename Type>
using optional=cereal::optional<Type>;

template<std::size_t MaxSize, std::size_t MinSize=1>
using schema_string=cereal::schema_string<MaxSize, MinSize>;

template<typename Type, std::size_t MaxSize, std::size_t MinSize=1>
using schema_array=cereal::schema_array<Type,MaxSize, MinSize>;

template<typename SchemaSet>
using schema_enum_value=cereal::schema_enum_value<SchemaSet>;

using schema_date_time=cereal::schema_data_time;

using schema_boolean=cereal::schema_boolean;

SCHEMA_ENUM(AttributeEnum,\
    Actual,\
    Target,\
    MinSet,\
    MaxSet);
using AttributeEnumType=schema_enum_value<AttributeEnum>;

SCHEMA_ENUM(AuthorizationStatusEnum,\
    Accepted,\
    Blocked,\
    ConcurrentTx,\
    Expired,\
    Invalid,\
    NoCredit,\
    NotAllowedTypeEVSE,\
    NotAtThisLocation,\
    NotAtThisTime,\
    Unknown);
using AuthorizationStatusEnumType=schema_enum_value<AuthorizationStatusEnum>;

SCHEMA_ENUM(ChargingLimitSourceEnum,\
    EMS,\
    Other,\
    SO,\
    CSO);
using ChargingLimitSourceEnumType=schema_enum_value<ChargingLimitSourceEnum>;

SCHEMA_ENUM(ChargingProfileKindEnum,\
    Absolute,\
    Recurring,\
    Relative);
using ChargingProfileKindEnumType=schema_enum_value<ChargingProfileKindEnum>;

SCHEMA_ENUM(ChargingProfilePurposeEnum,\
    ChargingStationExternalConstraints,\
    ChargingStationMaxProfile,\
    TxDefaultProfile,\
    TxProfile);
using ChargingProfilePurposeEnumType=schema_enum_value<ChargingProfilePurposeEnum>;

SCHEMA_ENUM(ChargingRateUnitEnum,\
    W,\
    A);
using ChargingRateUnitEnumType=schema_enum_value<ChargingRateUnitEnum>;

SCHEMA_ENUM(EncodingMethodEnum,\
    Other,\
    DLMS Message,\
    COSEM Protected Data,\
    EDL);
using EncodingMethodEnumType=schema_enum_value<EncodingMethodEnum>;

SCHEMA_ENUM(HashAlgorithmEnum,\
    SHA256,\
    SHA384,\
    SHA512);
using HashAlgorithmEnumType=schema_enum_value<HashAlgorithmEnum>;

SCHEMA_ENUM(IdTokenEnum,\
    Central,\
    eMAID,\
    ISO14443,\
    KeyCode,\
    Local,\
    NoAuthorization,\
    ISO15693);
using IdTokenEnumType=schema_enum_value<IdTokenEnum>;

SCHEMA_ENUM(LocationEnum,\
    Body,\
    Cable,\
    EV,\
    Inlet,\
    Outlet);
using LocationEnumType=schema_enum_value<LocationEnum>;

SCHEMA_ENUM(MeasurandEnum,\
    Current.Export,\
    Current.Import,\
    Current.Offered,\
    Energy.Active.Export.Register,\
    Energy.Active.Import.Register,\
    Energy.Reactive.Export.Register,\
    Energy.Reactive.Import.Register,\
    Energy.Active.Export.Interval,\
    Energy.Active.Import.Interval,\
    Energy.Active.Net,\
    Energy.Reactive.Export.Interval,\
    Energy.Reactive.Import.Interval,\
    Energy.Reactive.Net,\
    Energy.Apparent.Net,\
    Energy.Apparent.Import,\
    Energy.Apparent.Export,\
    Frequency,\
    Power.Active.Export,\
    Power.Active.Import,\
    Power.Factor,\
    Power.Offered,\
    Power.Reactive.Export,\
    Power.Reactive.Import,\
    SoC,\
    Voltage);
using MeasurandEnumType=schema_enum_value<MeasurandEnum>;

SCHEMA_ENUM(MessageFormatEnum,\
    ASCII,\
    HTML,\
    URI,\
    UTF8);
using MessageFormatEnumType=schema_enum_value<MessageFormatEnum>;

SCHEMA_ENUM(MessagePriorityEnum,\
    AlwaysFront,\
    InFront,\
    NormalCycle);
using MessagePriorityEnumType=schema_enum_value<MessagePriorityEnum>;

SCHEMA_ENUM(MessageStateEnum,\
    Charging,\
    Faulted,\
    Idle,\
    Unavailable);
using MessageStateEnumType=schema_enum_value<MessageStateEnum>;

SCHEMA_ENUM(MonitorEnum,\
    UpperThreshold,\
    LowerThreshold,\
    Delta,\
    Periodic,\
    PeriodicClockAligned);
using MonitorEnumType=schema_enum_value<MonitorEnum>;

SCHEMA_ENUM(PhaseEnum,\
    L1,\
    L2,\
    L3,\
    N,\
    L1-N,\
    L2-N,\
    L3-N,\
    L1-L2,\
    L2-L3,\
    L3-L1);
using PhaseEnumType=schema_enum_value<PhaseEnum>;

SCHEMA_ENUM(ReadingContextEnum,\
    Interruption.Begin,\
    Interruption.End,\
    Other,\
    Sample.Clock,\
    Sample.Periodic,\
    Transaction.Begin,\
    Transaction.End,\
    Trigger);
using ReadingContextEnumType=schema_enum_value<ReadingContextEnum>;

SCHEMA_ENUM(RecurrencyKindEnum,\
    Daily,\
    Weekly);
using RecurrencyKindEnumType=schema_enum_value<RecurrencyKindEnum>;

SCHEMA_ENUM(SignatureMethodEnum,\
    ECDSAP256SHA256,\
    ECDSAP384SHA384,\
    ECDSA192SHA256);
using SignatureMethodEnumType=schema_enum_value<SignatureMethodEnum>;

struct AdditionalInfoType
{
    schema_string<36> additionalIdToken;
    schema_string<50> type;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "additionalIdToken", additionalIdToken);
        cereal::nvp(archive, "type", type);
    }
};

struct CertificateHashDataType
{
    HashAlgorithmEnumType hashAlgorithm;
    schema_string<128> issuerKeyHash;
    schema_string<128> issuerNameHash;
    schema_string<20> serialNumber;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "hashAlgorithm", hashAlgorithm);
        cereal::nvp(archive, "issuerKeyHash", issuerKeyHash);
        cereal::nvp(archive, "issuerNameHash", issuerNameHash);
        cereal::nvp(archive, "serialNumber", serialNumber);
    }
};

struct ChargingSchedulePeriodType
{
    double limit;
    optional<int> numberPhases;
    optional<int> phaseToUse;
    int startPeriod;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "limit", limit);
        cereal::nvp(archive, "numberPhases", numberPhases);
        cereal::nvp(archive, "phaseToUse", phaseToUse);
        cereal::nvp(archive, "startPeriod", startPeriod);
    }
};

struct ChargingScheduleType
{
    ChargingRateUnitEnumType chargingRateUnit;
    schema_array<ChargingSchedulePeriodType,65536,1> chargingSchedulePeriod;
    optional<int> duration;
    optional<double> minChargingRate;
    optional<schema_date_time> startSchedule;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingRateUnit", chargingRateUnit);
        cereal::nvp(archive, "chargingSchedulePeriod", chargingSchedulePeriod);
        cereal::nvp(archive, "duration", duration);
        cereal::nvp(archive, "minChargingRate", minChargingRate);
        cereal::nvp(archive, "startSchedule", startSchedule);
    }
};

struct ChargingProfileType
{
    ChargingProfileKindEnumType chargingProfileKind;
    ChargingProfilePurposeEnumType chargingProfilePurpose;
    ChargingScheduleType chargingSchedule;
    int id;
    optional<schema_boolean> primary;
    optional<RecurrencyKindEnumType> recurrencyKind;
    int stackLevel;
    optional<schema_string<36>> transactionId;
    optional<schema_date_time> validFrom;
    optional<schema_date_time> validTo;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingProfileKind", chargingProfileKind);
        cereal::nvp(archive, "chargingProfilePurpose", chargingProfilePurpose);
        cereal::nvp(archive, "chargingSchedule", chargingSchedule);
        cereal::nvp(archive, "id", id);
        cereal::nvp(archive, "primary", primary);
        cereal::nvp(archive, "recurrencyKind", recurrencyKind);
        cereal::nvp(archive, "stackLevel", stackLevel);
        cereal::nvp(archive, "transactionId", transactionId);
        cereal::nvp(archive, "validFrom", validFrom);
        cereal::nvp(archive, "validTo", validTo);
    }
};

struct EVSEType
{
    optional<int> connectorId;
    int id;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "connectorId", connectorId);
        cereal::nvp(archive, "id", id);
    }
};

struct ComponentType
{
    optional<EVSEType> evse;
    optional<schema_string<50>> instance;
    schema_string<50> name;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "evse", evse);
        cereal::nvp(archive, "instance", instance);
        cereal::nvp(archive, "name", name);
    }
};

struct GroupIdTokenType
{
    schema_string<36> idToken;
    IdTokenEnumType type;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "idToken", idToken);
        cereal::nvp(archive, "type", type);
    }
};

struct IdTokenType
{
    optional<schema_array<AdditionalInfoType,65536,1>> additionalInfo;
    schema_string<36> idToken;
    IdTokenEnumType type;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "additionalInfo", additionalInfo);
        cereal::nvp(archive, "idToken", idToken);
        cereal::nvp(archive, "type", type);
    }
};

struct MessageContentType
{
    schema_string<512> content;
    MessageFormatEnumType format;
    optional<schema_string<8>> language;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "content", content);
        cereal::nvp(archive, "format", format);
        cereal::nvp(archive, "language", language);
    }
};

struct IdTokenInfoType
{
    optional<schema_date_time> cacheExpiryDateTime;
    optional<int> chargingPriority;
    optional<GroupIdTokenType> groupIdToken;
    optional<schema_string<8>> language1;
    optional<schema_string<8>> language2;
    optional<MessageContentType> personalMessage;
    AuthorizationStatusEnumType status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "cacheExpiryDateTime", cacheExpiryDateTime);
        cereal::nvp(archive, "chargingPriority", chargingPriority);
        cereal::nvp(archive, "groupIdToken", groupIdToken);
        cereal::nvp(archive, "language1", language1);
        cereal::nvp(archive, "language2", language2);
        cereal::nvp(archive, "personalMessage", personalMessage);
        cereal::nvp(archive, "status", status);
    }
};

struct MessageInfoType
{
    optional<ComponentType> display;
    optional<schema_date_time> endDateTime;
    int id;
    MessageContentType message;
    MessagePriorityEnumType priority;
    optional<schema_date_time> startDateTime;
    optional<MessageStateEnumType> state;
    optional<schema_string<36>> transactionId;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "display", display);
        cereal::nvp(archive, "endDateTime", endDateTime);
        cereal::nvp(archive, "id", id);
        cereal::nvp(archive, "message", message);
        cereal::nvp(archive, "priority", priority);
        cereal::nvp(archive, "startDateTime", startDateTime);
        cereal::nvp(archive, "state", state);
        cereal::nvp(archive, "transactionId", transactionId);
    }
};

struct OCSPRequestDataType
{
    HashAlgorithmEnumType hashAlgorithm;
    schema_string<128> issuerKeyHash;
    schema_string<128> issuerNameHash;
    optional<schema_string<512>> responderURL;
    schema_string<20> serialNumber;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "hashAlgorithm", hashAlgorithm);
        cereal::nvp(archive, "issuerKeyHash", issuerKeyHash);
        cereal::nvp(archive, "issuerNameHash", issuerNameHash);
        cereal::nvp(archive, "responderURL", responderURL);
        cereal::nvp(archive, "serialNumber", serialNumber);
    }
};

struct SignedMeterValueType
{
    schema_string<512> encodedMeterValue;
    EncodingMethodEnumType encodingMethod;
    schema_string<2500> meterValueSignature;
    SignatureMethodEnumType signatureMethod;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "encodedMeterValue", encodedMeterValue);
        cereal::nvp(archive, "encodingMethod", encodingMethod);
        cereal::nvp(archive, "meterValueSignature", meterValueSignature);
        cereal::nvp(archive, "signatureMethod", signatureMethod);
    }
};

struct UnitOfMeasureType
{
    optional<int> multiplier;
    optional<schema_string<20>> unit;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "multiplier", multiplier);
        cereal::nvp(archive, "unit", unit);
    }
};

struct SampledValueType
{
    optional<ReadingContextEnumType> context;
    optional<LocationEnumType> location;
    optional<MeasurandEnumType> measurand;
    optional<PhaseEnumType> phase;
    optional<SignedMeterValueType> signedMeterValue;
    optional<UnitOfMeasureType> unitOfMeasure;
    double value;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "context", context);
        cereal::nvp(archive, "location", location);
        cereal::nvp(archive, "measurand", measurand);
        cereal::nvp(archive, "phase", phase);
        cereal::nvp(archive, "signedMeterValue", signedMeterValue);
        cereal::nvp(archive, "unitOfMeasure", unitOfMeasure);
        cereal::nvp(archive, "value", value);
    }
};

struct MeterValueType
{
    schema_array<SampledValueType,65536,1> sampledValue;
    schema_date_time timestamp;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "sampledValue", sampledValue);
        cereal::nvp(archive, "timestamp", timestamp);
    }
};

struct VariableMonitoringType
{
    int id;
    int severity;
    schema_boolean transaction;
    MonitorEnumType type;
    double value;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "id", id);
        cereal::nvp(archive, "severity", severity);
        cereal::nvp(archive, "transaction", transaction);
        cereal::nvp(archive, "type", type);
        cereal::nvp(archive, "value", value);
    }
};

struct VariableType
{
    optional<schema_string<50>> instance;
    schema_string<50> name;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "instance", instance);
        cereal::nvp(archive, "name", name);
    }
};

struct ComponentVariableType
{
    ComponentType component;
    VariableType variable;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "component", component);
        cereal::nvp(archive, "variable", variable);
    }
};



} } 

