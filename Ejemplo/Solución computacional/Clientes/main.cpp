#include "ingresar.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ingresar w;
    w.show();

    return a.exec();
}
