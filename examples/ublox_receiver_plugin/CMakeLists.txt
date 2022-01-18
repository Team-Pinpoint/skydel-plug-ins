set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB UBLOX_RECEIVER_PLUGIN_SRC *.cpp *.ui)

add_library(ublox_receiver_plugin SHARED
    ${UBLOX_RECEIVER_PLUGIN_SRC}
    )

target_link_libraries(ublox_receiver_plugin PUBLIC
    Skydel::SkydelPlugin
    ublox
    ublox_commands
    )

target_include_directories(ublox_receiver_plugin PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

set_target_properties(ublox_receiver_plugin PROPERTIES CXX_STANDARD 17)

install(TARGETS ublox_receiver_plugin DESTINATION ${PLUGIN_INSTALL_DIR})
