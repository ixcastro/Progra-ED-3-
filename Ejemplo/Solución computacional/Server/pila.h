#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "nodopais.h"
#include "listaparaverticeskruskal.h"

using namespace std;

class nodoP {
   public:
        nodoP(pnodoCiudad v){
            valor = v;
            siguiente = NULL;
        }

        nodoP(pnodoCiudad v, nodoP * signodo){
            valor = v;
            siguiente = signodo;
        }
       pnodoCiudad valor;
    private:
        //pnodoA valor;
        nodoP *siguiente;

   friend class pila;
   friend class lista;
};

typedef nodoP *pnodoP;

class lista {
    public:
        lista() { primero = actual = NULL; }

        void EliminarInicio();
        void EliminarFinal();
        void EliminarPos(int pos);
        bool ListaVacia() { return primero == NULL; }
        void Borrar(string v);
        void Mostrar();
        void Siguiente();
        void Primero();
        void Ultimo();
        pnodoCiudad BorrarFinal();
        int largoLista();
        bool Buscar(string valor);
        void invertir();
        void push(pnodoCiudad v);
    protected:
        pnodoP primero;
        pnodoP actual;

    friend class cola;
};

#endif // PILA_H
