#include<iostream>
#include "nododijkstra.h"
#include "nodoconexion.h"

using namespace std;

nodoDijkstra::nodoDijkstra(string pCodPais, string pCodigoCiudad, int pPeso){
    CodPais = pCodPais;
    codigoCiudad = pCodigoCiudad;
    total = pPeso;
    otroCamino = nullptr;
    siguiente = nullptr;
    anterior =nullptr;
    predecesor = nullptr;
}
