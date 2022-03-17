#include "command.h"
#include "ublox.h"
#include <iostream>

class GetConfigurationCommand: public Command{
    public:
        GetConfigurationCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~GetConfigurationCommand(){};
        enum Constellations { GPS, SBAS, GALILEO, BELIDOU, IMES, QZSS, GLONASS};
        void execute();
        static void GetConfigurationCallback(ublox::CfgGNSS gnss_config, double time_stamp){
            try{
                std::cout << "" << std::endl;
                std::cout << "GNSS settings Command" << std::endl;
                std::cout << unsigned(gnss_config.msgVer) << std::endl;
                std::cout << unsigned(gnss_config.numTrkChHw) << std::endl;
                std::cout << unsigned(gnss_config.numTrkChUse) << std::endl;
                std::cout << unsigned(gnss_config.numConfigBlocks) << std::endl;
                int num_configs = unsigned(gnss_config.numConfigBlocks);
                for(int i = 0; i < num_configs; i++){
                    ublox::CfgGNSSBlock block = gnss_config.gnss_blocks[i];
                    // memcpy(&block, gnss_config.gnss_blocks[0], 8);
                    std::cout << unsigned(block.gnssId) << std::endl;
                    std::cout << unsigned(block.resTrkCh) << std::endl;
                    std::cout << unsigned(block.maxTrkCh) << std::endl;
                    std::cout << unsigned(block.reserved1) << std::endl;
                    std::cout << std::bitset<32>(block.flags) << std::endl;
                    std::bitset<32> Bs = std::bitset<32>(block.flags);
                    GetConfigurationCommand::Constellations constellation;
                    switch(block.gnssId){
                        case 0:
                            constellation = GetConfigurationCommand::Constellations::GPS;
                            std::cout << "GPS" << std::endl;
                            break;
                        case 1:
                            constellation = GetConfigurationCommand::Constellations::SBAS;
                            std::cout << "SBAS" << std::endl;
                            break;
                        case 2:
                            constellation = GetConfigurationCommand::Constellations::GALILEO;
                            std::cout << "GALILEO" << std::endl;
                            break;
                        case 3:
                            constellation = GetConfigurationCommand::Constellations::BELIDOU;
                            std::cout << "BELIDOU" << std::endl;
                            break;
                        case 4:
                            constellation = GetConfigurationCommand::Constellations::IMES;
                            std::cout << "IMES" << std::endl;
                            break;
                        case 5: 
                            constellation = GetConfigurationCommand::Constellations::QZSS;
                            std::cout << "QZSS" << std::endl;
                            break;
                        case 6: 
                            constellation = GetConfigurationCommand::Constellations::GLONASS;
                            std::cout << "GLONASS" << std::endl;
                            break;
                    }
                    if(Bs[0] == 1){
                        std::cout << "enabled" << std::endl;
                    }
                    else{
                        std::cout << "disabled" << std::endl;
                    }
                    std::cout << "----" << std::endl;
                }
                GetConfigurationCommand::pulled = true;
            }
            catch(std::exception &e){
                std::cout << "PseudorangeData() error";
            }
        }
    protected:
        static bool pulled;
};
