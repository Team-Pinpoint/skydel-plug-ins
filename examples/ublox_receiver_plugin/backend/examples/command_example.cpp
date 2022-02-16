#include "ublox.h"
#include <iostream>
#include <fstream>
#include <boost/function.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "createReceiverCommand.h"
#include "startCommand.h"
#include "currentFixCommand.h"

// #include "boost/filesystem.hpp"

using namespace ublox;
using namespace std;


ofstream data_file_;  //!< file stream for logging gps data
std::string data_filename_; //!< file name for logging gps data
NavStatus cur_nav_status;
bool StartDataLogging(std::string filename) {
    try {

        data_filename_ = filename;
        
        // open file and add header
        data_file_.open(data_filename_.c_str());

        // write header
        data_file_ << "%%RANGE  1) GPS Time(ms) 2) SVID  3) Pseudorange (m)  4) SVID  5) Pseudorange ..." << std::endl;
        data_file_ << "%%CLOCK  1) GPS Time(ms) 2) ClockBias(nsec) 3) ClkDrift(nsec/sec) 4) TimeAccuracyEstimate(nsec) 5) FreqAccuracyEstimate(ps/s)" << std::endl;

    } catch (std::exception &e) {
        std::cout << "Error opening log file: " << e.what();
        if (data_file_.is_open())
            data_file_.close();
        return false;
    }
    std::cout << "Started Data Log" << std::endl;
    return true;
}
void StopLoggingData() {
    if (data_file_.is_open())
        data_file_.close();
}
int main(int argc, char **argv)
{
    Ublox *my_gps;
    enum ReceiverStartType{NONE = 0,COLD = 1,WARM = 2,HOT = 3};
    if(argc < 3) {
        std::cerr << "Usage: ublox_example <serial port address> <baud rate>" << std::endl;
        return 0;
    }
    std::string port(argv[1]);
    int baudrate=115200;
    istringstream(argv[2]) >> baudrate;
    CreateUbloxReceiverCommand createReciever(9600,"/dev/tty.usbmodem101");
    my_gps = createReciever.execute();
    // Connect to Receiver
    // bool result = my_gps.Connect(port,baudrate);
    //     if (result) {
    //         cout << "Successfully connected." << endl;
    //     }
    //     else {
    //         cout << "Failed to connect." << endl;
    //         return -1;
    //     }

    //! Start Data Logging
    bool logging_on = StartDataLogging("range_data.log");

    ReceiverGetFixCommand getcurfix(my_gps);
    bool fix = getcurfix.execute();
    std::cerr << "Is fixed" << fix << std::endl;

    //comand test
    ReceiverStartCommand coldstartcmd(my_gps);
    coldstartcmd.execute(ReceiverStartCommand::ReceiverStartType::WARM);
    bool fix_after_warm = getcurfix.execute();
    std::cerr << "Is fixed" << fix_after_warm << std::endl;
    coldstartcmd.execute(ReceiverStartCommand::ReceiverStartType::HOT);
    bool fix_after_hot = getcurfix.execute();
    std::cerr << "Is fixed" << fix_after_hot << std::endl;

    my_gps->Disconnect();
    StopLoggingData();
    return 0;
}