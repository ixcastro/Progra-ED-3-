#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <iostream>
#include "sistematrenes.h"

using namespace std;

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(ServicioDeTrenes *servicio, int iID, QObject *parent = nullptr);
    void run();
    void controlador();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    int socketDescriptor;
    ServicioDeTrenes *trenes;

    friend class ServicioDeTrenes;
};

#endif // MYTHREAD_H
