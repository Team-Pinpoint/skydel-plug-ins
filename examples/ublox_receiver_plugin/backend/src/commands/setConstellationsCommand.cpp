#include "setConstellationsCommand.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool SetConstellationsCommand::set = false;
bool SetConstellationsCommand::pulled = false;
ublox::CfgGNSS SetConstellationsCommand::cur_config;
bool SetConstellationsCommand::execute(SetConstellationsCommand::Constellations * enableConstellations){
    (receiver -> set_configure_gnss_callback)(GetCurrentConfigurationCallback);
    (receiver -> PollMessage(0x06,0x3E));
    while(! SetConstellationsCommand::pulled){
        usleep(50);
    }
    int num_configs = unsigned(SetConstellationsCommand::cur_config.numConfigBlocks);
    int enabled_satellite = 0;
    int n = sizeof(enableConstellations) / sizeof(enableConstellations[0]);
    for(int i = 0; i < num_configs; i++){
        ublox::CfgGNSSBlock block = SetConstellationsCommand::cur_config.gnss_blocks[i];
        bitset<32> Bs = bitset<32>(block.flags);
        if(Bs[0] != 1){
            if(count(enableConstellations,enableConstellations+n,block.gnssId) > 0){
                Bs.flip(0);
                SetConstellationsCommand::cur_config.gnss_blocks[i].flags = Bs.to_ulong();
            }
        }
        else{
            if(count(enableConstellations,enableConstellations+n,block.gnssId) == 0){
                Bs.flip(0);
                SetConstellationsCommand::cur_config.gnss_blocks[i].flags = Bs.to_ulong();
            }
        }
    }
    for(int i = 0; i < 6; i++){
        cout << enableConstellations[i] << endl;
    }
    // unsigned char* msg_ptr = (unsigned char*) &SetConstellationsCommand::cur_config;
    // bool sent = (receiver -> SendMessage)(msg_ptr,sizeof(msg_ptr));
    return true;
};