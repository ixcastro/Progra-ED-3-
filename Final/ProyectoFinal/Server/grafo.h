#ifndef GRAFO_H
#define GRAFO_H
#include "city.h"
#include <vector>
#include <QVector>
#include <QJsonObject>
#include <QJsonDocument>

class Connection{

public:
    int distance;
    City *cityA,*cityB;

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
    QVector<City*> cities; //Lista de ciudades
    int numCities;
    QVector<QVector<int>> connections; //Matriz adyacencia con pesos
    QVector<Connection*> connectionsList; //Lista de conexiones

public:
    Grafo();
    Grafo(int numCities, QVector<City*> nCities, QVector<Connection*> nConnectionsList);

    //QVector<QVector<int>> kruskal();
    int findCityConnection(int,int); //Le devuelve el peso de una conexion
    void printKruskal(QVector<QVector<int>>);

    void readFile(string);
    QJsonDocument kruskalToJson();




     //-----------------------------------------//
    //-------------------JM--------------------//
    //-----------------------------------------//

     //-----------------------------------------//
    // FUNCION PRINCIPLA
    // PUNTO DE INICIO, PUNTO FINAL,
    //VECTORES LLENOS DE 0 DEL MISMO LARGO QUE LA CANTIDAD DE VERTICES
    //-----------------------------------------//
    void dijkstra(string pDataS, string pDataF);

    //---------------GET---------------//

    // VECTOR DE LA MATRX
    QVector<QVector<int>>getConnections();

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
    // OBTIENE EL NUMERO DE NODO SEGUN SU LETRA
    int getPosLetra(string pData);

    void readFileConnections(string fileName);
    City *getCity(int c);
    int getCityCode(int number);
    QVector<Connection *> kruskal();
    QVector<Connection *> prim();
private:
    int PostInv;
    int Post;
    int Acumulado;
    vector<int> Temp;
    vector<int> Final;
    vector<string> Path;
    vector<int> vTemp;
    vector<int> vFinal;


    friend class managerEST;
};

#endif // GRAFO_H

