#include "listapaises.h"
#include "listaparaverticeskruskal.h"

static ListaPais verticesSinArcos;
static listaD verticesOrdenados;

int ListaPais::largoLista()
{
    int cont=0;

    pnodoPais aux = primero;
    if(ListaVacia())
    {
        return cont;
    }
    else
    {
        while(aux!=primero)
        {
          aux=aux -> siguiente;
          cont++;
        }
    return cont;
    }

}

void ListaPais::InsertarInicio(string pCodigo, string pNombre)
{

   if (ListaVacia())
   {
     primero = new nodoPais(pCodigo, pNombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   }
   else
   {
     pnodoPais nuevo=new nodoPais (pCodigo, pNombre);
     nuevo->siguiente=primero;
     nuevo->anterior= primero->anterior;
     primero->anterior->siguiente=nuevo;
     nuevo->siguiente->anterior=nuevo;
     primero= nuevo;
   }
}

void ListaPais::InsertarFinal(string pCodigo, string pNombre)
{
   if (ListaVacia())
     {
     primero = new nodoPais(pCodigo, pNombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   }
   else
   {
     pnodoPais nuevo = new nodoPais(pCodigo, pNombre);
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }
}


void ListaPais::InsertarPos(string pCodigo, string pNombre,int pos)
{
   if (ListaVacia())
   {
     primero = new nodoPais(pCodigo, pNombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   }
   else
   {
      if(pos <=1)
        InsertarInicio(pCodigo, pNombre);
       else
       {
        if (pos==largoLista())
          InsertarFinal(pCodigo, pNombre);
        else
        {
             pnodoPais aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero))
             {
                   i++;
                   aux=aux->siguiente;
             }
             pnodoPais nuevo= new nodoPais(pCodigo, pNombre);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             aux->siguiente->anterior=aux;
             nuevo->siguiente->anterior=nuevo;
        }
       }
   }
}

void ListaPais::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodoPais temp= primero;
        primero= NULL;
        delete temp;
      }
      else
      {
         pnodoPais aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodoPais temp = aux->siguiente;
         aux->siguiente= primero;
         primero->anterior=aux;
         delete temp;
      }
    }
}

void ListaPais::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodoPais temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodoPais aux = primero->anterior;
        pnodoPais temp= primero;
        aux->siguiente=primero->siguiente;
        primero=primero->siguiente;
        primero->anterior=aux;
        delete temp;
      }
    }
}

void ListaPais:: borrarPosicion(int pos)
{

  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos>largoLista())||(pos<0))
        cout << "Error en posicion" << endl;
   else
   {
      if(pos==1)
        BorrarInicio();
      else
      {
       int cont=2;
       pnodoPais aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodoPais temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       delete temp;
     }
    }
  }
}

string ListaPais::Mostrar()
{
   pnodoPais aux=primero;
   string msg = "Paises: \n";
   while(aux->siguiente!=primero)
     {
      msg += aux->nombre+"\n";
      aux = aux->siguiente;
     }
     msg += aux->nombre+"\n";
     return msg;
}

void ListaPais::insertarCiudad(string pCodigoPais, string pCodigoCiudad, string pNombre){
    nodoPais *aux = primero;
    do{
        if(aux->codigo == pCodigoPais){
            if (aux->ciudad == NULL)
              {
              aux->ciudad = new nodoCiudad(pCodigoCiudad, pNombre);
              aux->ciudad->anterior=aux->ciudad;
              aux->ciudad->siguiente=aux->ciudad;

              ultimaCiudadAgregada = aux->ciudad;
            }
            else
            {
              pnodoCiudad nuevo = new nodoCiudad(pCodigoCiudad, pNombre);
              nuevo->anterior = aux->ciudad->anterior;
              nuevo->siguiente=aux->ciudad->anterior->siguiente;
              aux->ciudad->anterior->siguiente=nuevo;
              aux->ciudad->anterior=nuevo;

              ultimaCiudadAgregada = nuevo;
             }
            return;
         }
        aux = aux->siguiente;
    }
    while(aux!=primero);
}
void ListaPais::insertarConexion(string pCodPaisSalida, string pCodCiudadSalida, string pCodConexion, string pCodPaisDest, string pCodCiudadDest, int Tiempo, int pPrecio){
    nodoPais *aux = primero;
    do{
        if(aux->codigo == pCodPaisSalida){
            cout<<aux->codigo<<endl;
            pnodoCiudad auxCiudad = aux->ciudad;
            do {
                cout<<auxCiudad->codigoCiudad<<endl;
                if(auxCiudad->codigoCiudad == pCodCiudadSalida){
                    pnodoConexion auxConexion = auxCiudad->conexion;
                    cout<<"Inserta"<<endl;
                    if (!auxConexion)
                      {
                      auxCiudad->conexion = new nodoConexion(pCodConexion, pCodPaisDest, pCodCiudadDest, Tiempo, pPrecio);
                      auxCiudad->conexion->anterior=auxCiudad->conexion;
                      auxCiudad->conexion->siguiente=auxCiudad->conexion;

                      ultimaConexionAgregada = auxCiudad->conexion;
                    }
                    else
                    {
                      pnodoConexion nuevo = new nodoConexion(pCodConexion, pCodPaisDest, pCodCiudadDest, Tiempo, pPrecio);
                      nuevo->anterior = auxCiudad->conexion->anterior;
                      nuevo->siguiente=auxCiudad->conexion->anterior->siguiente;
                      auxCiudad->conexion->anterior->siguiente=nuevo;
                      auxCiudad->conexion->anterior=nuevo;

                      ultimaConexionAgregada = nuevo;
                    }
                    return;
                }
                auxCiudad = auxCiudad->siguiente;
            }
            //
            while (auxCiudad!=aux->ciudad);
            return;
            //
         }
        aux = aux->siguiente;
      }
    while(aux!=primero);
}
bool ListaPais::validaPais(string pCodigo){
    pnodoPais aux=primero;
    if(primero == NULL){
        return false;
    }
    while(aux->siguiente!=primero)
      {
        if(aux->codigo == pCodigo){
            return true;
        }
        aux = aux->siguiente;
      }
    if(aux->codigo == pCodigo){
        return true;
    }else{
      return false;
    }
}
//Valida una ciudad en un pais
bool ListaPais::validaCiudad(string pCodPais, string pCodCiudad){
    pnodoPais aux=primero;
    if(aux == NULL){
        return false;
    }
    do{
        if(aux->codigo == pCodPais){
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == NULL){
                return false;
            }else{
                do{
                    if(auxCiudad->codigoCiudad == pCodCiudad){
                        return true;
                    }else{
                        auxCiudad = auxCiudad->siguiente;
                    }
                }
                while(auxCiudad!=aux->ciudad);
            }

        }
        aux = aux->siguiente;
      }
    while(aux!=primero);
    return false;
}

