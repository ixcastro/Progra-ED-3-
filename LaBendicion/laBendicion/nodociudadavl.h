#ifndef NODOCIUDADAVL_H
#define NODOCIUDADAVL_H

#include <iostream>
#include "nodoconexion.h"
using namespace std;

class nodoCiudad {
public:

    nodoCiudad(int pCodCiudad,string pNombre, nodoCiudad *der = NULL, nodoCiudad *izq = NULL, nodoCiudad *sig=NULL, nodoCiudad *ant=NULL, nodoConexion *conexion=NULL):
        CodCiudad(pCodCiudad), Nombre(pNombre), FB(0),Hizq(izq), Hder(der), siguiente(sig), anterior(ant), conexiones(conexion) {}


    int CodCiudad;
    string Nombre;
    int FB;
    nodoCiudad *Hizq, *Hder, *siguiente, *anterior;
    pnodoConexion conexiones;

    friend class nodoPais;
    friend class PrograI;
};

typedef nodoCiudad *pnodoCiudad;


#endif // NODOCIUDADAVL_H
