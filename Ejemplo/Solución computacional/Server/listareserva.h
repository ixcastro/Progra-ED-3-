#ifndef LISTARESERVA_H
#define LISTARESERVA_H
#include <iostream>
#include "nodoreserva.h"
using namespace std;


class ListaReserva {
   public:
    ListaReserva() { primero = actual = NULL; }

    string InsertarFinal(string pComprador, string pCodTipoTren, string pCodTren, string pCodRuta, string pPasajeros, string pNumAsientos);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    void BorrarFinal();
    int largoLista();
    string Facturar(string pCodReserva);
    string consultarRutasMasUtilizadas();
    string consultarRutasMaenosUtilizadas();
    string consultarPaisMasVisitados();
    string consultarCiudadMasVisitada();
    string consultarUsuarioMasActivo();
    string consultarUsuarioMenosActivo();
    string consultarCantCompras();
    string consultarTrenMasUtilizado();
    string consultarTrenMenosUtilizado();

   private:
    pnodoReserva primero;
    pnodoReserva actual;
};


#endif // LISTARESERVA_H

