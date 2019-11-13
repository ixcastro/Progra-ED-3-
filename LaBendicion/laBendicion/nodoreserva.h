#ifndef NODORESERVA_H
#define NODORESERVA_H
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <sstream>
using namespace std;

class nodoReserva {
   public:
    nodoReserva(string pComprador, string pCodTipoTren, string pCodTren, string pCodRuta, string pPasajeros, string pNumAsientos)
    {
        comprador = pComprador;
        ostringstream os;
        srand(time(nullptr));
        consecutivo = 1 + rand() % (333 - 1);
        os<<"RES"<<"-"<<consecutivo;
        codigoReserva = os.str();

        codigoTipoTren = pCodTipoTren;
        codigoTren = pCodTren;
        codigoRuta = pCodRuta;

        istringstream (pPasajeros) >> pasajeros;
        istringstream (pNumAsientos) >> numAsientos;

        for (int i = 0;i<50;i++) {
            pasaportes[i] = "";
        }
        isFacturado = false;
        siguiente = NULL;
    }
    void asignarPasaportes(string *pPasaportes){
        if(pPasaportes->length()<50){
            int cant = sizeof(pPasaportes)/sizeof(*pPasaportes);
            for (int i = 0;i<cant;i++) {
               pasaportes[i] = pPasaportes[i];
            }
        }
    }


 private:
    string comprador;
    bool isFacturado;
    string codigoReserva;
    int consecutivo;
    string codigoTipoTren;
    string codigoTren;
    string codigoRuta;
    int pasajeros;
    string pasaportes[50];
    int numAsientos;
    nodoReserva *siguiente;


   friend class ServicioDeTrenes;
   friend class ListaReserva;
};
typedef nodoReserva *pnodoReserva;

#endif // NODORESERVA_H
