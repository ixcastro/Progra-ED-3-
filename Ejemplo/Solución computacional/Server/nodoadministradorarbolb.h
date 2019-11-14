#ifndef NODOADMINISTRADORARBOLB_H
#define NODOADMINISTRADORARBOLB_H

#include <iostream>
using namespace std;

class nodoAdministrador {
    public:
        nodoAdministrador(int pCodAdministrador, string pNombre){
            CodAdministrador = pCodAdministrador;
            Nombre = pNombre;

            siguiente = nullptr;
            anterior = nullptr;
        }

    private:
        int CodAdministrador;
        string Nombre;
        nodoAdministrador *siguiente;
        nodoAdministrador *anterior;

    friend class PaginaBAdministrador;
    friend class PrograI;
    friend class ArbolBAdministrador;

};

typedef nodoAdministrador *pnodoAdministrador;

#endif // NODOADMINISTRADORARBOLB_H
