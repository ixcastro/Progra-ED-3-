#ifndef SISTEMATRENES_H
#define SISTEMATRENES_H

#include <iostream>
#include <arboltrenesnew.h>
#include <arbolb.h>
#include <listareserva.h>
#include <listapaises.h>


#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class ServicioDeTrenes{
    public:
        ServicioDeTrenes(){}

        void separador(string oracion, int opcion);
        void lector(string nombreArchivo, int pos);
        void cargarArchivos();

        string AgregarPais(string pCodPais, string pNombre);
        string AgregarCiudad(string CodPais, string CodCiudad, string Nombre);
        string AgregarConexion(string CodPaisSalida, string CodCiudadSalida, string CodConexion, string CodPaisDest, string CodCiudadDest, string Tiempo, string pPrecio);
        string AgregarTipoTren(string CodTipoTren);
        string AgregarTren(string pCodTipoTren, string pCodTren, string pNombre, string pNumdeAsientos, string pPaisSalida, string pCiudadSalida);
        string AgregarRuta(string pCodTipoTren, string pCodTren, string pCodRuta, string pPaisSalida, string pCiudadSalida, string pPaisDest, string pCiudadDest, string pPrecio);
        string AgregarAdministrador(string CodAdministrador, string Nombre);
        string AgregarUsuario(string CodPais, string CodCiudad, string Pasaporte, string Nombre, string EstadoMigratorio);
        string AgregarAracciones(string CodPais, string CodCiudad, string codAtraccion, string nombre, string precio);

        string ValidarUsuario(string pPasaporte);
        string ValidarEM(string pPasaporte);
        string ValidaAdministrador(string pId);

        string ConsultarPaises();

        string ConsultarCiudades(string pCodPais);
        string mostrarCiudades(string pNombrePais);
        string mostrarAtracciones(string pPais, string pCiudad);
        void EncontrarPais(nodoPais *R, int pCodPais);
        void PreordenArbolCiudad(nodoCiudad *R);

        string ConsultarConexiones(string pCodPais);
        void EncontrarPaisParaConexion(nodoPais *R, int pCodPais, int pCodCiudad);
        void EncontrarCiudadParaConexion(nodoCiudad *R, int pCodCiudad);
        void PreordenArbolConexion(nodoConexion *R);

        string ConsultarTrenes(int pTipoTren);
        void EncotrarTipoTren(nodoTipoTren *R);
        void EncotrarTipoTren(nodoTipoTren *R,int codTipo);
        void PreordenArbolTren(nodoTren *R);
        void ConsultarUsuarios();

        string ConsultarNumAsientosTren(int pTipoTren, int pCodTren);
        void EncotrarTipoTrenParaTren(nodoTipoTren *R,int pTipoTren, int pCodTren);
        void EncontrarTren(nodoTren *R,int pCodTren);

        string ConsultarRutas(int pTipoTren, int pCodTren);
        void EncotrarTipoTrenParaRuta(nodoTipoTren *R,int pTipoTren, int pCodTren);
        void EncontrarTrenParaRuta(nodoTren *R,int pCodTren);
        void PreordenArbolRutas(NodoRuta *R);

        string ModificarTren(int pTipo, int pCodTren, string pNombre);
        string ModificarNumAsientos(int pTipo, int pCodTren, string pNumAsientos);
        string ModificarEstadoMigratorio(string pPasaporte, int pEstadoMigratorio);

        string ModificarPrecio(int pTipo, int pCodCiudad, int pCodRuta, int precio);
        string ConsultarPrecioConexion(string Pais, string ciudad, string conexion);
        string ConsultarPrecioRuta(int pTipoTren, int pCodTren, int pCodRuta);

        string ModificarPrecioConexion(string pCodPais, string pCodCiudad, string pCodConexion, int precio);
        string ModificarTiempoConexion(string pCodPais, string pCodCiudad, string pCodConexion, int tiempo);
        ///////////////////////////////////////////////////////////////////////////////////////////////////
        string ReporteConsultarPaises();
        string ReporteConsultarCiudades();
        string ReporteConsultarConexiones();
        string ReporteConsultarTrenes();
        string ReporteConsultarNumAsientosTren(int pTipoTren, int pCodTren);

        string reporteRutaMas();
        string reporteRutaMenos();
        string reporteUsuariosMas();
        string reporteUsuariosMenos();
        string reporteCantCompras();
        string reporteTrenMas();
        string reporteTrenMenos();
        string reporteCiudadMas();

        string reportePaisMas();

        string ReporteUltimoPaisInsertado();
        string ReporteUltimaCiudadInsertada();
        string ReporteUltimaConexionInsertada();
        string ReporteUltimoTrenInsertado();
        string ReporteUltimoTipoTrenInsertado();
        string ReporteConsultarPrecioConexion(string pCodPais, string pCodCiudad, string pCodConexion);

        string realizarReservacion(string pComprador, string pCodTipoTren, string pCodRuta, string pCodTren, string pPasajeros, string pNumAsientos);
        string facturar(string pCodigo);


        ///////////////////////////////////////////////////

        void Krukal();
        void Dijkstra( string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada, int opcion);

        string BuscarRuta(int pTipoTren, int pCodTren, string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada);
        bool BuscarRutaDijsktra(string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada);
        string NuevaRuta(string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada);
        string NuevaRutaMenorPrecio(string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada);
        string NuevaRutaMenorTiempo(string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada);


        friend class Server;
        friend class MyThread;
};


#endif // SISTEMATRENES_H
