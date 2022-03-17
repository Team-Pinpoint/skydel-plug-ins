#include "command.h"
#include "ublox.h"
#include <iostream>

class GetEnabledSatellitesCommand: public Command{
    public:
        GetEnabledSatellitesCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~GetEnabledSatellitesCommand(){};
        enum Constellations { GPS, SBAS, GALILEO, BELIDOU, IMES, QZSS, GLONASS, NONE};
        void execute();
        static void GetEnabledSatellitesCallback(ublox::CfgGNSS gnss_config, double time_stamp){
            try{
                int num_configs = unsigned(gnss_config.numConfigBlocks);
                int enabled_satellite = 0;
                for(int i = 0; i < num_configs; i++){
                    ublox::CfgGNSSBlock block = gnss_config.gnss_blocks[i];
                    // memcpy(&block, gnss_config.gnss_blocks[0], 8);
                    std::cout << unsigned(block.gnssId) << std::endl;
                    std::cout << unsigned(block.resTrkCh) << std::endl;
                    std::cout << unsigned(block.maxTrkCh) << std::endl;
                    std::cout << unsigned(block.reserved1) << std::endl;
                    std::cout << std::bitset<32>(block.flags) << std::endl;
                    std::bitset<32> Bs = std::bitset<32>(block.flags);
                    GetEnabledSatellitesCommand::Constellations constellation;
                    switch(block.gnssId){
                        case 0:
                            constellation = GetEnabledSatellitesCommand::Constellations::GPS;
                            std::cout << "GPS" << std::endl;
                            break;
                        case 1:
                            constellation = GetEnabledSatellitesCommand::Constellations::SBAS;
                            std::cout << "SBAS" << std::endl;
                            break;
                        case 2:
                            constellation = GetEnabledSatellitesCommand::Constellations::GALILEO;
                            std::cout << "GALILEO" << std::endl;
                            break;
                        case 3:
                            constellation = GetEnabledSatellitesCommand::Constellations::BELIDOU;
                            std::cout << "BELIDOU" << std::endl;
                            break;
                        case 4:
                            constellation = GetEnabledSatellitesCommand::Constellations::IMES;
                            std::cout << "IMES" << std::endl;
                            break;
                        case 5: 
                            constellation = GetEnabledSatellitesCommand::Constellations::QZSS;
                            std::cout << "QZSS" << std::endl;
                            break;
                        case 6: 
                            constellation = GetEnabledSatellitesCommand::Constellations::GLONASS;
                            std::cout << "GLONASS" << std::endl;
                            break;
                    }
                    if(Bs[0] == 1){
                        std::cout << "enabled" << std::endl;
                        GetEnabledSatellitesCommand::enabled_constellations[enabled_satellite] = constellation;
                        enabled_satellite += 1;
                    }
                    else{
                        std::cout << "disabled" << std::endl;
                    }
                    std::cout << "----" << std::endl;
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
