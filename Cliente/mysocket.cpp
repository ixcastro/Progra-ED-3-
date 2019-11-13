#include "mysocket.h"
#include <QString>
#include <QCoreApplication>
#include <QThread>
#include <QJsonArray>
#include<QJsonDocument>
#include<qjsonobject.h>
#include "menuclient.h"


static string  verifica= "";
mysocket::mysocket(QObject *parent) : QObject(parent){

}

void mysocket::doConnect(){

    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    library l;
    //-----------IP-SERVER---------------------//
    socket->connectToHost(l.getIp().c_str(), 1234);

    while(!socket->waitForConnected(3000)){
        cout << "error\n";
        //-----------IP-SERVER---------------------//
        socket->connectToHost(l.getIp().c_str(), 1234);
    }
}

void mysocket::readyRead()
{

    //socket->write(Data);
}

void mysocket::connected(){
    qDebug() << "Conectado!";

    while(true){



        cout<<"Digite su numero de cedula: ";
        cin>>ced;


        //------------ENVIO-DEL-DATO-CED---------//
        QJsonObject recordObject;
        recordObject.insert("Cedula", QJsonValue::fromVariant(ced));
        QJsonDocument doc(recordObject);
        socket->write(doc.toJson());
        socket->flush();
        socket->waitForReadyRead(1000);

        //------------RESPUESTA-AL-ENVIO-DE-LA-CED----//
        QByteArray Data = socket->readAll();


        if(Data == "T"){
            //-SE-CREA-EL-CLIENTE-----//
            menuClient mcl ;
            //-----BANDERA-PARA-SALIR-DEL-WHILE---/
            int flag = 0;
            //--------------COPIAR-----------------------//
            // indica que esta en proceso
            QJsonObject recordObject;
            recordObject.insert("Proceso", QJsonValue::fromVariant(1));
            QJsonDocument doc(recordObject);
            socket->write(doc.toJson());
            socket->waitForReadyRead(2000);
            QByteArray DataStop = socket->readAll();


            //----------------------------------------------------------//
            //----------------------- JM --------------------------------//
            //----------------------------------------------------------//
            int auxC = 0;
            while( DataStop == "T"){
                if(auxC==0){
                    cout<<"Estamos en mantenimiento. Intente mas tarde."<<endl;
                    auxC++;
                }

                QJsonObject recordObject;
                recordObject.insert("Proceso", QJsonValue::fromVariant(1));
                QJsonDocument doc(recordObject);
                socket->write(doc.toJson());
                socket->waitForReadyRead(3000);
                DataStop = socket->readAll();
            }
            //------------------------------------------------//

            while(flag !=5){

                //-----------CARGO-EL-MENU---------//
                flag = mcl.shareMenuCliente();
                switch (flag) {

                case 1:{//Consultar un precio

                    consultPrice();
                    break;
                }
                case 2: {//Consultar si un producto es de la canasta
                    consultIsBasket();
                    break;
                }
                case 3:{//Consultar el % impuesto de un producto.
                    consultTaxes();
                    break;
                }
                case 4:{// Comprar
                    buy();
                    break;
                }
                case 5:{//salir
                    cout<<"hasta la proxima"<<endl;
                    flag=5;
                    break;
                }

                }
            }

            // indica que SALE en proceso

            //----------------------------------------------------------//
            //----------------------- JM --------------------------------//
            //----------------------------------------------------------//
            QJsonObject recordObjectS;
            recordObjectS.insert("Proceso", QJsonValue::fromVariant(2));
            QJsonDocument docS(recordObjectS);
            socket->write(docS.toJson());
            socket->waitForReadyRead(2000);
             QByteArray DataStopd = socket->readAll();
            //----------------------------------------------------------//


        }else{

            //--------------COPIAR-----------------------//
            // indica que esta en proceso
            QJsonObject recordObject;
            recordObject.insert("Proceso", QJsonValue::fromVariant(1));
            QJsonDocument doc(recordObject);
            socket->write(doc.toJson());
            socket->waitForReadyRead(2000);
            QByteArray DataStop = socket->readAll();

            //----------------------------------------------------------//
            //----------------------- JM --------------------------------//
            //----------------------------------------------------------//
            int auxC = 0;
            while( DataStop == "T"){
                if(auxC==0){
                    cout<<"estamos en mantenimientointente mas tarde"<<endl;
                    auxC++;
                }

                QJsonObject recordObject;
                recordObject.insert("Proceso", QJsonValue::fromVariant(1));
                QJsonDocument doc(recordObject);
                socket->write(doc.toJson());
                socket->waitForReadyRead(3000);
                DataStop = socket->readAll();
            }
            //------------------------------------------------//

            menuClient mNCl;
            int xFlag = 0;
            while(xFlag != 5){
                xFlag = mNCl.shareMenuClienteNoRegistrado();
                switch(xFlag){
                case 1:{ //Consultar precio
                    consultPrice();
                    break;
                }
                case 2:{ //Consultar si un prod pertenece a CB
                    consultIsBasket();
                    break;
                }
                case 3:{ //Consultar impuesto
                    consultTaxes();
                    break;
                }
                case 4:{
                    registerClient(ced);
                    break;
                }
                case 5:{
                    cout<<"Hasta la proxima :)"<<endl;
                    break;
                }

                }
            }
            // indica que SALE en proceso
            //----------------------------------------------------------//
            //----------------------- JM --------------------------------//
            //----------------------------------------------------------//
            QJsonObject recordObjectS;
            recordObjectS.insert("Proceso", QJsonValue::fromVariant(2));
            QJsonDocument docS(recordObjectS);
            socket->write(docS.toJson());
            socket->waitForReadyRead(2000);
            QByteArray DataStopb = socket->readAll();

            //----------------------------------------------------------//
        }
    }
}


