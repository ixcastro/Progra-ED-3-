#include "arboltrenesnew.h"

static pnodoTipoTren auxTipoTrenPadre = nullptr;
static int precio;

void arbolTrenes::InsertaNodo(int pTipoTren){
    if(Raiz == nullptr){
        Raiz = new nodoTipoTren(pTipoTren);
    }else{
        Raiz->InsertaBinario(pTipoTren);
    }
}

void nodoTipoTren::InsertaBinario(int pTipoTren){
    if(TipoTren>pTipoTren){
        if(Hizq==NULL){
            Hizq = new nodoTipoTren(pTipoTren);

        }else{
            Hizq->InsertaBinario(pTipoTren);
        }
    }else{
        if(Hder==NULL){
            Hder = new nodoTipoTren(pTipoTren);

        }else{
            Hder->InsertaBinario(pTipoTren);
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////
//Ciudades
//////////////////////////////////////////////////////////////////////////////////////

void arbolTrenes::InsertarTren(nodoTipoTren *R,int pTipoTren, int pCodTren,string pNombre, string pnumAsientos, int pCodCiudadSalida, int pCodPaisSalida){

    if(R == nullptr){
        return ;
    }else{
        if(R->TipoTren == pTipoTren){
            if(R->Trenes == nullptr){
                R->Trenes=new nodoTren( pCodTren, pNombre, pnumAsientos, pCodCiudadSalida, pCodPaisSalida);
                Hh = true;
                return ;
            }else{
                auxTipoTrenPadre = R;
                InsertarBalanceado(R->Trenes, pCodTren, pNombre, pnumAsientos, pCodCiudadSalida, pCodPaisSalida);
                return ;
            }

        }else{
            if(R->TipoTren>pTipoTren){
                 InsertarTren(R->Hder,pTipoTren, pCodTren, pNombre, pnumAsientos, pCodCiudadSalida, pCodPaisSalida);
            }
            if(R->TipoTren<pTipoTren){
                InsertarTren(R->Hder,pTipoTren, pCodTren, pNombre, pnumAsientos, pCodCiudadSalida, pCodPaisSalida);
            }
        }
    }
}

void arbolTrenes::InsertarBalanceado(nodoTren *ra, int pCodTren,string pNombre, string pnumAsientos, int pCodCiudadSalida, int pCodPaisSalida){
    nodoTren *n1;
    if(ra==nullptr){
        ra=new nodoTren( pCodTren, pNombre, pnumAsientos, pCodCiudadSalida, pCodPaisSalida);
        Hh = true;
    }else{
        if(pCodTren<ra->CodTren){
            if(ra->Hizq==nullptr){
                ra->Hizq=new nodoTren( pCodTren, pNombre, pnumAsientos, pCodCiudadSalida, pCodPaisSalida);
                ra->Hizq->anterior = ra;
                Hh = true;
            }else{
                InsertarBalanceado(ra->Hizq, pCodTren, pNombre, pnumAsientos, pCodCiudadSalida, pCodPaisSalida);
            }

        if(Hh){
            switch(ra->FB){
                case 1: ra->FB=0;
                Hh = false;
                break;
                case 0: ra->FB  = -1;
                break;
                case -1: n1=ra->Hizq;
                if(n1->FB ==-1){
                    RotacionSimpleIzquierda(ra, n1);
                }else{
                    RotacionDobleIzquierda(ra,n1);
                }
                Hh = false;
                break;
            }
        }
        }else{
            if(pCodTren>ra->CodTren){
                if(ra->Hder==nullptr){
                    ra->Hder=new nodoTren( pCodTren, pNombre, pnumAsientos, pCodCiudadSalida, pCodPaisSalida);
                    ra->Hder->anterior = ra;
                    Hh = true;
                }else{
                    InsertarBalanceado(ra->Hder, pCodTren, pNombre, pnumAsientos, pCodCiudadSalida, pCodPaisSalida);
                }

                if(Hh){
                    switch(ra->FB){
                        case -1: ra->FB=0;
                        Hh = false;
                        break;
                        case 0: ra->FB=1;
                        break;
                        case 1:n1=ra->Hder;
                        if(n1->FB==1){
                            RotacionSimpleDerecha(ra, n1);
                        }else{
                            RotacionDobleDerecha(ra, n1);
                        }
                        Hh=false;
                        break;
                    }
                }
            }
        }
    }
}


void arbolTrenes::RotacionDobleIzquierda(nodoTren *n, nodoTren *n1){
    nodoTren *n2;
    n2=n1->Hder;

    n->Hizq = n2->Hder;
    if(n->Hizq!=nullptr){
        n->Hizq->anterior = n;
    }
    n2->Hder=n;

    n1->Hder=n2->Hizq;
    if(n1->Hder!=nullptr){
        n1->Hder->anterior = n1;
    }

    n2->Hizq=n1;
    if(n2->Hizq!=nullptr){
        n2->Hizq->anterior = n2;
    }

    if(n2->FB==1){
        n1->FB=-1;
    }else{
        n1->FB=0;
    }
    if(n2->FB==-1){
        n->FB=1;
    }else{
        n->FB=0;
    }
    n2->FB=0;

    if(n->anterior!=nullptr){
        if(n->anterior->Hder == n){
            n->anterior->Hder = n2;
            n->anterior = n2;
        }else{
            n->anterior->Hizq = n2;
            n->anterior = n2;
        }
    }else{
        auxTipoTrenPadre->Trenes = n2;
        n2->anterior = nullptr;
        n->anterior = n2;
    }
}

void arbolTrenes::RotacionDobleDerecha(nodoTren* ra, nodoTren* n1){
    nodoTren *n2;
    n2=n1->Hizq;

    ra->Hder = n2->Hizq;
    if(ra->Hder != nullptr){
        ra->Hder->anterior = ra;
    }
    n2->Hizq=ra;

    n1->Hizq=n2->Hder;
    if(n1->Hizq != nullptr){
        n1->Hizq->anterior = n1;
    }
    n2->Hder=n1;
    if(n2->Hder != nullptr){
        n2->Hder->anterior = n2;
    }

    if(n2->FB==1){
        ra->FB=-1;
    }else{
        ra->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    if(ra->anterior!=nullptr){
        if(ra->anterior->Hder == ra){
            ra->anterior->Hder = n2;
            ra->anterior = n2;
        }else{
            ra->anterior->Hizq = n2;
            ra->anterior = n2;
        }
    }else{
        auxTipoTrenPadre->Trenes = n2;
        n2->anterior = nullptr;
        ra->anterior = n2;
    }
}

void arbolTrenes::RotacionSimpleDerecha(nodoTren *ra, nodoTren *n1){
    ra->Hder=n1->Hizq;
    if(ra->Hder != nullptr){
        ra->Hder->anterior = ra;
    }
    n1->Hizq=ra;

    if(n1->FB==1){
        ra->FB=0;
        n1->FB=0;
    }else{
        ra->FB=1;
        n1->FB=-1;
    }


    if(ra->anterior!=nullptr){
        if(ra->anterior->Hder == ra){
            ra->anterior->Hder = n1;
            n1->Hizq->anterior = n1;
        }else{
            ra->anterior->Hizq = n1;
            n1->Hizq->anterior = n1;
        }
    }else{
        auxTipoTrenPadre->Trenes = n1;
        n1->anterior = nullptr;
        n1->Hizq->anterior = n1;
    }
}

void arbolTrenes::RotacionSimpleIzquierda(nodoTren *n, nodoTren* n1){
    n->Hizq=n1->Hder;

    if(n->Hizq != nullptr){
        n->Hizq->anterior = n;
    }
    n1->Hder=n;


    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=-1;
    }
    if(n->anterior!=nullptr){
        if(n->anterior->Hder == n){
            n->anterior->Hder = n1;
            n->anterior = n1;
        }else{
            n->anterior->Hizq = n1;
            n->anterior = n1;
        }
    }else{
        auxTipoTrenPadre->Trenes = n1;
        n1->anterior = nullptr;
        n->anterior = n1;
    }
}

void arbolTrenes::buscarTipoTren(nodoTipoTren *R, int pTipoTren){
    if(R == nullptr){
        return ;
    }
    if(R->TipoTren == pTipoTren){
        TipoTrenEncontrado = true;
        return ;
    }
    if(R->TipoTren>pTipoTren){
        buscarTipoTren(R->Hizq, pTipoTren);
    }
    if(R->TipoTren<pTipoTren){
        buscarTipoTren(R->Hder, pTipoTren);
    }
}


void arbolTrenes::buscarTipoTrenParaTren(nodoTipoTren *R, int pTipoTren, int pCodTren, int opcion){
    if(R == nullptr){
        return ;
    }else{
        if(R->TipoTren == pTipoTren){
            buscarTren(R->Trenes, pCodTren, opcion);
            return ;
        }else{
            if(R->TipoTren>pTipoTren){
                buscarTipoTrenParaTren(R->Hizq, pTipoTren, pCodTren, opcion);
            }
            if(R->TipoTren<pTipoTren){
                buscarTipoTrenParaTren(R->Hder, pTipoTren, pCodTren, opcion);
            }
        }
    }
}

void arbolTrenes::buscarTren(nodoTren *R, int pCodTren, int opcion){
    if(R == nullptr){
        return ;
    }

    if(R->CodTren == pCodTren){
        switch(opcion){
        case 1:
            TrenEncontrada = true;
            break;
        case 2:
          pais = R->CodPaisSalida;
          ciudad = R->CodCiudadSalida;
            break;
        }
        return ;
    }else{
        if(R->CodTren>pCodTren){
            buscarTren(R->Hizq, pCodTren, opcion);
        }
        if(R->CodTren<pCodTren){
            buscarTren(R->Hder, pCodTren, opcion);
        }
    }

}

bool arbolTrenes::validaTipoTren(int pCodPais){
    TipoTrenEncontrado = false;
    buscarTipoTren(Raiz,pCodPais);
    return TipoTrenEncontrado;
}

bool arbolTrenes::validaTren(int pTipoTren, int pCodTren){
    TipoTrenEncontrado = false;
    TrenEncontrada = false;
    buscarTipoTrenParaTren(Raiz,pTipoTren,pCodTren, 1);
    return TrenEncontrada;
}

//************************************************************************************************
void arbolTrenes::AgregarRuta(nodoTipoTren *R,int pCodTipoTren, int pCodTren, int codRuta, int pCodPais, int pCodCiudad, int pCodPaisD, int pCodCiudadD,int pPrecio){
    if(R == nullptr){
        return ;
    }else{
        if(R->TipoTren == pCodTipoTren){
            buscarTrenParaRuta(R->Trenes, pCodTren, codRuta, pCodPais, pCodCiudad, pCodPaisD, pCodCiudadD, pPrecio);
            return ;
        }else{
            if(R->TipoTren>pCodTipoTren){
                AgregarRuta(R->Hizq,pCodTipoTren, pCodTren, codRuta, pCodPais, pCodCiudad, pCodPaisD, pCodCiudadD,pPrecio);
            }
            if(R->TipoTren<pCodTipoTren){
                AgregarRuta(R->Hder,pCodTipoTren, pCodTren, codRuta, pCodPais, pCodCiudad, pCodPaisD, pCodCiudadD,pPrecio);
            }
        }
    }
}

void arbolTrenes::buscarTrenParaRuta(nodoTren *R, int pCodTren, int codRuta, int pCodPais, int pCodCiudad, int pCodPaisD, int pCodCiudadD, int pPrecio){
    if(R == nullptr){
        return ;
    }

    if(R->CodTren == pCodTren){
        auxTrenPadre = R;
        if(R->rutas==nullptr){
            R->rutas= new NodoRuta(codRuta, pCodPais, pCodCiudad, pCodPaisD,pCodCiudadD,pPrecio);
        }else{
            insertarRuta(codRuta, pCodPais, pCodCiudad, pCodPaisD,pCodCiudadD,pPrecio, R->rutas);
        }
        return ;
    }else{
        if(R->CodTren>pCodTren){
            buscarTrenParaRuta(R->Hizq, pCodTren, codRuta, pCodPais, pCodCiudad, pCodPaisD, pCodCiudadD, pPrecio);
        }
        if(R->CodTren<pCodTren){
            buscarTrenParaRuta(R->Hder, pCodTren, codRuta, pCodPais, pCodCiudad, pCodPaisD, pCodCiudadD, pPrecio);
        }
    }
}

void arbolTrenes::insertarRuta(int codRuta, int pCodPais, int pCodCiudad, int pCodPaisD, int pCodCiudadD, int pPrecio, NodoRuta *pPadre)
{
    if (pPadre == nullptr) {
        auxTrenPadre->rutas = new NodoRuta(codRuta, pCodPais, pCodCiudad, pCodPaisD,pCodCiudadD,pPrecio);
    }
    else {
        if (codRuta > pPadre->codRuta) {
            if (pPadre->hd == nullptr) {
                pPadre->hd = new NodoRuta(codRuta, pCodPais, pCodCiudad, pCodPaisD,pCodCiudadD,pPrecio);
                pPadre->hd->padre = pPadre;
                if ((pPadre->padre != nullptr) && (pPadre->padre->nivel == pPadre->nivel)) {
                    division(pPadre);
                }
            }
            else {
                insertarRuta(codRuta, pCodPais, pCodCiudad, pCodPaisD,pCodCiudadD,pPrecio, pPadre->hd);
            }
        }
        else {
            if (pPadre->hi == nullptr) {
                pPadre->hi = new NodoRuta(codRuta, pCodPais, pCodCiudad, pCodPaisD,pCodCiudadD,pPrecio);
                pPadre->hi->padre = pPadre;
                if(pPadre != auxTrenPadre->rutas){
                    torsion(pPadre->hi);
                    if ((pPadre->padre->padre != nullptr) && (pPadre->padre->padre->nivel == pPadre->nivel)) {
                        division(pPadre->padre);
                        return;
                    }
                    if ((pPadre->padre->nivel == pPadre->nivel) && (pPadre->hd != nullptr) && (pPadre->hd->nivel == pPadre->nivel)) {
                        division(pPadre);
                        return;
                    }
                }

            }
            else {
                insertarRuta(codRuta, pCodPais, pCodCiudad, pCodPaisD,pCodCiudadD,pPrecio, pPadre->hi);
            }
        }
    }
}

void arbolTrenes::torsion(NodoRuta *pPadre)
{
    pPadre->padre->hi = nullptr;
    pPadre->hd = pPadre->padre;
    pPadre->padre = pPadre->padre->padre;
    if (pPadre->padre->hd == pPadre->hd) {
        pPadre->padre->hd = pPadre;
    }
    if (pPadre->padre->hi == pPadre->hd) {
        pPadre->padre->hi = pPadre;
    }
    pPadre->hd->padre = pPadre;
    if (pPadre->padre == nullptr) {
        auxTrenPadre->rutas = pPadre;
    }
}

void arbolTrenes::division(NodoRuta *pPadre)
{
    pPadre->padre->hd = pPadre->hi;
    pPadre->hi = pPadre->padre;
    pPadre->padre = pPadre->padre->padre;
    pPadre->hi->padre = pPadre;
    if (pPadre->padre == nullptr) {
        auxTrenPadre->rutas = pPadre;
    }
    if ((pPadre->padre != nullptr) && (pPadre->padre->hi == pPadre->hi)) {
        pPadre->padre->hi = pPadre->hd;
        pPadre->hd->padre = pPadre->padre;
        pPadre->hd = pPadre->padre;
        pPadre->padre = pPadre->hd->padre;
        pPadre->hd->padre = pPadre;
        if (pPadre->padre == nullptr) {
            auxTrenPadre->rutas = pPadre;
        }
    }
    else {
        if ((pPadre->padre != nullptr) && (pPadre->padre->hd == pPadre->hi)) {
            pPadre->padre->hd = pPadre;
        }
    }
    pPadre->nivel++;//revisar si tuerce de nuevo o divide en nivel superior
    if ((pPadre->padre != nullptr) && (pPadre->padre->padre != nullptr)) {
        division(pPadre->padre);
    }
    else {
        if ((pPadre->padre != nullptr) && (pPadre->hd != nullptr) && (pPadre->hd->nivel == pPadre->nivel)) {
            division(pPadre);
        }
        else {
            if ((pPadre->hd != nullptr) && (pPadre->hd->nivel == pPadre->nivel) && (pPadre->hd->hd != nullptr)&&(pPadre->hd->hd->nivel == pPadre->nivel)){
                division(pPadre->hd);
            }
        }
    }
}

bool arbolTrenes::validaRuta(int pCodTipoTren, int pCodTren, int pCodRuta){
    RutaEncontrada = false;
    buscarTipoTrenParaRuta(Raiz,pCodTipoTren,pCodTren,pCodRuta, 1);
    return RutaEncontrada;
}

int arbolTrenes::obtenerPrecio(int pCodTipoTren, int pCodTren, int pCodRuta){
    precio = 0;
    buscarTipoTrenParaRuta(Raiz,pCodTipoTren,pCodTren,pCodRuta, 3);
    return precio;
}

void arbolTrenes::buscarTipoTrenParaRuta(nodoTipoTren *R, int pCodTipoTren, int pCodTren, int pCodRuta, int opcion){
    if(R == nullptr){
        return ;
    }else{
        if(R->TipoTren == pCodTipoTren){
            buscarTrenParaValidarRuta(R->Trenes, pCodTren, pCodRuta, opcion);
            return ;
        }else{
            if(R->TipoTren>pCodTipoTren){
                buscarTipoTrenParaRuta(R->Hizq, pCodTipoTren, pCodTren, pCodRuta, opcion);
            }
            if(R->TipoTren<pCodTipoTren){
                buscarTipoTrenParaRuta(R->Hder, pCodTipoTren, pCodTren, pCodRuta, opcion);
            }
        }
    }
}

void arbolTrenes::buscarTrenParaValidarRuta(nodoTren *R, int pCodTren, int pCodRuta, int opcion){
    if(R == nullptr){
        return ;
    }

    if(R->CodTren== pCodTren){
        buscarRutaParaValidar(R->rutas, pCodRuta, opcion);
        return ;
    }else{
        if(R->CodTren>pCodTren){
            buscarTrenParaValidarRuta(R->Hizq, pCodTren, pCodRuta, opcion);
        }
        if(R->CodTren<pCodTren){
            buscarTrenParaValidarRuta(R->Hder, pCodTren, pCodRuta, opcion);
        }
    }
}

void arbolTrenes::buscarRutaParaValidar(pnodoRuta R, int pCodRuta, int opcion){
    if(R == nullptr){
        return ;
    }
    if(R->codRuta == pCodRuta){
        switch(opcion){
        case 1:
            RutaEncontrada= true;
            break;
        case 2:
            pais =R->codPaisDest;
            ciudad = R->codCiudad;
            break;
        case 3:
            precio = R->precio;
            break;
        }
        return ;
    }else{
        if(R->codRuta>pCodRuta){
            buscarRutaParaValidar(R->hi, pCodRuta, opcion);
        }
        if(R->codRuta<pCodRuta){
            buscarRutaParaValidar(R->hi, pCodRuta, opcion);
        }
    }
}

bool arbolTrenes::validarCiudadSalidaRuta(int pCodTipoTren, int pCodTren, int pCodPais, int pCodCiudad){
    pais=0;
    ciudad=0;
    buscarTipoTrenParaTren(Raiz, pCodTipoTren, pCodTren, 2);
    if(pCodPais == pais and pCodCiudad == ciudad){
        return true;
    }else{
        return false;
    }

}
//*****************************************************************

void arbolTrenes::modificarTren(nodoTipoTren *R, int pTipoTren, int pCodTren, string pNombre){
    if(R == nullptr){
        return ;
    }else{
        if(R->TipoTren == pTipoTren){
            modificar(R->Trenes, pCodTren, pNombre);
            return ;
        }else{
            if(R->TipoTren>pTipoTren){
                modificarTren(R->Hizq, pTipoTren, pCodTren, pNombre);
            }
            if(R->TipoTren<pTipoTren){
                modificarTren(R->Hder, pTipoTren, pCodTren, pNombre);
            }
        }
    }
}

void arbolTrenes::modificar(nodoTren *R, int pCodTren, string pNombre){
    if(R == nullptr){
        return ;
    }
    if(R->CodTren == pCodTren){
        R->Nombre=pNombre;
        msgUltimoTrenModificado=" Nombre: "+R->Nombre+"\n"+"CodTren: "+to_string(R->CodTren)+"\n"+"Numero de Asientos: "+R->numAsientos+"\n"+"Pais de Salida: "+to_string(R->CodPaisSalida)+"\n"+"Ciudad de Salida: "+to_string(R->CodCiudadSalida)+"\n";

        return ;
    }else{
        if(R->CodTren>pCodTren){
            modificar(R->Hizq, pCodTren, pNombre);
        }
        if(R->CodTren<pCodTren){
            modificar(R->Hder, pCodTren, pNombre);
        }
    }
}

void arbolTrenes::modificarNumAsientos(nodoTipoTren *R, int pTipoTren, int pCodTren, string pNumAientos){
    if(R == nullptr){
        return ;
    }else{
        if(R->TipoTren == pTipoTren){
            modificarAsientos(R->Trenes, pCodTren,pNumAientos);
            return ;
        }else{
            if(R->TipoTren>pTipoTren){
                modificarNumAsientos(R->Hizq, pTipoTren, pCodTren, pNumAientos);
            }
            if(R->TipoTren<pTipoTren){
                modificarNumAsientos(R->Hder, pTipoTren, pCodTren, pNumAientos);
            }
        }
    }
}

void arbolTrenes::modificarAsientos(nodoTren *R, int pCodTren, string pNumAientos){
    if(R == nullptr){
        return ;
    }
    if(R->CodTren == pCodTren){
        R->numAsientos=pNumAientos;
        msgUltimoTrenModificado=" Nombre: "+R->Nombre+"\n"+"CodTren: "+to_string(R->CodTren)+"\n"+"Numero de Asientos: "+R->numAsientos+"\n"+"Pais de Salida: "+to_string(R->CodPaisSalida)+"\n"+"Ciudad de Salida: "+to_string(R->CodCiudadSalida)+"\n";
        return ;
    }else{
        if(R->CodTren>pCodTren){
            modificarAsientos(R->Hizq, pCodTren, pNumAientos);
        }
        if(R->CodTren<pCodTren){
            modificarAsientos(R->Hder, pCodTren, pNumAientos);
        }
    }
}

void arbolTrenes::buscarTipoTrenParaAsientos(nodoTipoTren *R, int pCodTipo, int pCodTren, int numAsientos, int opcion)
{
    if(R == nullptr){
        return ;
    }
    if(R->TipoTren == pCodTipo){
        if(opcion == 0){
            buscarTrenParaValidar(R->Trenes, pCodTren, numAsientos);
            return ;
        }else{
            buscarTrenParaReducir(R->Trenes, pCodTren, numAsientos);
        }
    }
    if(R->TipoTren>pCodTipo){
        buscarTipoTrenParaAsientos(R->Hizq, pCodTipo, pCodTren, numAsientos,opcion);
    }
    if(R->TipoTren<pCodTipo){
        buscarTipoTrenParaAsientos(R->Hder, pCodTipo, pCodTren, numAsientos,opcion);
    }
}

void arbolTrenes::buscarTrenParaValidar(nodoTren *R, int pCodTren, int numAsientos)
{
    if(R == nullptr){
        validaAsiento = false;
        return ;
    }
    if(R->CodTren == pCodTren){
        if(stoi(R->numAsientos) >= numAsientos){
            validaAsiento = true;
            return;
        }else{
            validaAsiento = false;
            return;
        }
    }else{
        if(R->CodTren>pCodTren){
            buscarTrenParaValidar(R->Hizq, pCodTren, numAsientos);
        }
        if(R->CodTren<pCodTren){
            buscarTrenParaValidar(R->Hder, pCodTren, numAsientos);
        }
    }
}

bool arbolTrenes::validaAsientos(int pCodTipo, int pCodTren, int numAsientos)
{
    validaAsiento = false;
    buscarTipoTrenParaAsientos(Raiz, pCodTipo, pCodTren, numAsientos,0);
    return validaAsiento;
}

void arbolTrenes::reducirAsientos(int pCodTipoTren, int pCodTren, int pNumAsientos)
{
    buscarTipoTrenParaAsientos(Raiz, pCodTipoTren, pCodTren, pNumAsientos,1);
}

void arbolTrenes::buscarTrenParaReducir(nodoTren *R, int pCodTren, int numAsientos)
{
    if(R == nullptr){
        validaAsiento = false;
        return ;
    }
    if(R->CodTren == pCodTren){
        if(stoi(R->numAsientos) >= numAsientos){
            R->numAsientos = to_string(stoi(R->numAsientos)-numAsientos);
            return;
        }else{
            validaAsiento = false;
            return;
        }
    }else{
        if(R->CodTren>pCodTren){
            buscarTrenParaValidar(R->Hizq, pCodTren, numAsientos);
        }
        if(R->CodTren<pCodTren){
            buscarTrenParaValidar(R->Hder, pCodTren, numAsientos);
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////


void arbolTrenes::buscarTipoTrenParaRutaModificar(nodoTipoTren *R, int pCodTipoTren, int pCodTren, int pCodRuta, int precio, int opcion){
    if(R == nullptr){
        return ;
    }else{
        if(R->TipoTren == pCodTipoTren){
            buscarTrenParaValidarRuta(R->Trenes, pCodTren, pCodRuta, opcion);
            return ;
        }else{
            if(R->TipoTren>pCodTipoTren){
                buscarTipoTrenParaRutaModificar(R->Hizq, pCodTipoTren, pCodTren, pCodRuta, precio, opcion);
            }
            if(R->TipoTren<pCodTipoTren){
                buscarTipoTrenParaRutaModificar(R->Hder, pCodTipoTren, pCodTren, pCodRuta, precio, opcion);
            }
        }
    }
}

void arbolTrenes::buscarTrenParaRutaModificar(nodoTren *R, int pCodTren, int pCodRuta, int precio, int opcion){
    if(R == nullptr){
        return ;
    }
    if(R->CodTren== pCodTren){
        buscarRutaParaValidar(R->rutas, pCodRuta, opcion);
        return ;
    }else{
        if(R->CodTren>pCodTren){
            buscarTrenParaRutaModificar(R->Hizq, pCodTren, pCodRuta, precio, opcion);
        }
        if(R->CodTren<pCodTren){
            buscarTrenParaRutaModificar(R->Hder, pCodTren, pCodRuta, precio,  opcion);
        }
    }
}

void arbolTrenes::buscarRutaParaModificar(pnodoRuta R, int pCodRuta, int precio, int opcion){
    if(R == nullptr){
        return ;
    }

    if(R->codRuta == pCodRuta){
        if(opcion ==1){
            R->precio = precio;

            return ;
        }
    }else{
        if(R->codRuta>pCodRuta){
            buscarRutaParaModificar(R->hi, pCodRuta, precio, opcion);
        }
        if(R->codRuta<pCodRuta){
            buscarRutaParaModificar(R->hi, pCodRuta, precio, opcion);
        }
    }
}
