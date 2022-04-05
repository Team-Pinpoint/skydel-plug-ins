#include "command.h"
#include "ublox.h"
#include "receiver_enums.h"
#include <iostream>
#include <set>

class GetEnabledConstellationsCommand: public Command{
    public:
        GetEnabledConstellationsCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~GetEnabledConstellationsCommand(){};
        enum Constellations { GPS, SBAS, GALILEO, BELIDOU, IMES, QZSS, GLONASS, NONE};
        std::set<Constellation> execute();
        static void GetEnabledSatellitesCallback(ublox::CfgGNSS gnss_config, double time_stamp){
            try{
                int num_configs = unsigned(gnss_config.numConfigBlocks);
                for(int i = 0; i < num_configs; i++){
                    ublox::CfgGNSSBlock block = gnss_config.gnss_blocks[i];
                    std::bitset<32> Bs = std::bitset<32>(block.flags);
                    if(Bs[0] == 1){
                        GetEnabledConstellationsCommand::enabled_constellations.insert((Constellation)block.gnssId);
                    }
                }
                GetEnabledConstellationsCommand::pulled = true;
            }
            catch(std::exception &e){
                std::cout << "PseudorangeData() error";
            }
        }
    protected:
        static bool pulled;
        static std::set<Constellation> enabled_constellations;
};
