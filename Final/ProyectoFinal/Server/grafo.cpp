#include "grafo.h"
#include <QDebug>

//---------------------//
#include <iostream>
#include <fstream>
using namespace std;
ofstream myfile;
//---------------------//

Grafo::Grafo(){
    numCities = 0;
}

Grafo::Grafo(int numCities, QVector<City*> nCities, QVector<Connection*> nConnectionsList){
    cities = nCities;
    connections = QVector<QVector<int>>(cities.size());
    this->numCities = numCities;
    connectionsList = nConnectionsList;

    for (int i = 0; i < numCities; i++)
        connections[i] = QVector<int>(cities.size(), 0); //Le asigna un valor muy grande a cada espacio de la matriz

    for(int j=0; j<connectionsList.size(); j++){
        int a = connectionsList[j]->cityA->getNumMatrix();
        int b = connectionsList[j]->cityB->getNumMatrix();

        connections[a][b] = connectionsList[j]->distance;
        connections[b][a] = connectionsList[j]->distance;
    }

    cout<<"Printing..."<<endl;
    for(int k = 0; k<connections.size(); k++){
        for(int x=0; x<connections.size(); x++){
            cout<<connections[k][x]<<" ";
        }
        cout<<endl;
    }
    //------------------------JM--------------------//

    for(int i=0; i < cities.size(); i++){
        vFinal.push_back(0);
        vTemp.push_back(0);
    }
    //------------------------JM--------------------//

}

int Grafo::getCityCode(int number){
    for(City *c : cities){
        if(c->getNumMatrix() == number){
            return c->getCode();
        }
    }
    return -1;
}

//QVector<QVector<int>> Grafo::kruskal(){
//    QVector<QVector<int>> ady = this->connections;



//    QVector<QVector<int>> arbol(cities.size());
//    QVector<int> pertenece(cities.size()); //Indica a que arbol pertenece el nodo

//    for(int i=0; i<numCities; i++){
//        arbol[i] = QVector<int>(cities.size(),0);
//        pertenece[i] = i;
//    }

//    int nodoA;
//    int nodoB;
//    int arcos = 1;
//    while(arcos < numCities){
//        //Encontrar el arco mínimo que no forma cíclo y guardar los nodos y la distancia
//        int min = INF;
//        for(int i = 0; i<numCities; i++){
//            for(int j=0; j<numCities; j++){
//                if(min > ady[i][j] && ady[i][j] != 0 && pertenece[i] != pertenece[j]){
//                    min = ady[i][j];
//                    nodoA = i;
//                    nodoB = j;
//                }
//            }
//        }
//        //Si los nodos no pertenecen al mismo arbol, agrego el arco al arbol minimo
//        if(pertenece[nodoA] != pertenece[nodoB]){
//            arbol[nodoA][nodoB] = min;
//            arbol[nodoB][nodoA] = min;

//            //Todos los nodos del arbol del nodoB ahora pertenecen al arbol del nodoA
//            int tmp = pertenece[nodoB];
//            pertenece[nodoB] = pertenece[nodoA];
//            for(int k=0; k<numCities; k++){
//                if(pertenece[k] == tmp){
//                    pertenece[k] = pertenece[nodoA];
//                }
//            }
//        }
//        arcos++;
//    }
//    return arbol;
//}

bool mayor(Connection *a, Connection *b){
    return a->distance < b->distance;
}

QVector<int> findSet(int id, QVector<Connection*> graph){
    QVector<int> set;
    set.append(id);

    bool added;

    do {
        added = false;
        for (Connection *connection : graph){
            if (set.contains(connection->cityA->getNumMatrix()) &&
                    !set.contains(connection->cityB->getNumMatrix())){
                set.append(connection->cityB->getNumMatrix());
                added = true;
                continue;
            }
            if (set.contains(connection->cityB->getNumMatrix()) &&
                    !set.contains(connection->cityA->getNumMatrix())){
                set.append(connection->cityA->getNumMatrix());
                added = true;
                continue;
            }
        }
    } while (added);

    return set;
}

