#include "getPositionCommand.h"
#include <iostream>

bool GetPositionCommand::pulled = false;
void GetPositionCommand::execute(){
    GetPositionCommand::pulled = false;
    (receiver -> set_nav_position_llh_callback)(GetPositionCallback);
    (receiver -> PollMessage(0x01,0x02));
    while(! GetPositionCommand::pulled){
        usleep(50);
    }
};