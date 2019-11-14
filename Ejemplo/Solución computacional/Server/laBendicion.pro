#-------------------------------------------------
#
# Project created by QtCreator 2019-05-14T16:03:00
#
#-------------------------------------------------

QT += core
QT += network
QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = laBendicion
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
        arbolb.cpp \
        listareserva.cpp \
        main.cpp \
        mythread.cpp \
        pagina.cpp \
        server.cpp \
        sistematrenes.cpp \
        ventana.cpp \
        ventanamenu.cpp \
    arboltrenesnew.cpp \
    listapaises.cpp \
    nododijkstra.cpp \
    nodoconexion.cpp \
    listaparaverticeskruskal.cpp \
    pila.cpp

HEADERS += \
        arbolb.h \
        listareserva.h \
        menu.h \
        mythread.h \
        nodoadministradorarbolb.h \
        nodociudadavl.h \
        nodoconexion.h \
        nodopaisabb.h \
        nodoreserva.h \
        nodoruta.h \
        nodotipotrenabb.h \
        nodotrenvl.h \
        nodousuarioarbolb.h \
        pagina.h \
        server.h \
        sistematrenes.h \
        stclave.h \
        ventana.h \
        ventanamenu.h \
    nodociudad.h \
    nodopais.h \
    listapaises.h \
    arboltrenesnew.h \
    nododijkstra.h \
    listaparaverticeskruskal.h \
    nodo.h \
    pila.h \
    nodoatracciones.h

FORMS += \
        ventana.ui \
        ventanamenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
