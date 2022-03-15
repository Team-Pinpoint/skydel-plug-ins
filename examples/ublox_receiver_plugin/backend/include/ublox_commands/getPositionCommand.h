#include "command.h"
#include "ublox.h"
#include <iostream>

class GetPositionCommand: public Command{
    public:
        GetPositionCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~GetPositionCommand(){};
        static void GetPositionCallback(ublox::NavPosLLH nav_position, double time_stamp){
            // std::cout << "NAV-POSLLH: " << std::endl <<
            //             "  GPS milliseconds: " << nav_position.iTOW << std::endl <<
            //             "  Latitude: " << nav_position.latitude_scaled << std::endl <<
            //             "  Longitude: " << nav_position.longitude_scaled << std::endl <<
            //             "  Height: " << nav_position.height << std::endl << std::endl;
            char buffer[100];
            int cx = snprintf(buffer, 100, "Latitude: %d, Longitude: %d, Height: %d",nav_position.latitude_scaled,nav_position.longitude_scaled,nav_position.height);
            std::cout << buffer << std::endl;
            GetPositionCommand::pulled = true;
        }
        void execute();
    protected:
        static bool pulled;
};
