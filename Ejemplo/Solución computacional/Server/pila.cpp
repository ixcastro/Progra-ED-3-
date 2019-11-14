#include "pila.h"
#include <iostream>

int lista::largoLista(){
    int cont=0;
    pnodoP aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
            aux=aux->siguiente;
            cont++;
        }
    return cont;
    }
}


pnodoCiudad lista::BorrarFinal(){
    if (ListaVacia()){
         return nullptr;
    }else{
        if (primero->siguiente == NULL) {
            pnodoP temp = primero;
            primero= NULL;
            return temp->valor;
        } else {
            pnodoP aux = primero;
            while (aux->siguiente->siguiente != NULL) {
                aux = aux->siguiente;
            }
            pnodoP temp = aux->siguiente;
            aux->siguiente= NULL;
            return temp->valor;
        }
    }
}


void lista:: push (pnodoCiudad v) {
    if (ListaVacia())
        primero = new nodoP(v);
    else{
        pnodoP aux = primero;
        while ( aux->siguiente != NULL)
            aux= aux->siguiente;
        aux->siguiente=new nodoP(v);
    }
}

void lista::Mostrar(){
    pnodoP aux;
    aux = primero;
    while(aux!=NULL) {
        cout << aux->valor->nombre << "-> ";
        aux = aux->siguiente;
   }
   cout << endl;
}

void lista::Siguiente(){
    if(actual) actual = actual->siguiente;
}

void lista::Primero(){
    actual = primero;
}

void lista::Ultimo(){
    actual = primero;
    if(!ListaVacia())
        while(actual->siguiente) Siguiente();
}