QVector<Connection*> Grafo::kruskal(){
    QVector<Connection*> kGraph;
    QVector<Connection*> connections = connectionsList;

    sort(connections.begin(),connections.end(),mayor);
    for(Connection *connection : connections){
        if(!findSet(connection->cityA->getNumMatrix(), kGraph).contains(connection->cityB->getNumMatrix())){
            kGraph.append(connection);
        }
    }

    return kGraph;
}

QVector<Connection*> Grafo::prim(){
    QVector<Connection*> mst(connectionsList.size(), nullptr);
    QVector<Connection*>  fr(connectionsList.size(), nullptr);
    QVector<int>          wt(connectionsList.size(), std::numeric_limits<int>::max());


    int min = -1;
    for(int v = 0; min != 0; v = min){
        min = 0;
        for(int w = 1;w < numCities; w++){
            Connection* connection = nullptr;
            for (Connection *findingConnection : connectionsList){
                if((findingConnection->cityA->getNumMatrix() == v && findingConnection->cityB->getNumMatrix() == w) ||
                        (findingConnection->cityA->getNumMatrix() == w && findingConnection->cityB->getNumMatrix() == v)){
                    connection = findingConnection;
                    break;
                }
            }
            if(!mst[w]){
                if(connection)
                    if(connection->distance < wt[w]){
                        wt[w] = connection->distance;
                        fr[w] = connection;
                    }
                if(wt[w] < wt[min])
                    min = w;
            }
        }
        if(min)
            mst[min] = fr[min];
    }
    for (int i = 0; i < mst.size(); i++){
        if (!mst[i]){
            mst.remove(i);
        }
    }
    return mst;
}

void Grafo::readFile(string fileName){ //Primero leo las ciudades
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
        if(!cities.contains(c)){
            cities.append(c);
            i++;
        }
    }

    numCities = i+1;

    for(City *c : cities){
        cout<<c->toString()<<endl;
    }
}

void Grafo::readFileConnections(string fileName){
    ifstream file;
    file.open(fileName,ios::in);

    string t;
    QString text;

    if(file.fail()){
        cout<<"No se pudo abrir el archivo de conexiones"<<endl;
        exit(1);
    }

    while(!file.eof()){
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList list = text.split(";");
        bool check = false;
        bool check2 = false;

        for(City *c : cities){
            if(c->getCode() == list[0].toInt()){
                check = true;
            }
            if(c->getCode() == list[1].toInt()){
                check2 = true;
            }
        }

        if(check && check2){
            City *a = getCity(list[0].toInt());
            City *b = getCity(list[1].toInt());
            connectionsList.append(new Connection(a,b,list[2].toInt()));
        }
    }
}

QJsonDocument Grafo::primToJson(){
    QJsonArray ar;

    QVector<Connection*> pri = prim();

    int peso = 0;


    cout << pri.size() << endl;
    for(int i=0; i<pri.size(); i++){
        int a = pri[i]->cityA->getNumMatrix();
        int b = pri[i]->cityB->getNumMatrix();
        int p = pri[i]->distance;
        QJsonObject c; //Inserta a connections
        c.insert("A",a);
        c.insert("B",b);
        c.insert("P",p);
        peso += p;
        cout<<"A "<<a<<"  B "<<b<<"  P "<<p<<endl;
        ar.append(c);
    }

    QJsonObject connect;
    connect.insert("Connections",ar);
    connect.insert("NumCities",numCities);
    connect.insert("Peso",peso);

    QJsonArray ciudades;
    for(int i=0; i<numCities; i++){
        ciudades.append(cities[i]->getCode());
    }

    connect.insert("Codigos",ciudades);
    qDebug()<<connect;
    QJsonDocument informacionCiudades(connect);
    return informacionCiudades;
}

