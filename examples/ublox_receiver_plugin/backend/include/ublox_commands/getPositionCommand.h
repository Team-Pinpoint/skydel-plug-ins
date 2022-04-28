#include "command.h"
#include "ublox.h"
#include <iostream>

class GetPositionCommand: public Command{
    public:
        GetPositionCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~GetPositionCommand() = default;
        static void GetPositionCallback(ublox::NavPosLLH nav_position, double time_stamp){
            char buffer[100];
            int cx = snprintf(buffer, 100, "Latitude: %d, Longitude: %d, Height: %d",nav_position.latitude_scaled,nav_position.longitude_scaled,nav_position.height);
            GetPositionCommand::pulled = true;
            memcpy(GetPositionCommand::position_string,buffer,100);
        }
        char* execute();
    protected:
        static bool pulled;
        static char position_string[100];
};
