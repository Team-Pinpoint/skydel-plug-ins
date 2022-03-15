#include "currentFixCommand.h"
#include "receiver_enums.h"
#include <iostream>

bool ReceiverGetFixCommand::receiverFix = false;
ReceiverStatus ReceiverGetFixCommand::receiverStatus = ReceiverStatus::NOT_CONNECTED;
ReceiverStatus ReceiverGetFixCommand::execute(){
    ReceiverGetFixCommand::receiverFix = false;
    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::NOT_CONNECTED;
    if (receiver && receiver->IsConnected()) {
        std::cout << "Setting Nav Status Callback" << std::endl;
        (receiver -> set_nav_status_callback)(NavigationStatusCallbackIsFixed);
        std::cout << "Setting Nav Status Refresh" << std::endl;
        (receiver -> PollMessage)(0x01,0x03);
        while(!ReceiverGetFixCommand::receiverFix){
            usleep(50); 
        }
    }
    return ReceiverGetFixCommand::receiverStatus;
}
