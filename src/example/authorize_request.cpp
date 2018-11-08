#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>
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
        cereal::JSONOutputArchive archive( ss );
        request.serialize(archive);
    }
    std::cout << ss.str() << std::endl;
 
    return 0;
}
