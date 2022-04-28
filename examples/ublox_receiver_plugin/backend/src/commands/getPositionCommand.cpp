#include "getPositionCommand.h"
#include <iostream>

bool GetPositionCommand::pulled = false;
char GetPositionCommand::position_string[100] = "";
char* GetPositionCommand::execute(){
    GetPositionCommand::pulled = false;
    GetPositionCommand::position_string[0] = '\0';
    if (receiver && receiver->IsConnected()) {
        (receiver -> set_nav_position_llh_callback)(GetPositionCallback);
        (receiver -> PollMessage(0x01,0x02));
        while(! GetPositionCommand::pulled){
            usleep(50);
        }
    }
    return GetPositionCommand::position_string;
};
