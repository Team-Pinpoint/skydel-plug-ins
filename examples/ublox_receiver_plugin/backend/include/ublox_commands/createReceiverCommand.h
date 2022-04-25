#include "command.h"
#include "ublox.h"
#include <iostream>

class CreateUbloxReceiverCommand: public Command{
    public:
        CreateUbloxReceiverCommand(int baud = 0, ublox::Ublox *recv = new ublox::Ublox()): Command(recv){
            baudrate = baud;
        };
        ~CreateUbloxReceiverCommand(){};
        ublox::Ublox* execute();
    protected:
        int baudrate;
};
