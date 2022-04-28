#include "command.h"
#include "ublox.h"
#include <iostream>

class SetConstellationsCommand: public Command{
    public:
        SetConstellationsCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~SetConstellationsCommand() = default;
        enum Constellations { GPS, SBAS, GALILEO, BELIDOU, IMES, QZSS, GLONASS, NONE};
        bool execute(SetConstellationsCommand::Constellations *);
        static void GetCurrentConfigurationCallback(ublox::CfgGNSS gnss_config, double time_stamp){
            try{
                SetConstellationsCommand::cur_config = gnss_config;
                SetConstellationsCommand::pulled = true;
            }
            catch(const std::exception &e){
                std::cout << "PseudorangeData() error";
            }
        }
    protected:
        static bool set;
        static bool pulled;
        static ublox::CfgGNSS cur_config;
};
