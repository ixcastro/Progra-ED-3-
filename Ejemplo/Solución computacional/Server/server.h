#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "mythread.h"
#include "sistematrenes.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(ServicioDeTrenes *servicio, QObject *parent = 0);
    void StartServer();
protected:
    void incomingConnection(qintptr socketDescriptor);
private:
    ServicioDeTrenes *trenes;

    friend class ServicioDeTrenes;
};

#endif // SERVER_H
