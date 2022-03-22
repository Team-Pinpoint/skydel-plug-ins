#include "command.h"
#include "ublox.h"
#include <iostream>

class GetUTCTimeCommand: public Command{
    public:
        GetUTCTimeCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~GetUTCTimeCommand(){};
        static void UTCTimeCallback(ublox::NavUTCTime nav_utc_time, double time_stamp){
            try{
                char buffer[20];
                int cx = snprintf(buffer, 20, "%d/%d/%d %d:%d:%d",unsigned(nav_utc_time.month),unsigned(nav_utc_time.day),nav_utc_time.year,unsigned(nav_utc_time.hour),unsigned(nav_utc_time.min),unsigned(nav_utc_time.sec));
                memcpy(GetUTCTimeCommand::time_string,buffer,20);
                GetUTCTimeCommand::pulled_time = true;
            }
            catch(std::exception &e){
                std::cout << "PseudorangeData() error";
            }
        }
        char* execute();
    protected:
        static bool pulled_time;
        static char time_string[20];
};
