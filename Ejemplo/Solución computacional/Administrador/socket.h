#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <iostream>

using namespace std;

class Socket : public QObject
{
    Q_OBJECT
public:
    explicit Socket(QObject *parent = nullptr);
    void conexion();

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    string controlador(string msg);

private:
    QTcpSocket *socket;
};

#endif // SOCKET_H
