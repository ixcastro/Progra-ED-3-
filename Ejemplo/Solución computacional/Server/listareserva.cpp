#include "listareserva.h"
int ListaReserva::largoLista(){
    int cont=0;

    pnodoReserva aux;
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




string ListaReserva::InsertarFinal(string pComprador, string pCodTipoTren, string pCodTren, string pCodRuta, string pPasajeros, string pNumAsientos)
{
   if (ListaVacia()){
     primero = new nodoReserva(pComprador, pCodTipoTren, pCodTren, pCodRuta, pPasajeros, pNumAsientos);
     return "Su codigo de reservacion es: "+primero->codigoReserva+"\n";
   }
   else
     { pnodoReserva aux = primero;
        while ( aux->siguiente != NULL){
          aux= aux->siguiente;
        }
        aux->siguiente=new nodoReserva(pComprador, pCodTipoTren, pCodTren, pCodRuta, pPasajeros, pNumAsientos);
        return "El codigo de reserva es: "+aux->siguiente->codigoReserva+"\n";
      }
}

void ListaReserva::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;

   }else{
        if (primero->siguiente == NULL) {
                pnodoReserva temp = primero;
                primero= NULL;
                delete temp;
            } else {

                pnodoReserva aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }

              pnodoReserva temp = aux->siguiente;
              aux->siguiente= NULL;
              delete temp;
            }
        }
}

void ListaReserva::Mostrar()
{
   nodoReserva *aux;
   if (primero== NULL)
       cout << "No hay elementos";
   else
   {
       aux = primero;
       while(aux != NULL)
       {
           cout << aux->codigoReserva << "-> ";
           aux = aux->siguiente;
       }
       cout << endl;
   }
}

