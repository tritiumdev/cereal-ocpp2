#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <regex>
#include <cassert>
#include <time.h>

// static constants
static constexpr uint64_t nanos_in_second()  { return 1000 * 1000 * 1000; }
static constexpr uint64_t nanos_in_minute()  { return 60 * nanos_in_second(); }
static constexpr uint64_t minutes_in_hour()  { return 60; }
static constexpr int nano_second_precision() { return 9; }
static constexpr const char* utc_indicator() { return "Z"; } // Could technically be "+00:00"

/**
 * A basic time point class - stores UTC time as nanoseconds since Linux epoch.
 *
 */
class time_point
{
public:
    using clock_type=std::chrono::high_resolution_clock;
    template<typename ClockType>
    using chrono_time_point=std::chrono::time_point<ClockType>;

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


class rfc3339
{
public:
    class exception : public std::exception
    {
    public:
        exception(const std::string message)
            : message_(message)
        {}

        const char * what () const throw ()
        {
            return message_.c_str();
        }
    private:

        std::string message_;
    };

    // Calculate the time zone offset
    static std::time_t time_zone()
    {
        static std::time_t now = std::time(NULL);
        std::time_t local = std::mktime(std::localtime(&now));
        std::time_t gmt = std::mktime(std::gmtime(&now));
        return std::difftime(gmt, local);
    }  

    // Check for a valid time offset according to the spec - must be a valid 
    // "time-offset" given the following notation
    //
    // time-numoffset  = ("+" / "-") time-hour ":" time-minute
    // time-offset     = "Z" / time-numoffset
    static bool calc_time_offset(const std::string& time_offset, uint64_t& offset_minutes)
    {
        static std::regex num_offset_regex{"[+-][0-9][0-9]:[0-9][0-9]"};
        if (time_offset == "Z") // 
        {
            offset_minutes = 0;
            return true;
        }
        if (std::regex_match(time_offset, num_offset_regex))
        {
            std::size_t pos = time_offset.find_last_of(":");
            assert(pos != std::string::npos);
            std::string hour_offset = time_offset.substr(1, pos);
            std::string minute_offset = time_offset.substr(pos);
            offset_minutes = std::atoi(hour_offset.c_str()) * minutes_in_hour()
             + std::atoi(minute_offset.c_str());
            if (time_offset[0] == '-') offset_minutes = -offset_minutes;
            return true;
        }
        return false;
    }

    static std::string to_string(
        time_point tp, 
        int subsecond_precision = 3,
        const std::string& time_offset = utc_indicator())
    {
        uint64_t offset_minutes = 0;
        if (!calc_time_offset(time_offset, offset_minutes))
        {
            throw exception("rfc3339::to_string - Parsing of time offset failed: " + time_offset);
        }

        tp = time_point::from(tp.nanos_since_epoch() + offset_minutes * nanos_in_minute());
 
        subsecond_precision = std::min(std::max(subsecond_precision, 0), nano_second_precision());
        std::time_t seconds = tp.nanos_since_epoch() / nanos_in_second();
        std::ostringstream stream;
        stream << std::put_time(gmtime(&seconds), "%FT%T");
        if (subsecond_precision)
        {
            std::string subsecond_string;
            uint32_t in_nanos = nanos_in_second() / 10;
            uint64_t subsecond = tp.nanos_since_epoch() - seconds * nanos_in_second();
            for(int i = 0; i < subsecond_precision; ++i)
            {
                uint32_t val = subsecond / in_nanos;
                subsecond_string.push_back('0' + val);
                subsecond -= val * in_nanos;
                in_nanos /= 10;
            }
            stream << "." << subsecond_string;
        }

        stream << time_offset;
        return stream.str();
    }

    static time_point from_string(std::string input)
    {
        uint64_t offset_minutes = 0;
        std::size_t pos = input.find_last_of("+-Z");
        if (pos != std::string::npos)
        {
            std::string time_offset = input.substr(pos);
            if (!calc_time_offset(time_offset, offset_minutes))
            {
                throw exception("For input " + input + ", parsing of time offset failed: " + time_offset);
            }
            input.resize(pos);
        }
        pos = input.find_last_of(".");
        uint64_t nanos = 0;
        if (pos != std::string::npos)
        {
            std::string subseconds = input.substr(pos+1);
            if (subseconds.size() > nano_second_precision())
            {
                throw exception("For input " + input + ", parsing of subsecond value failed:: " + subseconds);
            }

            uint32_t in_nanos = nanos_in_second() / 10;
            for(std::size_t i = 0; i < subseconds.size(); ++i)
            {
                int val = subseconds[i] - '0';
                if (val < 0 || val > 9)
                    throw exception("For input " + input + ",  invalid character detected in subsecond value : " + subseconds);
                nanos += val * in_nanos;
                in_nanos /= 10;
            }
            input.resize(pos);
        }
        std::stringstream stream(input);
        std::tm tm;
        stream >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%S");

        if (stream.fail())
        {
            throw exception("For input " + input + ", parsing time failed: " + input);
        }
        tm.tm_isdst = -1;
        std::time_t seconds = std::difftime(std::mktime(&tm), time_zone());
        uint64_t nanos_since_epoch = seconds * nanos_in_second() +
            nanos - offset_minutes * nanos_in_minute(); 
        return time_point::from(nanos_since_epoch);
    }

};

// Usage example
int main() 
{
    time_point tp{true};
    std::cout << "Start at " << rfc3339::to_string(tp, 3, "Z") << std::endl;
 
    for(auto tz_st: {"Z", "+00:00", "-08:00", "+11:00", "-00:30", "+01:15"})
    {
        for(std::size_t i = 0; i <= 1;  ++i)
        {
            time_point tp{true};
            std::string s = rfc3339::to_string(tp, i, tz_st);
            std::cout <<  s << std::endl;
            time_point tp2 = rfc3339::from_string(s);
            std::cout << rfc3339::to_string(tp2, i, tz_st) << std::endl;
        }
    }
}
