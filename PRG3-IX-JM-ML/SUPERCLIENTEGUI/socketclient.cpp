#include "socketclient.h"

SocketClient *SocketClient::instance = new SocketClient();

void SocketClient::readyRead(){

}

void SocketClient::connected(){

}

void SocketClient::bytesWritten(qint64 bytes){

}

void SocketClient::disconnected(){
    qDebug() << "Desconectado!";
}

void SocketClient::doConnect(){

    socket = new QTcpSocket(this);

    library l;
    //-----------IP-SERVER---------------------//
    socket->connectToHost(l.getIp().c_str(), 1234);

    while(!socket->waitForConnected(3000)){
        cout << "error\n";
        //-----------IP-SERVER---------------------//
        socket->connectToHost(l.getIp().c_str(), 1234);
    }
}

SocketClient::SocketClient(){
    doConnect();
}

SocketClient *SocketClient::getInstance(){
    return instance;
}

QJsonDocument SocketClient::request(QJsonDocument doc){
    this->socket->write(doc.toJson());
    socket->waitForReadyRead();
    QByteArray data = socket->readAll();
    return QJsonDocument::fromJson(data);
}
