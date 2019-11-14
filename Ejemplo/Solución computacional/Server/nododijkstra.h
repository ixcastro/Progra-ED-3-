#ifndef NODODIJKSTRA_H
#define NODODIJKSTRA_H
#include <iostream>
//#include "nodoconexion.h"

using namespace std;

class nodoDijkstra {
   public:
    nodoDijkstra(string pCodPais, string pCodigoCiudad, int pPeso);

//    void InsertarConexion(pnodoConexion &pConexion);

 private:

    int total=0;
    string CodPais;
    string codigoCiudad;
    string paisSalida;
    string ciudadSalida;
    nodoDijkstra *siguiente;
    nodoDijkstra *anterior;
    nodoDijkstra *otroCamino;
    nodoDijkstra *predecesor;

    bool visitado;
   friend class ListaConexiones;
   friend class ListaPais;
   friend class ServicioDeTrenes;
};

typedef nodoDijkstra *pnodoDijkstra;


#endif // NODODIJKSTRA_H
