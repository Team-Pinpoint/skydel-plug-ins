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
                std::cout << "" << std::endl;
                std::cout << "UTC Time: " << std::endl;
                std::cout << unsigned(nav_utc_time.day) << std::endl;
                std::cout << unsigned(nav_utc_time.month) << std::endl;
                std::cout << nav_utc_time.year << std::endl;
                std::cout << unsigned(nav_utc_time.hour) << std::endl;
                std::cout << unsigned(nav_utc_time.min) << std::endl;
                std::cout << unsigned(nav_utc_time.sec) << std::endl;
                std::cout << unsigned(nav_utc_time.tacc) << std::endl;
                std::cout << nav_utc_time.valid << std::endl;
                char buffer[100];
                int cx = snprintf(buffer, 100, "%d/%d/%d",unsigned(nav_utc_time.day),unsigned(nav_utc_time.month),nav_utc_time.year);
                std::cout << buffer << std:enl;
                UTCTimeCommand::pulled_time = true;
            }
            catch(std::exception &e){
                std::cout << "PseudorangeData() error";
            }
        }
    protected:
        static bool pulled_time;
};
