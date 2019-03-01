#include "../cereal/no_pretty_json.hpp"
#include <sstream>
#include "../protocol/authorize_request.hpp"
int main()
{
 
    using namespace lgpl3::ocpp20;
    AuthorizeRequest request;
    request.idToken.idToken = "43235a3b4a42";
    request.idToken.type = "Local";
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
    // Just for example...
    std::cout << "Check round trip request id token: " 
        << check_request.idToken.idToken.to_string() << std::endl;
 
    return 0;
}
