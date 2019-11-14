#include "listaparaverticeskruskal.h"


int listaD::largoLista(){
    int cont=0;
    pnodo aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=nullptr){
            aux=aux->siguiente;
            cont++;
        }
    return cont;
    }
}


void listaD::InsertarEnOrdenPrecio(string pCodConexion, string pPais,string pCiudad, string pPaisDestino,string pCiudadDestino,int pPrecio, int pTiempo){

    nodo *nuevoNodo = new nodo(pCodConexion, pPais, pCiudad,  pPaisDestino, pCiudadDestino, pPrecio,  pTiempo);
    if(!validar(pPaisDestino, pCiudadDestino, pPais, pCiudad, pPrecio, pTiempo)){
        if(ListaVacia()){
            cout<<"La lista esta vacia"<<endl;
            primero = nuevoNodo;
        }else{
            if(nuevoNodo->precio<=primero->precio){
                nuevoNodo->siguiente = primero;
                primero->anterior = nuevoNodo;
                primero = nuevoNodo;
                return;

            }else{
                pnodo aux = primero;
                while(aux->siguiente !=nullptr){
                    if(nuevoNodo->precio<=aux->precio){
                        nuevoNodo->siguiente = aux;
                        nuevoNodo->anterior = aux->anterior;
                        aux->anterior->siguiente = nuevoNodo;
                        aux->anterior = nuevoNodo;
                        return;
                    }else{
                        aux = aux->siguiente;
                    }
                }
                if(nuevoNodo->precio<=aux->precio){
                    nuevoNodo->siguiente = aux;
                    nuevoNodo->anterior = aux->anterior;
                    aux->anterior->siguiente = nuevoNodo;
                    aux->anterior = nuevoNodo;
                    return;
                }else{
                    aux->siguiente = nuevoNodo;
                    nuevoNodo->anterior = aux;
                    return;
                }
            }
        }
    }
}

bool listaD::validar(string pPais, string pCiudad, string pPaisDestino, string pCiudadDestino, int pPrecio, int pTiempo){
    nodo *aux = primero;
    while(aux !=nullptr){
        if(aux->pais == pPais and aux->ciudad == pCiudad and aux->paisDestino == pPaisDestino and aux->ciudadDestino == pCiudadDestino and aux->precio == pPrecio and aux->tiempo == pTiempo){
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}




void listaD::Mostrar(){
   nodo *aux;
   aux = primero;
   while(aux != nullptr) {
      cout << aux->pais<<";"<<aux->ciudad<<";"<<aux->paisDestino<<";"<<aux->ciudadDestino<<";"<<aux->precio<<endl;
      aux = aux->siguiente;
   }
   cout << endl;
}

void listaD::Siguiente(){
   if(actual) actual = actual->siguiente;
}

void listaD::Primero(){
   actual = primero;
}

void listaD::Ultimo(){
   actual = primero;
   if(!ListaVacia())
      while(actual->siguiente) Siguiente();
}

