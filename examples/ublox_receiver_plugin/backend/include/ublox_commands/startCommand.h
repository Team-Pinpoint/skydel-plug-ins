#include "command.h"
#include "ublox.h"
#include "receiver_enums.h"
#include <iostream>

class ReceiverStartCommand: public Command{
    public:
        ReceiverStartCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~ReceiverStartCommand(){};
        void execute(ReceiverStartType startType);
        enum class ReceiverStartType
        {
        NONE = 0,
        COLD = 1,
        WARM = 2,
        HOT = 3
        };
    protected:
        static bool receiver_reset;
};
