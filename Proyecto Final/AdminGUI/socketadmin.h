#ifndef SOCKETADMIN_H
#define SOCKETADMIN_H

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

class socketAdmin : public QObject
{
private:
    static socketAdmin *instance;
    QTcpSocket *socket;
    int ced;

    void doConnect();
    socketAdmin();

signals:

public slots:
    void readyRead();
    void connected();
    void disconnected();
    void bytesWritten(qint64);

public:
    static socketAdmin* getInstance();

    QJsonDocument request(QJsonDocument doc);
    QByteArray requestByte(QJsonDocument doc);

};

#endif // SOCKETADMIN_H
