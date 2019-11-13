#ifndef ARBOLPAISES_H
#define ARBOLPAISES_H
#include <iostream>
#include "nodopaisabb.h"
#include "nodociudadavl.h"
#include "nodoconexion.h"

using namespace std;

class arbolPaises{
public:
    arbolPaises(){
        Raiz = nullptr;
    }
    void InsertaNodo(int pCodPais, string pNombre);
    void PreordenI();
    void InordenI();
    void PostordenI();
    //////////////////////////////////////////////////////
    bool Hh;

    void InsertarCiudad(nodoPais *R,int pCodPais, int pCodCiudad, string pNombre);
    void InsertarBalanceado(nodoCiudad* ra, int pCodCiudad,string pNombre);
    void RotacionDobleIzquierda(nodoCiudad *n1, nodoCiudad *n2);
    void RotacionDobleDerecha(nodoCiudad *n1, nodoCiudad *n2);
    void RotacionSimpleIzquierda(nodoCiudad *n1, nodoCiudad *n2);
    void RotacionSimpleDerecha(nodoCiudad *n1, nodoCiudad *n2);

    void Equilibrar1(nodoCiudad *n, bool);
    void Equilibrar2(nodoCiudad *n, bool);
    /////////////////////////////////////////////////////////////

    void buscarPais(nodoPais *R, int pCodPais);
    void buscarPaisParaCiudad(nodoPais *R, int pCodPais, int pCodCiudad);
    void buscarCiudad(nodoCiudad *R, int pCodCiudad);
    bool validaPais(int pCodPais);
    bool validaCiudad(int pCodPais, int pCodCiudad);
    //////////////////////////////////////////////////////////////
    void AgregarConexion(nodoPais *R, int pCodPais, int pCodCiudad, int pCodigoConexion, int pCodPaisDest, int pCodCiudadDest, string pHoras, int pPrecio);
    void buscarCiudadParaConexion(nodoCiudad *R, int pCodCiudad, int pCodConexion, int pCodPaisDest, int pCodCiudadDest, string pHoras, int pPrecio);
    bool validaConexion(int pCodPais, int pCodCiudad, int pCodConexion);
    void buscarPaisParaConexion(nodoPais *R, int pCodPais, int pCodCiudad, int pCodConexion, int opcion, int variable);
    void buscarCiudadParaValidarConexion(nodoCiudad *R, int pCodCiudad, int pCodigoConexion, int opcion, int variable);
    void buscarConexionParaValidar(pnodoConexion R, int pCodigoConexion, int opcion, int variable);

    bool ConsultarConexionesParaRuta(int pCodPais,int pCodCiudad, int pCodPaisDest, int pCodCiudadDest);
    void EncontrarPaisParaConexionParaRuta(nodoPais *R, int pCodPais, int pCodCiudad,int pCodPaisDest, int pCodCiudadDest);
    void EncontrarCiudadParaConexionParaRuta(nodoCiudad *R, int pCodCiudad,int pCodPaisDest, int pCodCiudadDest);
    void PreordenArbolConexionParaRuta(nodoConexion *R,int pCodPaisDest, int pCodCiudadDest);

    void rotacionDobleDerecha(nodoConexion* nodoConexion);
    void insertarConexion(int pCodigoConexion, int pCodPaisDest, int pCodCiudadDest, string pHoras, int pPrecio, nodoConexion* pRaiz);
    void reglaDelTio(nodoConexion* nodoConexion);
    nodoConexion* abuelo(nodoConexion* nodoConexion);
    nodoConexion* tio(nodoConexion* nodoConexion);
    void rotar(nodoConexion* nodoConexion);
    void rotacionIzquierda(nodoConexion* nodoConexion);
    void rotacionDerecha(nodoConexion* nodoConexion);
    void rotacionDobleIzquierda(nodoConexion* nodoConexion);
    /////////////////////////////////////////////////////////////////

   private:
    nodoPais *Raiz;
    bool PaisEncontrado = false;
    bool CiudadEncontrada = false;
    bool ConexionEncontrada = false;
    pnodoCiudad auxCiudadMadre = nullptr;
    string msgConsultarConexion;

    friend class ServicioDeTrenes;
};
#endif // ARBOLPAISES_H
