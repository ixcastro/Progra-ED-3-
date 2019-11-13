#ifndef NODOTRENVL_H
#define NODOTRENVL_H

#include <iostream>
#include "nodoruta.h"
using namespace std;

class nodoTren {
public:

    nodoTren(int pCodTren,string pNombre, string pnumAsientos, int pCodCiudadSalida, int pCodPaisSalida, nodoTren *der = NULL, nodoTren *izq = NULL, nodoTren *sig=NULL, nodoTren *ant=NULL, NodoRuta *pRutas = NULL):
        CodTren(pCodTren), Nombre(pNombre), numAsientos(pnumAsientos), CodCiudadSalida(pCodCiudadSalida), CodPaisSalida(pCodPaisSalida) ,FB(0),Hizq(izq), Hder(der), siguiente(sig), anterior(ant), rutas(pRutas) {}


    int CodTren;
    string Nombre;
    string numAsientos;
    int CodCiudadSalida;
    int CodPaisSalida;

    int FB;
    nodoTren *Hizq, *Hder, *siguiente, *anterior;
    pnodoRuta rutas;
    friend class nodoTipoTren;
    friend class arbolTrenes;
};

typedef nodoTren *pnodoTren;

#endif // NODOTRENVL_H
