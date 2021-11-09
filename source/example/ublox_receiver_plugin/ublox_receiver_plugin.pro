include (../common.pri)

QT       += gui widgets

SOURCES += \
    start_receiver_view.cpp \
    ublox_receiver_plugin.cpp \
    ublox_receiver_view.cpp

HEADERS += \
    start_receiver_view.h \
    ublox_receiver_plugin.h \
    ublox_receiver_view.h

FORMS += \
    start_receiver_view.ui \
    ublox_receiver_view.ui

DISTFILES += \
    ublox_receiver_plugin.json
