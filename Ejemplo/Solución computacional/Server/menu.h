#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QThread>
#include <iostream>
#include "sistematrenes.h"

using namespace std;

class Menu : public QThread
{
public:
    explicit Menu(ServicioDeTrenes *trenes, QObject *parent = nullptr);
    void run();

    void Ingresar();
    void ingresoAdministrador();
    void menuAdministrador();

    void menuInsertar();
    void menuInsertarPais();
    void menuInsertarCiudad();
    void menuInsertarConexion();
    void menuInsertarTipoTren();
    void menuInsertarTren();
    void menuInsertarRuta();

    void menuModificar();
    void menuModificarPrecio();
    void menuModificarTiempo();
    void menuModificarAsientos();
    void menuModificarRuta();
    void menuModificarTren();
    void menuModificarEstadoMigratorio();

    void menuConsultarConexiones();
    void menuConsultarCiudadesPais();
    void menuConsultarRutaTren();
    void menuConsultarTren();
    void menuConsultarPrecio();

    void menuReportes();
    void menuReporteCiudades();
    void menuReporteConexiones();
    void menuReporteTrenes();
    void menuReportePrecioConexion();
    void menuReporteNumAsientos();

private:
    ServicioDeTrenes *aplicacion;

    friend class ServicioDeTrenes;
};

#endif // MENU_H

Menu::Menu(ServicioDeTrenes *trenes, QObject *parent) :
    QThread (parent)
{
    aplicacion = trenes;
}

void Menu::run()
{
    menuAdministrador();
}

void Menu::Ingresar()
{
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
        break;
    default:
        cout<<"El valor no esta en las opciones"<<endl;
        Ingresar();
        break;
    }
}

void Menu::ingresoAdministrador()
{
    string codigo = "";
    cout<<"+--------------------------------------------+"<<endl;
    cout<<"|                ADMINISTRADOR               |"<<endl;
    cout<<"+--------------------------------------------+"<<endl;
    cout<<"|   1- Ingrese su codigo: ";
    cin>>codigo;
    if(aplicacion->ValidaAdministrador(codigo) == "T"){
        menuAdministrador();
    }
    else {
        cout<<"+--------------------------------------------+"<<endl;
        cout<<"|      Codigo de administrador invalido      |"<<endl;
        return Ingresar();
    }
}

void Menu::menuAdministrador()
{
    string in = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"| 1.	Insertar                                |"<<endl;
    cout<<"| 2.	Modificar datos                         |"<<endl;
    cout<<"| 3.	Consultar Precio                        |"<<endl;
    cout<<"| 4.	Consultar conexiones de un pais         |"<<endl;
    cout<<"| 5.	Consultar ciudades de un pais           |"<<endl;
    cout<<"| 6.	Consultar Rutas de un tren              |"<<endl;
    cout<<"| 7.	Consultar trenes de un tipo de tren     |"<<endl;
    cout<<"| 8.	Registrar trenes                        |"<<endl;
    cout<<"| 9.	Generar reportes                        |"<<endl;
    cout<<"|10.	Salir                                   |"<<endl;
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<" Opcion:  ";
    cin>>in;
    cout<<"+------------------------------------------------+"<<endl;
    int key = 0;
    istringstream (in) >> key;
    switch (key) {
    case 1:
        menuInsertar();
        break;
    case 2:
        menuModificar();
        break;
    case 3:
        //menuConsultarPrecio();
        menuAdministrador();
        break;
    case 4:
        menuConsultarConexiones();
        menuAdministrador();
        break;
    case 5:
        menuConsultarCiudadesPais();
        menuAdministrador();
        break;
    case 6:
        menuConsultarRutaTren();
        menuAdministrador();
        break;
    case 7:
        menuConsultarTren();
        menuAdministrador();
        break;
    case 8:
        menuInsertarTren();
        menuAdministrador();
        break;
    case 9:
        menuReportes();
        break;
    case 10:
        Ingresar();
        break;
    default:
        cout<<"+--------------------------------------------+"<<endl;
        cout<<"|                Opcion invalida             |"<<endl;
        menuAdministrador();
        break;
    }
}