void mysocket::close(){
    socket->close();
}

void mysocket::bytesWritten(qint64 bytes)
{

}

void mysocket::disconnected()
{


    qDebug() << "Desconectado!";
}

void mysocket::consultPrice(){
    int codPas;
    int codMarca;
    int codFinalMarca;
    QJsonArray Prod;
    QJsonArray Marca;
    QByteArray DataPrice;
    int flagProd =0;
    int flagMarca =0;

    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PASILLO------//
    //-----------------INDICA-QUE-QUEREMOS-VER-LOS-PASILLOS--//
    QJsonObject recordObject;
    recordObject.insert("Pasillo", QJsonValue::fromVariant(1));
    QJsonDocument doc(recordObject);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);

    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
    QByteArray Data = socket->readAll();
    QJsonDocument itemDoc = QJsonDocument::fromJson(Data);
    QJsonArray pasillos = itemDoc.array();

    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //----------------IMPRIME-LOS-PASILLOS---------------//
    QString s = "";
    for(int i=0; i<pasillos.size(); i++){
        s +=  pasillos[i].toString();
    }

    cout<<s.toStdString();


    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
    cout<<"seleccione un cod de pasillo"<<endl;
    cin>>codPas;

    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectProducto;
    recordObjectProducto.insert("Producto", QJsonValue::fromVariant(codPas));
    QJsonDocument docProd(recordObjectProducto);
    socket->write(docProd.toJson());
    socket->waitForReadyRead(2000);


    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
    QByteArray DataProd = socket->readAll();
    QJsonDocument itemDocProd = QJsonDocument::fromJson(DataProd);
    Prod = itemDocProd.array();

    flagProd = Prod.size();

    //----------------------------//
    //-SI-EL-PASILLO-NO-ES-VALIDO-//
    //----------------------------//
    while (flagProd<=0){
        cout<<"pasillo invalido"<<endl;
        //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
        //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
        cout<<"seleccione un cod de pasillo valido"<<endl;
        cin>>codPas;

        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectProducto;
        recordObjectProducto.insert("Producto", QJsonValue::fromVariant(codPas));
        QJsonDocument docProd(recordObjectProducto);
        socket->write(docProd.toJson());
        socket->waitForReadyRead(2000);

        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
        QByteArray DataProd = socket->readAll();
        QJsonDocument itemDocProd = QJsonDocument::fromJson(DataProd);
        Prod = itemDocProd.array();
        flagProd = Prod.size();

    }


    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //------IMPRIME-LOS-PRODUCTOS-DEL-PASILLO-PEDIDO-------//
    QString auxProd = "";
    for(int i=0; i<Prod.size(); i++){
        auxProd +=  Prod[i].toString();
    }
    cout<<auxProd.toStdString();


    //////////////////MARCA/////////////////////////////

    //------SE-ESCRIBE-EL-JSON-PARA-LA-MARCA-DEL-PRODUCTO------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//

    cout<<"seleccione un cod de Producto"<<endl;
    cin>>codMarca;

    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectMarca;
    recordObjectMarca.insert("Marca", QJsonValue::fromVariant(codMarca));
    QJsonDocument docMarca(recordObjectMarca);
    socket->write(docMarca.toJson());
    socket->waitForReadyRead(2000);


    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-LAS-MARCAS------//
    QByteArray DataMarca = socket->readAll();
    QJsonDocument itemDocMarca = QJsonDocument::fromJson(DataMarca);
    Marca = itemDocMarca.array();

    flagMarca = Marca.size();

    //----------------------------//
    //-SI-EL-PRODCT-NO-ES-VALIDO-//
    //----------------------------//
    while (flagMarca<=0){
        cout<<"Cod Prod invalido"<<endl;
        //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
        //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
        cout<<"seleccione un cod de prod valido"<<endl;

        cin>>codMarca;

        //-------------OJO PARA LA COMPRATODO IGUAL PERO EL METODO
        // DEL RN QUE HAY QUE USAR ACA ES DIFERENTE
        //POR LO QUE HAY QUE CAMBIAR EL ROOT A MarcaCompra
        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectMarca;
        recordObjectMarca.insert("Marca", QJsonValue::fromVariant(codMarca));
        QJsonDocument docMarca(recordObjectMarca);
        socket->write(docMarca.toJson());
        socket->waitForReadyRead(2000);


        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-LAS-MARCAS------//
        QByteArray DataMarca = socket->readAll();
        QJsonDocument itemDocMarca = QJsonDocument::fromJson(DataMarca);
        Marca = itemDocMarca.array();

        flagMarca = Marca.size();

    }

    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //------IMPRIME-LAS-MARCAS-DEL-PRODUCTO-SELEC------//
    QString auxMarca = "";
    for(int i=0; i<Marca.size(); i++){
        auxMarca +=  Marca[i].toString();
    }
    cout<<auxMarca.toStdString();

    //------SE-ESCRIBE-EL-JSON-PARA-EL-PRECIO-DE-LA-MARCA------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//


    cout<<"seleccione un cod de Marca"<<endl;
    cin>>codFinalMarca;

    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectMarcaP;
    recordObjectMarcaP.insert("Precio", QJsonValue::fromVariant(codFinalMarca));
    QJsonDocument docMarcaP(recordObjectMarcaP);
    socket->write(docMarcaP.toJson());
    socket->waitForReadyRead(2000);
    //---------------LEE-PRECIO-----------------//
    DataPrice = socket->readAll();

    while(DataPrice == "0"){
        cout<<"cod de marca invalido"<<endl;
        cout<<"seleccione un cod de Marca Valido"<<endl;
        cin>>codFinalMarca;
        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectMarcaP;
        recordObjectMarcaP.insert("Precio", QJsonValue::fromVariant(codFinalMarca));
        QJsonDocument docMarcaP(recordObjectMarcaP);
        socket->write(docMarcaP.toJson());
        socket->waitForReadyRead(2000);
        //---------------LEE-PRECIO-----------------//
        DataPrice = socket->readAll();

    }
    cout<<"el precio del producto es "<<endl;
    cout<<DataPrice.toStdString()<<endl;
}

