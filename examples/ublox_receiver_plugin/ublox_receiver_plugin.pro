include (../common.pri)

QT       += gui widgets

INCLUDEPATH += \
    backend/include/serial \
    backend/include/ublox \
    backend/include/ublox_commands

SOURCES += \
    ublox_receiver_plugin.cpp \
    ublox_receiver_view.cpp \
    backend/src/*.cpp \
    backend/src/*.cc \
    backend/src/commands/*.cpp \
    backend/src/impl/*.cc

HEADERS += \
    ublox_receiver_plugin.h \
    ublox_receiver_view.h \
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
