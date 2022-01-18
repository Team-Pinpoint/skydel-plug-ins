#ifndef Command_H
#define Command_H
#include "ublox/ublox.h"
class Command{
    public: 
        Command(ublox::Ublox *recv = 0) {
            receiver = recv;
        }
        ~Command(){};

    protected:
        ublox::Ublox *receiver;
};
#endif