void mysocket::consultTaxes(){
    int codPas;
    int codMarca;
    int codFinalMarca;
    QJsonArray Prod;
    QJsonArray Marca;
    QByteArray DataPrice;
    int flagProd =0;
    int flagMarca =0;
    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PASILLO------//
    //-----------------INDICA-QUE-QUEREMOS-VER-LOS-PASILLOS--//
    QJsonObject recordObject;
    recordObject.insert("Pasillo", QJsonValue::fromVariant(1));
    QJsonDocument doc(recordObject);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);

    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
    QByteArray Data = socket->readAll();
    QJsonDocument itemDoc = QJsonDocument::fromJson(Data);
    QJsonArray pasillos = itemDoc.array();

    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //----------------IMPRIME-LOS-PASILLOS---------------//
    QString s = "";
    for(int i=0; i<pasillos.size(); i++){
        s +=  pasillos[i].toString();
    }

    cout<<s.toStdString();


    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
    cout<<"seleccione un cod de pasillo"<<endl;
    cin>>codPas;

    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectProducto;
    recordObjectProducto.insert("Producto", QJsonValue::fromVariant(codPas));
    QJsonDocument docProd(recordObjectProducto);
    socket->write(docProd.toJson());
    socket->waitForReadyRead(2000);


    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
    QByteArray DataProd = socket->readAll();
    QJsonDocument itemDocProd = QJsonDocument::fromJson(DataProd);
    Prod = itemDocProd.array();

    flagProd = Prod.size();

    //----------------------------//
    //-SI-EL-PASILLO-NO-ES-VALIDO-//
    //----------------------------//
    while (flagProd<=0){
        cout<<"pasillo invalido"<<endl;
        //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
        //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
        cout<<"seleccione un cod de pasillo valido"<<endl;
        cin>>codPas;

        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectProducto;
        recordObjectProducto.insert("Producto", QJsonValue::fromVariant(codPas));
        QJsonDocument docProd(recordObjectProducto);
        socket->write(docProd.toJson());
        socket->waitForReadyRead(2000);

        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
        QByteArray DataProd = socket->readAll();
        QJsonDocument itemDocProd = QJsonDocument::fromJson(DataProd);
        Prod = itemDocProd.array();
        flagProd = Prod.size();

    }


    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //------IMPRIME-LOS-PRODUCTOS-DEL-PASILLO-PEDIDO-------//
    QString auxProd = "";
    for(int i=0; i<Prod.size(); i++){
        auxProd +=  Prod[i].toString();
    }
    cout<<auxProd.toStdString();


    //////////////////MARCA/////////////////////////////

    //------SE-ESCRIBE-EL-JSON-PARA-LA-MARCA-DEL-PRODUCTO------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//

    cout<<"seleccione un cod de Producto"<<endl;
    cin>>codMarca;

    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectMarca;
    recordObjectMarca.insert("Marca", QJsonValue::fromVariant(codMarca));
    QJsonDocument docMarca(recordObjectMarca);
    socket->write(docMarca.toJson());
    socket->waitForReadyRead(2000);


    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-LAS-MARCAS------//
    QByteArray DataMarca = socket->readAll();
    QJsonDocument itemDocMarca = QJsonDocument::fromJson(DataMarca);
    Marca = itemDocMarca.array();

    flagMarca = Marca.size();

    //----------------------------//
    //-SI-EL-PRODCT-NO-ES-VALIDO-//
    //----------------------------//
    while (flagMarca<=0){
        cout<<"Cod Prod invalido"<<endl;
        //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
        //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
        cout<<"seleccione un cod de prod valido"<<endl;

        cin>>codMarca;

        //-------------OJO PARA LA COMPRATODO IGUAL PERO EL METODO
        // DEL RN QUE HAY QUE USAR ACA ES DIFERENTE
        //POR LO QUE HAY QUE CAMBIAR EL ROOT A MarcaCompra
        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectMarca;
        recordObjectMarca.insert("Marca", QJsonValue::fromVariant(codMarca));
        QJsonDocument docMarca(recordObjectMarca);
        socket->write(docMarca.toJson());
        socket->waitForReadyRead(2000);


        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-LAS-MARCAS------//
        QByteArray DataMarca = socket->readAll();
        QJsonDocument itemDocMarca = QJsonDocument::fromJson(DataMarca);
        Marca = itemDocMarca.array();

        flagMarca = Marca.size();

    }

    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //------IMPRIME-LAS-MARCAS-DEL-PRODUCTO-SELEC------//
    QString auxMarca = "";
    for(int i=0; i<Marca.size(); i++){
        auxMarca +=  Marca[i].toString();
    }
    cout<<auxMarca.toStdString();

    //------SE-ESCRIBE-EL-JSON-PARA-EL-PRECIO-DE-LA-MARCA------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//


    cout<<"seleccione un cod de Marca"<<endl;
    cin>>codFinalMarca;

    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectMarcaP;
    recordObjectMarcaP.insert("Porcentaje", QJsonValue::fromVariant(codFinalMarca));
    QJsonDocument docMarcaP(recordObjectMarcaP);
    socket->write(docMarcaP.toJson());
    socket->waitForReadyRead(2000);
    //---------------LEE-PRECIO-----------------//
    DataPrice = socket->readAll();

    while(DataPrice == "0"){
        cout<<"cod de marca invalido"<<endl;
        cout<<"seleccione un cod de Marca Valido"<<endl;
        cin>>codFinalMarca;
        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectMarcaP;
        recordObjectMarcaP.insert("Porcentaje", QJsonValue::fromVariant(codFinalMarca));
        QJsonDocument docMarcaP(recordObjectMarcaP);
        socket->write(docMarcaP.toJson());
        socket->waitForReadyRead(2000);
        //---------------LEE-PRECIO-----------------//
        DataPrice = socket->readAll();

    }
    cout<<"el porcentaje del producto es "<<endl;
    cout<<DataPrice.toStdString()<<endl;
}

