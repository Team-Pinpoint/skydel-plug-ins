#include "command.h"
#include "ublox.h"
#include <iostream>

class GetConfigurationCommand: public Command{
    public:
        GetConfigurationCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~GetConfigurationCommand(){};
        void execute();
        static void GetConfigurationCallback(ublox::CfgGNSS nav_utc_time, double time_stamp){
            try{
                std::cout << "" << std::endl;
                std::cout << "GNSS settings Command" << std::endl;
                GetConfigurationCommand::pulled = true;
            }
            catch(std::exception &e){
                std::cout << "PseudorangeData() error";
            }
        }
    protected:
        static bool pulled;
};
