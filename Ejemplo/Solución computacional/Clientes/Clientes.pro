#-------------------------------------------------
#
# Project created by QtCreator 2019-05-24T17:32:50
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Clientes
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
    atracciones.cpp \
    ciudades.cpp \
    clickablelabel.cpp \
        main.cpp \
    menu.cpp \
    consultar.cpp \
    reservar.cpp \
    agregarp.cpp \
    facturar.cpp \
    socket.cpp \
    ingresar.cpp \
    buscarr.cpp \
    nuevar.cpp

HEADERS += \
    atracciones.h \
    ciudades.h \
    clickablelabel.h \
    menu.h \
    consultar.h \
    reservar.h \
    agregarp.h \
    facturar.h \
    socket.h \
    ingresar.h \
    buscarr.h \
    nuevar.h

FORMS += \
    atracciones.ui \
    ciudades.ui \
    menu.ui \
    consultar.ui \
    reservar.ui \
    agregarp.ui \
    facturar.ui \
    ingresar.ui \
    buscarr.ui \
    nuevar.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resouces.qrc