void Menu::menuInsertar()
{
    string in = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"| 1.	Insertar Pais                           |"<<endl;
    cout<<"| 2.	Insertar Ciudad                         |"<<endl;
    cout<<"| 3.	Insertar Conexion                       |"<<endl;
    cout<<"| 4.	Insertar un tipo de tren                |"<<endl;
    cout<<"| 5.	Insertar una ruta                       |"<<endl;
    cout<<"| 6.	Atras                                   |"<<endl;
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<" Opcion:  ";
    cin>>in;
    cout<<"+------------------------------------------------+"<<endl;
    int key = 0;
    istringstream (in) >> key;
    switch (key) {
    case 1:
        menuInsertarPais();
        menuInsertar();
        break;
    case 2:
        menuInsertarCiudad();
        menuInsertar();
        break;
    case 3:
        menuInsertarConexion();
        menuInsertar();
        break;
    case 4:
        menuInsertarTipoTren();
        menuInsertar();
        break;
    case 5:
        menuInsertarRuta();
        menuInsertar();
        break;
    case 6:
        menuAdministrador();
        break;
    default:
        cout<<"+--------------------------------------------+"<<endl;
        cout<<"|                Opcion invalida             |"<<endl;
        menuInsertar();
        break;
    }
}

void Menu::menuInsertarPais(){
    string codigo = "";
    string nombre = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del pais: ";
    cin>>codigo;
    cout<<"|  Ingrese el nombre del pais: ";
    cin>>nombre;
    cout<<endl;
    cout<<nombre<<endl;
    cout<<aplicacion->AgregarPais(codigo, nombre)<<endl;
}
void Menu::menuInsertarCiudad(){
    string codigoPais = "";
    string codigoCiudad = "";
    string nombre = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del pais: ";
    cin>>codigoPais;
    cout<<endl;
    cout<<"|  Ingrese el codigo de la ciudad: ";
    cin>>codigoCiudad;
    cout<<endl;
    cout<<"|  Ingrese el nombre de la ciudad: ";
    cin>>nombre;
    cout<<endl;
    cout<<aplicacion->AgregarCiudad(codigoPais, codigoCiudad, nombre)<<endl;
}
void Menu::menuInsertarConexion(){
    string codigoPaisSalida = "";
    string codigoCiudadSalida = "";
    string codConexion = "";
    string codPaisDest = "";
    string codCiudadDest = "";
    string horas = "";
    string precio = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del pais de salida: ";
    cin>>codigoPaisSalida;
    cout<<endl;
    cout<<"|  Ingrese el codigo de la ciudad de salida: ";
    cin>>codigoCiudadSalida;
    cout<<endl;
    cout<<"|  Ingrese el codigo de la conexion: ";
    cin>>codConexion;
    cout<<endl;
    cout<<"|  Ingrese el codigo del pais de destino: ";
    cin>>codPaisDest;
    cout<<endl;
    cout<<"|  Ingrese el codigo de la ciudad de destino: ";
    cin>>codCiudadDest;
    cout<<endl;
    cout<<"|  Ingrese las horas que dura el viaje: ";
    cin>>horas;
    cout<<"|  Ingrese el precio: ";
    cin>>precio;
    cout<<endl;
    cout<<aplicacion->AgregarConexion(codigoPaisSalida,codigoCiudadSalida, codConexion, codPaisDest,codCiudadDest,horas, precio)<<endl;
}
void Menu::menuInsertarTipoTren(){
    string codigo = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del tipo de tren (ej: 00): ";
    cin>>codigo;
    cout<<endl;
    cout<<aplicacion->AgregarTipoTren(codigo)<<endl;
}
void Menu::menuInsertarTren(){
    string codigoTipoTren = "";
    string codigoTren = "";
    string nombre = "";
    string numAsientos = "";
    string paisSalida = "";
    string ciudadSalida = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del tipo de tren: ";
    cin>>codigoTipoTren;
    cout<<"|  Ingrese el codigo del tren: ";
    cin>>codigoTren;
    cout<<"|  Ingrese el nombre del tren: ";
    cin>>nombre;
    cout<<"|  Ingrese la cantidad de asientos del tren: ";
    cin>>numAsientos;
    cout<<"|  Ingrese el codigo del pais de salida: ";
    cin>>paisSalida;
    cout<<"|  Ingrese el codigo de la ciudad de salida: ";
    cin>>ciudadSalida;
    cout<<endl;
    cout<<aplicacion->AgregarTren(codigoTipoTren, codigoTren, nombre, numAsientos, paisSalida, ciudadSalida);
}
void Menu::menuInsertarRuta(){
    string codTipoTren = "";
    string codTren = "";
    string codRuta = "";
    string codigoPaisSalida = "";
    string codigoCiudadSalida = "";
    string codPaisDest = "";
    string codCiudadDest = "";
    string precio = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del tipo de tren: ";
    cin>>codTipoTren;
    cout<<"|  Ingrese el codigo del tren: ";
    cin>>codTren;
    cout<<"|  Ingrese el codigo de la ruta: ";
    cin>>codRuta;
    cout<<"|  Ingrese el codigo del pais de salida: ";
    cin>>codigoPaisSalida;
    cout<<"|  Ingrese el codigo de la ciudad de salida: ";
    cin>>codigoCiudadSalida;
    cout<<"|  Ingrese el codigo del pais de destino: ";
    cin>>codPaisDest;
    cout<<"|  Ingrese el codigo de la ciudad de destino: ";
    cin>>codCiudadDest;
    cout<<"|  Ingrese el precio: ";
    cin>>precio;
    cout<<endl;
    cout<<aplicacion->AgregarRuta(codTipoTren, codTren, codRuta, codigoPaisSalida, codigoCiudadSalida, codPaisDest, codCiudadDest, precio)<<endl;
}

