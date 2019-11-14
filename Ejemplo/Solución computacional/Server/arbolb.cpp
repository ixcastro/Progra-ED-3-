#include "arbolb.h"

static int matriz [100000000];
static int posicion = 0;
/*
 *   Constructor de objetos de clase ArbolB
 */
ArbolB::ArbolB(int nClv) : nClaves (nClv){           // cantidad maxima  de elementos en pagina, se "hereda" el número de claves para poder ser usado en todo el código
   lista = new StClave [nClaves + 1];
   listaPunt = new pPagina [nClaves + 2];
   nodosMinimos = nClaves / 2;
   raiz = nullptr;
}

/*
 *  Permite eliminar un nodo de un árbol
 */
void ArbolB::borrarNodo(pPagina nodo){
   int i;
   if (!nodo){
       return;
   }
   for (i = 0; i <= nodo->clavesUsadas; i++){
       borrarNodo (nodo->puntero[i]);
   }
   delete nodo;
}

/*
 *  Permite llamar a la función que muestra los datos de árbol de administradores
 */
void ArbolB::mostrarAdministrador(){
    cout << "\n Administradores:\n" << endl;
    verAdministrador (raiz);
}

/*
 *  Función recursiva que permite recorrer el árbol para mostrar sus valores.
 *  Muestra primero el subárbol izquierdo y después el subárbol derecho.
 *  El o los valores entre corchetes [ ] representan el nodo padre de la página.
 */
void ArbolB::verAdministrador(pPagina nodo){
    int i;

    if (!nodo){
       return;                                        // Cuando el nodo está vacío
    }
    for (i = 0; i < nodo->clavesUsadas - 1; i++) {
        cout << " Codigo de administrador: " << nodo->clave[i].valor << "    Nombre: " << nodo->clave[i].nombreAdministrador << endl;
    }
    if (nodo->clavesUsadas){
        cout << " Codigo de administrador: " << nodo->clave[i].valor << "    Nombre: " << nodo->clave[i].nombreAdministrador << endl;// " [";
    }
    for (i = 0; i <= nodo->clavesUsadas; i++) {
       verAdministrador (nodo->puntero[i]);
    }
}

/*
 *  Permite llamar a la función que muestra los datos de árbol de usuarios
 */
void ArbolB::mostrarUsuario(){
    cout << "\n Usuarios:\n" << endl;
    verUsuario (raiz);
}

/*
 *  Función recursiva que permite recorrer el árbol para mostrar sus valores.
 *  Muestra primero el subárbol izquierdo y después el subárbol derecho.
 *  El o los valores entre corchetes [ ] representan el nodo padre de la página.
 */
void ArbolB::verUsuario(pPagina nodo){
    int i;

    if (!nodo){
       return;                                        // Cuando el nodo está vacío
    }
    for (i = 0; i < nodo->clavesUsadas - 1; i++) {
        cout << " Numero de pasaporte: " << nodo->clave[i].valor << "    Nombre: " << nodo->clave[i].nombreUsuario << "   Pais: " << nodo->clave[i].codPais << "    Ciudad:" << nodo->clave[i].codCiudad << "    Estado Migratorio: " << nodo->clave[i].estadoMigratorio << endl;
    }
    if (nodo->clavesUsadas){
        cout << " Numero de pasaporte: " << nodo->clave[i].valor << "    Nombre: " << nodo->clave[i].nombreUsuario << "   Pais: " << nodo->clave[i].codPais << "    Ciudad:" << nodo->clave[i].codCiudad << "    Estado Migratorio: " << nodo->clave[i].estadoMigratorio << endl;
    }
    for (i = 0; i <= nodo->clavesUsadas; i++) {
       verUsuario (nodo->puntero[i]);
    }
}

/*
 *  Permite buscar un valor dentro del árbol.
 *  Si el valor se encuentra se retorna su valor de registro.
 */
string ArbolB::buscar(string claveS) {
    string str (claveS);
    int clave = stoi (claveS);
    pPagina nodo = raiz;
    int i;

    while (nodo){
        i = 0;
        while(i < nodo->clavesUsadas && (nodo->clave[i].valor < clave)){
            i++;
        }
        if (nodo->clave[i].valor == clave){
            return "T";
        }
        else {
            nodo = nodo->puntero[i];
        }
    }
    return "F";                       // si no encuentra el valor retorna -1
}

/*
 *    Permite validar si el usuario indicado posee problemas
 *                    migratorios o no.
 */
