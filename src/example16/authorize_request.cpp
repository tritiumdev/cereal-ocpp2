#include "../cereal/no_pretty_json.hpp"
#include <sstream>
#include "../protocol16/authorize.hpp"
int main()
{
 
    using namespace lgpl3::ocpp16;
    AuthorizeRequest request;
    request.idTag = "deadbeef";
    std::stringstream ss;
    {
        cereal::JSONOutputArchive archive(ss);
        request.serialize(archive);
    }

    std::cout << "json payload: " << ss.str() << std::endl;

    AuthorizeRequest check_request;
    {
        cereal::JSONInputArchive archive(ss);
        check_request.serialize(archive);
    }
 
    std::cout << "Check round trip request id token: " 
        << check_request.idTag.to_string() << std::endl;
 
    return 0;
}
