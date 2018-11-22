
#include "src/unit_test.hpp"
#include "src/time/rfc3339.hpp"
#include <random>
#include <algorithm>
#include <string>
#include <cstdint>
//#include <iostream> //debug only
//

namespace lgpl3 { namespace ocpp20 { namespace time { namespace test {

BOOST_AUTO_TEST_SUITE(test_rfc_3339)

BOOST_AUTO_TEST_CASE(test_good_example)
{
    // This test just shows the most basic of examples and probably
    // the most common use case (milliseconds precision, UTC 
    // "Z" time zone.
    std::string rfc_3339_string = "2018-11-22T10:04:18.868Z";
    // You generally construct a time_point from this string - 
    // but in a robust application you must do so in a try/catch
    time_point tp{false};
    try
    {
        tp = rfc3339::from_string(rfc_3339_string);
    }
    catch (rfc3339::exception& e)
    {
        // The string is valid, we should never get here..
        BOOST_CHECK(false);
    }

    // We can convert the time_point into a string 
    std::string round_trip = rfc3339::to_utc_string(tp, 3); 

    // ... and complete the round trip.. the two strings must be equal
    BOOST_CHECK_EQUAL(rfc_3339_string, round_trip);
}


BOOST_AUTO_TEST_CASE(test_longevity)
{
    // signed/unsigned conversions can cause unanticipated issues
    // for example 63 bit nanos since the epoch overflow at around
    // the year 2262.. 64 bit nanos last until around 2554. The 
    // library seeks to last until around 2554...
    std::string y2554_bug_time = "2554-07-21T23:34:33.709551615Z";
    time_point tp =  rfc3339::from_string(y2554_bug_time);
    std::string round_trip = rfc3339::to_utc_string(tp, 9); 
    BOOST_CHECK_EQUAL(y2554_bug_time, round_trip);

    std::string armageddon_time = "2554-07-21T23:34:33.709551616Z";
    time_point tp2 =  rfc3339::from_string(armageddon_time);
    BOOST_CHECK_EQUAL(tp2.nanos_since_epoch(), 0LU);
}

BOOST_AUTO_TEST_CASE(test_round_trip_broad_basket)
{
    // This test loops over time zone and subsecond precision,
    // first generating an rfc3339 string (s1) from a time point given a 
    // time zone. It then uses said string to construct a time point from which
    // another string is generated (s2) - s1 and s2 are tested for equality.
    // The time points will not necessarily be equal (due to precision), but
    // the strings will and must.
    using namespace lgpl3::ocpp20::time;
 
    for(auto tzone_string: {
            "Z", 
            "+00:00", 
            "-08:00", 
            "+11:00", 
            "-00:30", 
            "+01:15",
            "+24:00",  // Demonstrates what the library thinks is permissable (might change)
            "-24:00"}) // see comment above
    {
        for(std::size_t i = 0; i <= 9;  i+=1)
        {
            lgpl3::ocpp20::time::time_point tp1{true};
            std::string s1 = rfc3339::to_string(tp1, i, tzone_string);
            time_point tp2 = rfc3339::from_string(s1);
            std::string s2 =  rfc3339::to_string(tp2, i, tzone_string);
            // Uncomment to see a lot of examples of valid rfc3339 time strings
            //std::cout << "s1: " << s1 << " s2: " << s2 << std::endl;
            BOOST_CHECK_EQUAL(s1, s2);
        }
    }
}

BOOST_AUTO_TEST_CASE(test_bad_time_zone)
{
    for(auto bad_tzone_string: {
            "",
            "ZZ",
            "+0A:00",
            "-08:0",
            "11:00", 
            "--00:30",
            "+0115",
            "+24:01"})
    {
        std::string time_string = "2018-11-22T10:04:18.868";
        time_string += bad_tzone_string;
        // from_string throws too
        BOOST_CHECK_THROW(rfc3339::from_string(time_string), rfc3339::exception);

        time_point tp{true};
        // to_string throws too
        BOOST_CHECK_THROW(rfc3339::to_string(tp, 3, bad_tzone_string), rfc3339::exception);

    }
}

BOOST_AUTO_TEST_CASE(test_bad_subseconds)
{
    for(auto bad_subseconds: {
            "A",
            "001,",
            "abasd",
            "1234567890"} ) // 10 digits (9 is the max)
    {
        std::string time_string = "2018-11-22T10:04:18.868.";
        time_string += bad_subseconds;
        BOOST_CHECK_THROW(rfc3339::from_string(time_string), rfc3339::exception);
    }
}

std::string to_hex(const std::string& s)
{
    std::ostringstream result;
    result << std::setw(2) << std::setfill('0') << std::hex << std::uppercase ;
    for(std::size_t i = 0; i < s.size(); ++i)
    {
        // Yuck.. wrestling with C++ to pull this off..
        result << int(uint8_t(s[i]));
    }
    return "0x" + result.str();
}


BOOST_AUTO_TEST_CASE(fuzz_test_garbage_inputs_to_from_string)
{
    // Create random length, random garbage string and check that an exception
    // is thrown when from_string is called.
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,255);
    std::uniform_int_distribution<std::mt19937::result_type> size_dist(0,512);

    auto gen = [&dist, &rng]()->unsigned char
    {
        // Technically a valid string might be generated.. the chances are
        // slim. Thus we implicitly also test the "Million Monkeys Shakespeare
        // hypothesis".
        return dist(rng);
    };

    
    for(std::size_t i = 0; i < 1000; ++i)
    {
        std::string garbage; 
        garbage.resize(size_dist(rng), '?');
        std::generate(garbage.begin(), garbage.end(), gen);
        try
        {
            rfc3339::from_string(garbage);
        }
        catch (rfc3339::exception& e)
        {
            continue;
        }
        // Write this out as hex in the hope that the unit testing system logs it.
        std::cout << "Fooled by garbage string! " << to_hex(garbage) << std::endl;
        BOOST_CHECK(false);
    }
}

BOOST_AUTO_TEST_SUITE_END()

} } } }

