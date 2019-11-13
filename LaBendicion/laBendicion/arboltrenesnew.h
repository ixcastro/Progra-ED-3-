#ifndef ARBOLTRENESNEW_H
#define ARBOLTRENESNEW_H

#include <iostream>
#include "nodotipotrenabb.h"
#include "nodotrenvl.h"
#include "nodoruta.h"

using namespace std;

class arbolTrenes{
public:
    arbolTrenes(){
        Raiz = nullptr;
    }
    void InsertaNodo(int pTipoTren);
    void PreordenI();
    void InordenI();
    void PostordenI();
    //////////////////////////////////////////////////////
    bool Hh;
    void InsertarTren(nodoTipoTren *R,int pTipoTren, int pCodTren,string pNombre, string pnumAsientos, int pCodCiudadSalida, int pCodPaisSalida);
    void InsertarBalanceado(nodoTren *ra, int pCodTren,string pNombre, string pnumAsientos, int pCodCiudadSalida, int pCodPaisSalida);

    void RotacionDobleIzquierda(nodoTren *n, nodoTren *n1);
    void RotacionDobleDerecha(nodoTren *n, nodoTren *n1);
    void RotacionSimpleIzquierda(nodoTren *n, nodoTren *n1);
    void RotacionSimpleDerecha(nodoTren *n, nodoTren *n1);

    void Equilibrar1(nodoTren *n, bool);
    void Equilibrar2(nodoTren *n, bool);
    /////////////////////////////////////////////////////////////

    void buscarTipoTren(nodoTipoTren *R, int pCodPais);

    void buscarTipoTrenParaTren(nodoTipoTren *R, int pTipoTren, int pCodTren, int opcion);
    void buscarTren(nodoTren *R, int pCodTren, int opcion);

    bool validaTipoTren(int pCodPais);
    bool validaTren(int pTipoTren, int pCodTren);
    /////////////////////////////////////////////////////////////
    void AgregarRuta(nodoTipoTren *R,int pCodTipoTren, int pCodTren, int codRuta, int pCodPais, int pCodCiudad, int pCodPaisD, int pCodCiudadD,int pPrecio);
    void buscarTrenParaRuta(nodoTren *R, int pCodTren, int codRuta, int pCodPais, int pCodCiudad, int pCodPaisD, int pCodCiudadD,int pPrecio);
    void insertarRuta(int codRuta, int pCodPais, int pCodCiudad, int pCodPaisD, int pCodCiudadD, int pPrecio, NodoRuta *pPadre);
    void torsion(NodoRuta *pPadre);
    void division(NodoRuta *pPadre);
    bool validaRuta(int pCodTipoTren, int pCodTren, int pCodRuta);
    int obtenerPrecio(int pCodTipoTren, int pCodTren, int pCodRuta);
    void buscarTipoTrenParaRuta(nodoTipoTren *R, int pCodTipoTren, int pCodTren, int pCodRuta, int opcion);
    void buscarTrenParaValidarRuta(nodoTren *R, int pCodTren, int pCodRuta, int opcion);
    void buscarRutaParaValidar(pnodoRuta R, int pCodRuta, int opcion);
    /////////////////////////////////////////////////////////////
    bool validarCiudadSalidaRuta(int pCodTipoTren, int pCodTren, int pCodPais, int pCodCiudad);
    /////////////////////////////////////////////////////////////
    void buscarTipoTrenParaRutaModificar(nodoTipoTren *R, int pCodTipoTren, int pCodTren, int pCodRuta, int precio, int opcion);
    void buscarTrenParaRutaModificar(nodoTren *R, int pCodTren, int pCodRuta, int precio, int opcion);
    void buscarRutaParaModificar(pnodoRuta R, int pCodRuta, int precio, int opcion);

    void modificarTren(nodoTipoTren *R, int pTipoTren, int pCodTren, string pNombre);
    void modificar(nodoTren *R, int pCodTren, string pNombre);
    void modificarNumAsientos(nodoTipoTren *R, int pTipoTren, int pCodTren, string pNombre);
    void modificarAsientos(nodoTren *R, int pCodTren, string pNumAsientos);
    /////////////////////////////////////////////////////////////////
    void buscarTipoTrenParaAsientos(nodoTipoTren *R, int pCodTipo, int pCodTren, int numAsientos, int opcion);
    void buscarTrenParaValidar(nodoTren *R, int pCodTren, int numAsientos);
    bool validaAsientos(int pCodTipoTren,int pCodTren,int pNumAsientos);

    void reducirAsientos(int pCodTipoTren,int pCodTren,int pNumAsientos);
    void buscarTrenParaReducir(nodoTren *R, int pCodTren, int numAsientos);

   private:
    nodoTipoTren *Raiz;
    bool TipoTrenEncontrado = false;
    pnodoTren auxTrenPadre = nullptr;
    bool TrenEncontrada = false;
    bool RutaEncontrada = false;
    string msgUltimoTrenModificado;
    int pais;
    int ciudad;
    bool validaAsiento = false;

    friend class ServicioDeTrenes;
};

#endif // ARBOLTRENESNEW_H
