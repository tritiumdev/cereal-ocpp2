#pragma once

#include <string>

namespace cereal {

// A length capped string.. thin wrapper around a string.
// Can never store a string of length greater than N, and
// throws if you try to.
template<std::size_t MaxSize, std::size_t MinSize=1>
struct schema_string
{
    schema_string()
        : value_{}
    {}

    schema_string(const std::string& value)
    {
        copy(value);
    }

    schema_string(std::string&& value)
    {
        copy(value);
    }

    schema_string& operator=(const std::string& value)
    {
        copy(value);
        return *this;
    }

    schema_string& operator=(std::string&& value)
    {
        copy(value);
        return *this;
    }

    template<typename Archive>
    std::string save_minimal(Archive& archive) const
    {
        if (value_.size() < MinSize)
        {
            throw cereal::Exception(std::string{"schema_string too small"});
        }
        return value_;
    }
    
    template<typename Archive>
    void load_minimal(Archive& archive, const std::string& value)
    {
        // might throw
        copy(value);
    }

    // Not sure if we really need this 
    void clear() { value_.clear(); }

    const std::string& to_string() const { return value_; }

    private:
    
    void copy(const std::string& value)
    {
        if (value.size() > MaxSize)
        {
            throw cereal::Exception(std::string{"copy: schema_string large"});
        }
        if (value.size() < MinSize)
        {
            throw cereal::Exception(std::string{"copy: schema_string too small"});
        }
        value_ = value;
    }
 
    std::string value_;
};

}
