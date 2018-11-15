#pragma once

#include <chrono>
#include <cmath>
#include <cstdint>

namespace lgpl3 { namespace ocpp20 { namespace time {

// static constants
static constexpr uint64_t nanos_in_second()  { return 1000 * 1000 * 1000; }
static constexpr uint64_t nanos_in_minute()  { return 60 * nanos_in_second(); }
static constexpr uint64_t minutes_in_hour()  { return 60; }
static constexpr int nano_second_precision() { return 9; }
static constexpr const char* utc_indicator() { return "Z"; } // Could technically be "+00:00"

/**
 * A basic time point class - stores any UTC time internally at a uint64_t 
 * that represents nanoseconds since Linux epoch. Default constructor
 * captures the current point according to the chrono::high_resolution_clock.
 */
class time_point
{
public:
    using clock_type=std::chrono::high_resolution_clock;
    template<typename ClockType>
    using chrono_time_point=std::chrono::time_point<ClockType>;

    /**
     * \param set_from_now if trues store the current time internally
     * Primarily for efficiency, set false to avoid chewing unneccessary
     * cycles - i.e. if you're  about to call the static "from" method
     * instead.
     */
    time_point(bool set_from_now=true)
        : nanos_since_epoch_(0)
    {

        if (set_from_now)
        {
            chrono_time_point<clock_type> now = clock_type::now();
            nanos_since_epoch_ = 
                std::chrono::duration_cast<std::chrono::nanoseconds>(
                    now.time_since_epoch()).count();
        }
    }

    time_point(const time_point& that) = default;
    time_point& operator=(const time_point& that) = default;
    time_point(time_point&& that) = default;
    time_point& operator=(time_point&& that) = default;

    /** A convenience function for constructing a time_point
     * directly from a uint64_t representing nanos since the
     * epoch.
     */
    static time_point from(const uint64_t& nanos_since_epoch)
    {
        time_point tp{false};
        tp.nanos_since_epoch_ = nanos_since_epoch;
        return tp;
    }

    const uint64_t& nanos_since_epoch() const { return nanos_since_epoch_; }

private:
    uint64_t nanos_since_epoch_;
};


} } }
