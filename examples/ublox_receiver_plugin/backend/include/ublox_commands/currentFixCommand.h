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
                if (nav_status.fixtype == 0x00) {
                    std::cout << "No Fix" << std::endl;
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::NO_FIX;
                    ReceiverGetFixCommand::receiverFix = true;
                } else if (nav_status.fixtype == 0x01) {
                    std::cout << "Dead Reckoning Only" << std::endl;
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::FIX_1D;
                    ReceiverGetFixCommand::receiverFix = true;
                } else if (nav_status.fixtype == 0x02) {
                    std::cout << "2D Fix" << std::endl;
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::FIX_2D;
                    ReceiverGetFixCommand::receiverFix = true;
                } else if (nav_status.fixtype == 0x03) {
                    std::cout << "3D Fix" << std::endl;
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::FIX_3D;
                    ReceiverGetFixCommand::receiverFix = true;
                } else if (nav_status.fixtype == 0x04) {
                    std::cout << "GPS + Dead Reckoning" << std::endl;
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::GPS_AND_DEAD_RECKONING;
                    ReceiverGetFixCommand::receiverFix = true;
                } else if (nav_status.fixtype == 0x05) {
                    std::cout << "Time Only" << std::endl;
                    ReceiverGetFixCommand::receiverStatus = ReceiverStatus::TIME_ONLY;
                    ReceiverGetFixCommand::receiverFix = true;
                } else {
                    std::cout << "Unhandled Fix Type Returned" << std::endl;
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
