#include "getTimeCommand.h"
#include <iostream>

bool GetUTCTimeCommand::pulled_time = false;
char GetUTCTimeCommand::time_string[20] = "";
void GetUTCTimeCommand::execute(){
    GetUTCTimeCommand::pulled_time = false;
    GetUTCTimeCommand::time_string[0] = '\0';
    (receiver -> set_nav_utc_time_callback)(UTCTimeCallback);
    (receiver -> ConfigureMessageRate)(0x01,0x21,1);
    while(! GetUTCTimeCommand::pulled_time){
        usleep(50);
    }
    std::cout << GetUTCTimeCommand::time_string << std::endl;
};