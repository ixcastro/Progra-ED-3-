#ifndef NODO_H
#define NODO_H


#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(string pCodConexion, string pPais,string pCiudad, string pPaisDestino,string pCiudadDestino,int pPrecio, int pTiempo){
        pais = pPais;
        ciudad = pCiudad;
        paisDestino = pPaisDestino;
        ciudadDestino = pCiudadDestino;
        codConexion = pCodConexion;
        precio = pPrecio;
        tiempo = pTiempo;

        siguiente = nullptr;
        anterior = nullptr;
        visitado = false;

    }


private:
    string pais;
    string ciudad;
    string paisDestino;
    string ciudadDestino;
    string codConexion;
    int precio = 0;
    int tiempo = 0;
    nodo *siguiente;
    nodo *anterior;
    bool visitado;


   friend class listaD;
   friend class ListaPais;
};

typedef nodo *pnodo;

#endif // NODO_H

