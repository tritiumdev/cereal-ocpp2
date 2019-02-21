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

SCHEMA_ENUM(CostKindEnum,\
    CarbonDioxideEmission,\
    RelativePricePercentage,\
    RenewableGenerationPercentage);
using CostKindEnumType=schema_enum_value<CostKindEnum>;

struct CostType
{
    double amount;
    optional<int> amountMultiplier;
    CostKindEnumType costKind;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "amount", amount);
        cereal::nvp(archive, "amountMultiplier", amountMultiplier);
        cereal::nvp(archive, "costKind", costKind);
    }
};

struct ConsumptionCostType
{
    schema_array<CostType,3,1> cost;
    double startValue;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "cost", cost);
        cereal::nvp(archive, "startValue", startValue);
    }
};

struct RelativeTimeIntervalType
{
    optional<int> duration;
    int start;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "duration", duration);
        cereal::nvp(archive, "start", start);
    }
};

struct PMaxScheduleType
{
    double pMax;
    RelativeTimeIntervalType relativeTimeInterval;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "pMax", pMax);
        cereal::nvp(archive, "relativeTimeInterval", relativeTimeInterval);
    }
};

struct SalesTariffEntryType
{
    optional<schema_array<ConsumptionCostType,3,1>> consumptionCost;
    optional<int> ePriceLevel;
    optional<RelativeTimeIntervalType> relativeTimeInterval;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "consumptionCost", consumptionCost);
        cereal::nvp(archive, "ePriceLevel", ePriceLevel);
        cereal::nvp(archive, "relativeTimeInterval", relativeTimeInterval);
    }
};

struct SalesTariffType
{
    int id;
    optional<int> numEPriceLevels;
    optional<schema_string<32>> salesTariffDescription;
    schema_array<SalesTariffEntryType,1024,1> salesTariffEntry;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "id", id);
        cereal::nvp(archive, "numEPriceLevels", numEPriceLevels);
        cereal::nvp(archive, "salesTariffDescription", salesTariffDescription);
        cereal::nvp(archive, "salesTariffEntry", salesTariffEntry);
    }
};

struct SAScheduleType
{
    schema_array<PMaxScheduleType,1024,1> pMaxSchedule;
    int saScheduleTupleID;
    optional<SalesTariffType> salesTariff;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "pMaxSchedule", pMaxSchedule);
        cereal::nvp(archive, "saScheduleTupleID", saScheduleTupleID);
        cereal::nvp(archive, "salesTariff", salesTariff);
    }
};

struct NotifyCentralChargingNeedsRequest
{
    static const char* action() { return "NotifyCentralChargingNeeds"; }

    int evseId;
    schema_array<SAScheduleType,3,1> saSchedule;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "evseId", evseId);
        cereal::nvp(archive, "saSchedule", saSchedule);
    }
};



} } 

