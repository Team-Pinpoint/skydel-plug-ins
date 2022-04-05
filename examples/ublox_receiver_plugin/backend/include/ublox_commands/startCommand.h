#include "command.h"
#include "ublox.h"
#include "receiver_enums.h"
#include <iostream>

class ReceiverStartCommand: public Command{
    public:
        ReceiverStartCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~ReceiverStartCommand(){};
        enum ReceiverStartType{NONE = 0,COLD = 1,WARM = 2,HOT = 3};
        void execute(ReceiverStartType startType);
    protected:
        static bool receiver_reset;
};
