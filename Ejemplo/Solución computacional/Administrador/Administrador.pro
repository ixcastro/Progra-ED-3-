#-------------------------------------------------
#
# Project created by QtCreator 2019-05-16T10:54:07
#
#-------------------------------------------------

QT       += core
QT       += network

QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Administrador
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

#CONFIG += c++11

SOURCES += \
        atracciones.cpp \
        ciudades.cpp \
        clickablelabel.cpp \
        main.cpp \
        socket.cpp \
        ventanaagregar.cpp \
        ventanaconsultar.cpp \
        ventanaingreso.cpp \
        ventanamenu.cpp \
        ventanamodificar.cpp \
        ventanareportes.cpp

HEADERS += \
        atracciones.h \
        ciudades.h \
        clickablelabel.h \
        socket.h \
        ventanaagregar.h \
        ventanaconsultar.h \
        ventanaingreso.h \
        ventanamenu.h \
        ventanamodificar.h \
        ventanareportes.h

FORMS += \
        atracciones.ui \
        ciudades.ui \
        ventanaagregar.ui \
        ventanaconsultar.ui \
        ventanaingreso.ui \
        ventanamenu.ui \
        ventanamodificar.ui \
        ventanareportes.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    images.qrc
