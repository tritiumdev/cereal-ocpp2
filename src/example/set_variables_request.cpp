//#include <cereal/cereal.hpp>
//#include <cereal/archives/json.hpp>
#include "../cereal/no_pretty_json.hpp"
#include <sstream>
#include "../protocol/set_variables_request.hpp"
int main()
{
 
    using namespace lgpl3::ocpp20;
    SetVariablesRequest request;
    request.setVariableData.resize(1);

    SetVariableDataType& set_variable = request.setVariableData[0];
    
    set_variable.attributeValue = "100";
    set_variable.component.name = "FrontPanel";
    set_variable.component.instance = "1";

    EVSEType evse;
    evse.id = 1234;
    evse.connectorId = 1;
    set_variable.component.evse = std::move(evse);

    set_variable.variable.name = "Sensor1";
    set_variable.variable.instance = "FrontPanelTemp";

    std::stringstream ss;
    {
        cereal::JSONOutputArchive archive(ss);
        request.serialize(archive);
    }

    std::cout << "json payload: " <<  ss.str() << std::endl;

    SetVariablesRequest check_request;
    {
        cereal::JSONInputArchive archive(ss);
        check_request.serialize(archive);
    }
 
    std::cout << "Check round trip request component.name:: " 
        << check_request.setVariableData[0].component.name.to_string() << std::endl;
    return 0;
}
