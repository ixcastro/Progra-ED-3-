#include "window_main.h"
#include "window_login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //window_main w;
    window_logIn w;
    w.show();

    return a.exec();
}
