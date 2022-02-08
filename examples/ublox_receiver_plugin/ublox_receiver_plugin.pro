include (../common.pri)

QT       += gui widgets

INCLUDEPATH += \
    backend/include/serial \
    backend/include/ublox \
    backend/include/ublox_commands

SOURCES += \
    connect_receiver_view.cpp \
    start_receiver_view.cpp \
    ublox_receiver_plugin.cpp \
    ublox_receiver_view.cpp \
    backend/src/*.cpp \
    backend/src/*.cc \
    backend/src/commands/*.cpp \
    backend/src/impl/*.cc \
    backend/src/impl/list_ports/*.cc

HEADERS += \
    connect_receiver_view.h \
    start_receiver_view.h \
    ublox_receiver_plugin.h \
    ublox_receiver_view.h \
    receiver_enums.h \
    backend/include/ublox_commands/*.h \
    backend/include/serial/*.h \
    backend/include/serial/impl/*.h \
    backend/include/ublox/*.h

FORMS += \
    connect_receiver_view.ui \
    start_receiver_view.ui \
    ublox_receiver_view.ui

DISTFILES += \
    ublox_receiver_plugin.json