bool ListaPais::validaConexion(string pCodPais, string pCodCiudad, string pCodConexion){
    pnodoPais aux=primero;
    if(aux == NULL){
        return false;
    }
    do{
        if(aux->codigo == pCodPais){
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == NULL){
                return false;
            }else{
                do{
                    if(auxCiudad->codigoCiudad == pCodCiudad){
                        //
                        pnodoConexion auxConexion = auxCiudad->conexion;
                        if(auxConexion == NULL){
                            return false;
                        }else{
                            do{
                                if(auxConexion->codigoConexion == pCodConexion){
                                    return true;
                                }else{
                                    auxConexion = auxConexion->siguiente;
                                }
                            }
                            while(auxConexion!=auxCiudad->conexion);
                            return false;
                        }
                        //
                    }else{
                        auxCiudad = auxCiudad->siguiente;
                    }
                }
                while(auxCiudad!=aux->ciudad);
                return false;
            }

        }
        aux = aux->siguiente;
      }
    while(aux!=primero);
    return false;
}

bool ListaPais::validaConexion(string pCodPaisSalida, string pCodCiudadSalida, string pCodPaisDestino, string pCodCiudadDestino){
    pnodoPais aux=primero;
    if(aux == NULL){
        return false;
    }
    do{
        if(aux->codigo == pCodPaisSalida){
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == NULL){
                return false;
            }else{
                do{
                    if(auxCiudad->codigoCiudad == pCodCiudadSalida){
                        //
                        pnodoConexion auxConexion = auxCiudad->conexion;
                        if(auxConexion == NULL){
                            return false;
                        }else{
                            do{
                                if(auxConexion->codigoPaisDest == pCodPaisDestino && auxConexion->codigoCiudadDest == pCodCiudadDestino){
                                    return true;
                                }else{
                                    auxConexion = auxConexion->siguiente;
                                }
                            }
                            while(auxConexion!=auxCiudad->conexion);
                        }
                        //
                    }else{
                        auxCiudad = auxCiudad->siguiente;
                    }
                }
                while(auxCiudad!=aux->ciudad);
            }

        }
        aux = aux->siguiente;
      }
    while(aux!=primero);
    return false;
}

string ListaPais::MostrarCiudades(){
    pnodoPais aux=primero;
    string msg = "";
    if(aux==NULL){
        return "Lista de paises vacia\n";
    }else{
        msg = "Paises: \n";
        do{
                msg +=  aux->nombre + "\n";
                pnodoCiudad auxCiudad = aux->ciudad;
                if(auxCiudad == NULL){
                    msg += "  La lista de ciudades esta vacia\n";
                    aux = aux->siguiente;
                }else{
                    msg += "  Ciudades: \n";
                    do {
                        msg += "     "+auxCiudad->nombre+"\n";
                        auxCiudad = auxCiudad->siguiente;
                    }
                    while (auxCiudad!= aux->ciudad);
                  }
             aux = aux->siguiente;
        } while(aux!=primero);
        return msg;
    }

}


string ListaPais::MostrarConexiones(){
    pnodoPais aux=primero;
    string msg = "";
    if(aux==NULL){
        return "Lista de paises vacia\n";
    }else{
        msg = "Paises: \n";
        do{
            msg += aux->nombre + "\n";
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == NULL){
                msg +="  La lista de ciudades esta vacia\n";
                aux = aux->siguiente;
            }else{
                msg +="  Ciudades: \n";
                do {
                    msg +="     "+auxCiudad->nombre+"\n";
                    // Conexion
                    pnodoConexion auxConexion = auxCiudad->conexion;
                    if(auxConexion == NULL){
                        msg +="       La lista de conexiones esta vacia\n";
                    }else {
                        msg +="       Conexiones: \n";
                        do{
                            msg +="        De "+auxCiudad->nombre+", "+aux->nombre+" para: "+MostrarCiudad(auxConexion->codigoPaisDest,auxConexion->codigoCiudadDest)+". Cod. conexion: "+auxConexion->codigoConexion+". Duracion: "+to_string(auxConexion->horas)+" horas.\n";
                            auxConexion = auxConexion->siguiente;
                        }
                        while(auxConexion!=auxCiudad->conexion);
                    }
                    // Fin conexion
                    auxCiudad = auxCiudad->siguiente;
                }


                while (auxCiudad != aux->ciudad);
                // Fin conexion

                aux = aux->siguiente;
            }
        }
        while(aux!=primero);
        return msg;
    }
}
//Muestra la ciudad a partir de un codigo de pais y de ciudad
string ListaPais::MostrarCiudad(string pCodPais, string pCodCiudad){
    pnodoPais aux=primero;
    if(aux == NULL){
        return "El pais no existe";
    }
    do{
        if(aux->codigo == pCodPais){
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == NULL){
                return "El pais no tiene ciudades";
            }else{
                do{
                    if(auxCiudad->codigoCiudad == pCodCiudad){
                        return ""+auxCiudad->nombre+", "+aux->nombre;
                    }else{
                        auxCiudad = auxCiudad->siguiente;
                    }
                }
                while(auxCiudad!=aux->ciudad);
            }

        }
        aux = aux->siguiente;
      }
    while(aux!=primero);
    return "El pais no existe";
}
//Muestra el nombre de la ciudad a partir del codigo de ciudad
string ListaPais::MostrarCiudad(string pCodCiudad){
    pnodoPais aux=primero;
    if(aux == NULL){
        return "El pais no existe";
    }
    do{
        pnodoCiudad auxCiudad = aux->ciudad;
        if(auxCiudad == NULL){
            return "El pais no tiene ciudades registradas";
        }else{
            do{
                if(auxCiudad->codigoCiudad == pCodCiudad){
                    return auxCiudad->nombre;
                }else{
                    auxCiudad = auxCiudad->siguiente;
                }
            }
            while(auxCiudad!=aux->ciudad);
        }
        aux = aux->siguiente;
      }
    while(aux!=primero);
    return "No se encontro";
}

