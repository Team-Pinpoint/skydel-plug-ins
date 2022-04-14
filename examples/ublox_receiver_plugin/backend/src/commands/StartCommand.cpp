#include "startCommand.h"
#include "receiver_enums.h"
#include <iostream>

void ReceiverStartCommand::execute(ReceiverStartType startType){
    if (receiver && receiver->IsConnected()) {
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
    }
}