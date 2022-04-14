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
                if (nav_status.fixtype == 0x00) {
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::NO_FIX;
                    ReceiverGetFixCommand::receiverFix = true;
                } else if (nav_status.fixtype == 0x01) {
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::FIX_1D;
                    ReceiverGetFixCommand::receiverFix = true;
                } else if (nav_status.fixtype == 0x02) {
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::FIX_2D;
                    ReceiverGetFixCommand::receiverFix = true;
                } else if (nav_status.fixtype == 0x03) {
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::FIX_3D;
                    ReceiverGetFixCommand::receiverFix = true;
                } else if (nav_status.fixtype == 0x04) {
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::GPS_AND_DEAD_RECKONING;
                    ReceiverGetFixCommand::receiverFix = true;
                } else if (nav_status.fixtype == 0x05) {
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::TIME_ONLY;
                    ReceiverGetFixCommand::receiverFix = true;
                } else {
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::NO_FIX;
                    ReceiverGetFixCommand::receiverFix = true;
                }
            } catch (std::exception &e) {
                std::cout << "PseudorangeData() error";
            }    
        }
        ReceiverStatus execute();
    protected:
        static ReceiverStatus receiverStatus;
        static bool receiverFix;
};
