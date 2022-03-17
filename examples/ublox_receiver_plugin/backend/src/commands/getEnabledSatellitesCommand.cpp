#include "getEnabledSatellitesCommand.h"
#include <iostream>

bool GetEnabledSatellitesCommand::pulled = false;
GetEnabledSatellitesCommand::Constellations GetEnabledSatellitesCommand::enabled_constellations[6] = {GetEnabledSatellitesCommand::Constellations::NONE,GetEnabledSatellitesCommand::Constellations::NONE,GetEnabledSatellitesCommand::Constellations::NONE,GetEnabledSatellitesCommand::Constellations::NONE,GetEnabledSatellitesCommand::Constellations::NONE,GetEnabledSatellitesCommand::Constellations::NONE};
void GetEnabledSatellitesCommand::execute(){
    GetEnabledSatellitesCommand::pulled = false;
    for(int i = 0; i < 6; i++){
        GetEnabledSatellitesCommand::enabled_constellations[i] = GetEnabledSatellitesCommand::Constellations::NONE;
        std::cout << GetEnabledSatellitesCommand::enabled_constellations[i] << std::endl;
    }
    (receiver -> set_configure_gnss_callback)(GetEnabledSatellitesCallback);
    (receiver -> PollMessage(0x06,0x3E));
    while(! GetEnabledSatellitesCommand::pulled){
        usleep(50);
    }
    for(int i = 0; i < 6; i++){
        std::cout << GetEnabledSatellitesCommand::enabled_constellations[i] << std::endl;
    }
};