#ifndef ARBOLB_H
#define ARBOLB_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <QFile>
#include <QTextStream>
#include "pagina.h"

using namespace std;

/*
 *  Permite crear y manipular árboles B
 */

class ArbolB {
public:
    ArbolB (int numClave);
    long buscar (string clave);                    // retorna la posición del número si este fue encontrado
    long validarEstadoMigratorio (string codUsuario);
    bool insertar (StClave clave);
    void mostrarUsuario ();
    void mostrarAdministrador ();
    void leerArchivoUsuario ();
    void leerArchivoAdministrador ();

private:
    StClave *lista;
    pPagina  *listaPunt;
    pPagina  raiz;
    int nClaves;
    int nodosMinimos;
    void inserta (StClave clave, pPagina nodo, pPagina hijo1, pPagina hijo2);
    void borrarNodo (pPagina nodo);
    void verAdministrador (pPagina nodo);
    void verUsuario (pPagina nodo);

    friend class StClave;
};

#endif // ARBOLB_H
