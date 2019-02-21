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

#include <cereal/types/vector.hpp>
#include "../cereal/cereal_ext.hpp"
#include "../cereal/schema_enum.hpp"
#include "../cereal/schema_string.hpp"
#include "../cereal/schema_array.hpp"
#include "../cereal/schema_date_time.hpp"
#include <vector>

namespace lgpl3 { namespace ocpp16 { 

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

struct ChargingSchedulePeriodEntry
{
    double limit;
    optional<int> numberPhases;
    int startPeriod;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "limit", limit);
        cereal::nvp(archive, "numberPhases", numberPhases);
        cereal::nvp(archive, "startPeriod", startPeriod);
    }
};

struct ChargingSchedule
{
    SCHEMA_ENUM(ChargingRateUnitType,\
        A,\
        W);
    using ChargingRateUnitTypeEnum=schema_enum_value<ChargingRateUnitType>;

    ChargingRateUnitTypeEnum chargingRateUnit;
    schema_array<ChargingSchedulePeriodEntry,65536,0> chargingSchedulePeriod;
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

struct IdTagInfo
{
    SCHEMA_ENUM(StatusType,\
        Accepted,\
        Blocked,\
        Expired,\
        Invalid,\
        ConcurrentTx);
    using StatusTypeEnum=schema_enum_value<StatusType>;

    optional<schema_date_time> expiryDate;
    optional<schema_string<20>> parentIdTag;
    StatusTypeEnum status;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "expiryDate", expiryDate);
        cereal::nvp(archive, "parentIdTag", parentIdTag);
        cereal::nvp(archive, "status", status);
    }
};

struct SampledValueEntry
{
    SCHEMA_ENUM(ContextType,\
        Interruption.Begin,\
        Interruption.End,\
        Sample.Clock,\
        Sample.Periodic,\
        Transaction.Begin,\
        Transaction.End,\
        Trigger,\
        Other);
    using ContextTypeEnum=schema_enum_value<ContextType>;

    SCHEMA_ENUM(FormatType,\
        Raw,\
        SignedData);
    using FormatTypeEnum=schema_enum_value<FormatType>;

    SCHEMA_ENUM(LocationType,\
        Cable,\
        EV,\
        Inlet,\
        Outlet,\
        Body);
    using LocationTypeEnum=schema_enum_value<LocationType>;

    SCHEMA_ENUM(MeasurandType,\
        Energy.Active.Export.Register,\
        Energy.Active.Import.Register,\
        Energy.Reactive.Export.Register,\
        Energy.Reactive.Import.Register,\
        Energy.Active.Export.Interval,\
        Energy.Active.Import.Interval,\
        Energy.Reactive.Export.Interval,\
        Energy.Reactive.Import.Interval,\
        Power.Active.Export,\
        Power.Active.Import,\
        Power.Offered,\
        Power.Reactive.Export,\
        Power.Reactive.Import,\
        Power.Factor,\
        Current.Import,\
        Current.Export,\
        Current.Offered,\
        Voltage,\
        Frequency,\
        Temperature,\
        SoC,\
        RPM);
    using MeasurandTypeEnum=schema_enum_value<MeasurandType>;

    SCHEMA_ENUM(PhaseType,\
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
    using PhaseTypeEnum=schema_enum_value<PhaseType>;

    SCHEMA_ENUM(UnitType,\
        Wh,\
        kWh,\
        varh,\
        kvarh,\
        W,\
        kW,\
        VA,\
        kVA,\
        var,\
        kvar,\
        A,\
        V,\
        K,\
        Celcius,\
        Fahrenheit,\
        Percent);
    using UnitTypeEnum=schema_enum_value<UnitType>;

    optional<ContextTypeEnum> context;
    optional<FormatTypeEnum> format;
    optional<LocationTypeEnum> location;
    optional<MeasurandTypeEnum> measurand;
    optional<PhaseTypeEnum> phase;
    optional<UnitTypeEnum> unit;
    std::string  value;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "context", context);
        cereal::nvp(archive, "format", format);
        cereal::nvp(archive, "location", location);
        cereal::nvp(archive, "measurand", measurand);
        cereal::nvp(archive, "phase", phase);
        cereal::nvp(archive, "unit", unit);
        cereal::nvp(archive, "value", value);
    }
};



} } 

