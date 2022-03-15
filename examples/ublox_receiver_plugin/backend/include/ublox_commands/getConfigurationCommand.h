#include "command.h"
#include "ublox.h"
#include <iostream>

class GetConfigurationCommand: public Command{
    public:
        GetConfigurationCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~GetConfigurationCommand(){};
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
