#include "currentFixCommand.h"
#include "receiver_enums.h"
#include <iostream>

bool ReceiverGetFixCommand::receiverFix = false;
ReceiverStatus ReceiverGetFixCommand::receiverStatus = ReceiverStatus::NOT_CONNECTED;
ReceiverStatus ReceiverGetFixCommand::execute(){
    ReceiverGetFixCommand::receiverFix = false;
    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::NOT_CONNECTED;
    if (receiver && receiver->IsConnected()) {
        (receiver -> set_nav_status_callback)(NavigationStatusCallbackIsFixed);
        (receiver -> PollMessage)(0x01,0x03);
        while(!ReceiverGetFixCommand::receiverFix){
            usleep(50); 
        }
    }
    return ReceiverGetFixCommand::receiverStatus;
}