QJsonDocument Grafo::kruskalToJson(){ //Me devuelve Json para enviar
    QJsonArray ar;

    QVector<Connection*> krus = kruskal();

    int peso = 0;


    cout << krus.size() << endl;
    for(int i=0; i<krus.size(); i++){
        int a = krus[i]->cityA->getNumMatrix();
        int b = krus[i]->cityB->getNumMatrix();
        int p = krus[i]->distance;
        QJsonObject c; //Inserta a connections
        c.insert("A",a);
        c.insert("B",b);
        c.insert("P",p);
        peso += p;
        cout<<"A "<<a<<"  B "<<b<<"  P "<<p<<endl;
        ar.append(c);
    }

    QJsonObject connect;
    connect.insert("Connections",ar);
    connect.insert("NumCities",numCities);
    connect.insert("Peso",peso);

    QJsonArray ciudades;
    for(int i=0; i<numCities; i++){
        ciudades.append(cities[i]->getCode());
    }

    connect.insert("Codigos",ciudades);
    qDebug()<<connect;
    QJsonDocument informacionCiudades(connect);
    return informacionCiudades;
}

City* Grafo::getCity(int code){
    for(City *c : cities){
        if(c->getCode() == code){
            return c;
        }
    }
    return nullptr;
}


//------------------------JM----------------------------//

//----------------------GET-SET------------------------//

int Grafo::getPost(){
    return Post;
}

int Grafo::getPostInv(){
    return PostInv;
}

int Grafo::getAcumulado(){
    return Acumulado;
}

vector<int> Grafo::getTemp(){
    return Temp;
}

vector<int> Grafo::getFinal(){
    return Final;
}



void Grafo::setAcumulado(int pData){
    Acumulado=pData;
}


void Grafo::setPost(int pData){
    Post=pData;
}

void Grafo::setPostInv(int pData){
    PostInv=pData;
}

void Grafo::setTemp(vector<int> pV){
    Temp =pV;
}

void Grafo::setFinal(vector<int> pV){
    Final =pV;
}



//--------------------GETCONNECTION--------------------//

QVector<QVector<int>> Grafo::getConnections(){
    return  connections;
}


//----------------------Dijkstra-----------------------//

void Grafo::dijkstra(string pDataS, string pDataF){

   // cout<<"hola"<<endl;
    //---------------------//
    myfile.open ("Dijkstra.txt");
    //---------------------//
    int pStart = getPosLetra(pDataS);
    int pFinal =  getPosLetra (pDataF);
    setAcumulado(0);//ACUMULADO EN 0
    setPost(pStart);// POSICION INICAL
    vTemp[pStart] = -1;// CAMBIO DE VALOR DE 0 A -1 PARA EVITAR SOBRE ESCRITURA

    setTemp(vTemp);// SET DE TABLA TEMPORAL
    setFinal(vFinal);// SET DE TABLA FINAL

    setPostInv(pFinal);// SET DE LA POS FINAL
    Path.push_back(cities[pFinal]->getName().toStdString());// SET DEL PRIMER DATO DEL PATH

    while(checkAll()){// MIENTRAS QUE AUN EXISTAN NODOS SIN VISITAR
        myfile<< "--------------------------------------"<<endl;
        myfile<<"ANALIZANDO: "<<cities[getPost()]->getName().toStdString()<<endl;

        getAdyacente();//BUSQUEDA DE NODOS ADYACENTES
        showTable();// MUESTRA LA TABLA DE RESULTADOS
        getMin();// MUESTRA EL DATO ELEGIDO COMO CAMINO DE MENO PESO
        showTable();// MUESTRA LOS CAMBIOS EN LA TABLA
    }

    showFinalTable();// MUESTRA LA TABLA FINAL
    myfile<< "--------------------------------------"<<endl;
    myfile<< " EL PESO DEL CAMINO MAS CORTO ES : " << getFinal()[pFinal]<<endl;
    myfile<< "--------------------------------------"<<endl;


    while(getPostInv()!=pStart){// MIENTRAS NO SE LLEGUE AL PRIMER NODO (START)
        getAdyacenteInverso();// BUSQUEDA DE ADYACENTES INVERSOS
    }

    myfile<< "--------------------------------------"<<endl;
    myfile<< "EL RECORRDIO DE VERTICES ES :"<<endl;
    showPath();// MUESTRA EL PATH
    cout << "--------------------------------------"<<endl;



     myfile.close();

}


//--------------------------AUX------------------------//

