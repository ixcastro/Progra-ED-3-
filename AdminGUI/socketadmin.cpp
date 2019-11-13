#include "socketadmin.h"

socketAdmin *socketAdmin::instance = new socketAdmin();

void socketAdmin::readyRead(){

}

void socketAdmin::connected(){

}

void socketAdmin::bytesWritten(qint64 bytes){

}

void socketAdmin::disconnected(){
    qDebug() << "Desconectado!";
}
void socketAdmin::doConnect(){

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

socketAdmin::socketAdmin(){
    doConnect();
}

socketAdmin *socketAdmin::getInstance(){
    return instance;
}

QJsonDocument socketAdmin::request(QJsonDocument doc){
    this->socket->write(doc.toJson());
    socket->waitForReadyRead();
    QByteArray data = socket->readAll();
    return QJsonDocument::fromJson(data);
}
