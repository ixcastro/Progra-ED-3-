#ifndef PAGINA_H
#define PAGINA_H
#include <iostream>
#include "stclave.h"

class Pagina {
public:
    Pagina (int nClaves);
    ~Pagina ();
private:
    int clavesUsadas;           // cantidad de claves usadas en el nodo
    StClave *clave;             // valor que tendrá el nodo
    Pagina **puntero;            // array de punteros
    Pagina  *padre;              // Nodo padre del nodo

    friend class ArbolB;
};

typedef Pagina *pPagina;

#endif // PAGINA_H
