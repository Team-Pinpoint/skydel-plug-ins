set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB UBLOX_RECEIVER_PLUGIN_SRC *.cpp *.ui
    backend/src/*.cc
    backend/src/*.cpp
    backend/src/impl/*.cc
    backend/src/impl/list_ports/*.cc
    backend/src/commands/*.cpp
    )

add_library(ublox_receiver_plugin SHARED
    ${UBLOX_RECEIVER_PLUGIN_SRC}
    )

target_link_libraries(ublox_receiver_plugin PUBLIC
    Skydel::SkydelPlugin
    )

target_include_directories(ublox_receiver_plugin PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    backend/include/serial
    backend/include/ublox
    backend/include/ublox_commands
    )

set_target_properties(ublox_receiver_plugin PROPERTIES CXX_STANDARD 17)

install(TARGETS ublox_receiver_plugin DESTINATION ${PLUGIN_INSTALL_DIR})
