#include "arbolpaises.h"
static pnodoPais auxPaisPadre = nullptr;



void arbolPaises::InsertaNodo(int pCodPais, string pNombre){
    if(Raiz == nullptr){
        Raiz = new nodoPais(pCodPais, pNombre);
    }else{
        Raiz->InsertaBinario(pCodPais, pNombre);
    }
}

void nodoPais::InsertaBinario(int pCodPais, string pNombre){
    if(pCodPais<CodPais){
        if(Hizq==NULL){
            Hizq = new nodoPais(pCodPais, pNombre);
        }else{
            Hizq->InsertaBinario(pCodPais, pNombre);
        }
    }else{
        if(Hder==NULL){
            Hder = new nodoPais(pCodPais, pNombre);
        }else{
            Hder->InsertaBinario(pCodPais, pNombre);
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////
//Ciudades
//////////////////////////////////////////////////////////////////////////////////////
void arbolPaises::InsertarCiudad(nodoPais *R,int pCodPais, int pCodCiudad, string pNombre){

    if(R == nullptr){
        return ;
    }else{
        if(R->CodPais == pCodPais){
            if(R->Ciudades == nullptr){
                R->Ciudades=new nodoCiudad(pCodCiudad, pNombre);
                return ;
            }else{
                auxPaisPadre = R;
                InsertarBalanceado(R->Ciudades,pCodCiudad, pNombre);
                return ;
            }

        }else{
            if(R->CodPais>pCodPais){
                InsertarCiudad(R->Hizq,pCodPais,pCodCiudad, pNombre);
            }
            if(R->CodPais<pCodPais){
                InsertarCiudad(R->Hder,pCodPais,pCodCiudad, pNombre);
            }
        }
    }
}

void arbolPaises::InsertarBalanceado(nodoCiudad* ra, int pCodCiudad,string pNombre){
    pnodoCiudad n1;
//    if(ra==nullptr){
//        ra=new nodoCiudad(pCodCiudad, pNombre);
//        Hh = true;
//        cout<<ra->CodCiudad<<endl;
//    }else{
        if(pCodCiudad<ra->CodCiudad){
            if(ra->Hizq==nullptr){
                ra->Hizq=new nodoCiudad(pCodCiudad, pNombre);
                ra->Hizq->anterior = ra;
                Hh = true;
            }else{
                InsertarBalanceado(ra->Hizq, pCodCiudad, pNombre);
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
            if(pCodCiudad>ra->CodCiudad){
                if(ra->Hder==nullptr){
                    ra->Hder=new nodoCiudad(pCodCiudad, pNombre);
                    ra->Hder->anterior = ra;
                    Hh = true;
                }else{
                    InsertarBalanceado(ra->Hder, pCodCiudad, pNombre);
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

void arbolPaises::RotacionDobleIzquierda(nodoCiudad* n, nodoCiudad* n1){
    nodoCiudad *n2;
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
        auxPaisPadre->Ciudades = n2;
        n2->anterior = nullptr;
        n->anterior = n2;
    }
}

void arbolPaises::RotacionDobleDerecha(nodoCiudad* ra, nodoCiudad* n1){
    nodoCiudad *n2;
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
        auxPaisPadre->Ciudades = n2;
        n2->anterior = nullptr;
        ra->anterior = n2;
    }
}

void arbolPaises::RotacionSimpleDerecha(nodoCiudad* ra, nodoCiudad* n1){
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
        auxPaisPadre->Ciudades = n1;
        n1->anterior = nullptr;
        n1->Hizq->anterior = n1;
    }
}

void arbolPaises::RotacionSimpleIzquierda(nodoCiudad* n, nodoCiudad* n1){
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
        auxPaisPadre->Ciudades = n1;
        n1->anterior = nullptr;
        n->anterior = n1;
    }
}

void arbolPaises::buscarPais(nodoPais *R, int pCodPais){
    if(R == nullptr){
        return ;
    }
    if(R->CodPais == pCodPais){
        PaisEncontrado = true;
        return ;
    }
    if(R->CodPais>pCodPais){
        buscarPais(R->Hizq, pCodPais);
    }
    if(R->CodPais<pCodPais){
        buscarPais(R->Hder, pCodPais);
    }
}

void arbolPaises::buscarPaisParaCiudad(nodoPais *R, int pCodPais, int pCodCiudad){
    if(R == nullptr){
        return ;
    }else{
        if(R->CodPais == pCodPais){
            buscarCiudad(R->Ciudades, pCodCiudad);
            return ;
        }else{
            if(R->CodPais>pCodPais){
                buscarPaisParaCiudad(R->Hizq, pCodPais, pCodCiudad);
            }
            if(R->CodPais<pCodPais){
                buscarPaisParaCiudad(R->Hder, pCodPais, pCodCiudad);
            }
        }
    }
}

void arbolPaises::buscarCiudad(nodoCiudad *R, int pCodCiudad){
    if(R == nullptr){
        return ;
    }

    if(R->CodCiudad == pCodCiudad){
        CiudadEncontrada = true;
        return ;
    }else{
        if(R->CodCiudad>pCodCiudad){
            buscarCiudad(R->Hizq, pCodCiudad);
        }
        if(R->CodCiudad<pCodCiudad){
            buscarCiudad(R->Hder, pCodCiudad);
        }
    }

}

bool arbolPaises::validaPais(int pCodPais){
    PaisEncontrado = false;
    buscarPais(Raiz,pCodPais);
    return PaisEncontrado;
}

bool arbolPaises::validaCiudad(int pCodPais, int pCodCiudad){
    PaisEncontrado = false;
    CiudadEncontrada = false;
    buscarPaisParaCiudad(Raiz,pCodPais,pCodCiudad);
    return CiudadEncontrada;
}

//*****************************************CONEXIONES***************
void arbolPaises::AgregarConexion(nodoPais *R, int pCodPais, int pCodCiudad, int pCodigoConexion, int pCodPaisDest, int pCodCiudadDest, string pHoras, int pPrecio){
    if(R == nullptr){
        return ;
    }else{
        if(R->CodPais == pCodPais){
            buscarCiudadParaConexion(R->Ciudades, pCodCiudad, pCodigoConexion, pCodPaisDest, pCodCiudadDest,pHoras, pPrecio);
            return ;
        }else{
            if(R->CodPais>pCodPais){
                AgregarConexion(R->Hizq,pCodPais, pCodCiudad, pCodigoConexion, pCodPaisDest, pCodCiudadDest,pHoras,pPrecio);
            }
            if(R->CodPais<pCodPais){
                AgregarConexion(R->Hder,pCodPais, pCodCiudad, pCodigoConexion, pCodPaisDest, pCodCiudadDest,pHoras,pPrecio);
            }
        }
    }
}

void arbolPaises::buscarCiudadParaConexion(nodoCiudad *R, int pCodCiudad, int pCodigoConexion, int pCodPaisDest, int pCodCiudadDest, string pHoras, int pPrecio){
    if(R == nullptr){
        return ;
    }

    if(R->CodCiudad == pCodCiudad){
        auxCiudadMadre = R;
        if(R->conexiones==nullptr){
            R->conexiones= new nodoConexion(pCodigoConexion, pCodPaisDest, pCodCiudadDest, pHoras, pPrecio);
            R->conexiones->color=false;
        }else{
            insertarConexion(pCodigoConexion, pCodPaisDest, pCodCiudadDest, pHoras, pPrecio, R->conexiones);
        }
        return ;
    }else{
        if(R->CodCiudad>pCodCiudad){
            buscarCiudadParaConexion(R->Hizq, pCodCiudad, pCodigoConexion, pCodPaisDest, pCodCiudadDest, pHoras,pPrecio);
        }
        if(R->CodCiudad<pCodCiudad){
            buscarCiudadParaConexion(R->Hder, pCodCiudad, pCodigoConexion, pCodPaisDest, pCodCiudadDest, pHoras,pPrecio);
        }
    }
}

void arbolPaises::insertarConexion(int pCodigoConexion, int pCodPaisDest, int pCodCiudadDest, string pHoras, int pPrecio, pnodoConexion pRaiz)
{
    if (pRaiz == nullptr) {
        pRaiz = new nodoConexion(pCodigoConexion, pCodPaisDest, pCodCiudadDest, pHoras,pPrecio);
    }else{
        if (pCodigoConexion > pRaiz->codigoConexion) {
            if (pRaiz->HD != nullptr) {
                insertarConexion(pCodigoConexion, pCodPaisDest, pCodCiudadDest, pHoras,pPrecio, pRaiz->HD);
            }
            else {
                pRaiz->HD = new nodoConexion(pCodigoConexion, pCodPaisDest, pCodCiudadDest, pHoras,pPrecio);
                pRaiz->HD->padre = pRaiz;
                if (pRaiz->color) {
                    reglaDelTio(pRaiz->HD);
                }
                else {
                    return;
                }
            }
        }
        else {
            if (pRaiz->HI != nullptr) {
                insertarConexion(pCodigoConexion, pCodPaisDest, pCodCiudadDest, pHoras,pPrecio, pRaiz->HI);
            }
            else {
                pRaiz->HI = new nodoConexion(pCodigoConexion, pCodPaisDest, pCodCiudadDest, pHoras,pPrecio);
                pRaiz->HI->padre = pRaiz;
                if (pRaiz->color) {
                    reglaDelTio(pRaiz->HI);
                }
                else {
                    return;
                }
            }
        }
    }
}

void arbolPaises::reglaDelTio(nodoConexion* nodoConexion)
{
    pnodoConexion t = tio(nodoConexion);
    if ((t != nullptr) && (t->color)) {
        nodoConexion->padre->color = false;
        t->color = false;
        pnodoConexion a = abuelo(nodoConexion);
        if(auxCiudadMadre->conexiones != a){
            a->color = true;
        }
        if ((a->padre != nullptr) && (a->padre->color)) {
            reglaDelTio(a);
        }
    }
    else {
        rotar(nodoConexion);
    }
}

nodoConexion* arbolPaises::abuelo(nodoConexion* nodoConexion)
{
    if ((nodoConexion != nullptr) && (nodoConexion->padre != nullptr)) {
        return nodoConexion->padre->padre;
    }
    else {
        return nullptr;
    }
}

nodoConexion* arbolPaises::tio(nodoConexion* nodoConexion)
{
    pnodoConexion a = abuelo(nodoConexion);
    if (nodoConexion->padre == a->HI) {
        return a->HD;
    }
    else {
        return a->HI;
    }
}

void arbolPaises::rotar(nodoConexion* nodoConexion)
{
    pnodoConexion a = abuelo(nodoConexion);
    if ((nodoConexion == nodoConexion->padre->HD) && (nodoConexion->padre == a->HD)) {
        rotacionIzquierda(nodoConexion);

    }
    else if ((nodoConexion == nodoConexion->padre->HI) && (nodoConexion->padre == a->HI)) {
        rotacionDerecha(nodoConexion);
    }
    else {
        if ((a->HI != nullptr) && (a->HI->HD != nullptr)) {
            rotacionDobleIzquierda(nodoConexion);
        }
        else if ((a->HD != nullptr) && (a->HD->HI != nullptr)) {
            rotacionDobleDerecha(nodoConexion);
        }
    }
}

void arbolPaises::rotacionIzquierda(nodoConexion* nodoConexion)
{
    pnodoConexion a = abuelo(nodoConexion);
    pnodoConexion pPadre = nodoConexion->padre;
    pPadre->padre = a->padre;
    if (a->padre == nullptr) {
        auxCiudadMadre->conexiones = pPadre;
    }
    a->padre = pPadre;
    a->HD = pPadre->HI;
    if (a->HD != nullptr) {
        a->HD->padre = a;
    }
    pPadre->HI = a;
    pPadre->color = !(pPadre->color);
    a->color = !(a->color);
    if ((pPadre->padre != nullptr) && (pPadre->padre->HD == a)) {
        pPadre->padre->HD = pPadre;
    }
    else {
        if ((pPadre->padre != nullptr) && (pPadre->padre->HI == a)) {
            pPadre->padre->HI = pPadre;
        }
    }
    if ((a->HD != nullptr) && (a->HD->color) && (a->color)) {
        reglaDelTio(a->HD);
    }
    else {
        if ((a->HI != nullptr) && (a->HI->color) && (a->color)) {
            reglaDelTio(a->HI);
        }
    }
    if ((pPadre->padre != nullptr) && (pPadre->padre->color) && (pPadre->color)) {
        reglaDelTio(pPadre);
    }
}

void arbolPaises::rotacionDerecha(nodoConexion* nodoConexion)
{
    pnodoConexion a = abuelo(nodoConexion);
    pnodoConexion pPadre = nodoConexion->padre;
    pPadre->padre = a->padre;
    if (a->padre == nullptr) {
        auxCiudadMadre->conexiones = pPadre;
    }
    a->padre = pPadre;
    a->HI = pPadre->HD;
    if (a->HI != nullptr) {
        a->HI->padre = a;
    }
    pPadre->HD = a;
    pPadre->color = !(pPadre->color);
    a->color = !(a->color);
    if ((pPadre->padre != nullptr) && (pPadre->padre->HD == a)) {
        pPadre->padre->HD = pPadre;
    }
    else {
        if ((pPadre->padre != nullptr) && (pPadre->padre->HI == a)) {
            pPadre->padre->HI = pPadre;
        }
    }
    if ((a->HD != nullptr) && (a->HD->color) && (a->color)) {
        reglaDelTio(a->HD);
    }
    else {
        if ((a->HI != nullptr) && (a->HI->color) && (a->color)) {
            reglaDelTio(a->HI);
        }
    }
    if ((pPadre->padre != nullptr) && (pPadre->padre->color) && (pPadre->color)) {
        reglaDelTio(pPadre);
    }
}

void arbolPaises::rotacionDobleIzquierda(nodoConexion* nodoConexion)
{
    pnodoConexion a = abuelo(nodoConexion);
    pnodoConexion pPadre = nodoConexion->padre;
    nodoConexion->padre = a->padre;
    if (a->padre == nullptr) {
        auxCiudadMadre->conexiones = nodoConexion;
    }
    pPadre->HD = nodoConexion->HI;
    a->HI = nodoConexion->HD;
    nodoConexion->HI = pPadre;
    nodoConexion->HD = a;
    a->padre = nodoConexion;
    pPadre->padre = nodoConexion;
    nodoConexion->color = !(nodoConexion->color);
    a->color = !(a->color);
    if ((nodoConexion->padre != nullptr) && (nodoConexion->padre->HD == a)) {
        nodoConexion->padre->HD = nodoConexion;
    }
    else {
        if ((nodoConexion->padre != nullptr) && (nodoConexion->padre->HI == a)) {
            nodoConexion->padre->HI = nodoConexion;
        }
    }
    if ((a->HD != nullptr) && (a->HD->color) && (a->color)) {
        reglaDelTio(a->HD);
    }
    else {
        if ((a->HI != nullptr) && (a->HI->color) && (a->color)) {
            reglaDelTio(a->HI);
        }
    }
    if ((pPadre->HD != nullptr) && (pPadre->HD->color) && (pPadre->color)) {
        reglaDelTio(pPadre->HD);
    }
    else {
        if ((pPadre->HI != nullptr) && (pPadre->HI->color) && (pPadre->color)) {
            reglaDelTio(pPadre->HI);
        }
    }
    if ((nodoConexion->padre != nullptr) && (nodoConexion->padre->color) && (nodoConexion->color)) {
        reglaDelTio(nodoConexion);
    }
}

void arbolPaises::rotacionDobleDerecha(nodoConexion* nodoConexion)
{
    pnodoConexion a = abuelo(nodoConexion);
    pnodoConexion pPadre = nodoConexion->padre;
    nodoConexion->padre = a->padre;
    if (a->padre == nullptr) {
        auxCiudadMadre->conexiones = nodoConexion;
    }
    pPadre->HI = nodoConexion->HD;
    a->HD = nodoConexion->HI;
    nodoConexion->HD = pPadre;
    nodoConexion->HI = a;
    a->padre = nodoConexion;
    pPadre->padre = nodoConexion;
    nodoConexion->color = !(nodoConexion->color);
    a->color = !(a->color);
    if ((nodoConexion->padre != nullptr) && (nodoConexion->padre->HD == a)) {
        nodoConexion->padre->HD = nodoConexion;
    }
    else {
        if ((nodoConexion->padre != nullptr) && (nodoConexion->padre->HI == a)) {
            nodoConexion->padre->HI = nodoConexion;
        }
    }
    if ((a->HD != nullptr) && (a->HD->color) && (a->color)) {
        reglaDelTio(a->HD);
    }
    else {
        if ((a->HI != nullptr) && (a->HI->color) && (a->color)) {
            reglaDelTio(a->HI);
        }
    }
    if ((pPadre->HD != nullptr) && (pPadre->HD->color) && (pPadre->color)) {
        reglaDelTio(pPadre->HD);
    }
    else {
        if ((pPadre->HI != nullptr) && (pPadre->HI->color) && (pPadre->color)) {
            reglaDelTio(pPadre->HI);
        }
    }
    if ((nodoConexion->padre != nullptr) && (nodoConexion->padre->color) && (nodoConexion->color)) {
        reglaDelTio(nodoConexion);
    }
}

bool arbolPaises::validaConexion(int pCodPais, int pCodCiudad, int pCodConexion){
    ConexionEncontrada = false;
    buscarPaisParaConexion(Raiz,pCodPais,pCodCiudad,pCodConexion, 1, 0);
    return ConexionEncontrada;
}

void arbolPaises::buscarPaisParaConexion(nodoPais *R, int pCodPais, int pCodCiudad, int pCodConexion, int opcion, int variable){
    if(R == nullptr){
        return ;
    }else{
        if(R->CodPais == pCodPais){
            msgConsultarConexion+="Pais salida: "+to_string(R->CodPais);
            buscarCiudadParaValidarConexion(R->Ciudades, pCodCiudad, pCodConexion, opcion, variable);
            return ;
        }else{
            if(R->CodPais>pCodPais){
                buscarPaisParaConexion(R->Hizq, pCodPais, pCodCiudad, pCodConexion,opcion, variable);
            }
            if(R->CodPais<pCodPais){
                buscarPaisParaConexion(R->Hder, pCodPais, pCodCiudad, pCodConexion, opcion, variable);
            }
        }
    }
}


void arbolPaises::buscarCiudadParaValidarConexion(nodoCiudad *R, int pCodCiudad, int pCodigoConexion, int opcion, int variable){
    if(R == nullptr){
        return ;
    }

    if(R->CodCiudad == pCodCiudad){
        msgConsultarConexion+=" Ciudad salida: "+to_string(R->CodCiudad);
        buscarConexionParaValidar(R->conexiones, pCodigoConexion, opcion, variable);
        return ;
    }else{
        if(R->CodCiudad>pCodCiudad){
            buscarCiudadParaValidarConexion(R->Hizq, pCodCiudad, pCodigoConexion, opcion, variable);
        }
        if(R->CodCiudad<pCodCiudad){
            buscarCiudadParaValidarConexion(R->Hder, pCodCiudad, pCodigoConexion, opcion, variable);
        }
    }
}

void arbolPaises::buscarConexionParaValidar(pnodoConexion R, int pCodigoConexion, int opcion, int variable){

    if(R == nullptr){
        return ;
    }

    if(R->codigoConexion == pCodigoConexion){
        switch (opcion) {
            case 1:
                ConexionEncontrada = true;
                break;
            case 2 :
                msgConsultarConexion+=" CodConexion: "+to_string(R->codigoConexion)+" PaisDestino: "+to_string(R->codigoPaisDest)+" CiudadDestino: "+to_string(R->codigoCiudadDest);
                msgConsultarConexion+=" Precio: "+to_string(R->precio)+" Horas: "+R->horas;
                break;
            case 3:
                R->precio = variable;
                msgConsultarConexion = "Se ha modificado el Precio";
                break;
            case 4:
                R->horas = to_string(variable);
                msgConsultarConexion = "Se ha modificado el tiempo de la conexion";
                break;
        }

        return ;
    }else{
        if(R->codigoConexion>pCodigoConexion){
            buscarConexionParaValidar(R->HI, pCodigoConexion,opcion, variable);
        }
        if(R->codigoConexion<pCodigoConexion){
            buscarConexionParaValidar(R->HD, pCodigoConexion, opcion, variable);
        }
    }
}

bool arbolPaises::ConsultarConexionesParaRuta(int pCodPais, int pCodCiudad, int pCodPaisDest, int pCodCiudadDest){
    ConexionEncontrada = false;
    EncontrarPaisParaConexionParaRuta(Raiz,pCodPais,pCodCiudad,pCodPaisDest,pCodCiudadDest);
    return ConexionEncontrada;
}

void arbolPaises::EncontrarPaisParaConexionParaRuta(nodoPais *R, int pCodPais, int pCodCiudad, int pCodPaisDest, int pCodCiudadDest)
{
    if(R == nullptr){
    return ;
    }else{
        if(R->CodPais == pCodPais){
            EncontrarCiudadParaConexionParaRuta(R->Ciudades, pCodCiudad, pCodPaisDest, pCodCiudadDest);
            return ;
        }else{
            if(R->CodPais>pCodPais){
                EncontrarPaisParaConexionParaRuta(R->Hizq, pCodPais, pCodCiudad, pCodPaisDest, pCodCiudadDest);
            }
            if(R->CodPais<pCodPais){
                EncontrarPaisParaConexionParaRuta(R->Hder,pCodPais, pCodCiudad, pCodPaisDest, pCodCiudadDest);
            }
        }
    }
}

void arbolPaises::EncontrarCiudadParaConexionParaRuta(nodoCiudad *R, int pCodCiudad, int pCodPaisDest, int pCodCiudadDest){
    if(R == nullptr){
        return ;
    }

    if(R->CodCiudad == pCodCiudad){
        PreordenArbolConexionParaRuta(R->conexiones, pCodPaisDest, pCodCiudadDest);
        return ;
    }else{
        if(R->CodCiudad>pCodCiudad){
            EncontrarCiudadParaConexionParaRuta(R->Hizq, pCodCiudad, pCodPaisDest, pCodCiudadDest);
        }
        if(R->CodCiudad<pCodCiudad){
            EncontrarCiudadParaConexionParaRuta(R->Hder, pCodCiudad, pCodPaisDest, pCodCiudadDest);
        }
    }
}

void arbolPaises::PreordenArbolConexionParaRuta(nodoConexion *R, int pCodPaisDest, int pCodCiudadDest){
    if(R==nullptr){
        return;
    }else{
        if(R->codigoPaisDest == pCodPaisDest && R->codigoCiudadDest == pCodCiudadDest){
            ConexionEncontrada = true;
            return;
        }else{
            PreordenArbolConexionParaRuta(R->HI, pCodPaisDest, pCodCiudadDest);
            PreordenArbolConexionParaRuta(R->HD, pCodPaisDest, pCodCiudadDest);
        }
    }
}
