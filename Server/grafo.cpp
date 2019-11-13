#include "grafo.h"

Grafo::Grafo(){
}

Grafo::Grafo(int numCities, vector<City*> nCities, vector<Connection*> nConnectionsList){
    cities = nCities;
    connections = vector<vector<int>>(cities.size());
    this->numCities = numCities;
    connectionsList = nConnectionsList;

    for (int i = 0; i < numCities; i++)
        connections[i] = vector<int>(cities.size(), 0); //Le asigna un valor muy grande a cada espacio de la matriz

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
}

vector<vector<int>> Grafo::kruskal(){
    vector<vector<int>> ady = this->connections;
    vector<vector<int>> arbol(cities.size());
    vector<int> pertenece(cities.size()); //Indica a que arbol pertenece el nodo

    for(int i=0; i<numCities; i++){
        arbol[i] = vector<int>(cities.size(),0);
        pertenece[i] = i;
    }

    int nodoA;
    int nodoB;
    int arcos = 1;
    while(arcos < numCities){
        //Encontrar el arco mínimo que no forma cíclo y guardar los nodos y la distancia
        int min = INF;
        for(int i = 0; i<numCities; i++){
            for(int j=0; j<numCities; j++){
                if(min > ady[i][j] && ady[i][j] != 0 && pertenece[i] != pertenece[j]){
                    min = ady[i][j];
                    nodoA = i;
                    nodoB = j;
                }
            }
        }
        //Si los nodos no pertenecen al mismo arbol, agrego el arco al arbol minimo
        if(pertenece[nodoA] != pertenece[nodoB]){
            arbol[nodoA][nodoB] = min;
            arbol[nodoB][nodoA] = min;

            //Todos los nodos del arbol del nodoB ahora pertenecen al arbol del nodoA
            int tmp = pertenece[nodoB];
            pertenece[nodoB] = pertenece[nodoA];
            for(int k=0; k<numCities; k++){
                if(pertenece[k] == tmp){
                    pertenece[k] = pertenece[nodoA];
                }
            }
            arcos++;
        }
    }
    return arbol;
}

void Grafo::printKruskal(vector<vector<int>> arbol){
    cout<<"Kruskal..."<<endl;
    for(int i=0; i<arbol.size(); i++){
        for(int j=0; j<arbol.size(); j++){
            cout<<arbol[i][j]<<" ";
        }
        cout<<endl;
    }
}

int Grafo::primAlgorithm(){
    vector<vector<int>> matrix = this->connections;
    //vector<vector<int>> arbol(cities.size());

    int minDistance;
    int minor;
    int z;
    vector<int> cost(cities.size()); //Indica a que arbol pertenece el nodo
    vector<int> closest(cities.size()); //Indica a que arbol pertenece el nodo
    vector<bool> W(cities.size()); //Indica a que arbol pertenece el nodo

    for (int i = 0; i < cities.size(); i++) {
        W[i] = false;
    }

    minDistance = 0;
    W[0] = true;

    //For every arc starting in [0][1]
    for (int i = 1; i < cities.size(); i++) {
        cost[i] = matrix[0][i];
        closest[i] = 0;
    }
    for (int i = 1; i < cities.size(); i++) {
        //searches for the acr with less weigth from
        // Z to W
        //minor = cost[1];
        for (int k = 1; k < cities.size(); k++) {
            if (cost[k] > 0){
                minor = cost[k];
                z = k;
            }
        }
        z = 1;
        for (int j = 2; j < cities.size(); j++) {
            if (cost[j] > 0){
                if (cost[j] < minor){
                    minor = cost[j];
                    z = j;
                }
            }
        }
        minDistance += minor;
        cout << "Pasada: Vertice " <<
                cities[closest[z]]->getName().toStdString() <<
                " -> Vertice " << cities[z]->getName().toStdString() << " Peso: " <<
                cost[z] << endl;
        W[z] = true;
        cost[z] = 0;

        //Cost starts in 0 again
        for (int j = 1; j < cities.size() ; j++) {
            if ((matrix[z][j] < cost[j]) && !W[j]){
                cost[j] = matrix[z][j];
                closest[j] = z;
            }
        }
    }
    cout << "La distancia minima recorrida es de: " << minDistance <<endl;
    cout << "printinf infite: "<< INF <<endl;
    return minDistance;
}

