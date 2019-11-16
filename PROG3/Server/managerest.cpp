#include "managerest.h"
#include "QDir"

managerEST::managerEST()
{

}

void managerEST::loadFiles(){
    QString path = QDir().currentPath();
    EST->readHallFile(path.toStdString()+"/Pasillos.txt");
    EST->readProdFile(path.toStdString()+"/ProductosPasillos.txt");
    EST->readBrandFile(path.toStdString()+"/MarcasProductos.txt");

    EST->setFlagStop("F");
    EST->setFlagProcess("F");

    cities->readFile(path.toStdString()+"/Ciudades.txt");
    admins->readFile(path.toStdString()+"/Administradores.txt");

    this->readInventory(path.toStdString()+"/Inventario.txt");
    this->readClients(path.toStdString()+"/Clientes.txt");

    this->reporteClientes(clients->getRoot());
    this->reporteFacturas(clients->getRoot());
    this->reportePasillos(EST->getRoot());

    this->readGrafo(path.toStdString()+"/Ciudades.txt",path.toStdString()+"/Conexiones.txt");
}

ABBTree * managerEST::getEST(){
    return EST;
}

ClientBTree * managerEST::getClients(){
    return  clients;
}

AdminBTree * managerEST::getAdmin(){
    return admins;
}

AATree * managerEST::getInventory(){
    return inventory;
}

CityList * managerEST::getCities(){
    return cities;
}

QueueClient* managerEST::getCola(){
    return cola;
}


//--------------------------------------------CAMBIOS-------------------------------------------------

bool managerEST::validPoint(QVector<Connection*> connections, int codCiudad){
    for(Connection *connection : connections){
        if(connection->cityA->getCode() == codCiudad || connection->cityB->getCode() == codCiudad){
            return true;
        }
    }
    return false;
}

void managerEST::readGrafo(string fileName, string fileN){
    QVector<City*> cities;
    int numCities = 0;
    ifstream file;
    file.open(fileName,ios::in);

    string t;
    QString text;

    if(file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    int i = 0;
    while(!file.eof()){
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList list = text.split(";");
        City *c = new City(list[0].toInt(),i,list[1]);

        bool check = true;

        for(int j=0; j<cities.size(); j++){
            if(cities[j]->getCode() == list[0].toInt()){
                check = false;
            }
        }

        if(check){
            cities.append(c);
            i++;
        }
    }

    numCities = i;


    ifstream fileCon;
    fileCon.open(fileN,ios::in);
    QVector<Connection*> connectionsList;

    string t2;
    QString text2;

    if(fileCon.fail()){
        cout<<"No se pudo abrir el archivo de conexiones"<<endl;
        exit(1);
    }

    while(!fileCon.eof()){
        getline(fileCon,t2);
        text2 = QString::fromStdString(t2);
        QStringList list = text2.split(";");
        bool check = false;
        bool check2 = false;

        for(int i=0; i<cities.size(); i++){
            if(cities[i]->getCode() == list[0].toInt()){
                check = true;
            }
            if(cities[i]->getCode() == list[1].toInt()){
                check2 = true;
            }
        }

        if(check && check2){
            City *a = nullptr;
            City *b = nullptr;
            for(int i=0; i<cities.size(); i++){
                if(cities[i]->getCode() == list[0].toInt()){
                    a = cities[i];
                }
                if(cities[i]->getCode() == list[1].toInt()){
                    b = cities[i];
                }
            }

            if(a!=nullptr && b!=nullptr){
                connectionsList.append(new Connection(a,b,list[2].toInt()));
            }
        }
    }

    //Validar que es conexo

    QVector<City*> validCities;
    for(int i=0; i<cities.size(); i++){
        if(validPoint(connectionsList,cities[i]->getCode())){
            validCities.append(cities[i]);
        }
    }

    numCities = validCities.size();
    grafo = new Grafo(numCities,validCities,connectionsList);
}

void managerEST::readClients(string fileName){
    ifstream file;
    string f = fileName;
    file.open(f,ios::in);

    string t;
    QString text;

    if(file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(!file.eof()){
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        if(this->getCities()->exists(data[2].toInt())){
            Client *newClient = new Client(data[0].split(" ")[0].toInt(),data[1], data[2].split(" ")[0].toInt(), data[3],data[4]);
            this->getClients()->insert(newClient);
        }
    }
}

void managerEST::readInventory(string fileName){
    ifstream file;
    string f = fileName;
    file.open(f,ios::in);

    string t;
    QString text;

    if(file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(!file.eof()){
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        bool check = true;
        if(data[5] == "0"){
            check = false;
        }

        if(this->getEST()->exists(data[0].toInt())){
            if(this->getEST()->getNode(data[0].toInt())->getProducts()->exists(data[1].toInt())){
                if(this->getEST()->getNode(data[0].toInt())->getProducts()->getProduct(data[1].toInt())->getRN()->exists(data[2].toInt())){
                    Inventory *newInventory = new Inventory(data[0].split(" ")[0].toInt(),data[1].split(" ")[0].toInt(), data[2].split(" ")[0].toInt(), data[3],data[4].split(" ")[0].toInt(),check);
                    this->getInventory()->insert(newInventory);
                }
            }
        }
    }
}

void managerEST::reporteClientes(ClientBNode *r){
    if(r != nullptr){
        int i;
        for(i=0; i<r->getCount(); i++){
            reporteClientes(r->getChild(i));
            this->reporteCliente->insert(r->getValue(i+1)->getId(),0);
        }
        reporteClientes(r->getChild(i));
    }
}

void managerEST::reportePasillos(ABBNode *r){
    if(r != nullptr){
        reportePasillos(r->getLeftSon());
        this->reportePasillo->insert(r->getHall()->getCode(),0);
        reportePasillos(r->getRightSon());
    }
}

void managerEST::reporteFacturas(ClientBNode *r){
    if(r != nullptr){
        int i;
        for(i=0; i<r->getCount(); i++){
            reporteFacturas(r->getChild(i));
            this->facturasClientes->addData(r->getValue(i+1)->getId(),0);
        }
        reporteFacturas(r->getChild(i));
    }
}

SalesList* managerEST::getVendidosGondolas(){
    return vendidosGondolas;
}

SalesList* managerEST::getVendidosInventario(){
    return vendidosInventario;
}

SalesList* managerEST::getVendidos(){
    return vendidos;
}

SalesList* managerEST::getMayorGondola(){
    return mayorGondola;
}

ReportListInt* managerEST::getReportePasillo(){
    return reportePasillo;
}

ReportListInt* managerEST::getReporteCliente(){
    return reporteCliente;
}

ReportListFloat* managerEST::getFacturasClientes(){
    return facturasClientes;
}

QueueClient* managerEST::getRegistrar(){
    return registrar;
}

void managerEST::setVendidosInventario(){
    vendidosInventario = new SalesList();
}

Grafo *managerEST::getGrafo(){
    return grafo;
}
