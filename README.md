[![Ubuntu CMake Build](https://github.com/Team-Pinpoint/skydel-plug-ins/actions/workflows/ubuntu_cmake_build.yml/badge.svg)](https://github.com/Team-Pinpoint/skydel-plug-ins/actions/workflows/ubuntu_cmake_build.yml)
[![Ubuntu QMake Build](https://github.com/Team-Pinpoint/skydel-plug-ins/actions/workflows/ubuntu_qmake_build.yml/badge.svg)](https://github.com/Team-Pinpoint/skydel-plug-ins/actions/workflows/ubuntu_qmake_build.yml)
[![Style Check](https://github.com/Team-Pinpoint/skydel-plug-ins/actions/workflows/style_check.yml/badge.svg)](https://github.com/Team-Pinpoint/skydel-plug-ins/actions/workflows/style_check.yml)

## Welcome to Team PinPoint's UBlox Receiver Plugin!

### Important Notes
Due to a more complex build environment, Team PinPoint's UBlox Receiver plugin only has support for Ubuntu 2020.

### Pre-compiled
Check out our release links on the right for a pre-compiled binary.

### Build Locally
First, make sure you have your build environment set up properly: [Skydel's Plugin documentation](https://skydel.gitbook.io/skydel-plug-ins-documentation/)

Next, `cd` to your project directory.

Install `uuid-dev` and `boost`
```
sudo apt install uuid-dev libboost-all-dev 
```

Then, install `blaze`
```
git clone https://github.com/parsa/blaze
cd blaze && mkdir build && cd build
cmake -DBLAZE_BLAS_MODE=ON .. && sudo make install
```

Build your code
```
cd /path/to/skydel-plug-ins # REPLACE WITH YOUR PATH
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

Finally, when moving your `.so`'s over from a build, make sure you move the `ublox-receiver.so`, too.