string ListaPais::MostrarCiudades(string pNombrePais)
{
    pnodoPais aux=primero;
    if(aux == NULL){
        return "El pais no existe";
    }
    do{
        if(aux->nombre == pNombrePais){
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == NULL){
                return "El pais no tiene ciudades";
            }else{
                string msg = "";
                do{
                    msg +=auxCiudad->nombre+"\n";
                    auxCiudad = auxCiudad->siguiente;
                }
                while(auxCiudad!=aux->ciudad);
                return msg;
            }

        }
        aux = aux->siguiente;
      }
    while(aux!=primero);
    return "El pais no existe";
}

string ListaPais::MostrarCiudadesCodigo(string pCodPais)
{
    pnodoPais aux=primero;
    if(aux == NULL){
        return "El pais no existe";
    }
    do{
        if(aux->codigo == pCodPais){
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == NULL){
                return "El pais no tiene ciudades";
            }else{
                string msg = "";
                do{
                    msg +=auxCiudad->nombre+"\n";
                    auxCiudad = auxCiudad->siguiente;
                }
                while(auxCiudad!=aux->ciudad);
                return msg;
            }

        }
        aux = aux->siguiente;
      }
    while(aux!=primero);
    return "El pais no existe";
}

string ListaPais::MostrarAtracciones(string pPais, string pCiudad)
{
    string msg="No hay nada";
    pnodoPais aux=primero;
    if(aux==NULL){
        return "Lista de paises vacia\n";
    }else{
        do{
            if(aux->nombre == pPais){
                pnodoCiudad auxCiudad = aux->ciudad;
                if(auxCiudad == NULL){
                    msg+= "  La lista de ciudades esta vacia\n";
                }else{
                    do {
                        if(auxCiudad->nombre == pCiudad){
                            pnodoAtraccion auxAtraccion= auxCiudad->atracciones;
                            if(auxAtraccion == NULL){
                                return "La lista de atracciones esta vacia\n";
                            }else {
                                do{
                                    msg+= "Nombre: "+auxAtraccion->nombre+"\t"+"Precio: "+auxAtraccion->precio+"\n";
                                    auxAtraccion = auxAtraccion->siguiente;
                                }
                                while(auxAtraccion!=auxCiudad->atracciones);
                                return msg;
                            }
                            // Fin conexion
                            auxCiudad = auxCiudad->siguiente;
                        }
                    }


                    while (auxCiudad != aux->ciudad);
                    return msg;
                }
            }else{
               aux = aux->siguiente;
            }
        }
        while(aux!=primero);
        return msg;
    }
}



string ListaPais::modificarTiempo(string pCodPais, string pCodCiudad, string pCodConexion, string pTiempo){
    pnodoPais aux=primero;
    if(aux == NULL){
        return "No existen paises";
    }
    do{
        if(aux->codigo == pCodPais){
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == NULL){
                return "No existen ciudades registradas en el pais";
            }else{
                do{
                    if(auxCiudad->codigoCiudad == pCodCiudad){
                        //
                        pnodoConexion auxConexion = auxCiudad->conexion;
                        if(auxConexion == NULL){
                            return "No existen conexiones registradas";
                        }else{
                            do{
                                if(auxConexion->codigoConexion == pCodConexion){
                                    //SE RALIZA LA MODIFICAION DE TIEMPO
                                    auxConexion->horas = atoi(pTiempo.c_str());
                                    return "El tiempo se cambio a "+to_string(auxConexion->horas)+" horas.";
                                }else{
                                    auxConexion = auxConexion->siguiente;
                                }
                            }
                            while(auxConexion!=auxCiudad->conexion);
                        }
                        //
                    }else{
                        auxCiudad = auxCiudad->siguiente;
                    }
                }
                while(auxCiudad!=aux->ciudad);
            }

        }
        aux = aux->siguiente;
      }
    while(aux!=primero);
    return "No se pudo realizar la modificacion. No se encontro la conexion";
}
string ListaPais::ConsultarConexionesPais(string pCodPais){
    string msg="";
    pnodoPais aux=primero;
    if(aux==NULL){
        return "Lista de paises vacia\n";
    }else{
        do{
            if(aux->codigo == pCodPais){
                msg+="Pais: \n";
                msg+= aux->nombre + "\n";
                pnodoCiudad auxCiudad = aux->ciudad;
                if(auxCiudad == NULL){
                    msg+= "  La lista de ciudades esta vacia\n";
                }else{
                    msg+= "  Ciudades: \n";
                    do {
                        msg+="     "+auxCiudad->nombre+"\n";
                        // Conexion
                        pnodoConexion auxConexion = auxCiudad->conexion;
                        if(auxConexion == NULL){
                            msg+="       La lista de conexiones esta vacia\n";
                        }else {
//                            cout<<"       Conexiones: "<<endl;
                            do{
                                msg+="        De "+auxCiudad->nombre+", "+aux->nombre+" para: "+auxConexion->codigoPaisDest+"-"+auxConexion->codigoCiudadDest +". Cod. conexion: "+auxConexion->codigoConexion+". Duracion: "+to_string(auxConexion->horas)+" horas.\n";
                                auxConexion = auxConexion->siguiente;
                            }
                            while(auxConexion!=auxCiudad->conexion);
                        }
                        // Fin conexion
                        auxCiudad = auxCiudad->siguiente;
                    }


                    while (auxCiudad != aux->ciudad);
                    return msg;
                    // Fin conexion
                }
            }else{
               aux = aux->siguiente;
            }
        }
        while(aux!=primero);
        return msg;
    }
}
void ListaPais::ConsultarCiudadesPais(string pCodPais){
    pnodoPais aux=primero;
    if(aux==NULL){
        cout<<"Lista de paises vacia"<<endl;
    }else{
        do{
            if(aux->codigo== pCodPais){
                cout<<"Pais: "<<endl;
                cout << aux->nombre << "\n";
                pnodoCiudad auxCiudad = aux->ciudad;
                if(auxCiudad == NULL){
                    cout<<"  La lista de ciudades esta vacia"<<endl;

                }else{
                    cout<<"  Ciudades: "<<endl;
                    do {
                        cout<<"     "<<auxCiudad->nombre<<endl;

                        auxCiudad = auxCiudad->siguiente;
                    }
                    while (auxCiudad!= aux->ciudad);
                }
                return;
            }else{
                aux = aux->siguiente;
            }
        }
        while(aux!=primero);
    }
}

