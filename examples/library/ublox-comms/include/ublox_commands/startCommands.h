#include "ublox_commands/command.h"
#include "ublox/ublox.h"
#include <iostream>

class ReceiverResetCommand: public Command{
    public:
        ReceiverResetCommand(ublox::Ublox *recv = 0): Command(recv){
        };
        ~ReceiverResetCommand(){};
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
                    ReceiverResetCommand::receiver_reset = true;
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
    protected:
        static bool receiver_reset;
};

class ReceiverColdStartCommand: public ReceiverResetCommand{
    public: 
        ReceiverColdStartCommand(ublox::Ublox *recv = 0): ReceiverResetCommand(recv){};
        ~ReceiverColdStartCommand();
        void execute();
};
class ReceiverWarmStartCommand: public ReceiverResetCommand{
    public: 
        ReceiverWarmStartCommand(ublox::Ublox *recv = 0): ReceiverResetCommand(recv){};
        ~ReceiverWarmStartCommand();
        void execute();
};
class ReceiverHotStartCommand: public ReceiverResetCommand{
    public: 
        ReceiverHotStartCommand(ublox::Ublox *recv = 0): ReceiverResetCommand(recv){};
        ~ReceiverHotStartCommand();
        void execute();
};