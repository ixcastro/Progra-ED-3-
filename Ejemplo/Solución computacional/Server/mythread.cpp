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
        case -3:
            mensaje = trenes->mostrarAtracciones(arr[1],arr[2]);
            break;
        case -2:
            mensaje = trenes->mostrarCiudades(arr[1]);
            break;
        case -1:
            mensaje = trenes->ConsultarPaises();
            break;
        case 0:
            mensaje = trenes->ValidaAdministrador(arr[1]);
            //mensaje = trenes->ValidarUsuario(arr[1]);
            break;
        case 1:
            mensaje = trenes->AgregarPais(arr[1],arr[2]);
            break;
        case 2:
            mensaje = trenes->AgregarCiudad(arr[1],arr[2],arr[3]);
            break;
        case 3:
            mensaje = trenes->AgregarConexion(arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
            break;
        case 4:
            mensaje = trenes->AgregarTipoTren(arr[1]);
            break;
        case 5:
            mensaje = trenes->AgregarTren(arr[1],arr[2],arr[3],arr[4],arr[5],arr[6]);
            break;
        case 6:
            mensaje = trenes->AgregarRuta(arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);
            break;
        case 7:
            //Registrar la atraccion
            mensaje = trenes->AgregarAracciones(arr[1],arr[2],arr[3],arr[4],arr[5]);
            break;
        case 8:
            mensaje = trenes->ModificarPrecioConexion(arr[1],arr[2],arr[3],atoi(arr[4].c_str()));
            break;
        case 9:
            mensaje = trenes->ModificarTiempoConexion(arr[1],arr[2],arr[3],atoi(arr[4].c_str()));
            break;
        case 10:
            mensaje = trenes->ModificarNumAsientos(atoi(arr[1].c_str()),atoi(arr[2].c_str()),arr[3]);
            break;
        case 11:
            mensaje = trenes->ModificarPrecio(atoi(arr[1].c_str()),atoi(arr[2].c_str()),atoi(arr[3].c_str()),atoi(arr[4].c_str()));
            break;
        case 12:
            mensaje = trenes->ModificarTren(atoi(arr[1].c_str()),atoi(arr[2].c_str()),arr[3]);
            break;
        case 13:
            mensaje = trenes->ModificarEstadoMigratorio(arr[1],atoi(arr[2].c_str()));
            break;
        case 14:
            mensaje = trenes->ConsultarPrecioRuta(atoi(arr[1].c_str()),atoi(arr[2].c_str()),atoi(arr[3].c_str()));
            break;
        case 15:
            mensaje = trenes->ConsultarConexiones(arr[1]);
            break;
        case 16:{
            mensaje = trenes->ConsultarCiudades(arr[1]);
            break;
        }
        case 17:{
            int codTTTT;
            int codTren;
            istringstream iS (arr[1]);
            iS >> codTTTT;
            istringstream iSS (arr[2]);
            iSS >> codTren;
            mensaje = trenes->ConsultarRutas(codTTTT,codTren);
            break;
        } case 18:{
            int codTT;
            istringstream iss (arr[1]);
            iss >> codTT;
            mensaje = trenes->ConsultarTrenes(codTT);
            break;
        } case 19:
            mensaje = trenes->ReporteConsultarPaises();
            break;
        case 20:
            mensaje = trenes->ReporteConsultarCiudades();
            break;
        case 21:
            mensaje = trenes->ReporteConsultarConexiones();
            break;
        case 22:
            mensaje = trenes->ReporteConsultarTrenes();
            break;
        case 23:
            mensaje = trenes->ReporteConsultarPrecioConexion(arr[1],arr[2],arr[3]);
            break;
        case 24:
            mensaje = trenes->ReporteConsultarNumAsientosTren(atoi(arr[1].c_str()),atoi(arr[2].c_str()));
            break;
        case 25:
            mensaje = trenes->ReporteUltimoPaisInsertado();
            break;
        case 26:
            mensaje = trenes->ReporteUltimaCiudadInsertada();
            break;
        case 27:
            mensaje = trenes->ReporteUltimaConexionInsertada();
            break;
        case 28:
            mensaje = trenes->ReporteUltimoTipoTrenInsertado();
            break;
        case 29:
            mensaje = trenes->ReporteUltimoTrenInsertado();
            break;
        case 30:
            mensaje = trenes->reporteRutaMas();
            break;
        case 31:
            mensaje = trenes->reporteRutaMenos();
            break;
        case 32:
            mensaje = trenes->reportePaisMas();
            break;
        case 33:
            mensaje = trenes->reporteCiudadMas();
            break;
        case 34:
            mensaje = trenes->reporteUsuariosMas();
            break;
        case 35:
            mensaje = trenes->reporteUsuariosMenos();
            break;
        case 36:
            mensaje = trenes->reporteCantCompras();
            break;
        case 37:
            mensaje = trenes->reporteTrenMas();
            break;
        case 38:
            mensaje = trenes->reporteTrenMenos();
            break;
        case 50:
            mensaje = trenes->ValidarUsuario(arr[1]);
            break;
        case 51:
            mensaje = trenes->ConsultarPaises();
            break;
        case 52:
            mensaje = trenes->ConsultarCiudades(arr[1]);
            break;
        case 100:
            mensaje = trenes->ConsultarPrecioConexion(arr[1],arr[2],arr[3]);
            break;
        case 54:{
            int codTT;
            istringstream iss (arr[1]);
            iss >> codTT;
            mensaje = trenes->ConsultarTrenes(codTT);
            cout<<mensaje<<endl;
            break;
        } case 55:{
            int codTTT;
            int codT;
            istringstream iS (arr[1]);
            iS >> codTTT;
            istringstream iSS (arr[2]);
            iSS >> codT;
            mensaje = trenes->ConsultarNumAsientosTren(codTTT,codT);
            cout<<mensaje<<endl;
            break;
        } case 56:{
            int codTTTT;
            int codTren;
            istringstream iS (arr[1]);
            iS >> codTTTT;
            istringstream iSS (arr[2]);
            iSS >> codTren;
            mensaje = trenes->ConsultarRutas(codTTTT,codTren);
            cout<<mensaje<<endl;
            break;
        } case 57:{
            mensaje = trenes->ValidarEM(arr[1]);
            cout<<mensaje<<endl;
            break;
        } case 58:{
            mensaje = trenes->realizarReservacion(arr[1],arr[2],arr[3],arr[4],arr[5],arr[6]);
            break;
        } case 59:{
            mensaje = trenes->facturar(arr[1]);
            break;
        }
        case 60:{
                    int codTTTT;
                    int codTren;
                    istringstream iS (arr[1]);
                    iS >> codTTTT;
                    istringstream iSS (arr[2]);
                    iSS >> codTren;
                    mensaje = trenes->BuscarRuta(codTTTT,codTren,arr[3],arr[4],arr[5],arr[6]);
                    break;
        } case 61:{
                    mensaje = trenes->NuevaRuta(arr[1],arr[2],arr[3],arr[4]);
                    break;
        } case 62:{
                    mensaje = trenes->NuevaRutaMenorPrecio(arr[1],arr[2],arr[3],arr[4]);
                    break;
        } case 63:{
                    mensaje = trenes->NuevaRutaMenorTiempo(arr[1],arr[2],arr[3],arr[4]);
                    break;
                }
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

