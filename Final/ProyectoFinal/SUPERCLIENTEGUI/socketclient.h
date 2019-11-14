#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H
#include <QObject>
#include <QTcpSocket>
#include <QtDebug>
#include <iostream>
#include <string>
#include <QString>
#include <QCoreApplication>
#include <QThread>
#include <QJsonArray>
#include<QJsonDocument>
#include<qjsonobject.h>
#include "library.h"

using namespace std;

class SocketClient : public QObject{
private:
    static SocketClient *instance;
    QTcpSocket *socket;
    int ced;

    void doConnect();
    SocketClient();

signals:

public slots:
    void readyRead();
    void connected();
    void disconnected();
    void bytesWritten(qint64);

public:
    static SocketClient* getInstance();
    QJsonDocument request(QJsonDocument doc);
};

#endif // SOCKETCLIENT_H