string ArbolB::validarEstadoMigratorio (string codUsuario){
    string str (codUsuario);
    int clave = stoi (codUsuario);
    pPagina nodo = raiz;
    int i;
    while (nodo){
        i = 0;
        while(i < nodo->clavesUsadas && (nodo->clave[i].valor < clave)){
            i++;
        }
        if (nodo->clave[i].valor == clave){
            if (nodo->clave[i].estadoMigratorio == 0){          // si NO tiene problemas migratorios
                return "T";
            }
            else{
                return "F";
            }
        }
        else {
            nodo = nodo->puntero[i];
        }
    }
    return "F";                       // si no encuentra el valor retorna -1
}

/*
 *    Permite validar si el usuario indicado posee problemas
 *                    migratorios o no.
 */
string ArbolB::modificarEstadoMigratorio (string pPasaporte, int nuevoEM){
    string str (pPasaporte);
    int clave = stoi (pPasaporte);
    pPagina nodo = raiz;
    int i;
    while (nodo){
        i = 0;
        while(i < nodo->clavesUsadas && (nodo->clave[i].valor < clave)){
            i++;
        }
        if (nodo->clave[i].valor == clave){
            nodo->clave[i].estadoMigratorio =  nuevoEM;         // si NO tiene problemas migratorios
            return "Modificado";
        }
        else {
            nodo = nodo->puntero[i];
        }
    }
    return "El usuario no se encuentra registrado";                       // si no encuentra el valor retorna -1
}

/*
 *   Analiza si el valor que se quiere insertar ya fue insertado preeviamente,
 *   si no fue insertado llama a la función que lo insertará.
 */
bool ArbolB::insertar (StClave clave){
   pPagina nodo, padre;
   int i;

   // Comprueba que la clave no haya sido preeviamente registrada.
   padre = nodo = raiz;
   while(nodo) {
      padre = nodo;
      i = 0;
      while (i < nodo->clavesUsadas && (nodo->clave[i].valor < clave.valor)){
          i++;
      }
      if (nodo->clave[i].valor == clave.valor && i < nodo->clavesUsadas){
          return false;		// si retorna false es porque ya la clave estaba en el arbol
      }
      else{
          nodo = nodo->puntero[i];
      }
   }
   nodo = padre;
   inserta (clave, nodo, nullptr, nullptr);
   // se agrega el valor a una matriz que contiene todos los elementos insertados
   matriz[posicion] = clave.valor;
   posicion++;
   return true;         // Si retorna true es porque fue insertado con éxito
}

/*
 *   Permite agregar un nuevo valor al árbol.
 *   Realiza la división del nodo en caso de ser necesario.
 */
void ArbolB::inserta (StClave clave, pPagina nodo, pPagina hijo1, pPagina hijo2){
   pPagina padre, nuevo;
   int i, j;
   bool salir = false;

   // Insertar nueva clave en nodo:
   do {
      if (!nodo){                       // Si el árbol está vacío
         nodo = new Pagina (nClaves);
         nodo->clavesUsadas = 0;
         nodo->padre = nullptr;
         raiz = nodo;
      }
      padre = nodo->padre;
      if (nodo->clavesUsadas == nClaves){                                                       //Analiza si hay overflow
         nuevo = new Pagina(nClaves);
         i = 0;
         while (nodo->clave[i].valor < clave.valor && i < nClaves) {
            // Separa los valores en dos lista ordenadas
            lista[i] = nodo->clave[i];
            listaPunt[i] = nodo->puntero[i];
            i++;
         }
         lista[i] = clave;
         listaPunt[i] = hijo1;
         listaPunt[i + 1] = hijo2;
         while(i < nClaves) {
            lista[i + 1] = nodo->clave[i];
            listaPunt[i + 2] = nodo->puntero[i+1];
            i++;
         }
         // Divide los nodos
         // Asigna nodo izquierdo
         nodo->clavesUsadas = nClaves / 2;
         for (j = 0; j < nodo->clavesUsadas; j++) {
            nodo->clave[j] = lista[j];
            nodo->puntero[j] = listaPunt[j];
         }
         nodo->puntero[nodo->clavesUsadas] = listaPunt[nodo->clavesUsadas];
         // Asigna nodo derecho:
         nuevo->clavesUsadas = nClaves - nodo->clavesUsadas;
         for (j = 0; j < nuevo->clavesUsadas; j++) {
            nuevo->clave[j] = lista[j+(nClaves / 2) + 1];
            nuevo->puntero[j] = listaPunt[j+(nClaves / 2) + 1];
         }
         nuevo->puntero[nuevo->clavesUsadas] = listaPunt[nClaves + 1];
         for (j = 0; j <= nodo->clavesUsadas; j++){
            if(nodo->puntero[j]) (nodo->puntero[j])->padre = nodo;
         }
         for (j = 0; j <= nuevo->clavesUsadas; j++){
            if (nuevo->puntero[j]){
                (nuevo->puntero[j])->padre = nuevo;
            }
         }
         clave = lista [nClaves/2];
         hijo1 = nodo;
         hijo2 = nuevo;
         nodo = padre;
      }
      else{
         // No hay que hacer ninguna división o reacomodo
         i = 0;
         if (nodo->clavesUsadas > 0) {
            while(nodo->clave[i].valor < clave.valor && i < nodo->clavesUsadas){
                i++;
            }
            for (j = nodo->clavesUsadas; j > i; j--){
               nodo->clave[j] = nodo->clave[j-1];
            }
            for (j = nodo->clavesUsadas+1; j > i; j--){
               nodo->puntero[j] = nodo->puntero[j-1];
            }
         }
         nodo->clavesUsadas++;
         nodo->clave[i] = clave;
         nodo->puntero[i] = hijo1;
         nodo->puntero[i+1] = hijo2;
         if(hijo1) hijo1->padre = nodo;
         if(hijo2) hijo2->padre = nodo;
         salir = true;
      }
   } while(!salir);
}