string ListaPais::consultarPrecioConexion(string pCodPais, string pCodCiudad, string pCodConexion)
{
    pnodoPais aux = primero;
    if(aux == NULL){
        return "No hay paises registrados";
    }else{
        do{
            if(aux->codigo == pCodPais){
                string mensaje = "Pais de salida: "+aux->nombre;
                pnodoCiudad auxCiudad = aux->ciudad;
                do{
                    if(auxCiudad->codigoCiudad == pCodCiudad){
                        mensaje += " ciudad de salida: "+auxCiudad->nombre;
                        pnodoConexion auxConexion = auxCiudad->conexion;
                        do{
                            if(auxConexion->codigoConexion == pCodConexion){
                                return mensaje+" codigo de conexion: "+auxConexion->codigoConexion+". Pais de destino: "+
                                        auxConexion->codigoPaisDest+" ciudad de destino: "+auxConexion->codigoCiudadDest+
                                        ". Precio: "+to_string(auxConexion->precio);
                            }
                        }while(auxConexion != auxCiudad->conexion);
                    }else{
                        auxCiudad = auxCiudad->siguiente;
                    }
                }while(auxCiudad != aux->ciudad);
            }else{
                aux = aux->siguiente;
            }
        }while(aux!=primero);
        return "El pais no existe";
    }
}
string ListaPais::modificarPrecioConexion(string pCodPais, string pCodCiudad, string pCodConexion, string pPrecio){
    pnodoPais aux=primero;
    if(aux == NULL){
        return "No existen paises";
    }
    do{
        if(aux->codigo == pCodPais){
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == NULL){
                return "No existen ciudades registradas en el pais";
            }else{
                do{
                    if(auxCiudad->codigoCiudad == pCodCiudad){
                        //
                        pnodoConexion auxConexion = auxCiudad->conexion;
                        if(auxConexion == NULL){
                            return "No existen conexiones registradas";
                        }else{
                            do{
                                if(auxConexion->codigoConexion == pCodConexion){
                                    //SE RALIZA LA MODIFICAION DE TIEMPO
                                    auxConexion->precio = atoi(pPrecio.c_str());
                                    return "El tiempo se cambio a "+to_string(auxConexion->horas)+" horas.";
                                }else{
                                    auxConexion = auxConexion->siguiente;
                                }
                            }
                            while(auxConexion!=auxCiudad->conexion);
                        }
                        //
                    }else{
                        auxCiudad = auxCiudad->siguiente;
                    }
                }
                while(auxCiudad!=aux->ciudad);
            }

        }
        aux = aux->siguiente;
      }
    while(aux!=primero);
    return "No se pudo realizar la modificacion. No se encontro la conexion";
}

string ListaPais::obtenerUltimoPaisIngresado(){
    string msg = "ULTIMO PAIS AGREGADO: \n ";
    pnodoPais aux = primero->anterior;
    msg += "     Nombre del pais: "+aux->nombre+"\n";
    msg += "     Codigo del pais: "+aux->codigo+"\n";
    return msg;
}
string ListaPais::obtenerUltimaCiudadIngresada(){
    string msg = "ULTIMA CIUDAD AGREGADA: \n";
    msg += "    Nombre de la ciudad: "+ ultimaCiudadAgregada->nombre+"\n";
    msg += "    Codigo de la ciudad: "+ ultimaCiudadAgregada->codigoCiudad+"\n";
    return msg;
}
string ListaPais::obtenerUltimaConexionIngresada(){
    string msg = "ULTIMA CONEXION AGREGADA: \n";
    msg += "    Codigo de la conexion: "+ ultimaConexionAgregada->codigoConexion+"\n";
    msg += "    Codigo del pais de destino: "+ ultimaConexionAgregada->codigoPaisDest+"\n";
    msg += "    Codigo de la ciudad de destino: "+ ultimaConexionAgregada->codigoCiudadDest+"\n";
   // msg += "    Horas de viaje: "+ ultimaConexionAgregada->horas+"\n";
    return msg;

}


//Algoritmo grafos
void ListaPais::Kruskal(){
    primeroVisitados = nullptr;
    verticesOrdenados.primero = nullptr;

    cout<<"Entro en Kruskal"<<endl;
    OrdenarVertices();
    cout<<"Se han ordenado los vertices"<<endl;
    cout<<"Procede a conectar"<<endl;
    Conectar();

    ObtenerVerticesSinArcos();
    cout<<"Se obtuvieron los vertices"<<endl;

//    Conectar();

}

