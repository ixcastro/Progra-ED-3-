#ifndef NODOUSUARIOARBOLB_H
#define NODOUSUARIOARBOLB_H

#include <iostream>
using namespace std;

class nodoUsuario {
    public:
        nodoUsuario(int pCodPais, int pCodCiudad,int pPasaporte, string pNombre, string pEstadoMigratorio){
            CodPais=pCodPais;
            CodCiudad=pCodCiudad;
            Pasaporte = pPasaporte;
            Nombre = pNombre;
            EstadoMigratorio = pEstadoMigratorio;
            contador = 0;

            siguiente = nullptr;
            anterior = nullptr;
        }

    private:
        int CodPais;
        int CodCiudad;
        int Pasaporte;
        string Nombre;
        string EstadoMigratorio;
        int contador;
        nodoUsuario *siguiente;
        nodoUsuario *anterior;

    friend class ArbolBUsuario;
    friend class PaginaBUsuario;
    friend class PrograI;
    friend class PaginaB;
};

typedef nodoUsuario *pnodoUsuario;

#endif // NODOUSUARIOARBOLB_H
