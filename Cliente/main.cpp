#include <QCoreApplication>
#include"mysocket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    mysocket *mCliente;
    mCliente = new mysocket();
    mCliente->doConnect();

    return a.exec();
}
