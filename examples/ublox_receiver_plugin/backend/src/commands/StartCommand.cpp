#include "startCommand.h"
#include "receiver_enums.h"
#include <iostream>

void ReceiverStartCommand::execute(ReceiverStartType startType){
    if (receiver && receiver->IsConnected()) {
        switch (startType) {
            case ReceiverStartType::HOT:
                std::cout << "Hot Starting Receiver" << std::endl;
                (receiver -> ResetToHotStart)();
                break;
            case ReceiverStartType::WARM:
                std::cout << "Warm Starting Receiver" << std::endl;
                (receiver -> ResetToWarmStart)();
                break;
            default:
                std::cout << "Cold Starting Receiver" << std::endl;
                (receiver -> ResetToColdStart)(0x02);
                break;
        }
    }
}