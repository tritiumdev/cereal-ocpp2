#include "../cereal/no_pretty_json.hpp"
#include <sstream>
#include "../protocol/heartbeat_response.hpp"
int main()
{
 
    using namespace lgpl3::ocpp20;
    HeartbeatResponse response;
    std::stringstream ss;
    {
        cereal::JSONOutputArchive archive( ss );
        response.serialize(archive);
    }
    std::cout << ss.str() << std::endl;
 
    return 0;
}