void ListaPais::OrdenarVertices(){
    pnodoPais aux=primero;
    string msg = "";
    if(aux==nullptr){
        return ;
    }else{
        do{
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad != nullptr){
                do{
                    // Conexion
                    pnodoConexion auxConexion = auxCiudad->conexion;
                    if(auxConexion != nullptr){
                        do{
                            verticesOrdenados.InsertarEnOrdenPrecio(auxConexion->codigoConexion, aux->codigo,auxCiudad->codigoCiudad,auxConexion->codigoPaisDest,auxConexion->codigoCiudadDest, auxConexion->precio, auxConexion->horas);

                            auxConexion = auxConexion->siguiente;
                        }while(auxConexion!=auxCiudad->conexion);
                    }
                    // Fin conexion
                    auxCiudad = auxCiudad->siguiente;
                }while (auxCiudad != aux->ciudad);
            }
            aux = aux->siguiente;
        }while(aux!=primero);
    }
}

void ListaPais::Conectar(){
    int peso = 0;
    nodo *aux = verticesOrdenados.primero;
    InsertarCiudadVisitada("pais",aux->ciudad);
    while(aux!=nullptr){
        if(!VerificarVisitado(aux->ciudadDestino)){
            peso+=aux->precio;
            InsertarCiudadVisitada("pais",aux->ciudadDestino);
        }else{
            if(!VerificarVisitado(aux->ciudad)){
                peso+=aux->precio;
                InsertarCiudadVisitada("pais", aux->ciudad);
            }
        }
        aux = aux->siguiente;
    }
}


void ListaPais::ObtenerVerticesSinArcos(){
    pnodoPais aux=primero;
    if(aux==nullptr){
        cout<<"Lista de paises vacia"<<endl;
    }else{
        do{
            verticesSinArcos.InsertarFinal(aux->codigo,aux->nombre);
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == nullptr){
                cout<<"  La lista de ciudades esta vacia"<<endl;

            }else{
                do {
                    verticesSinArcos.insertarCiudad(aux->codigo,auxCiudad->codigoCiudad,auxCiudad->nombre);
                    auxCiudad = auxCiudad->siguiente;
                }while (auxCiudad!= aux->ciudad);
            }
            aux = aux->siguiente;
        }while(aux!=primero);
    }
}

void ListaPais::InsertarCiudadVisitada(string pPais, string pCodigoCiudad){
//    cout<<"Entro en insertar ciudad visitada"<<endl;
    if (primeroVisitados == nullptr){
//        cout<<"Primero visitados es null"<<endl;
         primeroVisitados = new nodoDijkstra(pPais,pCodigoCiudad,0);
         primeroVisitados->anterior=primeroVisitados;
         primeroVisitados->siguiente=primeroVisitados;
         ultimoVisitados = primeroVisitados;
    }else{
//        cout<<"Primero visitados diferente de null"<<endl;
         pnodoDijkstra nuevo = new nodoDijkstra(pPais,pCodigoCiudad,0);
         nuevo->anterior = primeroVisitados->anterior;
         nuevo->siguiente=primeroVisitados->anterior->siguiente;
         primeroVisitados->anterior->siguiente=nuevo;
         primeroVisitados->anterior=nuevo;
         ultimoVisitados = nuevo;
    }
}


bool ListaPais::VerificarVisitado(string pCodCiudad){
//    cout<<"Entro en verificar visitado "<<pCodCiudad<<endl;
    pnodoDijkstra aux= primeroVisitados;
    if(aux == nullptr){
//        cout<<"primero es null"<<endl;
        return false;
    }else{
//        cout<<aux->codigoCiudad<<endl;
        do{
//            cout<<pCodCiudad<<"=="<<aux->codigoCiudad<<endl;
            if(aux->codigoCiudad == pCodCiudad){
                return true;
            }
            aux = aux->siguiente;
        }while(aux!=primeroVisitados);
        return false;
    }
}
string ListaPais::prof(string codPais){
    pnodoPais aux=primero;
    string msg = "";
    if(aux==NULL){
        return "Lista de paises vacia\n";
    }else{
        msg = "Pais: \n";
        do{
            if (aux->codigo==codPais){
                msg +=  aux->nombre + "\n";
                pnodoCiudad auxCiudad = aux->ciudad;
                if(auxCiudad == NULL){
                    msg += "  La lista de ciudades esta vacia\n";
                    aux = aux->siguiente;
                }else{
                    msg += "  Ciudades: \n";
                    do {
                        msg += "     "+auxCiudad->nombre+"\n";
                        auxCiudad = auxCiudad->siguiente;
                    }
                    while (auxCiudad!= aux->ciudad);
                  }
                }
             aux = aux->siguiente;
        } while(aux!=primero);
        return msg;
    }

}

string ListaPais::Profundidad(string cod){
    cout<<"Entro en Profundidad"<<endl;
    OrdenarVertices();
    Conectar();
    ObtenerVerticesSinArcos();
    string codi= verticesSinArcos.prof(cod);
    cout<<codi<<endl;
    return codi;

//    Conectar();

}

string ListaPais::Dijkstra(string pPaisPartida, string pCiudadPartida,string pPaisDestino, string pDestino, int opcion){
    primeroVisitados = nullptr;
    evaluables = nullptr;
    rutaNueva = "";
    ObtenerNodo(pPaisPartida, pCiudadPartida);
    ObtenerCiudad(origen->CodPais,origen->codigoCiudad);
    InsertarCiudadVisitada(origen->CodPais, origen->codigoCiudad);
    primeroRutasNuevas = origen;
    primeroRutasNuevas->siguiente=primeroRutasNuevas;
    primeroRutasNuevas->anterior = primeroRutasNuevas;
    switch(opcion){
        case 0:
            EvaluarAdyacentes(pPaisDestino, pDestino);
            break;
        case 1:
            EvaluarAdyacentesPrecio(pPaisDestino, pDestino);
            break;

    }

    cout<<"Se evaluaron los adyacentes" <<endl;
    bool encontrado = false;
    ObtenerRuta(primeroRutasNuevas, pPaisDestino, pDestino, encontrado);
//    cout<<rutaNueva<<endl;
    cout<<"dijkstra sirvio XD"<<endl;
    return rutaNueva;

}

