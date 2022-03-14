#include "command.h"
#include "ublox.h"
#include <iostream>

class GetPositionCommand: public Command{
    public:
        GetPositionCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~GetPositionCommand(){};
        static void GetPositionCallback(ublox::NavPosLLH nav_position, double time_stamp){
            std::cout << "NAV-POSLLH: " << std::endl <<
                        "  GPS milliseconds: " << nav_position.iTOW << std::endl <<
                        "  Latitude: " << nav_position.latitude_scaled << std::endl <<
                        "  Longitude: " << nav_position.longitude_scaled << std::endl <<
                        "  Height: " << nav_position.height << std::endl << std::endl;
            GetPositionCommand::pulled = true;
        }
        void execute();
    protected:
        static bool pulled;
};
