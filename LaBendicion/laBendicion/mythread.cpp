#include "mythread.h"
#include <sstream>

MyThread::MyThread(ServicioDeTrenes *servicio, int ID, QObject *parent) : QThread(parent){
    this->socketDescriptor = ID;
    trenes = servicio;
}

void MyThread::run(){
    // thread starts here
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    //connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()),Qt::DirectConnection);
    if(socket){
        controlador();
    }

    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop
    exec();
}

void MyThread::controlador()
{
    if(socket->waitForReadyRead(30000000)){
        QByteArray yo = socket->readAll();
        QString msg;
        msg.append(yo);
        string text = msg.toUtf8().constData();

        string arr[10];
        char separador = ';';
        int contador = 0;
        for(size_t p=0, q=0; p!=text.npos; p=q){
            arr[contador] = text.substr(p+(p!=0),(q=text.find(separador, p+1))-p-(p!=0));
            contador++;
        }
        int key = 0;
        istringstream (arr[0]) >> key;

        string mensaje = "";
        switch (key) {
        case 0:
            mensaje = trenes->ValidarUsuario(arr[1]);
            break;
        case 1:
            mensaje = trenes->ConsultarPaises();
            break;
        case 2:
            mensaje = trenes->ConsultarCiudades(atoi(arr[1].c_str()));
            break;
        case 3:
            mensaje = trenes->ConsultarConexiones(atoi(arr[1].c_str()),atoi(arr[2].c_str()));
            break;
        case 4:
            mensaje = trenes->ConsultarTrenes(atoi(arr[1].c_str()));
            break;
        case 5:
            mensaje = trenes->ConsultarRutas(atoi(arr[1].c_str()),atoi(arr[2].c_str()));
            break;
        case 6:
            mensaje = trenes->ConsultarNumAsientosTren(atoi(arr[1].c_str()),atoi(arr[2].c_str()));
            break;
        case 7:
            mensaje = trenes->ConsultarPrecioConexion(atoi(arr[1].c_str()),atoi(arr[2].c_str()),atoi(arr[3].c_str()));
            break;
        case 8:
            mensaje = trenes->realizarReservacion(arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
            break;
        case 9:
            mensaje = trenes->facturar(arr[1]);
            break;
        }
        const char *mensajeParaCliente = mensaje.c_str();

        socket->write(mensajeParaCliente);
        socket->flush();
    }else{
        qDebug()<<"No se envio nada";
    }
}

void MyThread::readyRead(){
    QByteArray Data = socket->readAll();

    qDebug() << socketDescriptor << " Data in: " << Data;

//    socket->write(Data);
//    socket->flush();
}

void MyThread::disconnected(){
    socket->deleteLater();
    exit(0);
}

