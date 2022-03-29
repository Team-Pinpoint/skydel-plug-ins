#include "command.h"
#include "ublox.h"
#include <iostream>

class SetConstellationsCommand: public Command{
    public:
        SetConstellationsCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~SetConstellationsCommand(){};
        enum Constellations { GPS, SBAS, GALILEO, BELIDOU, IMES, QZSS, GLONASS, NONE};
        bool execute(SetConstellationsCommand::Constellations *);
        static void GetCurrentConfigurationCallback(ublox::CfgGNSS gnss_config, double time_stamp){
            try{
                SetConstellationsCommand::cur_config = gnss_config;
                // int num_configs = unsigned(gnss_config.numConfigBlocks);
                // int enabled_satellite = 0;
                // for(int i = 0; i < num_configs; i++){
                //     ublox::CfgGNSSBlock block = gnss_config.gnss_blocks[i];
                //     std::bitset<32> Bs = std::bitset<32>(block.flags);
                //     GetEnabledConstellationsCommand::Constellations constellation;
                //     switch(block.gnssId){
                //         case 0:
                //             constellation = GetEnabledConstellationsCommand::Constellations::GPS;
                //             break;
                //         case 1:
                //             constellation = GetEnabledConstellationsCommand::Constellations::SBAS;
                //             break;
                //         case 2:
                //             constellation = GetEnabledConstellationsCommand::Constellations::GALILEO;
                //             break;
                //         case 3:
                //             constellation = GetEnabledConstellationsCommand::Constellations::BELIDOU;
                //             break;
                //         case 4:
                //             constellation = GetEnabledConstellationsCommand::Constellations::IMES;
                //             break;
                //         case 5: 
                //             constellation = GetEnabledConstellationsCommand::Constellations::QZSS;
                //             break;
                //         case 6: 
                //             constellation = GetEnabledConstellationsCommand::Constellations::GLONASS;
                //             break;
                //     }
                //     std::cout<<Bs<<std::endl;
                //     if(Bs[0] == 1){
                //         GetEnabledConstellationsCommand::enabled_constellations[enabled_satellite] = constellation;
                //         enabled_satellite += 1;
                //     }
                // }
                SetConstellationsCommand::pulled = true;
            }
            catch(std::exception &e){
                std::cout << "PseudorangeData() error";
            }
        }
    protected:
        static bool set;
        static bool pulled;
        static ublox::CfgGNSS cur_config;
};
