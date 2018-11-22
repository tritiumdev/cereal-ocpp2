#pragma once

#include <sstream>
#include <iomanip>
#include <cmath>
#include <regex>
#include <cassert>
#include <cstdint>

#include "time_point.hpp"
#include "time.hpp"

namespace lgpl3 { namespace ocpp20 { namespace time {

/**
 * A utility class intended primarily for the parsing time strings in the
 * rfc3339 format.
 *
 */
class rfc3339
{
public:
    class exception : public std::exception
    {
    public:
        exception(const std::string message)
            : message_(message)
        {}

        const char* what() const noexcept
        {
            return message_.c_str();
        }
    private:

        std::string message_;
    };

    /**
     * \brief Calculate the time zone offset for this machine.
     */
    static std::time_t time_zone()
    {
        static std::time_t now = std::time(NULL);
        std::time_t local = std::mktime(std::localtime(&now));
        std::time_t gmt = std::mktime(std::gmtime(&now));
        return std::difftime(gmt, local);
    }  

    /** 
     * \brief Check for a valid time offset according to the spec - must be a valid 
     * "time-offset" given the following notation:
     *  time-numoffset  = ("+" / "-") time-hour ":" time-minute
     *  time-offset     = "Z" / time-numoffset
     */
    static bool calc_time_offset(const std::string& time_offset, int32_t& offset_minutes)
    {
        static std::regex num_offset_regex{"[+-][0-9][0-9]:[0-9][0-9]"};

        if (time_offset == utc_indicator()) // 
        {
            offset_minutes = 0;
            return true;
        }
        if (std::regex_match(time_offset, num_offset_regex))
        {
            std::size_t pos = time_offset.find_last_of(":");
            assert(pos != std::string::npos);

            std::string hour_offset = time_offset.substr(1, pos);
            std::string minute_offset = time_offset.substr(pos+1);

            int hours = std::atoi(hour_offset.c_str());
            offset_minutes = hours * minutes_in_hour()
                 + std::atoi(minute_offset.c_str());
            // Broad enforcement - the offset minutes must be less than a
            // a day's worth.
            if (offset_minutes > (int32_t)minutes_in_day()) return false;
            if (time_offset[0] == '-') offset_minutes = -offset_minutes;

            return true;
        }
        return false;
    }

    /**
     * \brief convert a time_point to an rfc3339 formatted string
     * \param tp the given time point
     * \param subsecond_precision decimal subseond precision of the output
     * for example - 3 means millisecond precision, 6 means microsecond
     * precision, 9 means nanosecond precision
     * \param time_offset the rfc3339 formatted time offset, for example -
     * "Z" for utc, "-08:00" for UTC minus 8 hours etc.
     */
    static std::string to_string(
        time_point tp, 
        int subsecond_precision = 3,
        const std::string& time_offset = utc_indicator())
    {
        // First calculate the offset minutes according to the
        // time_offset string.
        int32_t offset_minutes = 0;
        if (!calc_time_offset(time_offset, offset_minutes))
        {
            throw exception("rfc3339::to_string - Parsing of time offset failed: " + time_offset);
        }
        // Now shift the time_point into the correct time_zone
        // using the calculated offset.
        tp = time_point::from(tp.nanos_since_epoch() +
             offset_minutes * nanos_in_minute());
 
        subsecond_precision = 
            std::min(std::max(subsecond_precision, 0), nano_second_precision());
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

    /**
     * \brief Same as to_string except time zone is set to utc,
     * and therefore doesn't throw
     */
    static std::string to_utc_string(
        time_point tp, 
        int subsecond_precision = 3) noexcept
    {
        return to_string(tp, subsecond_precision, utc_indicator());
    }


    /**
     * \brief Convert an rfc3339 string to a time_point
     * Throws rfc3339::exception several ways, so should be 
     * wrapped in a try catch.
     */
    static time_point from_string(std::string input)
    {
        // This somewhat heavy handed regex was arrived at as a result of fuzz testing...
        // It could be made even more anal. But leaving as is, and marking a TODO here
        // for anyone who wants to come in a really give this function a hard thinking about.
        static std::regex rfc_check_regex{"[12][0-9][0-9][0-9]-[01][0-9]-[0-3][0-9]T[0-9][0-9]:[0-9][0-9]:[0-9][0-9].*"};

        if (!std::regex_match(input, rfc_check_regex))
        {
            throw exception("For input " + input + ": invalid rfc formatting");
        }

        int32_t offset_minutes = 0;
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

        // The decimal should be the first of. This is a strong condition. 
        pos = input.find_first_of(".");
        uint64_t nanos = 0;
        if (pos != std::string::npos)
        {
            std::string subseconds = input.substr(pos+1);
            if (subseconds.size() > nano_second_precision())
            {
                throw exception("For input " + input + ", parsing of subsecond value failed: " + subseconds);
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
        uint64_t nanos_since_epoch = seconds * nanos_in_second() + nanos
            - offset_minutes * nanos_in_minute();
        return time_point::from(nanos_since_epoch);
    }
};

} } }
