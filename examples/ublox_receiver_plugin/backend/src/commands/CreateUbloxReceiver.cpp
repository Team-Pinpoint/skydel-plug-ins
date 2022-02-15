#include "createReceiverCommand.h"
#include <iostream>
#include "ublox.h"

CreateUbloxReceiverCommand::~CreateUbloxReceiverCommand(){}
ublox::Ublox* CreateUbloxReceiverCommand::execute(){
    std::cout << baudrate << port << std::endl;
    bool result = 0;
    while(result == 0){
        result = receiver->Connect(port,baudrate);
        if (result) {
            std::cout << "Successfully connected." << std::endl;
            return receiver;
        }
        else {
            std::cout << "Failed to connect." << std::endl;
        }
    }
}
