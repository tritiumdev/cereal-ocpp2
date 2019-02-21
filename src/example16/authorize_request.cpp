#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>
#include <sstream>
#include "../protocol16/authorize.hpp"
int main()
{
 
    using namespace lgpl3::ocpp16;
    AuthorizeRequest request;
    request.idTag = "deadbeef";
    std::stringstream ss;
    {
        cereal::JSONOutputArchive archive( ss );
        request.serialize(archive);
    }
    std::cout << ss.str() << std::endl;
 
    return 0;
}