void Menu::menuModificar(){
    string in = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"| 1.	Modificar precio de una ruta            |"<<endl;
    cout<<"| 2.	Modificar el tiempo de una conexion     |"<<endl;
    cout<<"| 3.	Modificar numero de asientos de un tren |"<<endl;
    cout<<"| 4.	Modificar una ruta                      |"<<endl;
    cout<<"| 5.	Modificar un tren                       |"<<endl;
    cout<<"| 6.	Modificar un estado migratorio          |"<<endl;
    cout<<"| 7.	Atras                                   |"<<endl;
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<" Opcion:  ";
    cin>>in;
    cout<<"+------------------------------------------------+"<<endl;
    int key = 0;
    istringstream (in) >> key;
    switch (key) {
    case 1:
        menuModificarPrecio();
        menuModificar();
        break;
    case 2:
        menuModificarTiempo();
        menuModificar();
        break;
    case 3:
        menuModificarAsientos();
        menuModificar();
        break;
    case 4:
        menuModificarPrecio();
        menuModificar();
        break;
    case 5:
        menuModificarTren();
        menuModificar();
        break;
    case 6:
        menuModificarEstadoMigratorio();
        menuModificar();
        break;
    case 7:
        menuAdministrador();
        break;
    default:
        cout<<"+--------------------------------------------+"<<endl;
        cout<<"|                Opcion invalida             |"<<endl;
        menuModificar();
        break;
    }
}

void Menu::menuModificarPrecio(){
    string codTipoTren = "";
    string codTren = "";
    string codRuta = "";
    string precio = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del tipo de tren: ";
    cin>>codTipoTren;
    cout<<"|  Ingrese el codigo del tren: ";
    cin>>codTren;
    cout<<"|  Ingrese el codigo de la ruta: ";
    cin>>codRuta;
    cout<<"|  Ingrese el nuevo precio: ";
    cin>>precio;
    cout<<endl;
    cout<<aplicacion->ModificarPrecio(stoi(codTipoTren), stoi(codTren), stoi(codRuta), stoi(precio))<<endl;
}
void Menu::menuModificarTiempo(){
    string codigoPais = "";
    string codigoCiudad = "";
    string codConexion = "";
    string horas = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del pais: ";
    cin>>codigoPais;
    cout<<"|  Ingrese el codigo de la ciudad: ";
    cin>>codigoCiudad;
    cout<<"|  Ingrese el codigo de la conexion: ";
    cin>>codConexion;
    cout<<"|  Ingrese las horas que dura el viaje ahora: ";
    cin>>horas;
    cout<<endl;
//    cout<<aplicacion->ModificarTiempoConexion(stoi(codigoPais),stoi(codigoCiudad),stoi(codConexion),stoi(horas))<<endl;
}
void Menu::menuModificarAsientos(){
    string codigoTipoTren = "";
    string codigoTren = "";
    string numAsientos = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del tipo de tren: ";
    cin>>codigoTipoTren;
    cout<<"|  Ingrese el codigo del tren: ";
    cin>>codigoTren;
    cout<<"|  Ingrese la nueva cantidad de asientos del tren: ";
    cin>>numAsientos;
    cout<<endl;
    cout<<aplicacion->ModificarNumAsientos(stoi(codigoTipoTren),stoi(codigoTren),numAsientos)<<endl;
}

