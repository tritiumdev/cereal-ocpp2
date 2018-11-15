#pragma once

#include "../time/time_point.hpp"
#include "../time/rfc3339.hpp"

namespace cereal {

namespace time = lgpl3::ocpp20::time;

class rfc3339_string
{
public:
    rfc3339_string()
        : time_point_{true}
    {}

    rfc3339_string(const rfc3339_string& that) = default;
    rfc3339_string& operator=(const rfc3339_string& that) = default;
    rfc3339_string(rfc3339_string&& that) = default;
    rfc3339_string& operator=(rfc3339_string&& that) = default;

    void set_now()
    {
        // snap the time to now. Speculative, not used.
        time_point_ = time::time_point{true};
    }

    template<typename Archive>
    std::string save_minimal(Archive& archive) const
    {
        return time::rfc3339::to_string(time_point_);
    }
    
    template<typename Archive>
    void load_minimal(Archive& archive, const std::string& value)
    {
        // might throw
        time::time_point set_to = time::rfc3339::from_string(value);
        time_point_ = set_to;
    }

    private:

    time::time_point time_point_;
};

}
