include (../common.pri)

QT       += gui widgets

SOURCES += \
    connect_receiver_view.cpp \
    constellation_selection_view.cpp \
    start_receiver_view.cpp \
    ublox_receiver_plugin.cpp \
    ublox_receiver_view.cpp

HEADERS += \
    connect_receiver_view.h \
    constellation_selection_view.h \
    start_receiver_view.h \
    ublox_receiver_plugin.h \
    ublox_receiver_view.h

FORMS += \
    connect_receiver_view.ui \
    constellation_selection_view.ui \
    start_receiver_view.ui \
    ublox_receiver_view.ui

DISTFILES += \
    ublox_receiver_plugin.json
