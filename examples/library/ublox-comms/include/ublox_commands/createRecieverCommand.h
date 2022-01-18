#include "command.h"
#include "ublox.h"
#include <iostream>

class CreateUbloxReceiverCommand: public Command{
    public:
        CreateUbloxReceiverCommand(int baud = 0, std::string prt = 0){
            baudrate = baud;
            port = prt;
            ublox::Ublox receiver;
        };
        ~CreateUbloxReceiverCommand(){};
        ublox::Ublox& execute();
    protected:
        int baudrate;
        std::string port;
};