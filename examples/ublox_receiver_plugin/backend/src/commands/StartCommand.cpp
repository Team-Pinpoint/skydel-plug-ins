#include "startCommand.h"
#include <iostream>

bool ReceiverStartCommand::receiver_reset = false;
void ReceiverStartCommand::execute(ReceiverStartCommand::ReceiverStartType startType){
    ReceiverStartCommand::receiver_reset = false;
    std::cout << "Setting Nav Status Callback" << std::endl;
    (receiver -> set_nav_status_callback)(NavigationStatusCallback);
    std::cout << "Setting Nav Status Refresh" << std::endl;
    (receiver -> ConfigureMessageRate)(0x01,0x03,1);
    switch (startType) {
        case ReceiverStartType::HOT:
            (receiver -> ResetToHotStart)();
            break;
        case ReceiverStartType::WARM:
            (receiver -> ResetToWarmStart)();
            break;
        default:
            (receiver -> ResetToColdStart)(0x02);
            break;
    }
    while(! ReceiverStartCommand::receiver_reset){
        // std::cout << _receiver_fixed << std::endl;
        usleep(50); 
    }
}