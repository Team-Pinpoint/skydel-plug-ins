#include "command.h"
#include "ublox.h"
#include "receiver_enums.h"
#include <iostream>

class ReceiverGetFixCommand: public Command{
    public:
        ReceiverGetFixCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~ReceiverGetFixCommand(){};
        static void NavigationStatusCallbackIsFixed(ublox::NavStatus &nav_status, double &time_stamp){
            try{
                if (nav_status.fixtype == 0x03) {
                    if(ReceiverGetFixCommand::receiverFixCycles == 3){
                        ReceiverGetFixCommand::receiverFix = true;
                    }
                }
                ReceiverGetFixCommand::receiverFixCycles ++;
            } catch (std::exception &e) {
                std::cout << "PseudorangeData() error";
            }    
        }
        bool execute();
    protected:
        static bool receiverFix;
        static int receiverFixCycles;
};