void mysocket::consultIsBasket(){
    int codPas;
    int codMarca;
    int codFinalMarca;
    QJsonArray Prod;
    QJsonArray Marca;
    QByteArray DataPrice;
    int flagProd =0;
    int flagMarca =0;
    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PASILLO------//
    //-----------------INDICA-QUE-QUEREMOS-VER-LOS-PASILLOS--//
    QJsonObject recordObject;
    recordObject.insert("Pasillo", QJsonValue::fromVariant(1));
    QJsonDocument doc(recordObject);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);

    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
    QByteArray Data = socket->readAll();
    QJsonDocument itemDoc = QJsonDocument::fromJson(Data);
    QJsonArray pasillos = itemDoc.array();

    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //----------------IMPRIME-LOS-PASILLOS---------------//
    QString s = "";
    for(int i=0; i<pasillos.size(); i++){
        s +=  pasillos[i].toString();
    }

    cout<<s.toStdString();


    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
    cout<<"seleccione un cod de pasillo"<<endl;
    cin>>codPas;

    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectProducto;
    recordObjectProducto.insert("Producto", QJsonValue::fromVariant(codPas));
    QJsonDocument docProd(recordObjectProducto);
    socket->write(docProd.toJson());
    socket->waitForReadyRead(2000);


    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
    QByteArray DataProd = socket->readAll();
    QJsonDocument itemDocProd = QJsonDocument::fromJson(DataProd);
    Prod = itemDocProd.array();

    flagProd = Prod.size();

    //----------------------------//
    //-SI-EL-PASILLO-NO-ES-VALIDO-//
    //----------------------------//
    while (flagProd<=0){
        cout<<"pasillo invalido"<<endl;
        //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
        //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
        cout<<"seleccione un cod de pasillo valido"<<endl;
        cin>>codPas;

        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectProducto;
        recordObjectProducto.insert("Producto", QJsonValue::fromVariant(codPas));
        QJsonDocument docProd(recordObjectProducto);
        socket->write(docProd.toJson());
        socket->waitForReadyRead(2000);

        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
        QByteArray DataProd = socket->readAll();
        QJsonDocument itemDocProd = QJsonDocument::fromJson(DataProd);
        Prod = itemDocProd.array();
        flagProd = Prod.size();

    }


    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //------IMPRIME-LOS-PRODUCTOS-DEL-PASILLO-PEDIDO-------//
    QString auxProd = "";
    for(int i=0; i<Prod.size(); i++){
        auxProd +=  Prod[i].toString();
    }
    cout<<auxProd.toStdString();


    //////////////////MARCA/////////////////////////////

    //------SE-ESCRIBE-EL-JSON-PARA-LA-MARCA-DEL-PRODUCTO------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//

    cout<<"seleccione un cod de Producto"<<endl;
    cin>>codMarca;

    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectMarca;
    recordObjectMarca.insert("Marca", QJsonValue::fromVariant(codMarca));
    QJsonDocument docMarca(recordObjectMarca);
    socket->write(docMarca.toJson());
    socket->waitForReadyRead(2000);


    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-LAS-MARCAS------//
    QByteArray DataMarca = socket->readAll();
    QJsonDocument itemDocMarca = QJsonDocument::fromJson(DataMarca);
    Marca = itemDocMarca.array();

    flagMarca = Marca.size();

    //----------------------------//
    //-SI-EL-PRODCT-NO-ES-VALIDO-//
    //----------------------------//
    while (flagMarca<=0){
        cout<<"Cod Prod invalido"<<endl;
        //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
        //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
        cout<<"seleccione un cod de prod valido"<<endl;

        cin>>codMarca;

        //-------------OJO PARA LA COMPRATODO IGUAL PERO EL METODO
        // DEL RN QUE HAY QUE USAR ACA ES DIFERENTE
        //POR LO QUE HAY QUE CAMBIAR EL ROOT A MarcaCompra
        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectMarca;
        recordObjectMarca.insert("Marca", QJsonValue::fromVariant(codMarca));
        QJsonDocument docMarca(recordObjectMarca);
        socket->write(docMarca.toJson());
        socket->waitForReadyRead(2000);


        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-LAS-MARCAS------//
        QByteArray DataMarca = socket->readAll();
        QJsonDocument itemDocMarca = QJsonDocument::fromJson(DataMarca);
        Marca = itemDocMarca.array();

        flagMarca = Marca.size();

    }

    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //------IMPRIME-LAS-MARCAS-DEL-PRODUCTO-SELEC------//
    QString auxMarca = "";
    for(int i=0; i<Marca.size(); i++){
        auxMarca +=  Marca[i].toString();
    }
    cout<<auxMarca.toStdString();

    //------SE-ESCRIBE-EL-JSON-PARA-EL-PRECIO-DE-LA-MARCA------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//


    cout<<"seleccione un cod de Marca"<<endl;
    cin>>codFinalMarca;

    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectMarcaP;
    recordObjectMarcaP.insert("IsBasket", QJsonValue::fromVariant(codFinalMarca));
    QJsonDocument docMarcaP(recordObjectMarcaP);
    socket->write(docMarcaP.toJson());
    socket->waitForReadyRead(2000);
    //---------------LEE-PRECIO-----------------//
    DataPrice = socket->readAll();

    while(DataPrice == "0"){
        cout<<"cod de marca invalido"<<endl;
        cout<<"seleccione un cod de Marca Valido"<<endl;
        cin>>codFinalMarca;
        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectMarcaP;
        recordObjectMarcaP.insert("IsBasket", QJsonValue::fromVariant(codFinalMarca));
        QJsonDocument docMarcaP(recordObjectMarcaP);
        socket->write(docMarcaP.toJson());
        socket->waitForReadyRead(2000);
        //---------------LEE-PRECIO-----------------//
        DataPrice = socket->readAll();
    }
    cout<<DataPrice.toStdString()<<endl;

}

