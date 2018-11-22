
#include "../rfc3339.hpp"
#include <iostream>
// Usage example
int main() 
{
    using namespace lgpl3::ocpp20::time;
    time_point tp{true};
    std::cout << "Start at " << rfc3339::to_string(tp, 3, "Z") << std::endl;
 
    for(auto tz_st: {"Z", "+00:00", "-08:00", "+11:00", "-00:30", "+01:15"})
    {
        for(std::size_t i = 0; i <= 9;  i+=3)
        {
            time_point tp{true};
            std::string s = rfc3339::to_string(tp, i, tz_st);
            std::cout <<  s << std::endl;
            time_point tp2 = rfc3339::from_string(s);
            std::cout << rfc3339::to_string(tp2, i, tz_st) << std::endl;
        }
    }
}
