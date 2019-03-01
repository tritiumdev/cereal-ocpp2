#include "../cereal/no_pretty_json.hpp"
#include <sstream>
#include <string>
#include "../protocol/heartbeat_response.hpp"
int main()
{
 
    using namespace lgpl3::ocpp20;
    HeartbeatResponse response;
    std::stringstream ss;
    {
        cereal::JSONOutputArchive archive(ss);
        response.serialize(archive);
    }
    std::cout << "json payload: " << ss.str() << std::endl;

    HeartbeatResponse check_response;
    {
        cereal::JSONInputArchive archive(ss);
        check_response.serialize(archive);
    }

    std::cout << "Check round trip response currentTime:: " 
        << check_response.currentTime.to_string() << std::endl;
    
 
    return 0;
}
