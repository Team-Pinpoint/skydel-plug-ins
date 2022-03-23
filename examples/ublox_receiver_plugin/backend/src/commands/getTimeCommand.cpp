#include "getTimeCommand.h"
#include <iostream>

bool GetUTCTimeCommand::pulled_time = false;
char GetUTCTimeCommand::time_string[20] = "";
char* GetUTCTimeCommand::execute(){
    GetUTCTimeCommand::pulled_time = false;
    GetUTCTimeCommand::time_string[0] = '\0';
    if (receiver && receiver->IsConnected()) {
        (receiver -> set_nav_utc_time_callback)(UTCTimeCallback);
        (receiver -> ConfigureMessageRate)(0x01,0x21,1);
        while(! GetUTCTimeCommand::pulled_time){
            usleep(50);
        }
        std::cout << GetUTCTimeCommand::time_string << std::endl;
    }
    return GetUTCTimeCommand::time_string;
};
