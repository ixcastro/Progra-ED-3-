#ifndef SISTEMATRENES_H
#define SISTEMATRENES_H

#include <iostream>
#include <arbolpaises.h>
#include <arboltrenesnew.h>
//#include <arbolbusuarios.h>
//#include <arbolbadministradores.h>
#include <listareserva.h>

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


        string ValidarUsuario(string pPasaporte);
        string ValidaAdministrador(string pId);

        string ConsultarPaises();
        void PreordenArbolPais(nodoPais *R);

        string ConsultarCiudades(int pCodPais);
        void EncontrarPais(nodoPais *R, int pCodPais);
        void PreordenArbolCiudad(nodoCiudad *R);

        string ConsultarConexiones(int pCodPais, int pCodCiudad);
        void EncontrarPaisParaConexion(nodoPais *R, int pCodPais, int pCodCiudad);
        void EncontrarCiudadParaConexion(nodoCiudad *R, int pCodCiudad);
        void PreordenArbolConexion(nodoConexion *R);

        string ConsultarTrenes(int pTipoTren);
        void EncotrarTipoTren(nodoTipoTren *R,int pTipoTren);
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
        string ModificarEstadoMigratorio(int pPasaporte, string pEstadoMigratorio);

        string ModificarPrecio(int pTipo, int pCodCiudad, int pCodRuta, int precio);
        string ConsultarPrecioConexion(int Pais, int ciudad, int conexion);
        string ConsultarPrecioRuta(int pTipoTren, int pCodTren, int pCodRuta);

        string ModificarPrecioConexion(int pCodPais, int pCodCiudad, int pCodConexion, int precio);
        string ModificarTiempoConexion(int pCodPais, int pCodCiudad, int pCodConexion, int tiempo);
        ///////////////////////////////////////////////////////////////////////////////////////////////////
        void ReporteConsultarPaises();
        void ReporteConsultarCiudades(int pCodPais);
        void ReporteConsultarConexiones(int pCodPais, int pCodCiudad);
        void ReporteConsultarTrenes(int pTipoTren);
        void ReporteConsultarNumAsientosTren(int pTipoTren, int pCodTren);

        string reporteRutaMas();
        string reporteRutaMenos();
        string reporteUsuariosMas();
        string reporteUsuariosMenos();
        string reporteCantCompras();
        string reporteTrenMas();
        string reporteTrenMenos();
        string reporteCiudadMas();

        void ReporteUltimoPaisInsertado();
        void ReporteUltimaCiudadInsertada();
        void ReporteUltimaConexionInsertada();
        void ReporteUltimoTrenInsertado();
        void ReporteUltimoTipoTrenInsertado();
        void ReporteConsultarPrecioConexion(int pCodPais, int pCodCiudad, int pCodConexion);

        string realizarReservacion(string pComprador, string pCodTipoTren, string pCodRuta, string pCodTren, string pPasajeros, string pNumAsientos, string pPasaportes);
        string facturar(string pCodigo);

        friend class Server;
        friend class MyThread;
};


#endif // SISTEMATRENES_H
