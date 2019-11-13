#ifndef GRAFO_H
#define GRAFO_H
#include "city.h"
#include <vector>

class Connection{
    int distance;
    City *cityA,*cityB;

public:
    Connection(){
    }

    Connection(City *a, City *b, int p){
        distance = p;
        cityA = a;
        cityB = b;
    }

    friend class Grafo;
};





class Grafo{
    const int INF = numeric_limits<int>::max();
    vector<City*> cities; //Lista de ciudades
    int numCities;
    vector<vector<int>> connections; //Matriz adyacencia con pesos
    vector<Connection*> connectionsList; //Lista de conexiones

public:
    Grafo();
    Grafo(int numCities, vector<City*> nCities, vector<Connection*> nConnectionsList);

    vector<vector<int>> kruskal();
    int findCityConnection(int,int); //Le devuelve el peso de una conexion
    void printKruskal(vector<vector<int>>);

    int primAlgorithm();
    int prims();
    int prim();

    void readFile(string);




     //-----------------------------------------//
    //-------------------JM--------------------//
    //-----------------------------------------//

     //-----------------------------------------//
    // FUNCION PRINCIPLA
    // PUNTO DE INICIO, PUNTO FINAL,
    //VECTORES LLENOS DE 0 DEL MISMO LARGO QUE LA CANTIDAD DE VERTICES
    //-----------------------------------------//
    void dijkstra(int pStart, int pFinal, vector<int> vTemp, vector<int> vFinal);

    //---------------GET---------------//

    // VECTOR DE LA MATRX
    vector<vector<int>>getConnections();

    // POSICION DE LA TABLA
    int getPost();

    // POSICION DE LA TABLA EN SENTIDO
    //CONTRARIO PARA LA RESPUESTA
    int getPostInv();

    // VECTOR PARA PESOS TEMPORALES
    vector<int> getTemp();

    // VECTOR DE PESOS FINALES
    vector<int> getFinal();

    // DATO ACUMULADOR
    int getAcumulado();

     //---------------SET--------------//
    // SET DEL VALOR DE LA POSICION EN LAS TABLAS
    void setPost(int pData);
    // SET DEL VALOR INVERTIDO EN LA TABLA
    void setPostInv(int pData);
    // SET DEL ACUMULADOR DE PESOS
    void setAcumulado(int pData);
    // SET DE LA TABLA DE PESOS TEMPORALES
    void setTemp(vector<int> pV);
    //SET DE LA TABLA DE PESOS FINALES
    void setFinal(vector<int> pV);


    //--------------------AUX-----------------------//
    // OBTINE LOS ADYACENTES DE UN NODO (SOLO PARA DIJKSTRA)
    void getAdyacente();
    // OBTIENE LOS ADYACENTES PARA LA RESPUESTA
    void getAdyacenteInverso();
    // OBTIENE EL MINIMO DE LOS PESOS EN LA TABLA TEMP
    void getMin();
    // SE FIJA SI TODOS LOS VERTICES FUERON VISTADOS
    bool checkAll();
    // MUESTRA LA TABLA Y SUS DATOS
    void showTable();
    // MUESTRA LA TABLA FINAL
    void showFinalTable();
    // MUESTRA EL CAMINO DE RESPUESTA
    void showPath();

private:
    int PostInv;
    int Post;
    int Acumulado;
    vector<int> Temp;
    vector<int> Final;
    vector<string> Path;






};

#endif // GRAFO_H

