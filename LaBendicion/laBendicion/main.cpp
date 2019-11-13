#include "ventana.h"
#include <QApplication>
#include <iostream>
#include "sistematrenes.h"
#include "server.h"
#include "arbolb.h"
#include "arbolb.h"
#include "menu.h"

using namespace std;

static ServicioDeTrenes *trenes;
static Server *servidor;
static ArbolB *administradores;

void Ingresar();
void ingresoAdministrador();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ventana w;
    w.show();

    trenes = new ServicioDeTrenes();
    trenes->cargarArchivos();

    servidor = new Server(trenes);
    administradores = new ArbolB(4);
    administradores->leerArchivoAdministrador();
    administradores->mostrarAdministrador();
//    Ingresar();

    return a.exec();
}

void Ingresar(){
    string opcion;
    cout<<"+--------------------------------------------+"<<endl;
    cout<<"|             SERVICIO DE TRENES             |"<<endl;
    cout<<"+--------------------------------------------+"<<endl;
    cout<<"|   1- Ingresar como administrador           |"<<endl;
    cout<<"|   0- Salir                                 |"<<endl;
    cout<<"    R/: ";
    cin>>opcion;
    int key = 0;
    istringstream ( opcion ) >> key;
    switch (key) {
    case 1:
        ingresoAdministrador();
        break;
    case 0:
        cout<<"+--------------------------------------------+"<<endl;
        cout<<"|                HASTA LUEGO :)              |"<<endl;
        cout<<"+--------------------------------------------+"<<endl;
        exit(0);
    default:
        cout<<"El valor no esta en las opciones"<<endl;
        Ingresar();
        break;
    }
}

void ingresoAdministrador(){
    string codigo = "";

    cout<<"+--------------------------------------------+"<<endl;
    cout<<"|                ADMINISTRADOR               |"<<endl;
    cout<<"+--------------------------------------------+"<<endl;
    cout<<"|   1- Ingrese su codigo: ";
    cin>>codigo;
    if(trenes->ValidaAdministrador(codigo) == "T"){
        servidor->StartServer();
        Menu *menu = new Menu(trenes);
        menu->start();
    }
    else {
        cout<<"+--------------------------------------------+"<<endl;
        cout<<"|      Codigo de administrador invalido      |"<<endl;
        return Ingresar();
    }
}