#define infinity 9999
#define MAX 20

int G[MAX][MAX],spanning[MAX][MAX],n;

int Grafo::prims(){
    int cost[MAX][MAX];
    int u,v,min_distance,distance[MAX],from[MAX];
    int visited[MAX],no_of_edges,i,min_cost,j;

    //create cost[][] matrix,spanning[][]
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(G[i][j]==0)
                cost[i][j]=infinity;
            else
                cost[i][j]=G[i][j];
            spanning[i][j]=0;
        }

    //initialise visited[],distance[] and from[]
    distance[0]=0;
    visited[0]=1;

    for(i=1;i<n;i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }

    min_cost=0;		//cost of spanning tree
    no_of_edges=n-1;		//no. of edges to be added

    while(no_of_edges>0)
    {
        //find the vertex at minimum distance from the tree
        min_distance=infinity;
        for(i=1;i<n;i++)
            if(visited[i]==0&&distance[i]<min_distance)
            {
                v=i;
                min_distance=distance[i];
            }

        u=from[v];

        //insert the edge in spanning tree
        spanning[u][v]=distance[v];
        spanning[v][u]=distance[v];
        no_of_edges--;
        visited[v]=1;

        //updated the distance[] array
        for(i=1;i<n;i++)
            if(visited[i]==0&&cost[i][v]<distance[i])
            {
                distance[i]=cost[i][v];
                from[i]=v;
            }

        min_cost=min_cost+cost[u][v];
    }

    return(min_cost);

}

