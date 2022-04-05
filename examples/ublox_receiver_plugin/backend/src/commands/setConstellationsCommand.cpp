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
        std::cout << block.resTrkCh << std::endl;
        std::cout << block.maxTrkCh << std::endl;
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
    SetConstellationsCommand::cur_config.header.sync1 = UBX_SYNC_BYTE_1;
    SetConstellationsCommand::cur_config.header.sync2 = UBX_SYNC_BYTE_2;
    SetConstellationsCommand::cur_config.header.message_class = MSG_CLASS_CFG;
    SetConstellationsCommand::cur_config.header.message_id = MSG_ID_CFG_GNSS;
    SetConstellationsCommand::cur_config.header.payload_length = (4 + (8 * num_configs));
    unsigned char* msg_ptr = (unsigned char*) &SetConstellationsCommand::cur_config;
    bool sent = (receiver -> SendMessage)(msg_ptr,(4 + (8 * num_configs)));
    int x = 0;
    while(x < 10000){
        usleep(5000);
        x++;
    }
    return sent;
};