void ListaPais::ObtenerNodo(string pCodPais, string pCodCiudad){
    pnodoPais aux=primero;
    if(aux == nullptr){
        return ;
    }
    do{
        if(aux->codigo == pCodPais){
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == nullptr){
                return ;
            }else{
                do{
                    if(auxCiudad->codigoCiudad == pCodCiudad){
                        origen = new nodoDijkstra(pCodPais, pCodCiudad,0);
                        return ;
                    }else{
                        auxCiudad = auxCiudad->siguiente;
                    }
                }
                while(auxCiudad!=aux->ciudad);
            }

        }
        aux = aux->siguiente;
      }
    while(aux!=primero);
    return ;
}


void ListaPais::EvaluarAdyacentes(string pPais, string pCiudad){
    AgregarEvaluables(CiudadDijkstra->conexion, origen->CodPais, origen->codigoCiudad);
    pnodoDijkstra menorCosto = evaluables;
    string paisllegada="";
    string ciudadllegada = "";
    pnodoDijkstra aux;

    while(!VerificarVisitado(pCiudad)){
        menorCosto = evaluables;
//        cout<<"///////////////////////////////////////////////////"<<endl;
//        cout<<"____________________________________________"<<endl;
//        MostrarEvaluables();
//        cout<<"____________________________________________"<<endl;

        aux = evaluables;
        ObtenerCosto(primeroRutasNuevas,aux->paisSalida, aux->ciudadSalida);
//        cout<<"Se obtuvo el costo "<<costo<<endl;
        int newCosto=costo+aux->total;
//        cout<<newCosto<<endl;
        do{
//            cout<<"Va a obtener costo"<<endl;
            ObtenerCosto(primeroRutasNuevas,aux->paisSalida, aux->ciudadSalida);
//            cout<<"Se obtuvo el costo "<<costo<<endl;
//            cout<<"Min "<<aux->total<<endl;
            if(costo+aux->total<newCosto){
                newCosto = costo+aux->total;
                menorCosto = aux;
            }
            aux = aux->siguiente;
        }while(aux!=evaluables);

//        cout<<menorCosto->CodPais<<";"<<menorCosto->codigoCiudad<<endl;

        if(!VerificarVisitado(menorCosto->codigoCiudad)){
            InsertarNodoDijsktra(primeroRutasNuevas,menorCosto->paisSalida, menorCosto->ciudadSalida, menorCosto->CodPais,menorCosto->codigoCiudad,menorCosto->total);
            InsertarCiudadVisitada(menorCosto->CodPais,menorCosto->codigoCiudad);
//            cout<<menorCosto->CodPais<<";"<<menorCosto->codigoCiudad<<endl;
            ObtenerCiudad(menorCosto->CodPais, menorCosto->codigoCiudad);
//            cout<<"Ciudad a la cual se le extraeran las conexiones "<<CiudadDijkstra->codigoCiudad<<endl;
            paisllegada =  menorCosto->CodPais;
            ciudadllegada = menorCosto->codigoCiudad;
            AgregarEvaluables(CiudadDijkstra->conexion,menorCosto->CodPais, menorCosto->codigoCiudad);
        }
        if(menorCosto==evaluables){
            evaluables = menorCosto->siguiente;
            menorCosto->anterior->siguiente=menorCosto->siguiente;
            menorCosto->siguiente->anterior = menorCosto->anterior;
            menorCosto->siguiente = nullptr;
            menorCosto->anterior = nullptr;
            delete menorCosto;
            menorCosto = nullptr;
        }else{
            menorCosto->anterior->siguiente=menorCosto->siguiente;
            menorCosto->siguiente->anterior = menorCosto->anterior;
            menorCosto->siguiente = nullptr;
            menorCosto->anterior = nullptr;
            delete menorCosto;
            menorCosto = nullptr;
        }

//        LimpiarEvaluables();

//        cout<<"///////////////////////////////////////////////////"<<endl;
    }
    //Obtener nueva ruta
}

void ListaPais::ObtenerCosto(pnodoDijkstra &puntero, string pcodPais, string pCodCiudad){
//    cout<<"Entro en obtener costo"<<endl;
    pnodoDijkstra aux = puntero;
    if(aux == nullptr){
        return;
    }
    do{
//        cout<<aux->CodPais<<":" <<aux->codigoCiudad<<endl;
//        cout<<pcodPais<<":" <<pCodCiudad<<endl;
        if(aux->CodPais == pcodPais and aux->codigoCiudad == pCodCiudad){
//            cout<<"Costo total: "<<aux->total<<endl;
            costo = aux->total;
            return;
        }else{
            ObtenerCosto( aux->otroCamino,  pcodPais,  pCodCiudad);
            aux = aux->siguiente;
        }
    }while(aux!=puntero);
//    cout<<"sale de obtener costo"<<endl;
}

void ListaPais::ObtenerCiudad(string pcodPais, string pCodCiudad){
//    cout<<"Entro en obtener ciudad"<<endl;
    pnodoPais aux=primero;
    if(aux==nullptr){
        return;
    }else{
        do{
           if(aux->codigo == pcodPais){
               pnodoCiudad auxCiudad = aux->ciudad;
               if(auxCiudad == nullptr){
               }else{
                   do {
//                       cout<<auxCiudad->codigoCiudad<<"=="<<pCodCiudad<<endl;
                       if(auxCiudad->codigoCiudad==pCodCiudad){
                           CiudadDijkstra = auxCiudad;
                           return;
                       }
                       auxCiudad = auxCiudad->siguiente;
                   }while (auxCiudad!= aux->ciudad);
               }
           }
            aux = aux->siguiente;
        }while(aux!=primero);
        return ;
    }
}

