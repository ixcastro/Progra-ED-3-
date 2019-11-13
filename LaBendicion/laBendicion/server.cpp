#include "server.h"
#include "sistematrenes.h"
Server::Server(ServicioDeTrenes *servicio, QObject *parent) :
    QTcpServer(parent)
{
    trenes = servicio;
}

void Server::StartServer()
{
    QTcpServer *server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(!this->listen(QHostAddress::Any,8080))
    {
        qDebug() << "No se pudo conectar el servidor";
    }
    else
    {
//        qDebug() << "Esperando un cliente...";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    //qDebug() << socketDescriptor << " Connecting...";
    int socket = (int)socketDescriptor;
    MyThread *thread = new MyThread(trenes, socket, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
