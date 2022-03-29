#include "setSatellitesCommand.h"
#include <iostream>

bool SetSatellitesCommand::set = false;
bool SetSatellitesCommand::execute(SetSatellitesCommand::Constellations * enableConstellations){
    for(int i = 0; i < 6; i++){
        std::cout << enableConstellations[i] << std::endl;
    }
    return true;
};