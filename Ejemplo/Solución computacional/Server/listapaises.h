#include <iostream>
#include "pila.h"
#include "nododijkstra.h"

using namespace std;


class ListaPais {
   public:
    ListaPais() {
        primero = actual = NULL;
        ultimoPaisEliminado = NULL;
        ultimaCiudadEliminada = NULL;
        ultimaConexionEliminada = NULL;
        ultimaCiudadAgregada = NULL;
        ultimaConexionAgregada = NULL;
    }

    void InsertarInicio(string pCodigo, string pNombre);
    void InsertarFinal(string pCodigo, string pNombre);
    void InsertarPos (string pCodigo, string pNombre, int pos);
    bool ListaVacia() { return primero == NULL; }
    string Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();

    string eliminarPais(string pCodPais);
    string eliminarCiudad(string pCodPais, string pCodCiudad);
    string eliminarConexion(string pCodPais, string pCodCiudad, string pCodConexion);
    void insertarCiudad(string pCodigoPais, string pCodigoCiudad, string pNombre);
    void insertarConexion(string pCodPaisSalida, string pCodCiudadSalida, string pCodConexion, string pCodPaisDest, string pCodCiudadDest, int Tiempo, int pPrecio);
    bool validaPais(string pCodigo);
    bool validaCiudad(string pCodPais, string pCodCiudad);
    bool validaConexion(string pCodPais, string pCodCiudad, string pCodConexion);
    bool validaConexion(string pCodPaisSalida, string pCodCiudadSalida, string pCodPaisDestino, string pCodCiudadDestino);
    string MostrarCiudades();
    string MostrarConexiones();
    string MostrarCiudad(string pCodPais, string pCodCiudad);
    string MostrarCiudad(string pCodCiudad);
    string MostrarCiudades(string pNombrePais);
    string MostrarCiudadesCodigo(string pCodPais);
    string MostrarAtracciones(string pPais, string pCiudad);
    string modificarTiempo(string pCodPais, string pCodCiudad, string pCodConexion, string pTiempo);
    string modificarPrecioConexion(string pCodPais, string pCodCiudad, string pCodConexion, string pPrecio);

    string ConsultarConexionesPais(string pCodPais);
    void ConsultarCiudadesPais(string pCodPais);

    string consultarPrecioConexion(string pCodPais, string pCodCiudad, string pCodConexion);

    string obtenerUltimoPaisIngresado();
    string obtenerUltimaCiudadIngresada();
    string obtenerUltimaConexionIngresada();

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Kruskal();
    void OrdenarVertices();
    void Conectar();
    void ObtenerVerticesSinArcos();
    string Profundidad(string codPais);
    string prof(string codPais);
    void InsertarCiudadVisitada(string pPais, string pCodigoCiudad );
    void InsertarCiudadVisitada(pnodoCiudad &pCiudad);

    bool VerificarVisitado(string pCodCiudad);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    string Dijkstra(string pPaisPartida, string pCiudadllegada,string pPaisDestino, string pDestino, int opcion);
    void ObtenerNodo(string pCodPais, string pCodCiudad);
    void InsertarEvaluables(pnodoCiudad pCiudad);
    void EvaluarAdyacentes(string pPais, string pCiudad);
    void ObtenerCosto(pnodoDijkstra &puntero, string pcodPais, string pCodCiudad);
    void ObtenerCiudad(string pcodPais, string pCodCiudad);


    void InsertarNodoDijsktra(pnodoDijkstra &puntero, string pPaisPartida, string pCiudadSalida, string pPaisDestino, string pDestino,int pPeso);
    void InsertarConexionDijkstra(string pPaisPartida, string pCiudadllegada,string pPaisDestino, string pDestino);
    void AgregarEvaluables(pnodoConexion &pConexiones, string pPaisSalida, string pCiudadSalida);
    void ObtenerRuta(pnodoDijkstra &pNodoRuta, string pPais, string pCiudad, bool &encontrado);

    //Precio
    void AgregarEvaluablesPrecio(pnodoConexion &pConexiones, string pPaisSalida, string pCiudadSalida);
    void EvaluarAdyacentesPrecio(string pPais, string pCiudad);

    //////////////////////////////////////////////////////////////////////////////
    void insertarAtraccion(string pCodPais, string pCodCiudad, string pCodAtraccion, string pNombre, string pPrecio);
    bool validarAtraccion(string pCodPais, string pCodCiudad, string pCodAtraccion);

   private:
    pnodoPais primero;
    pnodoPais actual;
    nodoDijkstra *primeroVisitados;
    nodoDijkstra *ultimoVisitados;

    pnodoPais ultimoPaisEliminado;
    pnodoCiudad ultimaCiudadEliminada;
    pnodoConexion ultimaConexionEliminada;
    pnodoCiudad ultimaCiudadAgregada;
    pnodoConexion ultimaConexionAgregada;

    nodoDijkstra *origen;
    nodoDijkstra *primeroRutasNuevas;
    nodoDijkstra *evaluables = nullptr;
    nodoCiudad *CiudadDijkstra = nullptr;
    int costo = 0;

    string rutaNueva;
};


