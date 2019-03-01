#pragma once

#include "../time/time_point.hpp"
#include "../time/rfc3339.hpp"

namespace cereal {

namespace time = lgpl3::ocpp20::time;

class schema_data_time
{
public:
    schema_data_time()
        : time_point_{true}
    {}

    schema_data_time(const schema_data_time& that) = default;
    schema_data_time& operator=(const schema_data_time& that) = default;
    schema_data_time(schema_data_time&& that) = default;
    schema_data_time& operator=(schema_data_time&& that) = default;

    void set_now()
    {
        // snap the time to now. Speculative, not used.
        time_point_ = time::time_point{true};
    }

    template<typename Archive>
    std::string save_minimal(Archive& archive) const
    {
        return to_string();
    }
    
    template<typename Archive>
    void load_minimal(Archive& archive, const std::string& value)
    {
        // might throw
        time::time_point set_to = time::rfc3339::from_string(value);
        time_point_ = set_to;
    }

    const time::time_point& value() const { return time_point_; }

    std::string to_string() const { return time::rfc3339::to_string(time_point_); }

    private:

    time::time_point time_point_;
};

}
