#ifndef LISTAPARAVERTICESKRUSKAL_H
#define LISTAPARAVERTICESKRUSKAL_H


#include <iostream>
#include "nodo.h"

using namespace std;

class listaD {
   public:
    listaD() {}

    bool ListaVacia() { return primero == nullptr; }
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
    int largoLista();


    void InsertarEnOrdenPrecio(string pCodConexion, string pPais,string pCiudad, string pPaisDestino,string pCiudadDestino,int pPrecio, int pTiempo);
    bool validar(string pPais,string pCiudad, string pPaisDestino,string pCiudadDestino,int pPrecio, int pTiempo);

   private:
    pnodo primero = nullptr;
    pnodo actual= nullptr;

  friend class ListaPais;
};

#endif // LISTAPARAVERTICESKRUSKAL_H
