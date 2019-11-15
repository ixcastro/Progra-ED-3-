#include "w_login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    W_LOGIN w;
    w.show();
    return a.exec();
}
