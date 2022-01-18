
set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Built type for cmake")
# Find serial, if it hasn't already been found

if(NOT DEFINED serial_LIBRARIES OR NOT DEFINED serial_INCLUDE_DIRS)
  find_package(serial REQUIRED)
else (NOT DEFINED serial_LIBRARIES OR NOT DEFINED serial_INCLUDE_DIRS)
  set(serial_FOUND TRUE)
endif(NOT DEFINED serial_LIBRARIES OR NOT DEFINED serial_INCLUDE_DIRS)


if(serial_FOUND)
  include_directories(${serial_INCLUDE_DIRS})
  list(APPEND UBLOX_LINK_LIBS ${serial_LIBRARIES})
  if(UNIX AND NOT APPLE)
      list(APPEND UBLOX_LINK_LIBS rt)
  endif(UNIX AND NOT APPLE)
else(serial_FOUND)
  message(FATAL_ERROR "Serial library was not found.")
endif(serial_FOUND)

# Add the include folder to the include path
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add default source files
set(UBLOX_SRCS src/ublox.cpp)
set(UBLOX_COMMAND_SRCS src/commands/ColdStartCommand.cpp
                       src/commands/HotStartCommand.cpp
                       src/commands/WarmStartCommand.cpp
                       src/commands/CreateUbloxReciever.cpp)

# Find Boost, if it hasn't already been found
#set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS thread system REQUIRED)

link_directories(${Boost_LIBRARY_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

list(APPEND UBLOX_LINK_LIBS ${Boost_SYSTEM_LIBRARY}
                           ${Boost_THREAD_LIBRARY})


# Compile the Library
add_library(ublox STATIC ${UBLOX_SRCS})
target_include_directories(ublox PUBLIC include/ublox)

add_library(ublox_commands STATIC ${UBLOX_COMMAND_SRCS})
target_include_directories(ublox_commands PUBLIC include/ublox_commands)
target_include_directories(ublox_commands PUBLIC include/ublox)

target_link_libraries(ublox ${UBLOX_LINK_LIBS})