void Menu::menuModificarTren(){
    string codigoTipoTren = "";
    string codigoTren = "";
    string nombre = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del tipo de tren: ";
    cin>>codigoTipoTren;
    cout<<"|  Ingrese el codigo del tren: ";
    cin>>codigoTren;
    cout<<"|  Ingrese el nuevo nombre del tren: ";
    cin>>nombre;
    cout<<endl;
    cout<<aplicacion->ModificarTren(stoi(codigoTipoTren),stoi(codigoTren),nombre)<<endl;
}
void Menu::menuModificarEstadoMigratorio(){
    string pasaporte = "";
    string estado = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el pasaporte del usuario: ";
    cin>>pasaporte;
    cout<<"|  0- Estado disponible ";
    cout<<"|  1- Estado en problemas"<<endl;
    cout<<"|  Ingrese el nuevo estado del usuario: ";
    cin>>estado;
    cout<<endl;
    if(estado != "0" && estado != "1"){
        cout<<"Estado incorrecto!"<<endl;
        menuModificarEstadoMigratorio();
    }else{
//        cout<<aplicacion->ModificarEstadoMigratorio(stoi(pasaporte),estado)<<endl;
    }
}

void Menu::menuConsultarConexiones(){
    string pais = "";
    string ciudad = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del pais: ";
    cin>>pais;
    cout<<"|  Ingrese el codigo de la ciudad: ";
    cin>>ciudad;
    cout<<endl;
//    cout<<aplicacion->ConsultarConexiones(stoi(pais),stoi(ciudad))<<endl;
}

void Menu::menuConsultarCiudadesPais(){
    string codigo = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del pais: ";
    cin>>codigo;
    cout<<endl;
    //cout<<aplicacion->ConsultarCiudades(stoi(codigo))<<endl;
}

void Menu::menuConsultarRutaTren(){
    string codigoTipo = "";
    string codigoTren = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del tipo de tren (ej: 01): ";
    cin>>codigoTipo;
    cout<<"|  Ingrese el codigo del tren : ";
    cin>>codigoTren;
    cout<<endl;
    cout<<aplicacion->ConsultarRutas(stoi(codigoTipo),stoi(codigoTren))<<endl;
}

void Menu::menuConsultarTren(){
    string codigo = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del tipo de tren (ej: 01): ";
    cin>>codigo;
    cout<<endl;
//    cout<<aplicacion->ConsultarTrenes(stoi(codigo))<<endl;
}

void Menu::menuConsultarPrecio(){
    string codTipoTren = "";
    string codTren = "";
    string codRuta = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del tipo de tren: ";
    cin>>codTipoTren;
    cout<<"|  Ingrese el codigo del tren: ";
    cin>>codTren;
    cout<<"|  Ingrese el codigo de la ruta: ";
    cin>>codRuta;
    cout<<endl;

    //cout<<aplicacion->ConsultarPrecioRuta(stoi(codTipoTren),stoi(codTren),stoi(codRuta))<<endl;
}



