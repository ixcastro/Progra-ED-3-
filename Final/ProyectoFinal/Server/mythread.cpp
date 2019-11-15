#include "mythread.h"
#include "mysocket.h"

#include "adminbtree.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

static int consecutivo = 1;

MyThread::MyThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::setEST(managerEST pEST){
    this->EST = pEST;
}


void MyThread::run()
{
    // thread starts here
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop
    exec();
}



///-SET-MSG-SERVER-CLIENT-//
void MyThread::readyRead()
{


    //---------------------LEE-SOCKET--------------------//
    QByteArray Data = socket->readAll();
    QJsonDocument itemDoc = QJsonDocument::fromJson(Data);
    QJsonObject rootObject = itemDoc.object();
    QVariantMap json_map = rootObject.toVariantMap();

    //---------------------------------------------------//
    //-------------------ADMIN--------------------------//
    //---------------------------------------------------//

    //-------------SI-EL-JSON-ES-UNA-ID-ADMIN---------------//
    if(json_map.firstKey() == "CodAdmin"){
        //VALIDA-LA-CEDULA----//
        Admin* aux = EST.getAdmin()->searchAdmin(json_map["CodAdmin"].toInt(), EST.getAdmin()->getRoot());
        if(aux != nullptr){
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    if(json_map.firstKey() == "Kruskal"){
        cout<<"Solicitud"<<endl;
        QJsonDocument doc = EST.getGrafo()->kruskalToJson();
        socket->write(doc.toJson());

        cout<<"Respuesta"<<endl;
    }

    //-------------T si un pasllo existe, F sino---------------//
    if(json_map.firstKey() == "PasilloInsert"){
        //VALIDA-LA-CEDULA----//
        string aux;
        cout<<"pasillo"<<json_map["PasilloInsert"].toInt()<<endl;
        if( EST.getEST()->exists(json_map["PasilloInsert"].toInt())){
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    //-------------T si un producto exsite, F sino---------------//
    if(json_map.firstKey() == "ProdInser"){
        QJsonObject x = json_map["ProdInser"].toJsonObject();
        int pId = x.take("CodPas").toInt();
        int pidprod = x.take("CodProd").toInt();

        if(EST.getEST()->getNode(pId)->getProducts()->exists(pidprod)){
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    //-------------T si registra el producto, F sino---------------//
    if(json_map.firstKey() == "RegistrarProducto"){

        QJsonObject x = json_map["RegistrarProducto"].toJsonObject();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Iprod").toInt();
        QString namepro = x.take("nameProd").toString();

        if(EST.getEST()->getNode(pId)->getProducts()->exists(pidprod)){
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            Product* aux = new Product(pidprod,namepro.toStdString());
            EST.getEST()->getNode(pId)->insertProduct(aux);
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    //-------------T si registra el pasillo, F sino---------------//
    if(json_map.firstKey() == "RegistrarPasillo"){
        QJsonObject x = json_map["RegistrarPasillo"].toJsonObject();
        int pId = x.take("CodPas").toInt();
        QString pName = x.take("Nombre").toString();

        string a;
        if(EST.getEST()->exists(pId)){
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            Hall * aux = new Hall(pId, QString::fromStdString(pName.toStdString()));
            EST.getEST()->insert(aux);
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    //-------------T si existe la marca, F sino---------------//
    if(json_map.firstKey() == "inCodBrand"){
        QJsonObject x = json_map["inCodBrand"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Iprod").toInt();
        if(EST.getEST()->getNode(pId)->getProducts()->getProduct(pidprod)->getRN()->exists(pIdB)){
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }

    }

    //-------------T si registra la marca, F sino---------------//
    if(json_map.firstKey() == "RegistrarMarcaGondola"){
        QJsonObject x = json_map["RegistrarMarcaGondola"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Iprod").toInt();
        int pPrecio = x.take("Iprecio").toInt();
        int pcant = x.take("Icantidad").toInt();
        QString pName = x.take("Nombre").toString();

        if(EST.getEST()->exists(pId)){
            if(EST.getEST()->getNode(pId)->getProducts()->exists(pidprod)){
                if(!EST.getEST()->getNode(pId)->getProducts()->getProduct(pidprod)->getRN()->exists(pIdB)){
                    EST.getEST()->getNode(pId)->getProducts()->getProduct(pidprod)
                            ->getRN()->insert(new Brand(pIdB,pName,pcant,pPrecio));
                    QJsonObject o;
                    o.insert("Respuesta","T");
                    QJsonDocument r(o);
                    socket->write(r.toJson());
                }else{
                    QJsonObject o;
                    o.insert("Respuesta","F");
                    QJsonDocument r(o);
                    socket->write(r.toJson());
                }
            }else{
                QJsonObject o;
                o.insert("Respuesta","F");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }
        }else{
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    //-------------T si se inserta en el inventario, F sino---------------//
    if(json_map.firstKey() == "RegistrarMarcaInventario"){
        QJsonObject x = json_map["RegistrarMarcaInventario"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Iprod").toInt();
        QString pib = x.take("IisBask").toString();
        int pcant = x.take("Icantidad").toInt();
        QString pName = x.take("Nombre").toString();
        bool aux ;
        if(pib=="T"){
            aux=true;
        }else{
            aux = false;
        }

        if(EST.getInventory()->searchNode(pId,pidprod,pIdB, EST.getInventory()->getRoot())){
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else {
            Inventory *newInventory = new Inventory(pId,pidprod, pIdB, pName, pcant, aux);
            EST.getInventory()->insert(newInventory);
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    //---------------------------------------------------//
    //--------PREGUNTA SI EL CLIENTE ESTA EN PROCESO-----//
    //---------------------------------------------------//
    if(json_map.firstKey() == "StopClient"){
        if(EST.getEST()->getFlagProcess() == "T"){
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }
    //---------------------------------------------------//
    //---------------------------------------------------//




    //---------------------------------------------------//
    //-------CAMBIA LA BANDERA DE PARAR CLIENTE -----//
    //---------------------------------------------------//
    if(json_map.firstKey() == "StopClienteNow"){
        int AUX =json_map["StopClienteNow"].toInt();
        if(AUX == 1){
            EST.getEST()->setFlagStop("T");
        }else{
            EST.getEST()->setFlagStop("F");
        }
    }
    //---------------------------------------------------//
    //---------------------------------------------------//




    //---------------------------------------------------//
    //--------SI EL CLIENTE ESTA EN UN PROCESO-----------//
    //---------------------------------------------------//
    if(json_map.firstKey() == "Proceso"){
        int AUX =json_map["Proceso"].toInt();
        if(AUX == 1 && EST.getEST()->getFlagStop() == "F" ){
            EST.getEST()->setFlagProcess("T");
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
        else if (AUX == 2 && EST.getEST()->getFlagStop()== "F" ){
            EST.getEST()->setFlagProcess("F");
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }
    //---------------------------------------------------//
    //---------------------------------------------------//

    //---------------------------------------------------//
    //-----------------CLIENTE--------------------------//
    //---------------------------------------------------//

    //-------------Valida la cedula---------------//
    if(json_map.firstKey() == "Cedula"){
        //VALIDA-LA-CEDULA----//
        Client * AUX = this->EST.getClients()->searchClient(json_map["Cedula"].toInt(),EST.getClients()->getRoot());
        if(AUX != nullptr){
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    //-------------SI-EL-JSON-ES-UN-PASILLO---------------//
    if(json_map.firstKey() == "Pasillo"){
        //-CARGA-EL-HALL-LIST-//
        EST.getEST()->getHall(EST.getEST()->getRoot());
        QJsonDocument pasillos(hallList);
        //ENVIA-EL-HALL-LIST-//
        socket->write(pasillos.toJson());
        while(hallList.count()){
            hallList.pop_back();
        }
    }

    if(json_map.firstKey() == "InsertarCliente"){
        QJsonObject ob = json_map["InsertarCliente"].toJsonObject();
        int pId = ob.take("Cedula").toInt();
        QString pName = ob.take("Nombre").toString();
        int pCityCode = ob.take("CodigoCiudad").toInt();
        QString pPhone = ob.take("Phone").toString();
        QString pMail = ob.take("Correo").toString();

        cout<<"Ced "<<pId<<endl;

        if(EST.getClients()->searchClient(pId,EST.getClients()->getRoot())==nullptr){
            cout<<"Null"<<endl;
        }

        if(EST.getClients()->searchClient(pId,EST.getClients()->getRoot())!=nullptr || !EST.getCities()->exists(pCityCode)){
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            Client *c = new Client(pId,pName,pCityCode,pPhone,pMail);
            EST.getClients()->insert(c);
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    if(json_map.firstKey() == "ClientesCola"){
        EST.getCola()->getClientsQueue();
        QJsonDocument clientesCola(clientsQueue);
        socket->write(clientesCola.toJson());
        while(clientsQueue.count()){
            clientsQueue.pop_back();
        }
    }

    if(json_map.firstKey() == "Ciudades"){
        EST.getCities()->getCities();
        QJsonDocument city(cities);
        socket->write(city.toJson());
        while(cities.count()){
            cities.pop_back();
        }
    }

    //-------------SI-EL-JSON-ES-UN-PRODUCTO---------------//
    if(json_map.firstKey() == "Producto"){
        //-REVISA-QUE-EL-PASILLO-SOLICITADO-EXISTA-//
        if(EST.getEST()->exists(json_map["Producto"].toInt())){
            ABBNode * hallCL = EST.getEST()->getNode(json_map["Producto"].toInt());
            hallCL->getProducts()->getProdCL(hallCL->getProducts()->getRoot());
            QJsonDocument pasillos(hallProdList);
            if(hallProdList.size()!=0){
                EST.getReportePasillo()->insert(json_map["Producto"].toInt(),1);
            }
            socket->write(pasillos.toJson());
            while(hallProdList.count()){
                hallProdList.pop_back();
            }
            //secretHall = json_map["Producto"].toInt();
        }
    }

    //-------------SI-EL-JSON-ES-UN-PRODUCTO---------------//
    if(json_map.firstKey() == "Marca"){
        //-REVISA-QUE-EL-PROD-SOLICITADO-EXISTA-//
        // secrethall es el pasillo
        QJsonObject obj = json_map["Marca"].toJsonObject();
        int pPasillo = obj.take("Pasillo").toInt();
        int pProd = obj.take("Producto").toInt();
        ABBNode * hallCL = EST.getEST()->getNode(pPasillo);

        // verifica si la marca existe
        if(hallCL->getProducts()->exists(pProd)){

            hallCL->getProducts()->getProduct(pProd)->getRN()->
                    getBrandCL(hallCL->getProducts()->getProduct(pProd)->getRN()->getRoot());

            QJsonDocument pasillos(hallProdBrandList);
            socket->write(pasillos.toJson());
            while(hallProdBrandList.count()){
                hallProdBrandList.pop_back();
            }
        }
    }

    //-------------SI-EL-JSON-ES-UN-PRECIO---------------//
    if(json_map.firstKey() == "newPrecio"){
        QJsonObject x = json_map["newPrecio"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Icodprod").toInt();
        int pcant = x.take("Iprecio").toInt();

        QJsonObject ob;
        ABBNode * hallCL = EST.getEST()->getNode(pId);

        if(hallCL){
            AVLNode *prodCL = hallCL->getProducts()->getProduct(pidprod);
            if(prodCL){
                RNNode *brandCL = prodCL->getRN()->getBrand(pIdB);
                if(brandCL){
                    brandCL->getBrand()->setPrice(pcant);
                    ob.insert("Respuesta","T");
                }else{
                    ob.insert("Respuesta","F");
                }
            }else{
                ob.insert("Respuesta","F");
            }
        }else{
            ob.insert("Respuesta","F");
        }

        QJsonDocument doc(ob);
        socket->write(doc.toJson());
    }

    //-------------SI-EL-JSON-ES-UN-PRECIO---------------//
    if(json_map.firstKey() == "newCanasta"){
        QJsonObject x = json_map["newCanasta"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Icodprod").toInt();
        QString pName = x.take("IisBasket").toString();
        bool  aux;
        if(pName=="S"){
            aux=true;
        }else{
            aux = false;
        }

        QJsonObject ob;

        if(EST.getInventory()->searchNode(pId, pidprod, pIdB, EST.getInventory()->getRoot())){
            EST.getInventory()->searchNode(pId, pidprod, pIdB, EST.getInventory()->getRoot())->getInventory()->setIsBasket(aux);
            ob.insert("Respuesta","T");
        }else{
            ob.insert("Respuesta","F");
        }

        QJsonDocument doc(ob);
        socket->write(doc.toJson());
    }

    //-------------SI-EL-JSON-ES-UN-PRECIO---------------//
    if(json_map.firstKey() == "newPercentage"){
        QJsonObject x = json_map["newPercentage"].toJsonObject();
        int pIdB = x.take("IcodBran").toInt();
        int pId = x.take("Ihall").toInt();
        int pidprod = x.take("Icodprod").toInt();
        QString pName = x.take("Ipercentage").toString();
        std::string str = pName.toStdString();

        // val to store parsed floating type number
        float val = std::stof(str);

        QJsonObject ob;

        ABBNode * hallCL = EST.getEST()->getNode(pId);

        if(hallCL){
            AVLNode *prodCL = hallCL->getProducts()->getProduct(pidprod);
            if(prodCL){
                RNNode *brandCL = prodCL->getRN()->getBrand(pIdB);
                if(brandCL){
                    brandCL->getBrand()->setPercentage(val);
                    ob.insert("Respuesta","T");
                }else{
                    ob.insert("Respuesta","F");
                }
            }else{
                ob.insert("Respuesta","F");
            }
        }else{
            ob.insert("Respuesta","F");
        }

        QJsonDocument doc(ob);
        socket->write(doc.toJson());
    }

    //-------------SI-EL-JSON-ES-UN-PRECIO---------------//
    if(json_map.firstKey() == "Precio"){
        //-REVISA-QUE-EL-PROD-SOLICITADO-EXISTA-//
        // secrethall es el pasillo

        QJsonObject x = json_map["Precio"].toJsonObject();
        int pPasillo = x.take("Pasillo").toInt();
        int pProducto = x.take("Producto").toInt();
        int pMarca = x.take("Marca").toInt();

        ABBNode * hallCL = EST.getEST()->getNode(pPasillo);

        string precio = hallCL->getProducts()->getProduct(pProducto)->getRN()->
                getBrandPriceCL(hallCL->getProducts()->getProduct(pProducto)->
                                getRN()->getRoot() ,pMarca) ;


        QJsonObject pr;
        pr.insert("Precio",precio.c_str());
        QJsonDocument doc(pr);
        cout<<"Precio: "<<precio.c_str()<<endl;
        socket->write(doc.toJson());/*
        if(precio != "0"){
            socket->write(precio.c_str());
        }
        else{
            socket->write("0");
        }

        while(hallProdBrandList.count()){
            hallProdBrandList.pop_back();
        }*/
    }

    //-------------SI-EL-JSON-ES-UN-PORCENTAJE---------------//
    if(json_map.firstKey() == "Porcentaje"){
        //-REVISA-QUE-EL-PROD-SOLICITADO-EXISTA-//
        // secrethall es el pasillo

        QJsonObject x = json_map["Porcentaje"].toJsonObject();
        int pPasillo = x.take("Pasillo").toInt();
        int pProducto = x.take("Producto").toInt();
        int pMarca = x.take("Marca").toInt();

        ABBNode * hallCL = EST.getEST()->getNode(pPasillo);

        string porcentaje = hallCL->getProducts()->getProduct(pProducto)->getRN()
                ->getBrandPorcentCL(hallCL->getProducts()->getProduct(pProducto)->
                                    getRN()->getRoot() ,pMarca) ;

        QJsonObject pr;
        pr.insert("Porcentaje",porcentaje.c_str());
        QJsonDocument doc(pr);
        socket->write(doc.toJson());
    }

    //-------------SI-EL-JSON-ES-UN-ISBASKET---------------//
    if(json_map.firstKey() == "IsBasket"){
        QJsonObject x = json_map["IsBasket"].toJsonObject();
        int pPasillo = x.take("Pasillo").toInt();
        int pProducto = x.take("Producto").toInt();
        int pMarca = x.take("Marca").toInt();

        bool xIsBasket = EST.getInventory()->searchNode(pPasillo, pProducto, pMarca, EST.getInventory()->getRoot())->getInventory()->getIsBasket();
        QJsonObject pr;

        if(xIsBasket){
            pr.insert("IsBasket","El producto pertenece a canasta basica. ");
        }else{
            pr.insert("IsBasket","El producto no pertenece a canasta basica. ");
        }

        QJsonDocument doc(pr);
        socket->write(doc.toJson());
    }

    if(json_map.firstKey() == "Registrar"){
        QJsonObject x = json_map["Registrar"].toJsonObject();
        int pId = x.take("Cedula").toInt();
        QString pName = x.take("Nombre").toString();
        int pCityCode = x.take("CodigoCiudad").toInt();
        QString pPhone = x.take("Phone").toString();
        QString pMail = x.take("Correo").toString();

        //Creo un Client y lo inserto en una cola para luego registrarlos
        Client *c = new Client(pId,pName,pCityCode,pPhone,pMail);
        EST.getRegistrar()->encolar(c);

        //Solo le digo que su solicitud fue aceptada
        socket->write("Solicitud fue recibida por el administrador. En un par de dias se registrara en el sistema.");
    }

    if(json_map.firstKey() == "PrecioCompra"){

        //-REVISA-QUE-EL-PROD-SOLICITADO-EXISTA-//
        // secrethall es el pasillo
        ABBNode * hallCL = EST.getEST()->getNode(secretHall);

        // verifica si la marca existe
        if(hallCL->getProducts()->exists(json_map["PrecioCompra"].toInt())){

            hallCL->getProducts()->getProduct(json_map["PrecioCompra"].toInt())->getRN()
                    ->getBrandBuyCL(hallCL->getProducts()->getProduct(json_map["PrecioCompra"].toInt())->getRN()->getRoot());

            QJsonDocument pasillos(hallProdBrandList);
            socket->write(pasillos.toJson());
            while(hallProdBrandList.count()){
                hallProdBrandList.pop_back();
            }

        }

        secretProd = json_map["PrecioCompra"].toInt();
    }

    //-------------SI-EL-JSON-ES-UNA-COMPRA---------------//
    if(json_map.firstKey() == "MarcaAComprar"){
        cout<<json_map["MarcaAComprar"].toInt()<<endl;
        ABBNode * hallCL = EST.getEST()->getNode(secretHall);
        RNNode * product = hallCL->getProducts()->getProduct(secretProd)->getRN()->getRoot();
        //si la marca es valida
        if(hallCL->getProducts()->getProduct(secretProd)->getRN()->validateBand(product,json_map["MarcaAComprar"].toInt())){
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
        secretBrand = json_map["MarcaAComprar"].toInt();
    }

    //-------------SI-EL-JSON-ES-UNA-COMPRA---------------//
    if(json_map.firstKey() == "Comprar"){

        //EST.getEST()->print(EST.getEST()->getRoot());

        QJsonObject x = json_map["Comprar"].toJsonObject();
        int pId = x.take("Cedula").toString().toInt();
        int CantidadCompra = x.take("CantidadCompra").toString().toInt();
        int pPasillo = x.take("Pasillo").toString().toInt();
        int pProducto = x.take("Producto").toString().toInt();
        int pMarca = x.take("Marca").toString().toInt();

        cout<<"Id "<<pId<<endl;
        cout<<"Cant "<<CantidadCompra<<endl;
        cout<<"Pasillo "<<pPasillo<<endl;
        cout<<"Producto "<<pProducto<<endl;
        cout<<"Marca "<<pMarca<<endl;

        ABBNode * hallCL = EST.getEST()->getNode(pPasillo);
        RNNode * product = hallCL->getProducts()->getProduct(pProducto)->getRN()->getRoot();


        cout<<hallCL->getProducts()->getProduct(pProducto)->getRN()->validateCant(product,CantidadCompra)<<endl;
        //si la cantidad es valida
        if(hallCL->getProducts()->getProduct(pProducto)->getRN()->validateCant(product,CantidadCompra)){

            Client *c = EST.getClients()->searchClient(pId,EST.getClients()->getRoot());
            if(EST.getCola()->exists(c) && EST.getCola()->getFondo()->getClient()->getId() != c->getId()){ //El cliente está en la cola y no es el fondo
                QJsonObject ol;
                ol.insert("Respuesta","A");
                QJsonDocument l(ol);
                cout<<"No compras"<<endl;
                socket->write(l.toJson());
            }else{
                if(EST.getCola()->isEmpty() || EST.getCola()->getFondo()->getClient()->getId() != c->getId()){
                    EST.getCola()->encolar(c);
                }
                EST.getCola()->getFondo()->buy(pPasillo,pProducto,pMarca,CantidadCompra);

                int dataNew = EST.getEST()->getNode(pPasillo)->getProducts()->getProduct(pProducto)->getRN()->getBrand(pMarca)->getBrand()->getQuantity();

                EST.getEST()->getNode(pPasillo)->getProducts()->getProduct(pProducto)->getRN()->getBrand(pMarca)->getBrand()->setCount(dataNew-CantidadCompra);

                hallCL->getProducts()->getProduct(pProducto)->getRN()
                        ->getBrandBuyCL(hallCL->getProducts()->getProduct(pProducto)->getRN()->getRoot());

                while(hallProdBrandList.count()){
                    hallProdBrandList.pop_back();
                }
                QJsonObject oj;
                oj.insert("Respuesta","B");
                cout<<"Carrito"<<endl;
                QJsonDocument j(oj);
                socket->write(j.toJson());
            }

        }else{
            int data = hallCL->getProducts()->getProduct(pProducto)->getRN()->getMaxCant(product,pMarca);
            QJsonObject ro;
            ro.insert("Respuesta",QJsonValue::fromVariant(data));
            cout<<"Data "<<data<<endl;
            QJsonDocument r(ro);
            socket->write(r.toJson());

        }

        //cout<<"-----------------------------------------------------------------------------------"<<endl<<endl<<endl;

        //EST.getEST()->print(EST.getEST()->getRoot());
    }

    if(json_map.firstKey() == "Reporte"){
        QString type = json_map["Reporte"].toString();
        if(type == "PasilloMasVisitado"){
            if(EST.getReportePasillo()->noReport()){
                QJsonObject o;
                o.insert("Respuesta","No se han visitado pasillos. ");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }else{
                ofstream write ("PasilloMasVisitado.txt");
                write<<"Pasillos mas visitados: \n\n";
                ReportListInt *lista = EST.getReportePasillo()->major();
                ReportNodeInt *aux = lista->getFirst();
                while(aux != nullptr){
                    ABBNode *tmp = EST.getEST()->getNode(aux->getCode());
                    write<<"Codigo pasillo: "<<tmp->getHall()->getCode()<<" Nombre pasillo: "<<tmp->getHall()->getName().toStdString()<<"\n";
                    aux = aux->getNext();
                }
                write.close();
                QJsonObject o;
                o.insert("Respuesta","Archivo creado.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }
        }else if(type == "PasilloMenosVisitado"){
            if(EST.getReportePasillo()->noReport()){
                QJsonObject o;
                o.insert("Respuesta","No se han visitado pasillos.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }else{
                ofstream write ("PasilloMenosVisitado.txt");
                write<<"Pasillos menos visitados: \n\n";
                ReportListInt *lista = EST.getReportePasillo()->minor();
                ReportNodeInt *aux = lista->getFirst();
                while(aux != nullptr){
                    ABBNode *tmp = EST.getEST()->getNode(aux->getCode());
                    write<<"Codigo pasillo: "<<tmp->getHall()->getCode()<<" Nombre pasillo: "<<tmp->getHall()->getName().toStdString()<<"\n";
                    aux = aux->getNext();
                }
                write.close();
                QJsonObject o;
                o.insert("Respuesta","Archivo creado.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }
        }else if(type == "MarcaMasVendida"){
            if(EST.getVendidos()->isEmpty()){
                QJsonObject o;
                o.insert("Respuesta","No se han vendido productos.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }else{
                string datos = "";
                SalesList *masVendidos = EST.getVendidos()->major();
                if(masVendidos->isEmpty()){
                    datos = "No se han vendido productos.";
                }else{
                    StackClientNode *aux = masVendidos->getFirst();
                    while(aux != nullptr){
                        datos += EST.getEST()->getNode(aux->getData()->getHallCode())->getProducts()->getProduct(aux->getData()->getProdCode())->
                                getRN()->getBrand(aux->getData()->getBrandCode())->getBrand()->toString();
                        datos += "Cantidad vendida: " + to_string(aux->getData()->getQuantity()) + "\n\n";
                        aux = aux->getNext();
                    }
                }
                ofstream write ("MarcaMasVendida.txt");
                write<<"Marca/s mas vendida: \n\n";
                write<<datos;
                write.close();
                QJsonObject o;
                o.insert("Respuesta","Archivo creado.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }
        }else if(type == "ProductoMasVendidoPasillo"){ //Necesito un int
            if(EST.getVendidos()->isEmpty()){
                QJsonObject o;
                o.insert("Respuesta","No se han vendido productos.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }else{
                int p = json_map["xPasillo"].toInt();
                SalesList *ventasPasillo = EST.getVendidos()->masVendidosPasillo(p);
                string datos ="";
                if(ventasPasillo->isEmpty()){
                    datos = "No se han vendido productos de ese pasillo.";
                }else{
                    StackClientNode *aux = ventasPasillo->getFirst();
                    while(aux != nullptr){
                        datos += EST.getEST()->getNode(aux->getData()->getHallCode())->getProducts()->getProduct(aux->getData()->getProdCode())->
                                getRN()->getBrand(aux->getData()->getBrandCode())->getBrand()->toString();
                        datos += "Cantidad vendida: " + to_string(aux->getData()->getQuantity()) + "\n\n";
                        aux = aux->getNext();
                    }
                }
                ofstream write ("ProductosMasVendidosPasillo_" + to_string(EST.getEST()->getNode(p)->getHall()->getCode()) + ".txt");
                write<<"Productos mas vendidos en un pasillo: \n\n";
                write<<datos;
                write.close();
                QJsonObject o;
                o.insert("Respuesta","Archivo creado.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }
        }else if(type == "ClienteMasCompro"){
            if(EST.getFacturasClientes()->noReport()){
                QJsonObject o;
                o.insert("Respuesta","No se ha facturado");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }else{
                string datos = "";
                ReportListInt *facturaCliente = EST.getReporteCliente()->major();
                ReportNodeInt *aux = facturaCliente->getFirst();
                while(aux != nullptr){
                    datos += EST.getClients()->searchClient(aux->getCode(),EST.getClients()->getRoot())->toString();
                    datos += "Cantidad de facturas: " + to_string(aux->getCount()) + "\n\n";
                    aux = aux->getNext();
                }
                ofstream write ("ClienteMasCompro.txt");
                write<<"Cliente/s que mas compro: \n\n";
                write<<datos;
                write.close();
                QJsonObject o;
                o.insert("Respuesta","Archivo creado.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }
        }else if(type == "ClienteMenosCompro"){
            if(EST.getFacturasClientes()->noReport()){
                QJsonObject o;
                o.insert("Respuesta","No se ha facturado");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }else{
                string datos = "";
                ReportListInt *facturaCliente = EST.getReporteCliente()->minor();
                ReportNodeInt *aux = facturaCliente->getFirst();
                while(aux != nullptr){
                    datos += EST.getClients()->searchClient(aux->getCode(),EST.getClients()->getRoot())->toString();
                    datos += "Cantidad de facturas: " + to_string(aux->getCount()) + "\n\n";
                    aux = aux->getNext();
                }
                ofstream write ("ClienteMenosCompro.txt");
                write<<"Cliente/s que menos compro: \n\n";
                write<<datos;
                write.close();
                QJsonObject o;
                o.insert("Respuesta","Archivo creado.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }
        }else if(type == "ProductoMasCargoGondola"){
            if(EST.getMayorGondola()->isEmpty()){
                QJsonObject o;
                o.insert("Respuesta","No se ha cargado en gondola");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }else{
                string datos = "";
                StackClientNode *aux  = EST.getMayorGondola()->getFirst();
                while(aux != nullptr){
                    datos += aux->getData()->toStringG();
                    aux = aux->getNext();
                }
                ofstream write ("ProductoMasCargadoGondola.txt");
                write<<"Producto/s mas cargado en gondola: \n\n";
                write<<datos;
                write.close();
                QJsonObject o;
                o.insert("Respuesta","Archivo creado.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }
        }else if(type == "ClienteMasFacturo"){
            if(EST.getReporteCliente()->noReport()){
                QJsonObject o;
                o.insert("Respuesta","No se ha facturado.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }else{
                string datos = "";
                ReportListFloat *facturas = EST.getFacturasClientes()->major();
                ReportNodeFloat *aux = facturas->getFirst();
                while(aux != nullptr){
                    datos += EST.getClients()->searchClient(aux->getCode(),EST.getClients()->getRoot())->toString();
                    datos += "Monto facturado: " + to_string(aux->getMonto()) + "\n\n";
                    aux = aux->getNext();
                }
                ofstream write ("ClienteMasFacturo.txt");
                write<<"Cliente/s que mas facturo: \n\n";
                write<<datos;
                write.close();
                QJsonObject o;
                o.insert("Respuesta","Archivo creado.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }
        }else if(type == "MarcasProducto"){ //Necesito dos ints

            int p = rootObject.take("xPasillo").toInt();
            int pr = rootObject.take("xProducto").toInt();

            EST.getEST()->getNode(p)->getProducts()->getProduct(pr)->getRN()->
                    getBrandCL(EST.getEST()->getNode(p)->getProducts()->getProduct(pr)->getRN()->getRoot());

            QString s = "";
            for(int i=0; i<hallProdBrandList.size(); i++){
                s += hallProdBrandList[i].toString();
            }

            while(hallProdBrandList.count()){
                hallProdBrandList.pop_back();
            }

            ofstream write ("MarcasProducto_" + to_string(EST.getEST()->getNode(p)->getHall()->getCode()) + "_" +
                            to_string(EST.getEST()->getNode(p)->getProducts()->getProduct(pr)->getProduct()->getCode()) + ".txt");
            write<<"Marca/s de un producto: \n\n";
            write<<s.toStdString();
            write.close();
            QJsonObject o;
            o.insert("Respuesta","Archivo creado.");
            QJsonDocument r(o);
            socket->write(r.toJson());

        }else if(type == "FacturaMayorMonto"){
            if(EST.getReporteCliente()->noReport()){
                QJsonObject o;
                o.insert("Respuesta","No se ha facturado");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }else{
                string datos = "";
                ReportListFloat *facturas = EST.getFacturasClientes()->major();
                ReportNodeFloat *aux = facturas->getFirst();
                while(aux != nullptr){
                    datos += EST.getClients()->searchClient(aux->getCode(),EST.getClients()->getRoot())->toString();
                    datos += " Monto: " + to_string(aux->getMonto()) + "\n\n";
                    aux = aux->getNext();
                }
                ofstream write ("FacturaMayorMonto.txt");
                write<<"Factura/s con mayor monto: \n\n";
                write<<datos;
                write.close();
                QJsonObject o;
                o.insert("Respuesta","Archivo creado.");
                QJsonDocument r(o);
                socket->write(r.toJson());
            }
        }else if(type == "ProductosPasillo"){ //Necesito un int
            int pas = json_map["xProductos"].toInt();
            ofstream write ("ProductosPasillo" + to_string(pas) + ".txt");
            write<<"Lista de productos del pasillo" + to_string(pas) + ": \n\n";
            EST.getEST()->getNode(pas)->getProducts()->getProdCL(EST.getEST()->getNode(pas)->getProducts()->getRoot());

            QString s = "";
            for(int i=0; i<hallProdList.size(); i++){
                s +=  hallProdList[i].toString();
            }

            while(hallProdList.count()){
                hallProdList.pop_back();
            }

            write<<s.toStdString();
            write.close();
            QJsonObject o;
            o.insert("Respuesta","Archivo creado.");
            QJsonDocument r(o);
            socket->write(r.toJson());

        }else if(type == "ClientesSuper"){
            ofstream write ("ClientesSuper.txt");
            write<<"Lista de clientes del supermercado: \n\n";
            EST.getClients()->toString(EST.getClients()->getRoot());

            QString s = "";
            for(int i=0; i<clientList.size(); i++){
                s +=  clientList[i].toString();
                s += "\n";
            }

            while(clientList.count()){
                clientList.pop_back();
            }

            write<<s.toStdString();
            write.close();
            QJsonObject o;
            o.insert("Respuesta","Archivo creado.");
            QJsonDocument r(o);
            socket->write(r.toJson());

        }else if(type == "PasillosSuper"){
            ofstream write ("PasillosSuper.txt");
            write<<"Lista de pasillo del supermercado: \n\n";
            EST.getEST()->getHall(EST.getEST()->getRoot());

            QString s = "";
            for(int i=0; i<hallList.size(); i++){
                s +=  hallList[i].toString();
                s += "\n";
            }

            while(hallList.count()){
                hallList.pop_back();
            }


            write<<s.toStdString();
            write.close();
            QJsonObject o;
            o.insert("Respuesta","Archivo creado.");
            QJsonDocument r(o);
            socket->write(r.toJson());

        }else if(type == "InventarioSuper"){//Inventario
            ofstream write ("InventarioSuper.txt");
            write<<"Lista del inventario del supermercado: \n\n";
            EST.getInventory()->toString();


            QString s = "";
            for(int i=0; i<inventoryList.size(); i++){
                s +=  inventoryList[i].toString();
                s += "\n";
                cout<<s.toStdString()<<endl;
            }

            while(inventoryList.count()){
                inventoryList.pop_back();
            }

            write<<s.toStdString();
            write.close();
            QJsonObject o;
            o.insert("Respuesta","Archivo creado.");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            QJsonObject o;
            o.insert("Respuesta","Ocurrio un problema... Intentelo mas tarde");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    if(json_map.firstKey() == "Facturar"){
        if(EST.getCola()->isEmpty()){
            QJsonObject o;
            o.insert("Respuesta","No se han realizado compras.");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            QueueNode *aux = EST.getCola()->desencolar();
            string filename = to_string(aux->getClient()->getId())+".txt";
            ifstream read (filename);
            ofstream write ("newFile.txt");
            string text;
            if(!read.fail()){ //Leo el archivo si es que existe
                while(!read.eof()){
                    getline(read,text);
                    write<<text<<"\n";
                }
                read.close();
                if(std::remove(filename.c_str()) != 0){ //Elimino el archivo que ya existe
                    cout<<"Ocurrio un error"<<endl;
                }
            }
            write<<"Consecutivo: "<<consecutivo<<"\n";
            write<<"Cedula del cliente: "<<aux->getClient()->getId()<<"\n";
            write<<"Nombre: "<<aux->getClient()->getName().toStdString()<<"\n";
            write<<"Telefono: "<<aux->getClient()->getPhone().toStdString()<<"\n";
            string prod = "";
            prod += "Cantidad Codigo producto Nombre \tPrecio \tImpuesto \tTotal \n";
            StackClientNode *aux2 = aux->getStack()->pop();
            float deuda = float(0);
            while(aux2 != nullptr){
                //Cantidad y codigo del producto
                prod += to_string(aux2->getData()->getQuantity()) + "\t\t" + to_string(aux2->getData()->getBrandCode()) + "\t ";
                //Nombre
                prod += EST.getEST()->getNode(aux2->getData()->getHallCode())->getProducts()->getProduct(aux2->getData()->getProdCode())->
                        getRN()->getBrand(aux2->getData()->getBrandCode())->getBrand()->getName().toStdString() + "\t";

                //Precio
                prod += to_string(EST.getEST()->getNode(aux2->getData()->getHallCode())->getProducts()->getProduct(aux2->getData()->getProdCode())->
                                  getRN()->getBrand(aux2->getData()->getBrandCode())->getBrand()->getPrice());
                float precio = EST.getEST()->getNode(aux2->getData()->getHallCode())->getProducts()->getProduct(aux2->getData()->getProdCode())->
                        getRN()->getBrand(aux2->getData()->getBrandCode())->getBrand()->getPrice();
                float impuesto;
                if(EST.getInventory()->searchNode(aux2->getData()->getHallCode(),aux2->getData()->getProdCode(),
                                                  aux2->getData()->getBrandCode(), EST.getInventory()->getRoot())->getInventory()->getIsBasket()){
                    impuesto = float(1);
                }else{
                    impuesto = EST.getEST()->getNode(aux2->getData()->getHallCode())->getProducts()->getProduct(aux2->getData()->getProdCode())->
                            getRN()->getBrand(aux2->getData()->getBrandCode())->getBrand()->getPercentage();
                }
                //Impuesto
                prod += "\t" + to_string(impuesto);

                deuda += precio*impuesto*aux2->getData()->getQuantity();
                prod += "\t" + to_string(precio*impuesto*aux2->getData()->getQuantity()) + "\n";

                //Inserto en lista ventas, lista para revisar inventario y para revisar gondolas
                EST.getVendidos()->insert(aux2->getData());
                EST.getVendidosGondolas()->insertGondola(aux2->getData());
                EST.getVendidosInventario()->insert(aux2->getData());

                aux2 = aux->getStack()->pop();
            }

            write<<prod<<"\n";
            write<<"Total a pagar: "<<deuda<<"\n\n";
            read.close();
            write.close();
            std::rename("newFile.txt",filename.c_str());

            //Actualizo para repotes
            EST.getReporteCliente()->insert(aux->getClient()->getId(),1);
            EST.getReporteCliente()->print();
            EST.getFacturasClientes()->addData(aux->getClient()->getId(), deuda);
            cout<<"GG"<<endl;
            EST.getFacturasClientes()->print();

            consecutivo ++;
            QJsonObject o;
            o.insert("Respuesta","Factura generada.");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    if(json_map.firstKey() == "RegistrarCliente"){
        if(EST.getRegistrar()->isEmpty()){
            QJsonObject o;
            o.insert("Respuesta","No hay solicitudes de registro.");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            while(!EST.getRegistrar()->isEmpty()){
                Client *aux = EST.getRegistrar()->desencolar()->getClient();
                EST.getClients()->insert(aux);
            }
            QJsonObject o;
            o.insert("Respuesta","Se han registrado las solicitudes.");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    if(json_map.firstKey() == "VerificarInventario"){
        if(EST.getVendidosInventario()->isEmpty()){
            QJsonObject o;
            o.insert("Respuesta","No se han vendido productos.");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            StackClientNode *aux = EST.getVendidosInventario()->getFirst();
            while(aux){
                AANode *inv = EST.getInventory()->searchNode(aux->getData()->getHallCode(), aux->getData()->getProdCode(), aux->getData()->getBrandCode(), EST.getInventory()->getRoot());
                if(inv){
                    if(inv->getInventory()->getStock() <= 20){
                        string data = "No hay suficientes productos en Stock de " + inv->getInventory()->getName().toStdString();
                        socket->write(data.c_str());
                        socket->waitForReadyRead();
                        QByteArray plus = socket->readAll();
                        cout<<"1"<<endl;
                        QJsonDocument plusDoc = QJsonDocument::fromJson(plus);
                        cout<<"2"<<endl;
                        QJsonObject plusObj = plusDoc.object();
                        cout<<"3"<<endl;
                        int p = plusObj.take("Cantidad").toInt();
                        cout<<"Cant "<<to_string(p)<<endl;
                        cout<<"4"<<endl;
                        EST.getInventory()->searchNode(aux->getData()->getHallCode(), aux->getData()->getProdCode(), aux->getData()->getBrandCode(), EST.getInventory()->getRoot())
                                ->getInventory()->setStock(inv->getInventory()->getStock() + p);
                        cout<<"5"<<endl;
                        cout<<to_string(inv->getInventory()->getStock() + p)<<endl;
                    }
                }
                aux = aux->getNext();
            }
            QJsonObject o;
            o.insert("Respuesta","Inventario verificado.");
            QJsonDocument r(o);
            socket->write(r.toJson());
            EST.setVendidosInventario(); //Vaciar esta lista de inventario de ventas
            //EST.getInventory()->print(EST.getInventory()->getRoot());
        }
    }

    if(json_map.firstKey() == "EliminarCliente"){
        if(EST.getClients()->searchClient(json_map["EliminarCliente"].toInt(),EST.getClients()->getRoot())){
            EST.getClients()->del(json_map["EliminarCliente"].toInt());
            QJsonObject o;
            o.insert("Respuesta","T");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }else{
            QJsonObject o;
            o.insert("Respuesta","F");
            QJsonDocument r(o);
            socket->write(r.toJson());
        }
    }

    //En proceso...  de la suicidacion
    if(json_map.firstKey() == "EliminarProducto"){

        QJsonObject x = json_map["EliminarProducto"].toJsonObject();
        int pPasillo = x.take("Pasillo").toInt();
        int pProducto = x.take("Producto").toInt();

        EST.getEST()->getNode(pPasillo)->getProducts()->deleteAVLData(pProducto);

        QJsonObject o;
        o.insert("Respuesta","T");
        QJsonDocument r(o);
        socket->write(r.toJson());
    }

    if(json_map.firstKey() == "EliminarMarca"){

        QJsonObject x = json_map["EliminarMarca"].toJsonObject();
        int pPasillo = x.take("Pasillo").toInt();
        int pProducto = x.take("Producto").toInt();
        int pMarca = x.take("Marca").toInt();

        EST.getEST()->getNode(pPasillo)->getProducts()->getProduct(pProducto)->getRN()->deleteRNData(pMarca);
        QJsonObject o;
        o.insert("Respuesta","T");
        QJsonDocument r(o);
        socket->write(r.toJson());
    }


}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    exit(0);
}
