set(SERIAL_SCRS src/impl/unix.cc
                src/serial.cc)
set(UBLOX_SRCS src/ublox.cpp)
set(UBLOX_COMMAND_SRCS src/commands/StartCommand.cpp
                       src/commands/CreateUbloxReceiver.cpp
                       src/commands/currentFixCommand.cpp
                       src/commands/getTimeCommand.cpp
                       src/commands/getConfigurationCommand.cpp
                       src/commands/getPositionCommand.cpp)

# Find Boost, if it hasn't already been found
#set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS thread system REQUIRED)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()


link_directories(${Boost_LIBRARY_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

list(APPEND UBLOX_LINK_LIBS ${Boost_SYSTEM_LIBRARY}
                           ${Boost_THREAD_LIBRARY})


# Compile the Library
add_library(serial STATIC ${SERIAL_SCRS})
target_include_directories(serial PUBLIC include/serial)

add_library(ublox STATIC ${UBLOX_SRCS})
target_include_directories(ublox PUBLIC include/ublox)
target_include_directories(ublox PUBLIC include/serial)

add_library(ublox_commands STATIC ${UBLOX_COMMAND_SRCS})
target_include_directories(ublox_commands PUBLIC include/ublox_commands)
target_include_directories(ublox_commands PUBLIC include/ublox)
target_include_directories(ublox_commands PUBLIC include/serial)

target_link_libraries(ublox ${UBLOX_LINK_LIBS})

# Build Examples
# If asked to
option(UBLOX_BUILD_EXAMPLES "Build uBlox examples?" ON)
IF(UBLOX_BUILD_EXAMPLES)
    # Compile the ublox Test program
    add_executable(command_example examples/command_example.cpp)
    # Link the Test program to the ublox library
    target_link_libraries(command_example ublox ublox_commands serial ${UBLOX_LINK_LIBS})
ENDIF(UBLOX_BUILD_EXAMPLES)