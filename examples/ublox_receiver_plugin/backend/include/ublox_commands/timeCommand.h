#include "command.h"
#include "ublox.h"
#include <iostream>

class UTCTimeCommand: public Command{
    public:
        UTCTimeCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~UTCTimeCommand(){};
        void execute();
        static void UTCTimeCallback(ublox::NavUTCTime nav_utc_time, double time_stamp){
            try{
                // std::cout << "" << std::endl;
                // std::cout << "UTC Time: " << std::endl;
                // std::cout << unsigned(nav_utc_time.day) << std::endl;
                // std::cout << unsigned(nav_utc_time.month) << std::endl;
                // std::cout << nav_utc_time.year << std::endl;
                // std::cout << unsigned(nav_utc_time.hour) << std::endl;
                // std::cout << unsigned(nav_utc_time.min) << std::endl;
                // std::cout << unsigned(nav_utc_time.sec) << std::endl;
                // std::cout << unsigned(nav_utc_time.tacc) << std::endl;
                // std::cout << nav_utc_time.valid << std::endl;
                char buffer[20];
                int cx = snprintf(buffer, 20, "%d/%d/%d %d:%d:%d",unsigned(nav_utc_time.month),unsigned(nav_utc_time.day),nav_utc_time.year,unsigned(nav_utc_time.hour),unsigned(nav_utc_time.min),unsigned(nav_utc_time.sec));
                std::cout << buffer << std::endl;
                memcpy(UTCTimeCommand::time_string,buffer,20);
                UTCTimeCommand::pulled_time = true;
            }
            catch(std::exception &e){
                std::cout << "PseudorangeData() error";
            }
        }
    protected:
        static bool pulled_time;
        static char time_string[20];
};
