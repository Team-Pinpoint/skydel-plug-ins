#include "command.h"
#include "ublox.h"
#include "receiver_enums.h"
#include <iostream>

class ReceiverStartCommand: public Command{
    public:
        ReceiverStartCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~ReceiverStartCommand(){};
        enum ReceiverStartType{NONE = 0,COLD = 1,WARM = 2,HOT = 3};
        static void NavigationStatusCallback(ublox::NavStatus &nav_status, double &time_stamp){
            try{
                std::cout << "GPS Fix Type: "<< std::endl;
                if (nav_status.fixtype == 0x00) {
                    std::cout << "No Fix" << std::endl;
                    std::cout << "TTFF: " << " none ms" << std::endl;
                    std::cout << "Milliseconds since Startup/Reset: " << nav_status.msss
                            << std::endl;
                } else if (nav_status.fixtype == 0x01) {
                    std::cout << "Dead Reckoning Only" << std::endl;
                } else if (nav_status.fixtype == 0x02) {
                    std::cout << "2D Fix" << std::endl;
                } else if (nav_status.fixtype == 0x03) {
                    std::cout << "3D Fix" << std::endl;
                    ReceiverStartCommand::receiver_reset = true;
                } else if (nav_status.fixtype == 0x04) {
                    std::cout << "GPS + Dead Reckoning" << std::endl;
                } else if (nav_status.fixtype == 0x05) {
                    std::cout << "Time Only" << std::endl;
                } else {
                    std::cout << std::endl;
                }

                if (nav_status.fixtype != 0x00) {
                    std::cout << "TTFF: " << (nav_status.ttff / 1000.) << " sec"
                            << std::endl;
                    std::cout << "Milliseconds since Startup/Reset: "
                            << (nav_status.msss / 1000.) << " sec" << std::endl;
                }
            } catch (std::exception &e) {
                std::cout << "PseudorangeData() error";
            }    
        }
        void execute(ReceiverStartCommand::ReceiverStartType startType);
    protected:
        static bool receiver_reset;
};
