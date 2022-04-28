#include "getEnabledConstellationsCommand.h"
#include "receiver_enums.h"
#include <iostream>
#include <set>

bool GetEnabledConstellationsCommand::pulled = false;
std::set<Constellation> GetEnabledConstellationsCommand::enabled_constellations;
std::set<Constellation> GetEnabledConstellationsCommand::execute(){
    GetEnabledConstellationsCommand::pulled = false;
    GetEnabledConstellationsCommand::enabled_constellations.clear();
    if (receiver && receiver->IsConnected()) {
      (receiver -> set_configure_gnss_callback)(GetEnabledSatellitesCallback);
      (receiver -> PollMessage(0x06,0x3E));
      while(! GetEnabledConstellationsCommand::pulled){
          usleep(50);
      }
    }
    return GetEnabledConstellationsCommand::enabled_constellations;
};
