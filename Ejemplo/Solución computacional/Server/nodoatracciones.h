#ifndef NODOATRACCIONES_H
#define NODOATRACCIONES_H

#ifndef NODOATRACCION_H
#define NODOATRACCION_H

#include <iostream>

using namespace std;

class nodoAtraccion {
   public:
    nodoAtraccion(string pCodAtraccion, string pNombre, string pPrecio){
       CodAtraccion = pCodAtraccion;
       nombre = pNombre;
       precio = pPrecio;
       siguiente = nullptr;
       anterior = nullptr;
    }

 private:
    string CodAtraccion;
    string precio;
    string nombre;
    nodoAtraccion *siguiente;
    nodoAtraccion *anterior;

   friend class ListaPais;
   friend class ServicioDeTrenes;
};
typedef nodoAtraccion *pnodoAtraccion;

#endif // NODOATRACCION_H

#endif // NODOATRACCIONES_H