// OBTINE LOS ADYACENTES DE UN NODO (SOLO PARA DIJKSTRA)

void Grafo::getAdyacente(){

    // posicion de busqueda
    int pPos = getPost();
    string  vtS;

    // vector de adyacentes
    vector<int> pTemp = getTemp();

    myfile<< "--------------------------------------"<<endl;
    myfile<<"LOS ADYACENTES DE "<<cities[pPos]->getName().toStdString()<<" SON: "<<endl;
    myfile<< "--------------------------------------"<<endl;
    myfile<< " CIUDAD |  DATO  | DATO MAS ACUMULADO "<<endl;
    myfile<< "--------------------------------------"<<endl;

    // recorre la matriz
    for(int j=0; j < pTemp.size(); j++){

        vtS = vtS + to_string(getConnections()[pPos][j]) + " , " ;

        // con pos anclado busca adyacentes
        if (getConnections()[pPos][j] != 0){

            // si el temp es 0 lo sobre escribe y le suma el acumulado
            if(pTemp[j] == 0){

                pTemp[j] = getConnections()[pPos][j] + getAcumulado();

                myfile<<"    "<<cities[j]->getName().toStdString()<<"   |    "<<
                        getConnections()[pPos][j]<< "   |    "<<
                        getConnections()[pPos][j] <<"   +   "<< getPost()<<"  =  "<<  getConnections()[pPos][j] + getAcumulado()<<endl;
                myfile<< "--------------------------------------"<<endl;

            }else{
                // si temp es menor al nuevo numero lo sobre escribe y le suma el acumulado
                if( getPost() > 0 &&  pTemp[j] > getConnections()[pPos][j] + getAcumulado()){

                    pTemp[j] = getConnections()[pPos][j] + getAcumulado();

                    myfile<<"    "<<cities[j]->getName().toStdString()<<"   |    "<<
                            getConnections()[pPos][j]<< "   |    "<<
                            getConnections()[pPos][j] <<"   +   "<< getPost()<<"  =  "<<  getConnections()[pPos][j] + getAcumulado()<<endl;
                    myfile<< "--------------------------------------"<<endl;
                }
            }

        }
    }

    // si el dato no es 0
    if(pPos!=0){
        pTemp[getPost()] = pTemp[getPost()]*-1;
    }
    // set al tem
    setTemp(pTemp);
    myfile<<endl;
    myfile<<"--------------------------------------"<<endl;
    myfile<<"            VECTOR ANALIZADO           "<<endl;
    myfile<<"--------------------------------------"<<endl;
    myfile<<"   "<<vtS <<endl;
    myfile<<"--------------------------------------"<<endl;
}







// OBTIENE EL MINIMO DE LOS PESOS EN LA TABLA TEMP

void Grafo::getMin(){

    vector<int> pTemp  = getTemp();
    vector<int> pFinal = getFinal();

    int min = 500;
    int save =0;

    myfile<<endl;
    myfile<<endl;
    myfile<< "--------------------------------------"<<endl;
    myfile<< "   BUSCANDO EL CAMINO MAS CORTO        "<<endl;
    myfile<< "--------------------------------------"<<endl;
    myfile<<endl;
    myfile<<endl;

    // recorre el vector de temp buscando el menor
    for(int i=0; i < pTemp.size(); i++){
        if (
                pTemp[i]> 0 &&// no es 0 ni uno marcado
                min > pTemp[i]// es menor al minimo
                ){

            min = pTemp[i];
            save = i;
        }
    }

    myfile<< "--------------------------------------"<<endl;
    myfile<< "EL CAMINO MAS CORTO ES  : "<<cities[save]->getName().toStdString()<<endl;
    myfile<< "--------------------------------------"<<endl;
    myfile<< "EL VALOR DEL ACUMULADO ES: "<<min<<endl;
    myfile<< "--------------------------------------"<<endl;
    myfile<< "SELECCIONAMOS EL VERTICE : "<< cities[save]->getName().toStdString()<<endl;
    myfile<< "--------------------------------------"<<endl;
    myfile<< "COMO NUEVA ETIQUETA FINAL EN LA TABLA"<<endl;
    myfile<< "--------------------------------------"<<endl;

    setPost(save);
    setAcumulado(min);
    pFinal[save]= min;
    setFinal(pFinal);

}





