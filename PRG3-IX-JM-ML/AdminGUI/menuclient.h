#ifndef MENUCLIENT_H
#define MENUCLIENT_H
#include "library.h"
#include <qjsonobject.h>
class menuClient
{
public:
    menuClient();
    void salir();
    int menuModificacion();
    int menuConsultas();
    int menuReportes();
    void registerClient();
    void setFlag(bool pBool);
    bool getFlag();

private:
    bool flag = true;
    string BANNER ="XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    string LOGIN =" __    _____ _____ _____ _____\n"
                  "|  |  |     |   __|     |   | |\n"
                  "|  |__|  |  |  |  |-   -| | | |\n"
                  "|_____|_____|_____|_____|_|___|\n";

    string MENU = "::::    ::::: :::::::::: ::::    ::: :::    :::      \n"
                  "+:+:+: :+:+:+ :+:        :+:+:   :+: :+:    :+:      \n"
                  "+:+ +:+:+ +:+ +:+        :+:+:+  +:+ +:+    +:+      \n"
                  "+#+  +:+  +#+ +#++:++#   +#+ +:+ +#+ +#+    +:+      \n"
                  "+#+       +#+ +#+        +#+  +#+#+# +#+    +#+      \n"
                  "#+#       #+# #+#        #+#   #+#+# #+#    #+#      \n"
                  "###       ### ########## ###    ####  ########";
};

#endif // MENUCLIENT_H
