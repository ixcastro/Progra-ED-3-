#include "socket.h"

Socket::Socket(QObject *parent) :
    QObject(parent)
{
}

void Socket::conexion()
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));


    socket->connectToHost("localhost", 8080);
    if(!socket->waitForDisconnected(1000))
    {
        qDebug() << "";
    }else{
        qDebug() << "Termino";
    }
}

void Socket::connected()
{
    //qDebug() << "Connected!";

    //controlador();
}

void Socket::disconnected()
{
    socket->disconnectFromHost();
    //qDebug() << "Disconnected!";
}

void Socket::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes;
}

void Socket::readyRead()
{
    qDebug() << "Reading...";
    qDebug() << socket->readAll();
}

string Socket::controlador(string msg){
    cout<<msg<<endl;
    const char *mensajeServer = msg.c_str();
    socket->write(mensajeServer);
    cout<<"Mando el msg"<<endl;
    socket->flush();
    string mensajeRecibido ="";
    if(socket->waitForReadyRead(30000000)){
        QByteArray msgS = socket->readAll();
        QString msgQ;
        msgQ.append(msgS);
        mensajeRecibido = msgQ.toUtf8().constData();
    }
    else{
        qDebug() << "Servidor no disponible... Intente de nuevo";
    }
    socket->disconnectFromHost();
    return mensajeRecibido;
}


