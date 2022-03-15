#include "getEnabledSatellitesCommand.h"
#include <iostream>

bool GetEnabledSatellitesCommand::pulled = false;
void GetEnabledSatellitesCommand::execute(){
    GetEnabledSatellitesCommand::pulled = false;
    (receiver -> set_configure_gnss_callback)(GetConfigurationCallback);
    (receiver -> PollMessage(0x06,0x3E));
    while(! GetEnabledSatellitesCommand::pulled){
        usleep(50);
    }
};