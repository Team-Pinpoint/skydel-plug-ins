#include "timeCommand.h"
#include <iostream>

bool UTCTimeCommand::pulled_time = false;
char UTCTimeCommand::time_string[20] = "";
void UTCTimeCommand::execute(){
    UTCTimeCommand::pulled_time = false;
    UTCTimeCommand::time_string[0] = '\0';
    (receiver -> set_nav_utc_time_callback)(UTCTimeCallback);
    (receiver -> ConfigureMessageRate)(0x01,0x21,1);
    while(! UTCTimeCommand::pulled_time){
        usleep(50);
    }
};