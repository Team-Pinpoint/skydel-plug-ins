#include "currentFixCommand.h"
#include <iostream>

bool ReceiverGetFixCommand::receiverFix = false;
int ReceiverGetFixCommand::receiverFixCycles = 0;
bool ReceiverGetFixCommand::execute(){
    ReceiverGetFixCommand::receiverFix = false;
    ReceiverGetFixCommand::receiverFixCycles = 0;
    std::cout << "Setting Nav Status Callback" << std::endl;
    (receiver -> set_nav_status_callback)(NavigationStatusCallbackIsFixed);
    std::cout << "Setting Nav Status Refresh" << std::endl;
    (receiver -> ConfigureMessageRate)(0x01,0x03,1);
    while(ReceiverGetFixCommand::receiverFixCycles < 4){
        usleep(50); 
    }
    return ReceiverGetFixCommand::receiverFix;
}