void ListaPais::InsertarNodoDijsktra(pnodoDijkstra &puntero, string pPaisPartida, string pCiudadSalida, string pPaisDestino, string pDestino,int pPeso){
    pnodoDijkstra aux = puntero;
    if(aux == nullptr){
        return;
    }
    do{
//        cout<<aux->CodPais<<";"<<aux->codigoCiudad<<" == "<<pPaisPartida<<";"<<pCiudadSalida<<endl;
        if(aux->CodPais == pPaisPartida and aux->codigoCiudad == pCiudadSalida){
            if(aux->otroCamino == nullptr){
                aux->otroCamino = new nodoDijkstra(pPaisDestino,pDestino, pPeso);
                aux->otroCamino->siguiente = aux->otroCamino;
                aux->otroCamino->anterior = aux->otroCamino;
                aux->otroCamino->predecesor = aux;
                aux->otroCamino->total +=aux->total;
            }else{
                pnodoDijkstra nuevo = new nodoDijkstra(pPaisDestino,pDestino, pPeso);
                nuevo->anterior = aux->otroCamino->anterior;
                nuevo->siguiente=aux->otroCamino->anterior->siguiente;
                aux->otroCamino->anterior->siguiente=nuevo;
                aux->otroCamino->anterior=nuevo;
                nuevo->total+=aux->total;
                nuevo->predecesor = aux;
            }
//            cout<<aux->otroCamino->
            return;
        }else{
            if(aux->otroCamino != nullptr){
                InsertarNodoDijsktra(aux->otroCamino, pPaisPartida, pCiudadSalida, pPaisDestino,pDestino, pPeso);
            }
            aux = aux->siguiente;
        }
    }while(aux!=puntero);
}

void ListaPais::AgregarEvaluables(pnodoConexion &pConexiones, string pPaisSalida, string pCiudadSalida){
    nodoConexion *auxConexiones = pConexiones;
//    cout<<pPaisSalida<<";"<<pCiudadSalida<<endl;
    do{
        if(evaluables==nullptr){
            evaluables= new nodoDijkstra(auxConexiones->codigoPaisDest, auxConexiones->codigoCiudadDest,auxConexiones->horas);
            evaluables->paisSalida = pPaisSalida; evaluables->ciudadSalida = pCiudadSalida;
            evaluables->siguiente = evaluables;
            evaluables->anterior = evaluables;
        }else{
            pnodoDijkstra nuevo = new nodoDijkstra(auxConexiones->codigoPaisDest, auxConexiones->codigoCiudadDest,auxConexiones->horas);
            nuevo->paisSalida = pPaisSalida; nuevo->ciudadSalida = pCiudadSalida;

            nuevo->anterior = evaluables->anterior;
//            cout<<"Aca no se cae"<<endl;
            nuevo->siguiente=evaluables->anterior->siguiente;
//            cout<<"Aca no se cae 2"<<endl;
            evaluables->anterior->siguiente=nuevo;
//            cout<<"Aca no se cae 4"<<endl;
            evaluables->anterior=nuevo;
        }
//        cout<<auxConexiones->codigoPaisDest<<";"<<auxConexiones->codigoCiudadDest<<";"<<auxConexiones->horas<<endl;
        auxConexiones = auxConexiones->siguiente;
    }while(auxConexiones!=pConexiones);
}

void ListaPais::ObtenerRuta(pnodoDijkstra &pNodoRuta, string pPais, string pCiudad, bool &encontrado){
    if(pNodoRuta == nullptr){
        return;
    }
    cout<<"Entro en obtener ruta"<<endl;
    pnodoDijkstra aux = pNodoRuta;
    do{
//        cout<<aux->CodPais<< "=="<< pPais <<"|"<< aux->codigoCiudad <<"==" <<pCiudad<<endl;
        if(aux->CodPais == pPais and aux->codigoCiudad == pCiudad){
            rutaNueva=aux->codigoCiudad+";"+to_string(aux->total)+"\n";
            aux = aux->predecesor;
            while(aux->predecesor != nullptr){
                rutaNueva=aux->codigoCiudad+";"+rutaNueva;
                aux = aux->predecesor;
            }
            rutaNueva=aux->codigoCiudad+";"+rutaNueva;
//            cout<<aux->codigoCiudad<<" "<<aux->total<<endl;
            encontrado = true;
            return;
        }

        ObtenerRuta(aux->otroCamino,pPais, pCiudad, encontrado);
        if(encontrado){
            return;
        }
        aux = aux->siguiente;
    }while(aux!=pNodoRuta);
}

void ListaPais::AgregarEvaluablesPrecio(pnodoConexion &pConexiones, string pPaisSalida, string pCiudadSalida){
    nodoConexion *auxConexiones = pConexiones;
//    cout<<pPaisSalida<<";"<<pCiudadSalida<<endl;
    do{
        if(evaluables==nullptr){
            evaluables= new nodoDijkstra(auxConexiones->codigoPaisDest, auxConexiones->codigoCiudadDest,auxConexiones->precio);
            evaluables->paisSalida = pPaisSalida; evaluables->ciudadSalida = pCiudadSalida;
            evaluables->siguiente = evaluables;
            evaluables->anterior = evaluables;
        }else{
            pnodoDijkstra nuevo = new nodoDijkstra(auxConexiones->codigoPaisDest, auxConexiones->codigoCiudadDest,auxConexiones->precio);
            nuevo->paisSalida = pPaisSalida; nuevo->ciudadSalida = pCiudadSalida;

            nuevo->anterior = evaluables->anterior;
//            cout<<"Aca no se cae"<<endl;
            nuevo->siguiente=evaluables->anterior->siguiente;
//            cout<<"Aca no se cae 2"<<endl;
            evaluables->anterior->siguiente=nuevo;
//            cout<<"Aca no se cae 4"<<endl;
            evaluables->anterior=nuevo;
        }
//        cout<<auxConexiones->codigoPaisDest<<";"<<auxConexiones->codigoCiudadDest<<";"<<auxConexiones->horas<<endl;
        auxConexiones = auxConexiones->siguiente;
    }while(auxConexiones!=pConexiones);
}

