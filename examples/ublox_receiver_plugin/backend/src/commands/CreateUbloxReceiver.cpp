#include "createReceiverCommand.h"
#include <iostream>
#include "ublox.h"
#include "serial.h"

CreateUbloxReceiverCommand::~CreateUbloxReceiverCommand(){}
ublox::Ublox* CreateUbloxReceiverCommand::execute(){
    std::string port = "";
    for (auto & p : serial::list_ports()) {
        // check if vendor id is ublox (1546) and product id is a receiver (begins with 01a)
        // TODO: should we only support the newest ublox receiver (which we have) ... 01a8
        if (p.hardware_id.find("VID:PID=1546:01a") != std::string::npos) {
            port = p.port;
            break;
        }
    }

    if (port == "") {
        std::cout << "Could not find port with ublox receiver." << std::endl;
        return receiver;
    }

    bool result = 0;
    while(result == 0){
        result = receiver->Connect(port,baudrate);
        if (result) {
            // std::cout << "Successfully connected to ublox receiver at " << port << std::endl;
            return receiver;
        }
        // else {
        //     std::cout << "Failed to connect to ublox receiver at " << port << std::endl;
        // }
    }
}
