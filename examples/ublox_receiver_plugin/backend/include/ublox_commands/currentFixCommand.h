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
                std::cout << "GPS Fix Type: "<< std::endl;
                if (nav_status.fixtype == 0x03) {
                    std::cout << "3D Fix" << std::endl;
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
