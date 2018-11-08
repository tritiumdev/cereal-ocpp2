#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cereal/cereal.hpp>

//#ifndef SCHEMA_ENUM 
#define SCHEMA_ENUM(Name, ...) \
struct Name \
{ \
    static const char* name() { return #Name; } \
    \
    static const std::vector<std::string>& strings() \
    { \
        static std::vector<std::string> v;  \
        if (v.empty()) \
        { \
            std::string text = #__VA_ARGS__; \
            std::replace(text.begin(), text.end(), ',', ' '); \
            std::istringstream iss{text}; \
            v = std::vector<std::string>{ \
                std::istream_iterator<std::string>{iss}, \
                std::istream_iterator<std::string>()}; \
        } \
        return v; \
    }; \
    static std::string verify(const std::string& candidate) \
    { \
        return (std::find(strings().begin(), strings().end(), candidate) == strings().end()) ? \
            std::string{} : candidate; \
    }\
};

//#endif SCHEMA_ENUM 

namespace cereal {

// typically instantiated with an enum created by the SCHEMA_ENUM macro
template<typename SchemaEnum>
class schema_enum_value
{
public:
    static schema_enum_value from_string(const std::string& value)
    {
        schema_enum_value  ssv;
        ssv.v_ = SchemaEnum::verify(value);
        return ssv;
    }

    schema_enum_value& operator=(const std::string& v)
    {
        *this = from_string(v);
        return *this;
    }

    template<typename Archive>
    std::string save_minimal(Archive& archive) const
    {
        std::string ret = SchemaEnum::verify(v_);
        if (ret.empty())
        {
            throw cereal::Exception(std::string{"saving empy value in schema_enum_value: "} + SchemaEnum::name());
        }
        return ret;
    }

    template<typename Archive>
    void load_minimal(Archive& archive, const std::string& value)
    {
        std::string new_value = SchemaEnum::verify(value);
        if (!new_value.empty())
        {
            v_ = new_value;
        }
        else
        {
            throw cereal::Exception(std::string{"failed loading in schema_enum_value: "} + SchemaEnum::name());
        }
    }

private:
    std::string v_;
};

}

