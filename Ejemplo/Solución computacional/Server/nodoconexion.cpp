#include <iostream>
#include "nodoconexion.h"
using namespace std;

nodoConexion::nodoConexion(string pCodigoConexion, string pCodPaisDest, string pCodCiudadDest, int pHoras, int pPrecio)
{
   codigoConexion = pCodigoConexion;
   codigoPaisDest = pCodPaisDest;
   codigoCiudadDest = pCodCiudadDest;
   horas = pHoras;
   precio= pPrecio;
   siguiente = nullptr;
   anterior =nullptr;
}
