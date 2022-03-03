#include "getConfigurationCommand.h"
#include <iostream>

bool GetConfigurationCommand::pulled = false;
void GetConfigurationCommand::execute(){
    GetConfigurationCommand::pulled = false;
    (receiver -> set_configure_gnss_callback)(GetConfigurationCallback);
    (receiver -> PollMessage(0x06,0x3E));
    while(! GetConfigurationCommand::pulled){
        usleep(50);
    }
};