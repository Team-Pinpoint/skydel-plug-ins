#include "ublox_commands/startCommands.h"
#include <iostream>

bool ReceiverResetCommand::receiver_reset = false;
ReceiverWarmStartCommand::~ReceiverWarmStartCommand(){}
void ReceiverWarmStartCommand::execute(){
    std::cout << "Setting Nav Status Callback" << std::endl;
    (receiver -> set_nav_status_callback)(NavigationStatusCallback);
    std::cout << "Setting Nav Status Refresh" << std::endl;
    (receiver -> ConfigureMessageRate)(0x01,0x03,1);
    (receiver -> ResetToWarmStart)();
    while(! ReceiverResetCommand::receiver_reset){
        // std::cout << _receiver_fixed << std::endl;
        usleep(50); 
    }
}