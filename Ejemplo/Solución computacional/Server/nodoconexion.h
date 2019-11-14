#include <iostream>
using namespace std;

class nodoConexion {
   public:
    nodoConexion(string pCodigoConexion, string pCodPaisDest, string pCodCiudadDest, int pHoras, int pPrecio);

 private:
    string codigoConexion;
    string codigoPaisDest;
    string codigoCiudadDest;
    int horas;
    int precio;
    nodoConexion *siguiente;
    nodoConexion *anterior;


   friend class ListaPais;
   friend class ServicioDeTrenes;
};
typedef nodoConexion *pnodoConexion;
