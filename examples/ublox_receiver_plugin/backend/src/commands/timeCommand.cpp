#include "timeCommand.h"
#include <iostream>

bool UTCTimeCommand::pulled_time = false;
void UTCTimeCommand::execute(){
    UTCTimeCommand::pulled_time = false;
    (receiver -> set_nav_utc_time_callback)(UTCTimeCallback);
    (receiver -> ConfigureMessageRate)(0x01,0x21,1);
    while(! UTCTimeCommand::pulled_time){
        usleep(50);
    }
};