/*
 *  Permite leer los datos del archivo de usuarios y
 *  asignarlos a su respectiva variable para posteriormente
 *  insertarlos al árbol correspondiente.
 */
void ::ArbolB::leerArchivoUsuario(){
    ifstream file;
    string codPaisS;
    string codCiudadS;
    string numPasaporteS;
    string nombre;
    string estadoMigratorioS;
    int codPais;
    int codCiudad;
    int numPasaporte;
    int estadoMigratorio;
    int registro = 0;
    file.open ("Usuarios.txt", ios::out | ios::in);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream stream (line.c_str());
            string valor;
            int i = 1;
            while(getline(stream,valor,';')) {
                if (i == 1){
                    codPaisS = valor;
                    i ++;
                }
                else{
                    if (i == 2){
                        codCiudadS = valor;
                        i ++;
                    }
                    else{
                        if (i == 3){
                            numPasaporteS = valor;
                            i ++;
                        }
                        else{
                            if (i == 4){
                                nombre = valor;
                                i ++;
                            }
                            else{
                                if (i == 5){
                                    estadoMigratorioS = valor;
                                    i ++;
                                }
                            }
                        }
                    }
                }
            }
            registro++;
            StClave nuevoUsuario;
            string str (numPasaporteS);     // conversión de string a int
            numPasaporte = stoi (str);
            string str2 (codPaisS);
            codPais = stoi (str2);
            string str3 (codCiudadS);
            codCiudad = stoi (str3);
            string str4 (estadoMigratorioS);
            estadoMigratorio = stoi (str4);
            nuevoUsuario.valor = numPasaporte;  // valor con el que se va a ordenar
            nuevoUsuario.codPais = codPais;
            nuevoUsuario.codCiudad = codCiudad;
            nuevoUsuario.nombreUsuario = nombre;
            nuevoUsuario.estadoMigratorio = estadoMigratorio;
            nuevoUsuario.registro =  registro;
            insertar (nuevoUsuario);
         }
         file.close();
    }
    else{
        cout << "\n No se pudo abrir el archivo por favor intente de nuevo." << endl;
        return;
    }
}

/*
 *  Permite leer los datos del archivo de administradores y
 *  asignarlos a su respectiva variable para posteriormente
 *  insertarlos al árbol correspondiente.
 */
void ::ArbolB::leerArchivoAdministrador(){
    ifstream file;
    string codAdministradorS;
    int codAdministrador;
    string nombre;
    int registro = 0;
    file.open ("Administradores.txt", ios::out | ios::in);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream stream (line.c_str());
            string valor;
            int i = 1;
            while(getline(stream, valor,';')) {
                if (i == 1){
                    codAdministradorS = valor;
                    i ++;
                }
                else{
                    if (i == 2){
                        nombre = valor;
                        i ++;
                    }
                }
            }
            registro++;
            string str (codAdministradorS);
            codAdministrador = stoi (str);
            StClave nuevoAdministrador;
            nuevoAdministrador.valor = codAdministrador;
            nuevoAdministrador.registro = registro;
            nuevoAdministrador.nombreAdministrador = nombre;
            insertar (nuevoAdministrador);
         }
         file.close();
    }
    else{
        cout << "\n No se pudo abrir el archivo por favor intente de nuevo." << endl;
        return;
    }
}
