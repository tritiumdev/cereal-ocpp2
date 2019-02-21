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

SCHEMA_ENUM(EnergyTransferModeEnum,\
    AC_single_phase_core,\
    AC_three_phase_core,\
    DC_combo_core,\
    DC_core,\
    DC_extended,\
    DC_unique);
using EnergyTransferModeEnumType=schema_enum_value<EnergyTransferModeEnum>;

struct ACChargingParametersType
{
    int energyAmount;
    int evMaxCurrent;
    int evMaxVoltage;
    int evMinCurrent;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "energyAmount", energyAmount);
        cereal::nvp(archive, "evMaxCurrent", evMaxCurrent);
        cereal::nvp(archive, "evMaxVoltage", evMaxVoltage);
        cereal::nvp(archive, "evMinCurrent", evMinCurrent);
    }
};

struct DCChargingParametersType
{
    optional<int> bulkSoC;
    optional<int> energyAmount;
    optional<int> evEnergyCapacity;
    int evMaxCurrent;
    optional<int> evMaxPower;
    int evMaxVoltage;
    optional<int> fullSoC;
    optional<int> stateOfCharge;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "bulkSoC", bulkSoC);
        cereal::nvp(archive, "energyAmount", energyAmount);
        cereal::nvp(archive, "evEnergyCapacity", evEnergyCapacity);
        cereal::nvp(archive, "evMaxCurrent", evMaxCurrent);
        cereal::nvp(archive, "evMaxPower", evMaxPower);
        cereal::nvp(archive, "evMaxVoltage", evMaxVoltage);
        cereal::nvp(archive, "fullSoC", fullSoC);
        cereal::nvp(archive, "stateOfCharge", stateOfCharge);
    }
};

struct ChargingNeedsType
{
    optional<ACChargingParametersType> acChargingParameters;
    optional<DCChargingParametersType> dcChargingParameters;
    optional<schema_date_time> departureTime;
    EnergyTransferModeEnumType requestedEnergyTransfer;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "acChargingParameters", acChargingParameters);
        cereal::nvp(archive, "dcChargingParameters", dcChargingParameters);
        cereal::nvp(archive, "departureTime", departureTime);
        cereal::nvp(archive, "requestedEnergyTransfer", requestedEnergyTransfer);
    }
};

struct NotifyEVChargingNeedsRequest
{
    static const char* action() { return "NotifyEVChargingNeeds"; }

    ChargingNeedsType chargingNeeds;
    int evseId;
    optional<int> maxScheduleTuples;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "chargingNeeds", chargingNeeds);
        cereal::nvp(archive, "evseId", evseId);
        cereal::nvp(archive, "maxScheduleTuples", maxScheduleTuples);
    }
};



} } 

