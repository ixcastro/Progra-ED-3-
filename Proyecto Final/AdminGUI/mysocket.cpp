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
    int bye;

    while(true){

        cout<<"Ingrese su codigo de administrador: ";
        cin>>ced;
        bye = 0;

        //------------ENVIO-DEL-DATO-CED---------//
        QJsonObject recordObject;
        recordObject.insert("CodAdmin", QJsonValue::fromVariant(ced));
        QJsonDocument doc(recordObject);
        socket->write(doc.toJson());
        socket->flush();
        socket->waitForReadyRead(1000);

        //------------RESPUESTA-AL-ENVIO-DE-LA-CED----//
        QByteArray Data = socket->readAll();

        if(Data == "T"){
            menuClient mcl;
            bool check = true;
            while(check){
                cout<<"Seleccione un tipo de menu: "<<endl;
                cout<<"1. Menu de Modificacion "<<endl;
                cout<<"2. Menu de Consulta "<<endl;
                cout<<"3. Reportes."<<endl;
                cout<<"4. Salir."<<endl;
                int menuType;
                cin>>menuType;
                while( menuType <0 || menuType > 4 ){
                    cout<<"Seleccion invalida."<< endl<<endl;
                    cout<<"Seleccione un tipo de menu: "<<endl;
                    cout<<"1. Menu de Modificacion "<<endl;
                    cout<<"2. Menu de Consulta "<<endl;
                    cout<<"3. Reportes."<<endl;
                    cout<<"4. Salir."<<endl;
                    cin>>menuType;
                }
                switch(menuType){
                case 1:{
                    modificar();
                    break;
                }
                case 2:{
                    consultar();
                    break;
                }
                case 3:{
                    reportes();
                    break;
                }
                case 4:{
                    check = false;
                    break;
                }
                }
            }
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

bool mysocket::insertHall(int pCod, string pName){

    QJsonObject recordObjects;
    recordObjects.insert("CodPas",QJsonValue::fromVariant(pCod));
    recordObjects.insert("Nombre",QString::fromStdString(pName));
    QJsonObject record;
    record.insert("RegistrarPasillo",recordObjects);

    QJsonDocument docIN(record);

    socket->write(docIN.toJson());
    socket->waitForReadyRead(2000);

    QByteArray Data = socket->readAll();
    if (Data == "T"){
        //porque ya existe el pasillo y no se va a insertar
        return false;
    } else {
        return true;
    }
}

void mysocket::insertHall(){

    int pCod;
    //    int pCod;
    string pName;
    cout<<"Inserte el cod del pasillo"<<endl;
    cin>>pCod;

    QJsonObject recordObject;
    recordObject.insert("PasilloInsert", QJsonValue::fromVariant(pCod));
    QJsonDocument doc(recordObject);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
    QByteArray Data = socket->readAll();
    while(Data == "T"){
        cout<<"Ese pasillo ya existe.."<<endl;
        cout<<"Dijite un cod de pasillo diferente"<<endl;
        cin>>pCod;
        QJsonObject recordObject;
        recordObject.insert("PasilloInsert", QJsonValue::fromVariant(pCod));
        QJsonDocument doc(recordObject);
        socket->write(doc.toJson());
        socket->waitForReadyRead(2000);
        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
        Data = socket->readAll();
    }

    cout<<"Inserte el nombre del pasillo"<<endl;
    cin>>pName;

    QJsonObject recordObjects;
    recordObjects.insert("CodPas",QJsonValue::fromVariant(pCod));
    recordObjects.insert("Nombre",QString::fromStdString(pName));
    QJsonObject record;
    record.insert("RegistrarPasillo",recordObjects);

    QJsonDocument docIN(record);
    socket->write(docIN.toJson());
    socket->waitForReadyRead(2000);

    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;

}

void mysocket::insertProduct(){
    int pCodProd;
    string pNameProd;

    int pCod;
    //    int pCod;
    string pName;
    cout<<"Inserte el cod del pasillo"<<endl;
    cin>>pCod;


    QJsonObject recordObject1;
    recordObject1.insert("PasilloInsert", QJsonValue::fromVariant(pCod));
    QJsonDocument doc1(recordObject1);
    socket->write(doc1.toJson());
    socket->waitForReadyRead(2000);
    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
    QByteArray Data = socket->readAll();
    while(Data != "T"){
        cout<<"Inserte el nombre del pasillo"<<endl;
        cin>>pName;
        QJsonObject recordObject2;
        recordObject2.insert("CodPas",QJsonValue::fromVariant(pCod));
        recordObject2.insert("Nombre",QString::fromStdString(pName));
        QJsonObject record2;
        record2.insert("RegistrarPasillo",recordObject2);
        QJsonDocument docIN(record2);
        socket->write(docIN.toJson());
        socket->waitForReadyRead(2000);

        QByteArray data = socket->readAll();
        cout<<data.toStdString()<<endl;
        Data = "T";
    }


    cout<<"Inserte el cod del producto"<<endl;
    cin>>pCodProd;

    QJsonObject recordObjects;
    recordObjects.insert("CodPas",QJsonValue::fromVariant(pCod));
    recordObjects.insert("CodProd",QJsonValue::fromVariant(pCodProd));
    QJsonObject record;
    record.insert("ProdInser",recordObjects);
    QJsonDocument docINt(record);
    socket->write(docINt.toJson());
    socket->waitForReadyRead(2000);

    QByteArray datain = socket->readAll();

    while(datain.toStdString()=="T"){

        cout<<"Ese cod de prodicto ya existe.."<<endl;
        cout<<"Dijite un cod de producto diferente"<<endl;
        cin>>pCodProd;
        recordObjects.insert("CodProd",QJsonValue::fromVariant(pCodProd));
        record.insert("ProdInser",recordObjects);
        QJsonDocument docINt(record);
        socket->write(docINt.toJson());
        socket->waitForReadyRead(2000);

    }

    cout<<"Inserte el nombre del producto"<<endl;
    cin>> pNameProd;

    QJsonObject recordObjec;
    recordObjec.insert("nameProd",QString::fromStdString(pNameProd));
    recordObjec.insert("Iprod",QJsonValue::fromVariant(pCodProd));
    recordObjec.insert("Ihall",QJsonValue::fromVariant(pCod));
    QJsonObject recor;
    recor.insert("ProdInserProd",recordObjec);
    QJsonDocument doi(recor);
    socket->write(doi.toJson());
    socket->waitForReadyRead(2000);
    QByteArray DataL = socket->readAll();
    cout<<DataL.toStdString()<<endl;

}

void mysocket::insertBrand(){

    int brandCode = 0;
    string name = "";
    int quantity = 0;
    int price = 0;
    string isBask = "";

    int pCodProd;
    string pNameProd;

    int pCod;
    //    int pCod;
    string pName;
    cout<<"Inserte el cod del pasillo"<<endl;
    cin>>pCod;


    QJsonObject recordObject1;
    recordObject1.insert("PasilloInsert", QJsonValue::fromVariant(pCod));
    QJsonDocument doc1(recordObject1);
    socket->write(doc1.toJson());
    socket->waitForReadyRead(2000);
    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
    QByteArray Data = socket->readAll();
    while(Data.toStdString().compare("T") != 0){
        cout<<"Inserte el nombre del pasillo"<<endl;
        cin>>pName;
        QJsonObject recordObject2;
        recordObject2.insert("CodPas",QJsonValue::fromVariant(pCod));
        recordObject2.insert("Nombre",QString::fromStdString(pName));
        QJsonObject record2;
        record2.insert("RegistrarPasillo",recordObject2);
        QJsonDocument docIN(record2);
        socket->write(docIN.toJson());
        socket->waitForReadyRead(2000);

        QByteArray data = socket->readAll();
        cout<<data.toStdString()<<endl;
        Data = "T";
    }


    cout<<"Inserte el cod del producto"<<endl;
    cin>>pCodProd;

    QJsonObject recordObjects;
    recordObjects.insert("CodPas",QJsonValue::fromVariant(pCod));
    recordObjects.insert("CodProd",QJsonValue::fromVariant(pCodProd));
    QJsonObject record;
    record.insert("ProdInser",recordObjects);
    QJsonDocument docINt(record);
    socket->write(docINt.toJson());
    socket->waitForReadyRead(2000);

    QByteArray datain = socket->readAll();

    while(datain.toStdString()!="T"){// si el prod no existe

        cout<<"Inserte el nombre del producto"<<endl;
        cin>> pNameProd;

        QJsonObject recordObjec;
        recordObjec.insert("nameProd",QString::fromStdString(pNameProd));
        recordObjec.insert("Iprod",QJsonValue::fromVariant(pCodProd));
        recordObjec.insert("Ihall",QJsonValue::fromVariant(pCod));
        QJsonObject recor;
        recor.insert("ProdInserProd",recordObjec);
        QJsonDocument doi(recor);
        socket->write(doi.toJson());
        socket->waitForReadyRead(2000);
        datain = "T";

    }// si el produto existe??

    //aca hay un error
    cout<<"Dijite el cod de la marca"<<endl;
    cin>>  brandCode;

    QJsonObject recordObjec4;
    recordObjec4.insert("Iprod",QJsonValue::fromVariant(pCodProd));
    recordObjec4.insert("Ihall",QJsonValue::fromVariant(pCod));
    recordObjec4.insert("IcodBran",QJsonValue::fromVariant(brandCode));
    QJsonObject recor4;
    recor4.insert("inCodBrand",recordObjec4);
    QJsonDocument doi4(recor4);
    socket->write(doi4.toJson());
    socket->waitForReadyRead(2000);
    QByteArray datain4 = socket->readAll();
    while(datain4=="T"){
        cout<<"El codigo de marca ya existe, digite uno nuevo: ";
        cin>>brandCode;
        QJsonObject recordObjec4;
        recordObjec4.insert("Iprod",QJsonValue::fromVariant(pCodProd));
        recordObjec4.insert("Ihall",QJsonValue::fromVariant(pCod));
        recordObjec4.insert("IcodBran",QJsonValue::fromVariant(brandCode));
        QJsonObject recor4;
        recor4.insert("inCodBrand",recordObjec4);
        QJsonDocument doi4(recor4);
        socket->write(doi4.toJson());
        socket->waitForReadyRead(2000);
        datain4 = socket->readAll();
    }
    cout<<"Digite le nombre de la marca: ";
    cin>>name;

    cout<<"Digite la cantidad de productos que desea agregar en gondola: ";
    cin>>quantity;

    while(quantity<0){
        cout<<"Cantidad incorrecta, digite una nueva: ";
        cin>>quantity;
    }

    cout<<"Digite el precio del producto: ";
    cin>>price;

    while(price <= 0){
        cout<<"Precio incorrecto, digite una nueva: ";
        cin>>price;
    }
    QJsonObject recordObjec5;
    recordObjec5.insert("Iprod",QJsonValue::fromVariant(pCodProd));
    recordObjec5.insert("Ihall",QJsonValue::fromVariant(pCod));
    recordObjec5.insert("IcodBran",QJsonValue::fromVariant(brandCode));
    recordObjec5.insert("Icantidad",QJsonValue::fromVariant(quantity));
    recordObjec5.insert("Iprecio",QJsonValue::fromVariant(price));
    recordObjec5.insert("Nombre",QString::fromStdString(name));
    QJsonObject recor5;
    recor5.insert("inCreateBrad",recordObjec5);
    QJsonDocument doi5(recor5);
    socket->write(doi5.toJson());
    socket->waitForReadyRead(2000);
    QByteArray datain5 = socket->readAll();
    cout<<datain5.toStdString()<<endl;


    cout<<"Digite la cantidad de productos que desea agregar al inventario: ";
    cin>>quantity;

    while(quantity<0){
        cout<<"Cantidad incorrecta, digite una nueva: ";
        cin>>quantity;
    }

    cout<<"El producto pertenece a canasta basica (S/N)? ";
    cin>>isBask;

    if(isBask!="S"){
        isBask = "N";
    }

    QJsonObject recordObjec6;
    recordObjec6.insert("Iprod",QJsonValue::fromVariant(pCodProd));
    recordObjec6.insert("Ihall",QJsonValue::fromVariant(pCod));
    recordObjec6.insert("IcodBran",QJsonValue::fromVariant(brandCode));
    recordObjec6.insert("Icantidad",QJsonValue::fromVariant(quantity));
    recordObjec6.insert("IisBask",QString::fromStdString(isBask));
    recordObjec6.insert("Nombre",QString::fromStdString(name));
    QJsonObject recor6;
    recor6.insert("inCreateBradInv",recordObjec6);
    QJsonDocument doi6(recor6);
    socket->write(doi6.toJson());
    socket->waitForReadyRead(2000);
    QByteArray datain6 = socket->readAll();
    cout<<datain6.toStdString()<<endl;



}

void mysocket::setPrice(){

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

    int newPrice;
    cout<<"digite el nuevo precio del producto "<<endl;
    cin>> newPrice;

    QJsonObject recordObjec6;
    recordObjec6.insert("Ihall",QJsonValue::fromVariant(codPas));
    recordObjec6.insert("Icodprod",QJsonValue::fromVariant(codMarca));
    recordObjec6.insert("IcodBran",QJsonValue::fromVariant(codFinalMarca));
    recordObjec6.insert("Iprecio",QJsonValue::fromVariant(newPrice));

    QJsonObject recor6;
    recor6.insert("newPrecio",recordObjec6);
    QJsonDocument doi6(recor6);
    socket->write(doi6.toJson());
    socket->waitForReadyRead(2000);
    QByteArray datain6 = socket->readAll();
    cout<<datain6.toStdString()<<endl;

}

void mysocket::serPorcent(){
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

    string newPrice;
    cout<<"digite el nuevo porcentaje "<<endl;
    cin>> newPrice;

    QJsonObject recordObjec6;
    recordObjec6.insert("Ihall",QJsonValue::fromVariant(codPas));
    recordObjec6.insert("Icodprod",QJsonValue::fromVariant(codMarca));
    recordObjec6.insert("IcodBran",QJsonValue::fromVariant(codFinalMarca));
    recordObjec6.insert("Iprecio",QString::fromStdString(newPrice));

    QJsonObject recor6;
    recor6.insert("newProcent",recordObjec6);
    QJsonDocument doi6(recor6);
    socket->write(doi6.toJson());
    socket->waitForReadyRead(2000);
    QByteArray datain6 = socket->readAll();
    cout<<datain6.toStdString()<<endl;

}

void mysocket::setBasket(){
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

    string newPrice;
    cout<<"digite la nueva canasta (S/N) "<<endl;
    cin>> newPrice;

    if(newPrice!="S"){
        newPrice = "N";
    }

    QJsonObject recordObjec6;
    recordObjec6.insert("Ihall",QJsonValue::fromVariant(codPas));
    recordObjec6.insert("Icodprod",QJsonValue::fromVariant(codMarca));
    recordObjec6.insert("IcodBran",QJsonValue::fromVariant(codFinalMarca));
    recordObjec6.insert("Icanasta",QString::fromStdString(newPrice));

    QJsonObject recor6;
    recor6.insert("newCanasta",recordObjec6);
    QJsonDocument doi6(recor6);
    socket->write(doi6.toJson());
    socket->waitForReadyRead(2000);
    QByteArray datain6 = socket->readAll();
    cout<<datain6.toStdString()<<endl;

}

void mysocket::registrarClientes(){
    QJsonObject recordObj;
    recordObj.insert("RegistrarCliente","T");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}


//-----------------------------------------Para el menu------------------------------------

void mysocket::modificar(){


    //--------------COPIAR-----------------------//
    int flag = 0;
    menuClient mcl;
    QJsonObject recordObject;

    recordObject.insert("StopClient", QJsonValue::fromVariant(1));
    QJsonDocument doc(recordObject);
    socket->write(doc.toJson());
    socket->flush();

    socket->waitForReadyRead(1000);
    QByteArray Data = socket->readAll();


    int w = 0;
    //-----------Pregunta si el clinete esta en proceso-----//
    while( Data.toStdString() == "T"){// significa que esta en proceso

        QJsonObject recordObject;
        recordObject.insert("StopClient", QJsonValue::fromVariant(1));
        QJsonDocument doc(recordObject);
        socket->write(doc.toJson());
        socket->flush();
        socket->waitForReadyRead(4000000);
        Data = socket->readAll();
        if(w==0){
            cout<<"Un cliente esta en proceso espere"<<endl;
            w++;
        }

    }
    //-----------detiene al clinete al clinete comprar-----//
    QJsonObject recordObjectSN;
    recordObjectSN.insert("StopClienteNow", QJsonValue::fromVariant(1));
    QJsonDocument docSN(recordObjectSN);
    socket->write(docSN.toJson());
    socket->flush();

    //-------------------------------------//

    while(flag !=8){

        //-----------CARGO-EL-MENU---------//
        flag = mcl.menuModificacion();
        switch (flag) {

        case 1:{
            //insertar pasillo
            insertHall();
            break;
        }
        case 2: {
            //insertar producto
            insertProduct();
            break;
        }
        case 3:{
            //insertar marca
            insertBrand();
            break;
        }
        case 4:{
            //insertar cliente
            registrarClientes();
            break;
        }
        case 5:{
            //modificar precio
            setPrice();
            break;
        }
        case 6:{
            //modificar porcentaje de impuesto
            serPorcent();
            break;
        }
        case 7:{
            //modificar canasta basica
            setBasket();
            break;
        }
        case 8:{//salir
            //--------------COPIAR-----------------------//
            //-----------permite al clinete comprar-----//
            QJsonObject recordObjectSN;
            recordObjectSN.insert("StopClienteNow", QJsonValue::fromVariant(2));
            QJsonDocument docSN(recordObjectSN);
            socket->write(docSN.toJson());
            socket->flush();
            socket->waitForReadyRead(1000);
            break;
            //-------------------------------------//
        }
        }

    }
}

void mysocket::consultar(){
    menuClient mcl;
    int xFlag = 0;
    while(xFlag != 7){
        xFlag = mcl.menuConsultas();
        switch(xFlag){
        case 1:{ //Consultar precio
            consultPrice();// ya esta
            break;
        }
        case 2:{ //Consultar si un prod pertenece a CB
            consultIsBasket();// ya esta
            break;
        }
        case 3:{ //Consultar impuesto
            consultTaxes();// ya esta
            break;
        }
        case 4:{//facturar
            facturar();
            break;
        }
        case 5:{//revisasr gondolas
            break;
        }
        case 6:{//verificar inventario
            verificarInventario();
            break;
        }
        case 7:{//Volver
            break;
        }
        }
    }
}

void mysocket::reportes(){
    menuClient mcl;
    int xFlag = 0;
    while(xFlag != 15){
        xFlag = mcl.menuReportes();
        switch(xFlag){
        case 1:{
            //Pasillo mas visitado
            pasilloMasVisitado();
            break;
        }
        case 2:{
            //Pasillo menos visitado
            pasilloMenosVisitado();
            break;
        }
        case 3:{
            //Marca mas vendida
            marcasMasVendidas();
            break;
        }
        case 4:{
            //Producto mas vendido en pasillo
            productosMasVendidosPasillo();
            break;
        }
        case 5:{
            //Cliente mas compro
            clienteMasCompro();
            break;
        }
        case 6:{
            //Cliente menos compro
            clienteMenosCompro();
            break;
        }
        case 7:{
            //Producto mas cargo gondolas
            productoMasCargoGondola();
            break;
        }
        case 8:{
            //Cliente mas facturo
            clienteMasFacturo();
            break;
        }
        case 9:{
            //Marcas de un producto
            marcasProducto();
            break;
        }
        case 10:{
            //Factura mayor monto
            facturaMayorMonto();
            break;
        }
        case 11:{
            //Productos de un pasillo
            productosPasillo();
            break;
        }
        case 12:{
            //Clientes super
            clientesSuper();
            break;
        }
        case 13:{
            //Pasillos super
            pasillosSuper();
            break;
        }
        case 14:{
            //Volver
            inventarioSuper();
            break;
        }
        case 15:{
            break;
        }
        }
    }
}

void mysocket::verificarInventario(){
    QJsonObject recordObj;
    recordObj.insert("VerificarInventario","T");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);

    QByteArray data = socket->readAll();

    if(data.toStdString() == "No"){
        cout<<"No hay productos para verificar inventario."<<endl;
    }else{
        while(data.toStdString() != "Inventario verificado"){
            cout<<data.toStdString()<<endl;
            int cant = 0;
            cout<<"Digite la cantidad de productos que desea cargar al inventario: ";
            cin>>cant;
            while(cant<=0){
                cout<<"Cantidad incorrecta. Digite una nueva: ";
                cin>>cant;
            }
            QJsonObject c;
            cout<<"Cant "<<to_string(cant)<<endl;
            c.insert("Cantidad",QJsonValue::fromVariant(cant));
            QJsonDocument d(c);
            socket->write(d.toJson());
            socket->waitForReadyRead(2000);
            data = socket->readAll();
        }
        cout<<data.toStdString()<<endl;
    }
}

void mysocket::pasilloMasVisitado(){
    QJsonObject recordObj;
    recordObj.insert("Reporte","PasilloMasVisitado");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}

void mysocket::pasilloMenosVisitado(){
    QJsonObject recordObj;
    recordObj.insert("Reporte","PasilloMenosVisitado");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}

void mysocket::marcasMasVendidas(){
    QJsonObject recordObj;
    recordObj.insert("Reporte","MarcaMasVendida");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}

void mysocket::productosMasVendidosPasillo(){

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

    //Solicito la lista de pasillos
    int pCod;
    string pName;
    cout<<"Inserte el codigo del pasillo del que desea el reporte: ";
    cin>>pCod;

    QJsonObject val;
    val.insert("PasilloInsert", QJsonValue::fromVariant(pCod));
    QJsonDocument dVal(val);
    socket->write(dVal.toJson());
    socket->waitForReadyRead(2000);

    QByteArray data = socket->readAll(); //T si existe, F si no existe
    while(data != "T"){
        cout<<"El codigo del pasillo es incorrecto. ";
        cout<<"Dijite un cod de pasillo diferente: ";
        cin>>pCod;
        QJsonObject recordObject;
        recordObject.insert("PasilloInsert", QJsonValue::fromVariant(pCod));
        QJsonDocument doc(recordObject);
        socket->write(doc.toJson());
        socket->waitForReadyRead(2000);
        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
        data = socket->readAll();
    }
    QJsonObject recordObj;

    recordObj.insert("xPasillo",QJsonValue::fromVariant(pCod));
    recordObj.insert("Reporte","ProductoMasVendidoPasillo");
    QJsonDocument docu(recordObj);
    socket->write(docu.toJson());
    socket->waitForReadyRead(2000);
    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
    QByteArray respuesta = socket->readAll();
    cout<<respuesta.toStdString()<<endl;
}

void mysocket::clienteMasCompro(){
    QJsonObject recordObj;
    recordObj.insert("Reporte","ClienteMasCompro");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}

void mysocket::clienteMenosCompro(){
    QJsonObject recordObj;
    recordObj.insert("Reporte","ClienteMenosCompro");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}

void mysocket::productoMasCargoGondola(){
    QJsonObject recordObj;
    recordObj.insert("Reporte","ProductoMasCargoGondola");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}

void mysocket::clienteMasFacturo(){
    QJsonObject recordObj;
    recordObj.insert("Reporte","ClienteMasFacturo");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}














void mysocket::marcasProducto(){

    QJsonObject recordObject;
    recordObject.insert("Pasillo", QJsonValue::fromVariant(1));
    QJsonDocument doc(recordObject);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);

    QByteArray Data = socket->readAll();
    QJsonDocument itemDoc = QJsonDocument::fromJson(Data);
    QJsonArray pasillos = itemDoc.array();

    QString s = "";
    for(int i=0; i<pasillos.size(); i++){
        s +=  pasillos[i].toString();
    }
    cout<<s.toStdString();

    //Solicito la lista de pasillos
    int pCod;
    string pName;
    cout<<"Inserte el codigo del pasillo: ";
    cin>>pCod;

    QJsonObject val;
    val.insert("PasilloInsert", QJsonValue::fromVariant(pCod));
    QJsonDocument dVal(val);
    socket->write(dVal.toJson());
    socket->waitForReadyRead(2000);

    QByteArray data = socket->readAll(); //T si existe, F si no existe
    while(data != "T"){
        cout<<"El codigo del pasillo es incorrecto. ";
        cout<<"Dijite un cod de pasillo diferente: ";
        cin>>pCod;
        QJsonObject recordObject;
        recordObject.insert("PasilloInsert", QJsonValue::fromVariant(pCod));
        QJsonDocument doc(recordObject);
        socket->write(doc.toJson());
        socket->waitForReadyRead(2000);
        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
        data = socket->readAll();
    }

    QJsonObject recProd;
    recProd.insert("Producto",QJsonValue::fromVariant(pCod));
    QJsonDocument docProd(recProd);
    socket->write(docProd.toJson());
    socket->waitForReadyRead();
    QByteArray prod = socket->readAll();

    QJsonDocument itemProd = QJsonDocument::fromJson(prod);
    QJsonArray productos = itemProd.array();

    QString p = "";
    for(int i=0; i<productos.size(); i++){
        p +=  productos[i].toString();
    }
    cout<<p.toStdString();

    int pCodProd;

    cout<<"Inserte el cod del producto"<<endl;
    cin>>pCodProd;

    QJsonObject recordObjects;
    recordObjects.insert("CodPas",QJsonValue::fromVariant(pCod));
    recordObjects.insert("CodProd",QJsonValue::fromVariant(pCodProd));
    QJsonObject record;
    record.insert("ProdInser",recordObjects);
    QJsonDocument docINt(record);
    socket->write(docINt.toJson());
    socket->waitForReadyRead(2000);

    QByteArray datain = socket->readAll();

    while(datain.toStdString()!="T"){// si el prod no existe
        cout<<"El codigo de producto es incorrecto. ";
        cout<<"Digite un cod diferente: ";
        cin>>pCodProd;

        QJsonObject recordObjec;
        recordObjec.insert("CodPas",QJsonValue::fromVariant(pCod));
        recordObjec.insert("CodProd",QJsonValue::fromVariant(pCodProd));
        QJsonObject reco;
        reco.insert("ProdInser",recordObjec);
        QJsonDocument docI(reco);
        socket->write(docI.toJson());
        socket->waitForReadyRead(2000);

        datain = socket->readAll();
    }

    QJsonObject recordOb;

    recordOb.insert("xPasillo",QJsonValue::fromVariant(pCod));
    recordOb.insert("xProducto",QJsonValue::fromVariant(pCodProd));
    recordOb.insert("Reporte","MarcasProducto");
    QJsonDocument docu(recordOb);
    socket->write(docu.toJson());
    socket->waitForReadyRead(2000);
    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
    QByteArray respuesta = socket->readAll();
    cout<<respuesta.toStdString()<<endl;
}