string ListaReserva::consultarRutasMasUtilizadas(){
    string msg = "";
    pnodoReserva aux = primero;
    string listaRutas[50];
    int listaCant[50];
    for(int i = 0; i<50; i++){
        listaRutas[i] = "";
        listaCant[i] = 0;
    }
    if(aux!=NULL){
        while(aux!=NULL){
            int cont = 0;
            bool verifica = false;
            while(listaRutas[cont] != ""){
                string compara = aux->codigoRuta;
                if(compara == listaRutas[cont]){
                    verifica = true;
                }
                cont++;
            }
            if(!verifica){
                string guarda = aux->codigoRuta;
                listaRutas[cont] = guarda;
                listaCant[cont] = listaCant[cont]+1;
            }else{
                listaCant[cont-1] = listaCant[cont-1]+1;
            }
            aux = aux->siguiente;
        }
        int maxValor = 0;
        int cont = 0;
        int posSaved = 0;
        while(listaRutas[cont] != ""){
            if(listaCant[cont] > maxValor){
                maxValor = listaCant[cont];
                //Guarda la posicion de la ruta mas usada
                posSaved = cont;
            }
            cont++;
        }
        ostringstream os;
        os<<listaCant[posSaved];
        msg = "La ruta mas usada es: " + listaRutas[posSaved]+", con "+os.str()+" reservaciones realizadas.";
        return msg;
    }else{
        return "No se ha registrado ninguna reserva";
    }

}
string ListaReserva::consultarRutasMaenosUtilizadas(){
    string msg = "";
    pnodoReserva aux = primero;
    string listaRutas[50];
    int listaCant[50];
    for(int i = 0; i<50; i++){
        listaRutas[i] = "";
        listaCant[i] = 0;
    }
    if(aux!=NULL){
        while(aux!=NULL){
            int cont = 0;
            bool verifica = false;
            while(listaRutas[cont] != ""){
                string compara = aux->codigoRuta;
                if(compara == listaRutas[cont]){
                    verifica = true;
                }
                cont++;
            }
            if(!verifica){
                string guarda = aux->codigoRuta;
                listaRutas[cont] = guarda;
                listaCant[cont] = listaCant[cont]+1;
            }else{
                listaCant[cont-1] = listaCant[cont-1]+1;
            }
            aux = aux->siguiente;
        }
        int minValor = 100;
        int cont = 0;
        int posSaved = 0;
        while(listaRutas[cont] != ""){
            if(listaCant[cont] < minValor){
                minValor = listaCant[cont];
                posSaved = cont;
            }
            cont++;
        }
        ostringstream os;
        os<<listaCant[posSaved];
        msg = "La ruta menos usada es: " + listaRutas[posSaved]+", con "+os.str()+" reservaciones realizadas.";
        return msg;
    }else{
        return "No se ha registrado ninguna reserva";
    }
}
string ListaReserva::consultarPaisMasVisitados(){
    string msg = "";
    pnodoReserva aux = primero;
    string listaPaises[50];
    int listaCant[50];
    for(int i = 0; i<50; i++){
        listaPaises[i] = "";
        listaCant[i] = 0;
    }
    if(aux != NULL){
        while(aux!=NULL){
            int cont = 0;
            bool verifica = false;
            while(listaPaises[cont] != ""){
                string compara = aux->codigoRuta;
                if(compara == listaPaises[cont]){
                    verifica = true;
                }
                cont++;
            }
            if(!verifica){
                string guarda = aux->codigoRuta;
                listaPaises[cont] = guarda;
                listaCant[cont] = listaCant[cont]+1;
            }else{
                listaCant[cont-1] = listaCant[cont-1]+1;
            }
            aux = aux->siguiente;
        }
        int maxValor = 0;
        int cont = 0;
        int posSaved = 0;
        while(listaPaises[cont] != ""){
            if(listaCant[cont] > maxValor){
                maxValor = listaCant[cont];
                posSaved = cont;
            }
            cont++;
        }
        ostringstream os;
        os<<listaCant[posSaved];
        msg = "El pais mas visitado es: " + listaPaises[posSaved]+", con "+os.str()+" reservaciones realizadas.";
        return msg;
    }else{
        return "No se ha registrado ninguna reserva";
    }
}
string ListaReserva::consultarCiudadMasVisitada(){
    string msg = "";
    pnodoReserva aux = primero;
    string listaCiudades[50];
    int listaCant[50];
    for(int i = 0; i<50; i++){
        listaCiudades[i] = "";
        listaCant[i] = 0;
    }
    if(aux != NULL){
        while(aux!=NULL){
            int cont = 0;
            bool verifica = false;
            while(listaCiudades[cont] != ""){
                string compara = aux->codigoRuta;
                if(compara == listaCiudades[cont]){
                    verifica = true;
                }
                cont++;
            }
            if(!verifica){
                string guarda = aux->codigoRuta;
                listaCiudades[cont] = guarda;
                listaCant[cont] = listaCant[cont]+1;
            }else{
                listaCant[cont-1] = listaCant[cont-1]+1;
            }
            aux = aux->siguiente;
        }
        int maxValor = 0;
        int cont = 0;
        int posSaved = 0;
        while(listaCiudades[cont] != ""){
            if(listaCant[cont] > maxValor){
                maxValor = listaCant[cont];
                posSaved = cont;
            }
            cont++;
        }
        ostringstream os;
        os<<listaCant[posSaved];
        msg = "La ciudad mas visitada es: " + listaCiudades[posSaved]+", con "+os.str()+" reservaciones realizadas.";
        return msg;
    }else{
        return "No se ha registrado ninguna reserva";
    }
}
string ListaReserva::consultarUsuarioMasActivo(){
    string msg = "";
    pnodoReserva aux = primero;
    string listaUsuarios[50];
    int listaCant[50];
    for(int i = 0; i<50; i++){
        listaUsuarios[i] = "";
        listaCant[i] = 0;
    }
    if(aux!= NULL){
        while(aux!=NULL){
            int cont = 0;
            bool verifica = false;
            while(listaUsuarios[cont] != ""){
                string compara = aux->comprador;
                if(compara == listaUsuarios[cont]){
                    verifica = true;
                }
                cont++;
            }
            if(!verifica){
                string guarda = aux->comprador;
                listaUsuarios[cont] = guarda;
                listaCant[cont] = listaCant[cont]+1;
            }else{
                listaCant[cont-1] = listaCant[cont-1]+1;
            }
            aux = aux->siguiente;
        }
        int maxValor = 0;
        int cont = 0;
        int posSaved = 0;
        while(listaUsuarios[cont] != ""){
            if(listaCant[cont] > maxValor){
                maxValor = listaCant[cont];
                posSaved = cont;
            }
            cont++;
        }
        ostringstream os;
        os<<listaCant[posSaved];
        msg = "El usuario que mas ha comprado tiene el pasaporte: " + listaUsuarios[posSaved]+", con "+os.str()+" reservaciones realizadas.";
        return msg;
    }else{
        return "No se ha registrado ninguna reserva";
    }
}
string ListaReserva::consultarUsuarioMenosActivo(){
    string msg = "";
    pnodoReserva aux = primero;
    string listaUsuarios[50];
    int listaCant[50];
    for(int i = 0; i<50; i++){
        listaUsuarios[i] = "";
        listaCant[i] = 0;
    }
    if(aux != NULL){
        while(aux!=NULL){
            int cont = 0;
            bool verifica = false;
            while(listaUsuarios[cont] != ""){
                string compara = aux->comprador;
                if(compara == listaUsuarios[cont]){
                    verifica = true;
                }
                cont++;
            }
            if(!verifica){
                string guarda = aux->comprador;
                listaUsuarios[cont] = guarda;
                listaCant[cont] = listaCant[cont]+1;
            }else{
                listaCant[cont-1] = listaCant[cont-1]+1;
            }
            aux = aux->siguiente;
        }
        int minValor = 100;
        int cont = 0;
        int posSaved = 0;
        while(listaUsuarios[cont] != ""){
            if(listaCant[cont] < minValor){
                minValor = listaCant[cont];
                posSaved = cont;
            }
            cont++;
        }
        ostringstream os;
        os<<listaCant[posSaved];
        msg = "El usuario que menos ha comprado tiene el pasaporte: " + listaUsuarios[posSaved]+", con "+os.str()+" reservaciones realizadas.";
        return msg;
    }else{
        return "No se ha registrado ninguna reserva";
    }
}
string ListaReserva::consultarCantCompras(){
    string msg = "";
    pnodoReserva aux = primero;
    string listaUsuarios[50];
    int listaCant[50];
    for(int i = 0; i<50; i++){
        listaUsuarios[i] = "";
        listaCant[i] = 0;
    }
    if(aux != NULL){
        while(aux!=NULL){
            int cont = 0;
            bool verifica = false;
            while(listaUsuarios[cont] != ""){
                string compara = aux->comprador;
                if(compara == listaUsuarios[cont]){
                    verifica = true;
                }
                cont++;
            }
            if(!verifica){
                string guarda = aux->comprador;
                listaUsuarios[cont] = guarda;
                listaCant[cont] = listaCant[cont]+1;
            }else{
                listaCant[cont-1] = listaCant[cont-1]+1;
            }
            aux = aux->siguiente;
        }
        int cont = 0;
        while(listaUsuarios[cont] != ""){
            ostringstream os;
            os<<listaCant[cont];
            msg += "El usuario con el pasaporte: " + listaUsuarios[cont]+", tiene "+os.str()+" reservaciones realizadas.\n";
            cont++;
        }
        return msg;
    }else{
        return "No se ha registrado ninguna reserva";
    }
}
string ListaReserva::consultarTrenMasUtilizado(){
    string msg = "";
    pnodoReserva aux = primero;
    string listaTrenes[50];
    int listaCant[50];
    for(int i = 0; i<50; i++){
        listaTrenes[i] = "";
        listaCant[i] = 0;
    }
    if(aux!= NULL){
        while(aux!=NULL){
            int cont = 0;
            bool verifica = false;
            while(listaTrenes[cont] != ""){
                string compara = aux->codigoTren;
                if(compara == listaTrenes[cont]){
                    verifica = true;
                }
                cont++;
            }
            if(!verifica){
                string guarda = aux->codigoTren;
                listaTrenes[cont] = guarda;
                listaCant[cont] = listaCant[cont]+1;
            }else{
                listaCant[cont-1] = listaCant[cont-1]+1;
            }
            aux = aux->siguiente;
        }
        int maxValor = 0;
        int cont = 0;
        int posSaved = 0;
        while(listaTrenes[cont] != ""){
            if(listaCant[cont] > maxValor){
                maxValor = listaCant[cont];
                posSaved = cont;
            }
            cont++;
        }
        ostringstream os;
        os<<listaCant[posSaved];
        msg = "El tren que mas se ha utilizado tiene el codigo: " + listaTrenes[posSaved]+", con "+os.str()+" reservaciones realizadas.";
        return msg;
    }else{
        return "No se ha registrado ninguna reserva";
    }
}
string ListaReserva::consultarTrenMenosUtilizado(){
    string msg = "";
    pnodoReserva aux = primero;
    string listaTrenes[50];
    int listaCant[50];
    for(int i = 0; i<50; i++){
        listaTrenes[i] = "";
        listaCant[i] = 0;
    }
    if(aux!= NULL){
        while(aux!=NULL){
            int cont = 0;
            bool verifica = false;
            while(listaTrenes[cont] != ""){
                string compara = aux->codigoTren;
                if(compara == listaTrenes[cont]){
                    verifica = true;
                }
                cont++;
            }
            if(!verifica){
                string guarda = aux->codigoTren;
                listaTrenes[cont] = guarda;
                listaCant[cont] = listaCant[cont]+1;
            }else{
                listaCant[cont-1] = listaCant[cont-1]+1;
            }
            aux = aux->siguiente;
        }
        int minValor = 100;
        int cont = 0;
        int posSaved = 0;
        while(listaTrenes[cont] != ""){
            if(listaCant[cont] < minValor){
                minValor = listaCant[cont];
                posSaved = cont;
            }
            cont++;
        }
        ostringstream os;
        os<<listaCant[posSaved];
        msg = "El tren que menos se ha utilizado tiene el codigo: " + listaTrenes[posSaved]+", con "+os.str()+" reservaciones realizadas.";
        return msg;
    }else{
        return "No se ha registrado ninguna reserva";
    }
}
