#include "createReceiverCommand.h"
#include <iostream>

ublox::Ublox& CreateUbloxReceiverCommand::execute(){
    std::cout << baudrate << std::endl;

    bool result = (receiver->Connect)(port,baudrate);
    if (result) {
        std::cout << "Successfully connected." << std::endl;
        return *receiver;
    }
    else {
        std::cout << "Failed to connect." << std::endl;
    }
}
