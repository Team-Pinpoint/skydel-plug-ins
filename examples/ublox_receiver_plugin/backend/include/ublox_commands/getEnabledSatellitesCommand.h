#include "command.h"
#include "ublox.h"
#include <iostream>

class GetEnabledSatellitesCommand: public Command{
    public:
        GetEnabledSatellitesCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~GetEnabledSatellitesCommand(){};
        enum Constellations { GPS, SBAS, GALILEO, BELIDOU, IMES, QZSS, GLONASS, NONE};
        GetEnabledSatellitesCommand::Constellations * execute();
        static void GetEnabledSatellitesCallback(ublox::CfgGNSS gnss_config, double time_stamp){
            try{
                int num_configs = unsigned(gnss_config.numConfigBlocks);
                int enabled_satellite = 0;
                for(int i = 0; i < num_configs; i++){
                    ublox::CfgGNSSBlock block = gnss_config.gnss_blocks[i];
                    std::bitset<32> Bs = std::bitset<32>(block.flags);
                    GetEnabledSatellitesCommand::Constellations constellation;
                    switch(block.gnssId){
                        case 0:
                            constellation = GetEnabledSatellitesCommand::Constellations::GPS;
                            break;
                        case 1:
                            constellation = GetEnabledSatellitesCommand::Constellations::SBAS;
                            break;
                        case 2:
                            constellation = GetEnabledSatellitesCommand::Constellations::GALILEO;
                            break;
                        case 3:
                            constellation = GetEnabledSatellitesCommand::Constellations::BELIDOU;
                            break;
                        case 4:
                            constellation = GetEnabledSatellitesCommand::Constellations::IMES;
                            break;
                        case 5: 
                            constellation = GetEnabledSatellitesCommand::Constellations::QZSS;
                            break;
                        case 6: 
                            constellation = GetEnabledSatellitesCommand::Constellations::GLONASS;
                            break;
                    }
                    std::cout<<Bs<<std::endl;
                    if(Bs[0] == 1){
                        GetEnabledSatellitesCommand::enabled_constellations[enabled_satellite] = constellation;
                        enabled_satellite += 1;
                    }
                }
                GetEnabledSatellitesCommand::pulled = true;
            }
            catch(std::exception &e){
                std::cout << "PseudorangeData() error";
            }
        }
    protected:
        static bool pulled;
        static GetEnabledSatellitesCommand::Constellations enabled_constellations [6];
};
