#ifndef NODOCIUDAD_H
#define NODOCIUDAD_H

#include <iostream>
#include "nodoconexion.h"
#include "nodoatracciones.h"
using namespace std;

class nodoCiudad {
   public:
    nodoCiudad(string pCodigoCiudad, string pNombre)
    {
       codigoCiudad = pCodigoCiudad;
       nombre = pNombre;
       conexion = nullptr;
       siguiente = nullptr;
       anterior =nullptr;
       visitado = false;
       atracciones = nullptr;
    }

 private:
    string codigoCiudad;
    string nombre;
    nodoConexion *conexion;
    nodoAtraccion *atracciones;
    nodoCiudad *siguiente;
    nodoCiudad *anterior;
    bool visitado;


   friend class ListaPais;
   friend class ServicioDeTrenes;
   friend class lista;
};
typedef nodoCiudad *pnodoCiudad;

#endif // NODOCIUDAD_H
