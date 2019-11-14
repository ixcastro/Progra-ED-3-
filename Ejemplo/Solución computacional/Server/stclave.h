#ifndef STCLAVE_H
#define STCLAVE_H

#include <iostream>
#include <string.h>
using namespace std;

class StClave{
public:
    StClave (){
        valor = 0;
        registro = 0;
        nombreAdministrador = "";
        nombreUsuario = "";
        codPais = 0;
        codCiudad = 0;
        estadoMigratorio = 0;
    }

private:
    int valor;
    long registro;
    int codAdministrador;
    string nombreAdministrador;
    string nombreUsuario;
    int codPais;
    int codCiudad;
    int numPasaporte;
    int estadoMigratorio;


    friend class Pagina;
    friend class ArbolB;
};

#endif // STCLAVE_H

