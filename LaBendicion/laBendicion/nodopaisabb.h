#ifndef NODOPAISABB_H
#define NODOPAISABB_H

#include <iostream>
#include "nodociudadavl.h"

using namespace std;

class nodoPais {
public:

    nodoPais(int pCodPais,string pNombre, nodoPais *der = NULL, nodoPais *izq = NULL, nodoPais *sig=NULL, nodoPais *ant=NULL, nodoCiudad *ciud=NULL):
        CodPais(pCodPais), Nombre(pNombre), FB(0),Hizq(izq), Hder(der), siguiente(sig), anterior(ant), Ciudades(ciud) {}


    int CodPais;
    string Nombre;
    int FB;
    nodoPais *Hizq, *Hder, *siguiente, *anterior;
    pnodoCiudad Ciudades;

    void InsertaBinario(int pCodPais, string pNombre);

    friend class arbolPaises;
};

typedef nodoPais *pnodoPais;

#endif // NODOPAISABB_H