void ListaPais::EvaluarAdyacentesPrecio(string pPais, string pCiudad){
    AgregarEvaluablesPrecio(CiudadDijkstra->conexion, origen->CodPais, origen->codigoCiudad);
    pnodoDijkstra menorCosto = evaluables;
    string paisllegada="";
    string ciudadllegada = "";
    pnodoDijkstra aux;

    while(!VerificarVisitado(pCiudad)){
        menorCosto = evaluables;
//        cout<<"///////////////////////////////////////////////////"<<endl;
//        cout<<"____________________________________________"<<endl;
//        MostrarEvaluables();
//        cout<<"____________________________________________"<<endl;

        aux = evaluables;
        ObtenerCosto(primeroRutasNuevas,aux->paisSalida, aux->ciudadSalida);
//        cout<<"Se obtuvo el costo "<<costo<<endl;
        int newCosto=costo+aux->total;
//        cout<<newCosto<<endl;
        do{
//            cout<<"Va a obtener costo"<<endl;
            ObtenerCosto(primeroRutasNuevas,aux->paisSalida, aux->ciudadSalida);
//            cout<<"Se obtuvo el costo "<<costo<<endl;
//            cout<<"Min "<<aux->total<<endl;
            if(costo+aux->total<newCosto){
                newCosto = costo+aux->total;
                menorCosto = aux;
            }
            aux = aux->siguiente;
        }while(aux!=evaluables);

//        cout<<menorCosto->CodPais<<";"<<menorCosto->codigoCiudad<<endl;

        if(!VerificarVisitado(menorCosto->codigoCiudad)){
            InsertarNodoDijsktra(primeroRutasNuevas,menorCosto->paisSalida, menorCosto->ciudadSalida, menorCosto->CodPais,menorCosto->codigoCiudad,menorCosto->total);
            InsertarCiudadVisitada(menorCosto->CodPais,menorCosto->codigoCiudad);
//            cout<<menorCosto->CodPais<<";"<<menorCosto->codigoCiudad<<endl;
            ObtenerCiudad(menorCosto->CodPais, menorCosto->codigoCiudad);
//            cout<<"Ciudad a la cual se le extraeran las conexiones "<<CiudadDijkstra->codigoCiudad<<endl;
            paisllegada =  menorCosto->CodPais;
            ciudadllegada = menorCosto->codigoCiudad;
            AgregarEvaluablesPrecio(CiudadDijkstra->conexion,menorCosto->CodPais, menorCosto->codigoCiudad);
        }
        if(menorCosto==evaluables){
            evaluables = menorCosto->siguiente;
            menorCosto->anterior->siguiente=menorCosto->siguiente;
            menorCosto->siguiente->anterior = menorCosto->anterior;
            menorCosto->siguiente = nullptr;
            menorCosto->anterior = nullptr;
            delete menorCosto;
            menorCosto = nullptr;
        }else{
            menorCosto->anterior->siguiente=menorCosto->siguiente;
            menorCosto->siguiente->anterior = menorCosto->anterior;
            menorCosto->siguiente = nullptr;
            menorCosto->anterior = nullptr;
            delete menorCosto;
            menorCosto = nullptr;
        }

//        LimpiarEvaluables();

//        cout<<"///////////////////////////////////////////////////"<<endl;
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////
void ListaPais::insertarAtraccion(string pCodPais, string pCodCiudad, string pCodAtraccion, string pNombre, string pPrecio){
    nodoPais *aux = primero;
    do{
        if(aux->codigo == pCodPais){
            pnodoCiudad auxCiudad = aux->ciudad;
            do {
                if(auxCiudad->codigoCiudad == pCodCiudad){
                    pnodoAtraccion auxAtraccion = auxCiudad->atracciones;
                    if (!auxAtraccion)
                      {
                      auxCiudad->atracciones = new nodoAtraccion( pCodAtraccion, pNombre, pPrecio);
                      auxCiudad->atracciones->anterior=auxCiudad->atracciones;
                      auxCiudad->atracciones->siguiente=auxCiudad->atracciones;

                      ultimaConexionAgregada = auxCiudad->conexion;
                    }
                    else
                    {
                      pnodoAtraccion nuevo = new nodoAtraccion( pCodAtraccion, pNombre, pPrecio);
                      nuevo->anterior = auxCiudad->atracciones->anterior;
                      nuevo->siguiente=auxCiudad->atracciones->anterior->siguiente;
                      auxCiudad->atracciones->anterior->siguiente=nuevo;
                      auxCiudad->atracciones->anterior=nuevo;

//                      ultimaConexionAgregada = nuevo;
                    }
                    return;
                }
                auxCiudad = auxCiudad->siguiente;
            }
            //
            while (auxCiudad!=aux->ciudad);
            return ;
            //
         }
        aux = aux->siguiente;
      }
    while(aux!=primero);
}

bool ListaPais::validarAtraccion(string pCodPais, string pCodCiudad, string pCodAtraccion){
    pnodoPais aux=primero;
    if(aux == NULL){
        return false;
    }
    do{
        if(aux->codigo == pCodPais){
            pnodoCiudad auxCiudad = aux->ciudad;
            if(auxCiudad == NULL){
                return false;
            }else{
                do{
                    if(auxCiudad->codigoCiudad == pCodCiudad){
                        //
                        pnodoAtraccion auxAtracciones = auxCiudad->atracciones;
                        if(auxAtracciones == NULL){
                            return false;
                        }else{
                            do{
                                if(auxAtracciones->CodAtraccion == pCodAtraccion){
                                    return true;
                                }else{
                                    auxAtracciones = auxAtracciones->siguiente;
                                }
                            }
                            while(auxAtracciones!=auxCiudad->atracciones);
                            return false;
                        }
                        //
                    }else{
                        auxCiudad = auxCiudad->siguiente;
                    }
                }
                while(auxCiudad!=aux->ciudad);
                return false;
            }

        }
        aux = aux->siguiente;
      }
    while(aux!=primero);
    return false;
}


