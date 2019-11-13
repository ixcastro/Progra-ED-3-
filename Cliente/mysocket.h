#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QtDebug>
#include <iostream>
#include <string>

using namespace std;


class mysocket : public QObject
{
    Q_OBJECT
public:
    explicit mysocket(QObject *parent = nullptr);
    void doConnect();

    //QByteArray leer();
    //void escribir(QByteArray escritura);
    void close();
    void consultPrice();
    void consultTaxes();
    void consultIsBasket();
    void registerClient(int);
    void buy();
    //void buy(int);
signals:

public slots:
    void readyRead();
    void connected();
    void disconnected();
    void bytesWritten(qint64);

private:
    QTcpSocket *socket;
    int ced;
};

#endif // MYSOCKET_H
