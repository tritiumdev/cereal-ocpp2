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

SCHEMA_ENUM(DataEnum,\
    string,\
    decimal,\
    integer,\
    dateTime,\
    boolean,\
    OptionList,\
    SequenceList,\
    MemberList);
using DataEnumType=schema_enum_value<DataEnum>;

SCHEMA_ENUM(MutabilityEnum,\
    ReadOnly,\
    WriteOnly,\
    ReadWrite);
using MutabilityEnumType=schema_enum_value<MutabilityEnum>;

struct VariableAttributeType
{
    schema_boolean constant;
    optional<MutabilityEnumType> mutability;
    schema_boolean persistence;
    optional<AttributeEnumType> type;
    schema_string<1000> value;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "constant", constant);
        cereal::nvp(archive, "mutability", mutability);
        cereal::nvp(archive, "persistence", persistence);
        cereal::nvp(archive, "type", type);
        cereal::nvp(archive, "value", value);
    }
};

struct VariableCharacteristicsType
{
    DataEnumType dataType;
    optional<double> maxLimit;
    optional<double> minLimit;
    schema_boolean supportsMonitoring;
    optional<schema_string<16>> unit;
    optional<schema_string<1000>> valuesList;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "dataType", dataType);
        cereal::nvp(archive, "maxLimit", maxLimit);
        cereal::nvp(archive, "minLimit", minLimit);
        cereal::nvp(archive, "supportsMonitoring", supportsMonitoring);
        cereal::nvp(archive, "unit", unit);
        cereal::nvp(archive, "valuesList", valuesList);
    }
};

struct ReportDataType
{
    ComponentType component;
    VariableType variable;
    schema_array<VariableAttributeType,4,1> variableAttribute;
    optional<VariableCharacteristicsType> variableCharacteristics;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "component", component);
        cereal::nvp(archive, "variable", variable);
        cereal::nvp(archive, "variableAttribute", variableAttribute);
        cereal::nvp(archive, "variableCharacteristics", variableCharacteristics);
    }
};

struct NotifyReportRequest
{
    static const char* action() { return "NotifyReport"; }

    schema_date_time generatedAt;
    schema_array<ReportDataType,65536,1> reportData;
    optional<int> requestId;
    int seqNo;
    schema_boolean tbc;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "generatedAt", generatedAt);
        cereal::nvp(archive, "reportData", reportData);
        cereal::nvp(archive, "requestId", requestId);
        cereal::nvp(archive, "seqNo", seqNo);
        cereal::nvp(archive, "tbc", tbc);
    }
};



} } 

