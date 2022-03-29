#include "command.h"
#include "ublox.h"
#include <iostream>

class SetSatellitesCommand: public Command{
    public:
        SetSatellitesCommand(ublox::Ublox *recv = 0): Command(recv){};
        ~SetSatellitesCommand(){};
        enum Constellations { GPS, SBAS, GALILEO, BELIDOU, IMES, QZSS, GLONASS, NONE};
        bool execute(SetSatellitesCommand::Constellations *);
    protected:
        static bool set;
};
