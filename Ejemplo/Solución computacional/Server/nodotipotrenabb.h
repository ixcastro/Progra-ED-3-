#ifndef NODOTIPOTRENABB_H
#define NODOTIPOTRENABB_H


#include <iostream>
#include "nodotrenvl.h"

using namespace std;

class nodoTipoTren {
public:

    nodoTipoTren(int pTipoTren, nodoTipoTren *der = NULL, nodoTipoTren *izq = NULL, nodoTipoTren *sig=NULL, nodoTipoTren *ant=NULL, nodoTipoTren *ciud=NULL):
        TipoTren(pTipoTren), FB(0),Hizq(izq), Hder(der), siguiente(sig), anterior(ant), Trenes(nullptr) {}


    int TipoTren;
    int FB;
    nodoTipoTren *Hizq, *Hder, *siguiente, *anterior;
    nodoTren *Trenes;

    void InsertaBinario(int pTipoTren);

    friend class arbolTrenes;
};

typedef nodoTipoTren *pnodoTipoTren;
#endif // NODOTIPOTRENABB_H