void Menu::menuReportes(){
    string in = "";
    cout<<"+--------------------------------------------------+"<<endl;
    cout<<"| 1.	Consultar paises                           |"<<endl;
    cout<<"| 2.	Consultar ciudades                         |"<<endl;
    cout<<"| 3.	Consultar conexiones                       |"<<endl;
    cout<<"| 4.	Consultar trenes                           |"<<endl;
    cout<<"| 5.	Consultar precios de una conexion          |"<<endl;
    cout<<"| 6.	Consultar numero de asientos de un tren    |"<<endl;
    cout<<"| 7.	Consultar ultimo pais insertado al sistema |"<<endl;
    cout<<"| 8.	Consultar ultimas ciudad insertada         |"<<endl;
    cout<<"| 9.	Consultar ultima conexion insertada        |"<<endl;
    cout<<"|10.	Consultar ultimo tren insertado            |"<<endl;
    cout<<"|11.	Consultar ultimo tipo de tren insertado    |"<<endl;
    cout<<"|12.	Consultar ruta mas utilizada               |"<<endl;
    cout<<"|13.	Consultar nunca utilizada                  |"<<endl;
    cout<<"|14.	Consultar pais mas visitado                |"<<endl;
    cout<<"|15. Consultar ciudad mas visitada              |"<<endl;
    cout<<"|16.	Consultar usuario que mas compro           |"<<endl;
    cout<<"|17.	Consultar usuario que menos compro         |"<<endl;
    cout<<"|18.	Consultar cantidad de compras por usuario  |"<<endl;
    cout<<"|19.	Consultar tren mas utilizado               |"<<endl;
    cout<<"|20.	Consultar tren menos utilizado             |"<<endl;

    cout<<"|21.	Atras                                      |"<<endl;
    cout<<"+--------------------------------------------------+"<<endl;
    cout<<" Opcion:  ";
    cin>>in;
    cout<<"+---------------------------------------------------+"<<endl;
    int key = 0;
    istringstream (in) >> key;
    switch (key) {
    case 1:
        aplicacion->ReporteConsultarPaises();
        cout<<"Se ha generado el reporte"<<endl;
        menuReportes();
        break;
    case 2:
        menuReporteCiudades();
        menuReportes();
        break;
    case 3:
        menuReporteConexiones();
        menuReportes();
        break;
    case 4:
        menuReporteTrenes();
        menuReportes();
        break;
    case 5:
        menuReportePrecioConexion();
        menuReportes();
        break;
    case 6:
        menuReporteNumAsientos();
        menuReportes();
        break;
    case 7:
        aplicacion->ReporteUltimoPaisInsertado();
        cout<<"El reporte ha sido generado!"<<endl;
        menuReportes();
        break;
    case 8:
        aplicacion->ReporteUltimaCiudadInsertada();
        cout<<"El reporte ha sido generado!"<<endl;
        menuReportes();
        break;
    case 9:
        aplicacion->ReporteUltimaConexionInsertada();
        cout<<"El reporte ha sido generado!"<<endl;
        menuReportes();
        break;
    case 10:
        aplicacion->ReporteUltimoTrenInsertado();
        cout<<"El reporte ha sido generado!"<<endl;
        menuReportes();
        break;
    case 11:
        aplicacion->ReporteUltimoTipoTrenInsertado();
        cout<<"El reporte ha sido generado!"<<endl;
        menuReportes();
        break;
    case 12:
        cout<<aplicacion->reporteRutaMas()<<endl;
        menuReportes();
        break;
    case 13:
        cout<<aplicacion->reporteRutaMenos()<<endl;
        menuReportes();
        break;
    case 14:
        // Pais mas visitado
        menuReportes();
        break;
    case 15:
        // ciudad mas visitada
        menuReportes();
        break;
    case 16:
        cout<<aplicacion->reporteUsuariosMas()<<endl;
        menuReportes();
        break;
    case 17:
        cout<<aplicacion->reporteUsuariosMenos()<<endl;
        menuReportes();
        break;
    case 18:
        cout<<aplicacion->reporteCantCompras()<<endl;
        menuReportes();
        break;
    case 19:
        cout<<aplicacion->reporteTrenMas()<<endl;
        menuReportes();
        break;
    case 20:
        cout<<aplicacion->reporteTrenMenos()<<endl;
        menuReportes();
        break;
    case 21:
        //atrass
        menuAdministrador();
        break;
    default:
        cout<<"+--------------------------------------------+"<<endl;
        cout<<"|                Opcion invalida             |"<<endl;
        menuReportes();
        break;
    }
}

void Menu::menuReporteCiudades()
{
    string codigo = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del pais: ";
    cin>>codigo;
    cout<<endl;
//    aplicacion->ReporteConsultarCiudades(stoi(codigo));
    cout<<"El reporte se ha generado!"<<endl;

}

void Menu::menuReporteConexiones()
{
    string pais = "";
    string ciudad = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del pais: ";
    cin>>pais;
    cout<<"|  Ingrese el codigo de la ciudad: ";
    cin>>ciudad;
    cout<<endl;
//    aplicacion->ReporteConsultarConexiones(stoi(pais),stoi(ciudad));
    cout<<"El reporte se ha generado!"<<endl;
}

void Menu::menuReporteTrenes(){
    string codigoTipoTren = "";
    cout<<"+--------------------------------------------+"<<endl;
    cout<<"|1- Ingrese el codigo del tipo de tren: ";
    cin>>codigoTipoTren;
    cout<<endl;
//    aplicacion->ReporteConsultarTrenes(stoi(codigoTipoTren));
    cout<<"El reporte se ha generado!"<<endl;
}

void Menu::menuReportePrecioConexion()
{
    string pais = "";
    string ciudad = "";
    string conexion = "";
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  Ingrese el codigo del pais: ";
    cin>>pais;
    cout<<"|  Ingrese el codigo de la ciudad: ";
    cin>>ciudad;
    cout<<"|  Ingrese el codigo de la conexion: ";
    cin>>conexion;
    cout<<endl;
//    aplicacion->ReporteConsultarPrecioConexion(stoi(pais),stoi(ciudad),stoi(conexion));
    cout<<"El reporte se ha generado!"<<endl;
}

void Menu::menuReporteNumAsientos()
{
    string codigoTipoTren = "";
    string codigoTren = "";
    cout<<"+--------------------------------------------+"<<endl;
    cout<<"|1- Ingrese el codigo del tipo de tren: ";
    cin>>codigoTipoTren;
    cout<<"|1- Ingrese el codigo del tren: ";
    cin>>codigoTren;
    cout<<endl;
    aplicacion->ReporteConsultarNumAsientosTren(stoi(codigoTipoTren),stoi(codigoTren));
    cout<<"El reporte se ha generado!"<<endl;
}
