#ifndef QUEUECLIENT_H
#define QUEUECLIENT_H
#include "queuenode.h"

extern QJsonArray clientsQueue;

class QueueClient{
    QueueNode *frente;
    QueueNode *fondo;
public:
    QueueClient();
    void encolar(Client*);
    QueueNode *desencolar();
    bool isEmpty();
    bool exists(Client*);
    QueueNode* getFondo();
    void getClientsQueue();
};

#endif // QUEUECLIENT_H
