#include "wlogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WLogin w;
    w.show();
    return a.exec();
}