int Grafo::prim(){
    int cost[cities.size()][cities.size()];
    vector<vector<int>> Gg = this->connections;
    //int Gg[cities.size()][cities.size()];
    int span[cities.size()][cities.size()];
    int u,v,min_distance,distance[cities.size()],from[cities.size()];
    int visited[cities.size()],no_of_edges,i,min_cost,j;

    //fill the spanning with 0s
    for(int i = 0; i < cities.size(); i++){
        for(int j = 0; j < cities.size(); j++){
            span[i][j] = 0;
        }
    }

    //create cost[][] matrix,spanning[][]
    for( i = 0; i < cities.size(); i++) {
        for( j = 0; j < cities.size(); j++)
        {
            if(Gg[i][j] == 0) {
                cost[i][j] = 9999;
                //change for INF
            } else {
                cost[i][j] = Gg[i][j];
                span[i][j] = 0;
            }
        }
    }
    //

    //initialise visited[],distance[] and from[]
    distance[0] = 0;
    visited[0] = 1;

    for(i = 1; i < cities.size(); i++) {
        distance[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }

    min_cost = 0;		//cost of spanning tree
    no_of_edges = cities.size()-1;		//no. of edges to be added

    while(no_of_edges > 0) {
        //find the vertex at minimum distance from the tree
        min_distance = 9999;
        for(i = 1; i < cities.size(); i++) {
            if(visited[i] == 0  &&  distance[i] < min_distance) {
                v = i;
                min_distance = distance[i];
            }
        }
        u = from[v];

        //insert the edge in spanning tree
        span[u][v] = distance[v];
        span[v][u] = distance[v];
        no_of_edges--;
        visited[v] = 1;

        //updated the distance[] array
        for( i = 1; i < cities.size(); i++) {
            if(visited[i] == 0  &&  cost[i][v] < distance[i])
            {
                distance[i] = cost[i][v];
                from[i] = v;
            }
        }
        min_cost = min_cost + cost[u][v];
    }
    cout<<"Prim..."<<endl;
    for(int i=0; i < cities.size(); i++){
        for(int j=0; j < cities.size(); j++){
            cout<<span[i][j]<<" ";
        }
        cout<<endl;
    }

    cout << "Minium cost is: "<<min_cost<<endl;
    return(min_cost);

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

    int pNumCities = 0;
    vector<City*> pCities;
    vector<Connection*> pConnectionsList;

    while(!file.eof()){
        getline(file,t);
        text = QString::fromStdString(t);

    }

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

vector<vector<int>> Grafo::getConnections(){
    return  connections;
}


//----------------------Dijkstra-----------------------//

void Grafo::dijkstra(int pStart, int pFinal, vector<int> vTemp, vector<int> vFinal){

    setAcumulado(0);//ACUMULADO EN 0
    setPost(pStart);// POSICION INICAL
    vTemp[pStart] = -1;// CAMBIO DE VALOR DE 0 A -1 PARA EVITAR SOBRE ESCRITURA

    setTemp(vTemp);// SET DE TABLA TEMPORAL
    setFinal(vFinal);// SET DE TABLA FINAL

    setPostInv(pFinal);// SET DE LA POS FINAL
    Path.push_back(cities[pFinal]->getName().toStdString());// SET DEL PRIMER DATO DEL PATH



    while(checkAll()){// MIENTRAS QUE AUN EXISTAN NODOS SIN VISITAR
        cout << "--------------------------------------"<<endl;
        cout<<"ANALIZANDO: "<<cities[getPost()]->getName().toStdString()<<endl;

        getAdyacente();//BUSQUEDA DE NODOS ADYACENTES
        showTable();// MUESTRA LA TABLA DE RESULTADOS
        getMin();// MUESTRA EL DATO ELEGIDO COMO CAMINO DE MENO PESO
        showTable();// MUESTRA LOS CAMBIOS EN LA TABLA
    }
    showFinalTable();// MUESTRA LA TABLA FINAL
    cout << "--------------------------------------"<<endl;
    cout << " EL PESO DEL CAMINO MAS CORTO ES : " << getFinal()[pFinal]<<endl;
    cout << "--------------------------------------"<<endl;


    while(getPostInv()!=pStart){// MIENTRAS NO SE LLEGUE AL PRIMER NODO (START)
        getAdyacenteInverso();// BUSQUEDA DE ADYACENTES INVERSOS
    }

    cout << "--------------------------------------"<<endl;
    cout << "EL RECORRDIO DE VERTICES ES :"<<endl;
    showPath();// MUESTRA EL PATH
    cout << "--------------------------------------"<<endl;


}


//--------------------------AUX------------------------//

// OBTINE LOS ADYACENTES DE UN NODO (SOLO PARA DIJKSTRA)

void Grafo::getAdyacente(){

    // posicion de busqueda
    int pPos = getPost();
    string  vtS;

    // vector de adyacentes
    vector<int> pTemp = getTemp();

    cout << "--------------------------------------"<<endl;
    cout<<"LOS ADYACENTES DE "<<cities[pPos]->getName().toStdString()<<" SON: "<<endl;
    cout << "--------------------------------------"<<endl;
    cout << " CIUDAD |  DATO  | DATO MAS ACUMULADO "<<endl;
    cout << "--------------------------------------"<<endl;

    // recorre la matriz
    for(int j=0; j < pTemp.size(); j++){

        vtS = vtS + to_string(getConnections()[pPos][j]) + " , " ;

        // con pos anclado busca adyacentes
        if (getConnections()[pPos][j] != 0){

            // si el temp es 0 lo sobre escribe y le suma el acumulado
            if(pTemp[j] == 0){

                pTemp[j] = getConnections()[pPos][j] + getAcumulado();

                cout<<"    "<<cities[j]->getName().toStdString()<<"   |    "<<
                      getConnections()[pPos][j]<< "   |    "<<
                      getConnections()[pPos][j] <<"   +   "<< getPost()<<"  =  "<<  getConnections()[pPos][j] + getAcumulado()<<endl;
                cout << "--------------------------------------"<<endl;

            }else{
                // si temp es menor al nuevo numero lo sobre escribe y le suma el acumulado
                if( getPost() > 0 &&  pTemp[j] > getConnections()[pPos][j] + getAcumulado()){

                    pTemp[j] = getConnections()[pPos][j] + getAcumulado();

                    cout<<"    "<<cities[j]->getName().toStdString()<<"   |    "<<
                          getConnections()[pPos][j]<< "   |    "<<
                          getConnections()[pPos][j] <<"   +   "<< getPost()<<"  =  "<<  getConnections()[pPos][j] + getAcumulado()<<endl;
                    cout << "--------------------------------------"<<endl;
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
    cout<<endl;
    cout <<"--------------------------------------"<<endl;
    cout<<"            VECTOR ANALIZADO           "<<endl;
    cout <<"--------------------------------------"<<endl;
    cout <<"   "<<vtS <<endl;
    cout <<"--------------------------------------"<<endl;
}







// OBTIENE EL MINIMO DE LOS PESOS EN LA TABLA TEMP

void Grafo::getMin(){

    vector<int> pTemp  = getTemp();
    vector<int> pFinal = getFinal();

    int min = 500;
    int save =0;

    cout<<endl;
    cout<<endl;
    cout << "--------------------------------------"<<endl;
    cout << "   BUSCANDO EL CAMINO MAS CORTO        "<<endl;
    cout << "--------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;

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

    cout << "--------------------------------------"<<endl;
    cout << "EL CAMINO MAS CORTO ES  : "<<cities[save]->getName().toStdString()<<endl;
    cout << "--------------------------------------"<<endl;
    cout << "EL VALOR DEL ACUMULADO ES: "<<min<<endl;
    cout << "--------------------------------------"<<endl;
    cout << "SELECCIONAMOS EL VERTICE : "<< cities[save]->getName().toStdString()<<endl;
    cout << "--------------------------------------"<<endl;
    cout << "COMO NUEVA ETIQUETA FINAL EN LA TABLA"<<endl;
    cout << "--------------------------------------"<<endl;

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

    cout<<endl;
    cout<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout << "--------------------------------------"<<endl;
    cout<<"   CIUDAD  |  FINAL   |   TEMP     "<<endl;
    cout << "--------------------------------------"<<endl;

    for(int i=0; i < pFinal.size(); i++){
        cout<<"     "<< cities[i]->getName().toStdString()
           <<"     |     "<<pFinal[i]<<"    |    "<<pTemp[i]<<"    "<<endl;
        cout << "--------------------------------------"<<endl;
    }

    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<endl;
    cout<<endl;

}


// MUESTRA LA TABLA FINAL CON LOS ULTIMOS DATOS RELEVANTES

void Grafo::showFinalTable(){

    vector<int> pTemp  = getTemp();
    vector<int> pFinal = getFinal();

    cout<<endl;
    cout<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<"            TABLA FINAL              "<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout << "--------------------------------------"<<endl;
    cout<<"   CIUDAD  |  FINAL   |   TEMP     "<<endl;
    cout << "--------------------------------------"<<endl;

    for(int i=0; i < pFinal.size(); i++){
        if(pFinal[i] == 0 && pTemp[i] == -1 ){
            pTemp[i]=0;
        }
        if( pTemp[i] < 0){
            pTemp[i] =  pTemp[i]*-1;

        }
        cout<<"     "<< cities[i]->getName().toStdString()
           <<"     |     "<<pFinal[i]<<"    |    "<<pTemp[i]<<"    "<<endl;
        cout << "--------------------------------------"<<endl;
    }

    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<endl;
    cout<<endl;
    setTemp(pTemp);
    setFinal(pFinal);

}


// MUESTRA EL CAMINO DE RESPUESTA

void Grafo::showPath(){
    for(int j=Path.size()-1; j !=-1; j--){
        cout<< Path[j] << "-";
    }
    cout<<endl;
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
