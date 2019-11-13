#ifndef NODOCONEXION_H
#define NODOCONEXION_H
#include <iostream>

using namespace std;

class nodoConexion
{
public:
    nodoConexion(int pCodigoConexion, int pCodPaisDest, int pCodCiudadDest, string pHoras, int pPrecio)
    {
        codigoConexion = pCodigoConexion;
        codigoPaisDest = pCodPaisDest;
        codigoCiudadDest = pCodCiudadDest;
        horas = pHoras;
        precio = pPrecio;
        color = true;
        HD = nullptr;
        HI = nullptr;
        padre = nullptr;
    }
private:
    int codigoConexion;
    int codigoPaisDest;
    int codigoCiudadDest;
    string horas;
    int precio;
    bool color;
    nodoConexion *HD;
    nodoConexion *HI;
    nodoConexion *padre;

friend class arbolPaises;
friend class ServicioDeTrenes;

};
typedef nodoConexion *pnodoConexion;
#endif // NODOCONEXION_H