// SE FIJA SI TODOS LOS VERTICES FUERON VISTADOS

bool Grafo::checkAll(){
    int check = 0;
    vector<int> pFinal = getFinal();

    for(int i=0; i < pFinal.size(); i++){
        if (pFinal[i]==0){
            check++;
        }
    }

    if(check==1){
        return false;
    }
    else{
        return true;
    }
}



// MUESTRA LA TABLA Y SUS DATOS EN CADA ACTUALIZACION

void Grafo::showTable(){
    vector<int> pTemp  = getTemp();
    vector<int> pFinal = getFinal();

    myfile<<endl;
    myfile<<endl;
    myfile<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    myfile<< "--------------------------------------"<<endl;
    myfile<<"   CIUDAD  |  FINAL   |   TEMP     "<<endl;
    myfile<< "--------------------------------------"<<endl;

    for(int i=0; i < pFinal.size(); i++){
        myfile<<"     "<< cities[i]->getName().toStdString()
             <<"     |     "<<pFinal[i]<<"    |    "<<pTemp[i]<<"    "<<endl;
        myfile<< "--------------------------------------"<<endl;
    }

    myfile<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    myfile<<endl;
    myfile<<endl;

}


// MUESTRA LA TABLA FINAL CON LOS ULTIMOS DATOS RELEVANTES

void Grafo::showFinalTable(){

    vector<int> pTemp  = getTemp();
    vector<int> pFinal = getFinal();

    myfile<<endl;
    myfile<<endl;
    myfile<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    myfile<<"            TABLA FINAL              "<<endl;
    myfile<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    myfile<< "--------------------------------------"<<endl;
    myfile<<"   CIUDAD  |  FINAL   |   TEMP     "<<endl;
    myfile<< "--------------------------------------"<<endl;

    for(int i=0; i < pFinal.size(); i++){
        if(pFinal[i] == 0 && pTemp[i] == -1 ){
            pTemp[i]=0;
        }
        if( pTemp[i] < 0){
            pTemp[i] =  pTemp[i]*-1;

        }
        myfile<<"     "<< cities[i]->getName().toStdString()
             <<"     |     "<<pFinal[i]<<"    |    "<<pTemp[i]<<"    "<<endl;
        myfile<< "--------------------------------------"<<endl;
    }

    myfile<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    myfile<<endl;
    myfile<<endl;
    setTemp(pTemp);
    setFinal(pFinal);

}


// MUESTRA EL CAMINO DE RESPUESTA

void Grafo::showPath(){
    for(int j=Path.size()-1; j !=-1; j--){
          myfile<< Path[j] << "-";
    }
    myfile<<endl;
}



// OBTIENE LOS ADYACENTES PARA LA RESPUESTA

void Grafo::getAdyacenteInverso(){

    // posicion de busqueda
    int pPos = getPostInv();

    // vectores adyacentes
    vector<int> pTemp = getTemp();
    vector<int> pFinal = getFinal();

    for(int j=0; j < pTemp.size(); j++){
        // con pos anclado busca adyacentes
        if (getConnections()[pPos][j] != 0){
            if( pFinal[pPos] -  getConnections()[pPos][j] ==  pFinal[j]){
                //                cout<< pFinal[pPos] <<" -"<<  getConnections()[pPos][j] <<" =" <<pFinal[j]<<endl;
                //                cout<<"VERTICE "<<cities[j]->getName().toStdString()<<endl;
                // push data
                Path.push_back(cities[j]->getName().toStdString());
                //set new postinv
                setPostInv(j);
            }
        }
    }
}




// OBTIENE EL NUMERO DE NODO SEGUN SU LETRA

int Grafo::getPosLetra(string pData){
    for(int j=0; j < cities.size(); j++){
        if(pData ==  cities[j]->getName().toStdString()){
            return  cities[j]->getNumMatrix();
        }
    }
}
