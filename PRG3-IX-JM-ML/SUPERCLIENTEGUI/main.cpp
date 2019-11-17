#include "w_login.h"
#include <QApplication>
#include "library.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    W_LOGIN w;
    w.show();
    return a.exec();
}
