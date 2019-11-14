#include "pagina.h"

Pagina::Pagina(int nClaves){
    clavesUsadas = 0;
    clave = new StClave[nClaves];
    puntero = new pPagina [nClaves + 1];
    padre = nullptr;
}

Pagina::~Pagina(){
    delete[] clave;
    delete[] puntero;
}
