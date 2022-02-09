#include "command.h"
#include "ublox.h"
#include <iostream>

class CreateUbloxReceiverCommand: public Command{
    public:
        CreateUbloxReceiverCommand(int baud = 0, std::string prt = 0,ublox::Ublox *recv = new ublox::Ublox()): Command(recv){
            baudrate = baud;
            port = prt;
        };
        ~CreateUbloxReceiverCommand();
        ublox::Ublox* execute();
    protected:
        int baudrate;
        std::string port;
};
