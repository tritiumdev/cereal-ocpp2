
#include <string>
#include <sstream>
#include <experimental/optional>
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>
#include "../cereal_ext.hpp"
#include "../schema_string.hpp"
#include "../schema_array.hpp"
#include "../schema_enum.hpp"
#include "../schema_date_time.hpp"


SCHEMA_ENUM(fruit, apple, banana, orange);
using cereal_fruit=cereal::schema_enum_value<fruit>;

void check_schema_enum()
{
    {
        cereal_fruit cf = cereal_fruit::from_string("apple");
        std::stringstream ss;
        {
            cereal::JSONOutputArchive archive( ss );
            cereal::nvp(archive, "fruit", cf);
        }
        std::cout << ss.str() << std::endl;
    }
    {
        // throws
        cereal_fruit cf;
        std::stringstream ss;
        {
            cereal::JSONOutputArchive archive( ss );
            cereal::nvp(archive, "fruit", cf);
        }
        std::cout << ss.str() << std::endl;
    }
}

struct test
{
    int required_integer;
    cereal::optional<std::string> optional_string;
    cereal::optional<cereal::schema_string<50>> schema_string;
    cereal::schema_array<double,2,0> schema_array;

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "required_integer", required_integer);
        cereal::nvp(archive, "optional_string", optional_string);
        cereal::nvp(archive, "schema_string", schema_string);
        cereal::nvp(archive, "schema_array", schema_array);
    }
};


int main()
{
    cereal::schema_data_time rs;
    std::stringstream stream;
    {
        cereal::JSONOutputArchive archive( stream );
        cereal::nvp(archive, "date_time", rs);
    }
    std::cout << stream.str();

    cereal::schema_string<4> s;
    stream = std::stringstream{};
    s = "dasf";
    test t;
    t.required_integer = 1;
    {
        cereal::JSONOutputArchive archive( stream );
        t.serialize(archive);
    }
    std::cout << stream.str() << std::endl;
    stream = std::stringstream{};
    t.optional_string = "test";
    t.schema_string = "abcdefg";
    {
        cereal::JSONOutputArchive archive( stream );
        t.serialize(archive);
    }
    std::cout << stream.str() << std::endl;

    check_schema_enum();
    return 0;
}