void mysocket::facturaMayorMonto(){
    QJsonObject recordObj;
    recordObj.insert("Reporte","FacturaMayorMonto");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}

void mysocket::productosPasillo(){
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

    //Solicito la lista de pasillos
    int pCod;
    string pName;
    cout<<"Inserte el codigo del pasillo: ";
    cin>>pCod;

    QJsonObject val;
    val.insert("PasilloInsert", QJsonValue::fromVariant(pCod));
    QJsonDocument dVal(val);
    socket->write(dVal.toJson());
    socket->waitForReadyRead(2000);

    QByteArray data = socket->readAll(); //T si existe, F si no existe
    while(data != "T"){
        cout<<"El codigo del pasillo es incorrecto. ";
        cout<<"Dijite un cod de pasillo diferente: ";
        cin>>pCod;
        QJsonObject recordObject;
        recordObject.insert("PasilloInsert", QJsonValue::fromVariant(pCod));
        QJsonDocument doc(recordObject);
        socket->write(doc.toJson());
        socket->waitForReadyRead(2000);
        //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
        data = socket->readAll();
    }
    QJsonObject recordObj;

    recordObj.insert("xProductos",QJsonValue::fromVariant(pCod));
    recordObj.insert("Reporte","ProductosPasillo");
    QJsonDocument docu(recordObj);
    socket->write(docu.toJson());
    socket->waitForReadyRead(2000);
    //------SE-LEE-EL-JSON-DE-LA-RESPUESTA-DE-PASILLOS------//
    QByteArray respuesta = socket->readAll();
    cout<<respuesta.toStdString()<<endl;
}

void mysocket::clientesSuper(){
    QJsonObject recordObj;
    recordObj.insert("Reporte","ClientesSuper");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;

}

void mysocket::pasillosSuper(){
    QJsonObject recordObj;
    recordObj.insert("Reporte","PasillosSuper");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}

void mysocket::inventarioSuper(){
    QJsonObject recordObj;
    recordObj.insert("Reporte","InventarioSuper");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}

void mysocket::facturar(){
    QJsonObject recordObj;
    recordObj.insert("Facturar","T");
    QJsonDocument doc(recordObj);
    socket->write(doc.toJson());
    socket->waitForReadyRead(2000);
    QByteArray data = socket->readAll();
    cout<<data.toStdString()<<endl;
}









//---------------------LISTOS------------------------//
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
