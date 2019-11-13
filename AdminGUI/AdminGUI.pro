#-------------------------------------------------
#
# Project created by QtCreator 2019-11-13T03:21:39
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AdminGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        window_main.cpp \
    library.cpp \
    mysocket.cpp \
    menuclient.cpp \
    window_insert.cpp \
    window_insert_hall.cpp \
    window_city.cpp \
    window_query.cpp \
    window_delete.cpp \
    window_insert_client.cpp \
    window_modify.cpp \
    window_report.cpp \
    socketadmin.cpp

HEADERS += \
        window_main.h \
    library.h \
    mysocket.h \
    menuclient.h \
    window_insert.h \
    window_insert_hall.h \
    window_city.h \
    window_query.h \
    window_delete.h \
    window_insert_client.h \
    window_modify.h \
    window_report.h \
    socketadmin.h

FORMS += \
        window_main.ui \
    window_insert.ui \
    window_insert_hall.ui \
    window_city.ui \
    window_query.ui \
    window_delete.ui \
    window_insert_client.ui \
    window_modify.ui \
    window_report.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