void mysocket::registerClient(int pId){
    string pName;
    string lastName;
    int pCityCode = 0;
    string pPhone = "";
    string pEmail = "";

    QJsonObject recordObject;

    cout<<"Digite su nombre: ";
    cin>>pName;

    cout<<"Digite su apellido: ";
    cin>>lastName;

    pName += " " + lastName;

    cout<<"Digite el codigo de su ciudad: ";
    cin>>pCityCode;

    cout<<"Digite su numero de telefono: ";
    cin>>pPhone;

    cout<<"DIgite su correo: ";
    cin>>pEmail;


    recordObject.insert("Cedula",QJsonValue::fromVariant(pId));
    recordObject.insert("Nombre",QString::fromStdString(pName));
    recordObject.insert("CodigoCiudad",QJsonValue::fromVariant(pCityCode));
    recordObject.insert("Phone", QString::fromStdString(pPhone));
    recordObject.insert("Correo",QString::fromStdString(pEmail));

    QJsonObject record;
    record.insert("Registrar",recordObject);

    QJsonDocument doc(record);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);

    //Recibo un mensaje de que el servidor almacenó los datos para registrar luego
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}

void mysocket::buy(){
    int codPas;
    int codMarca;
    int codCantMarca;
    int codFinalMarca;
    QJsonArray Prod;
    QJsonArray Marca;
    QJsonArray MarcaComp;
    QByteArray DataPrice;
    int flagProd =0;
    int flagMarca =0;
    int bye;

    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PASILLO------//
    //-----------------INDICA-QUE-QUEREMOS-VER-LOS-PASILLOS--//
    QJsonObject recordObject;
    recordObject.insert("Pasillo", QJsonValue::fromVariant(1));
    QJsonDocument doc(recordObject);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);

    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
    QByteArray Data = socket->readAll();
    QJsonDocument itemDoc = QJsonDocument::fromJson(Data);
    QJsonArray pasillos = itemDoc.array();

    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //----------------IMPRIME-LOS-PASILLOS---------------//
    QString s = "";
    for(int i=0; i<pasillos.size(); i++){
        s +=  pasillos[i].toString();
    }

    cout<<s.toStdString();


    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
    cout<<"seleccione un cod de pasillo"<<endl;
    cin>>codPas;

    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectProducto;
    recordObjectProducto.insert("Producto", QJsonValue::fromVariant(codPas));
    QJsonDocument docProd(recordObjectProducto);
    socket->write(docProd.toJson());
    socket->waitForReadyRead(2000);


    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
    QByteArray DataProd = socket->readAll();
    QJsonDocument itemDocProd = QJsonDocument::fromJson(DataProd);
    Prod = itemDocProd.array();

    flagProd = Prod.size();

    //----------------------------//
    //-SI-EL-PASILLO-NO-ES-VALIDO-//
    //----------------------------//
    while (flagProd<=0){
        cout<<"pasillo invalido"<<endl;
        //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
        //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
        cout<<"seleccione un cod de pasillo valido"<<endl;
        cin>>codPas;

        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectProducto;
        recordObjectProducto.insert("Producto", QJsonValue::fromVariant(codPas));
        QJsonDocument docProd(recordObjectProducto);
        socket->write(docProd.toJson());
        socket->waitForReadyRead(2000);

        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
        QByteArray DataProd = socket->readAll();
        QJsonDocument itemDocProd = QJsonDocument::fromJson(DataProd);
        Prod = itemDocProd.array();
        flagProd = Prod.size();

    }


    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //------IMPRIME-LOS-PRODUCTOS-DEL-PASILLO-PEDIDO-------//
    QString auxProd = "";
    for(int i=0; i<Prod.size(); i++){
        auxProd +=  Prod[i].toString();
    }
    cout<<auxProd.toStdString();


    //////////////////MARCA/////////////////////////////

    //------SE-ESCRIBE-EL-JSON-PARA-LA-MARCA-DEL-PRODUCTO------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//

    cout<<"seleccione un cod de Producto"<<endl;
    cin>>codMarca;

    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectMarca;
    recordObjectMarca.insert("PrecioCompra", QJsonValue::fromVariant(codMarca));
    QJsonDocument docMarca(recordObjectMarca);
    socket->write(docMarca.toJson());
    socket->waitForReadyRead(2000);


    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-LAS-MARCAS------//
    QByteArray DataMarca = socket->readAll();
    QJsonDocument itemDocMarca = QJsonDocument::fromJson(DataMarca);
    Marca = itemDocMarca.array();

    flagMarca = Marca.size();

    //----------------------------//
    //-SI-EL-PRODCT-NO-ES-VALIDO-//
    //----------------------------//
    while (flagMarca<=0){
        cout<<"Cod Prod invalido"<<endl;
        //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PRODUCTO------//
        //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
        cout<<"seleccione un cod de prod valido"<<endl;

        cin>>codMarca;

        //-------------OJO PARA LA COMPRATODO IGUAL PERO EL METODO
        // DEL RN QUE HAY QUE USAR ACA ES DIFERENTE
        //POR LO QUE HAY QUE CAMBIAR EL ROOT A MarcaCompra
        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectMarca;
        recordObjectMarca.insert("PrecioCompra", QJsonValue::fromVariant(codMarca));
        QJsonDocument docMarca(recordObjectMarca);
        socket->write(docMarca.toJson());
        socket->waitForReadyRead(2000);


        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-LAS-MARCAS------//
        QByteArray DataMarca = socket->readAll();
        QJsonDocument itemDocMarca = QJsonDocument::fromJson(DataMarca);
        Marca = itemDocMarca.array();

        flagMarca = Marca.size();

    }

    //--------------IMPRIMIMOS-EL-DATO-EN-PANTALLA---------//
    //------IMPRIME-LAS-MARCAS-DEL-PRODUCTO-SELEC------//
    QString auxMarca = "";
    for(int i=0; i<Marca.size(); i++){
        auxMarca +=  Marca[i].toString();
    }
    cout<<auxMarca.toStdString();




    //------SE-ESCRIBE-EL-JSON-PARA-EL-PRECIO-DE-LA-MARCA------//
    //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
    cout<<"seleccione el cod de marca que desea comprar "<<endl;
    cin>>codFinalMarca;
    //---------------CREAEL-JSON----------------//
    QJsonObject recordObjectMarcaCP;
    recordObjectMarcaCP.insert("MarcaAComprar", QJsonValue::fromVariant(codFinalMarca));
    QJsonDocument docMarcaCP(recordObjectMarcaCP);
    socket->write(docMarcaCP.toJson());
    socket->waitForReadyRead(2000);
    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
    DataProd = socket->readAll();
    string flagBrand = DataProd.toStdString();
    while(flagBrand == "F"){
        //------SE-ESCRIBE-EL-JSON-PARA-EL-PRECIO-DE-LA-MARCA------//
        //----------------PASAMOS-EL-PASILLO-DESEADO-------------//
        cout<<"Cod de marca invalido "<<endl;
        cout<<"seleccione el cod de marca valido "<<endl;
        cin>>codFinalMarca;
        //---------------CREAEL-JSON----------------//
        QJsonObject recordObjectMarcaCP;
        recordObjectMarcaCP.insert("MarcaAComprar", QJsonValue::fromVariant(codFinalMarca));
        QJsonDocument docMarcaCP(recordObjectMarcaCP);
        socket->write(docMarcaCP.toJson());
        socket->waitForReadyRead(2000);
        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
        DataProd = socket->readAll();
        flagBrand = DataProd.toStdString();
    }

    QByteArray DataProdX;
    cout<<"seleccione la cantidad que desea comprar "<<endl;
    cin>>codCantMarca;

    //-----------SI LA CANTIDAD A COMPRAR ES MAYOR A 0 -------//
    if(codFinalMarca>0){
        //---------------CREAEL-JSON----------------//

        QJsonObject recordObjectCL;
        recordObjectCL.insert("Cedula",QJsonValue::fromVariant(ced));
        recordObjectCL.insert("CantidadCompra", QJsonValue::fromVariant(codCantMarca));

        QJsonObject record;
        record.insert("Comprar", recordObjectCL);

        QJsonDocument docMarcaP(record);
        socket->write(docMarcaP.toJson());
        socket->waitForReadyRead(2000);
        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
        DataProdX = socket->readAll();
        while(DataProdX!="En el carrito"){
            cout<<"la cantidad seleccionada es mayor a la existente"<<endl;
            cout<<"la cantidad maxima de este producto es "+DataProdX.toStdString()<<endl;
            cout<<"detalle la cantidad que desea comprar "<<endl;
            cin>>codCantMarca;

            QJsonObject recordObjectCL;
            recordObjectCL.insert("Cedula",QJsonValue::fromVariant(ced));
            recordObjectCL.insert("CantidadCompra", QJsonValue::fromVariant(codCantMarca));

            QJsonObject record;
            record.insert("Comprar", recordObjectCL);

            QJsonDocument docMarcaP(record);
            socket->write(docMarcaP.toJson());
            socket->waitForReadyRead(2000);
            //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PRODUCTOS------//
            DataProdX = socket->readAll();

        }

    }




    cout<<DataProdX.toStdString()<<endl;
}


























