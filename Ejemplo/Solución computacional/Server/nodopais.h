#ifndef NODOPAIS_H
#define NODOPAIS_H

#include <iostream>
#include "nodociudad.h"
using namespace std;

class nodoPais {
   public:
    nodoPais(string pCodigo, string pNombre)
    {
       codigo = pCodigo;
       nombre = pNombre;
       siguiente = nullptr;
       anterior = nullptr;
       ciudad = nullptr;
    }

 private:
    string codigo;
    string nombre;
    nodoCiudad *ciudad;
    nodoPais *siguiente;
    nodoPais *anterior;

   friend class ListaPais;
   friend class ServicioDeTrenes;
};
typedef nodoPais *pnodoPais;

#endif // NODOPAIS_H
