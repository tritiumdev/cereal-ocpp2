
#include <string>
#include <sstream>
#include <experimental/optional>
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>
#include "../cereal_ext.hpp"
#include "../schema_string.hpp"
#include "../schema_enum.hpp"
#include "../rfc3339_string.hpp"


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

    template<typename Archive>
    void serialize(Archive& archive)
    {
        cereal::nvp(archive, "required_integer", required_integer);
        cereal::nvp(archive, "optional_string", optional_string);
        cereal::nvp(archive, "schema_string", schema_string);
    }
};


int main()
{
    lgpl3::ocpp20::cereal::rfc3339_string rs;
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
