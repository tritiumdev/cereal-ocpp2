
#include "src/unit_test.hpp"
#include "src/cereal/schema_array.hpp"
#include "src/cereal/cereal_ext.hpp"
#include "src/cereal/no_pretty_json.hpp"

namespace cereal { namespace test {

BOOST_AUTO_TEST_SUITE(test_cereal_schema_array)

BOOST_AUTO_TEST_CASE(test_basic_reliability)
{
    using test_schema_array=schema_array<std::string, 2, 1>;
    test_schema_array array;

    {
        // You can't yet serialize this array - as its min size is 1
        std::stringstream stream;
        cereal::JSONOutputArchive archive( stream );
        BOOST_CHECK_THROW(cereal::nvp(archive, "test", array), cereal::Exception);
    }

    std::vector<std::string> test_inputs({"foo", "bar"});
    for(std::size_t j = 0; j < test_inputs.size(); ++j)
    {
        array.push_back(test_inputs[j]);
        std::stringstream stream;

        {
            cereal::JSONOutputArchive archive( stream );
            cereal::nvp(archive, "test", array);
        }
        //std::cout << stream.str() << std::endl;

        {
            cereal::JSONInputArchive in_archive( stream );
            test_schema_array round_trip_array;
            cereal::nvp(in_archive, "test", round_trip_array);

            BOOST_CHECK_EQUAL(array.size(), round_trip_array.size());

            for(std::size_t i = 0; i < array.size(); ++i)
            {
                BOOST_CHECK_EQUAL(array[i], round_trip_array[i]);
            }
        }
    }
    
    // You can't push_back onto this array any further - else you violate size constraints
    BOOST_CHECK_THROW(array.push_back("no_chance"), cereal::Exception);
}

BOOST_AUTO_TEST_SUITE_END()

} }

