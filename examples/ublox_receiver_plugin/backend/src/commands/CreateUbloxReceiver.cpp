#include "createReceiverCommand.h"
#include <iostream>

ublox::Ublox& CreateUbloxReceiverCommand::execute(){
    std::cout << baudrate << std::endl;
    // TODO: sit and wait for a port with a ublox receiver in it

    bool result = (receiver->Connect)(port,baudrate);
    if (result) {
        std::cout << "Successfully connected." << std::endl;
        return *receiver;
    }
    else {
        std::cout << "Failed to connect." << std::endl;
    }
}
