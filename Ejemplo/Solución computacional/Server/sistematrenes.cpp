#include "sistematrenes.h"

static arbolTrenes trenes;
static ArbolB usuarios(4);
static ArbolB administradores(4);
static ListaReserva reservas;
static ListaPais paises;

static string msgConsultarPaises;
static string msgConsultarCiudades;
static string msgConsultarConexiones;
static string msgConsultarTrenes;
static string msgConsultarRutas;
static string msgConsultarNumAsientos;

static string msgUltimoPaisInsertado;
static string msgUltimaCiudadInsertada;
static string msgUltimaConexionInsertada;
static string msgUltimoTrenInsertado;
static string msgUltimoTipoTrenInsertado;

static string MsgUltimoTrenModificado;


void ServicioDeTrenes::separador(string oracion, int opcion){
    string arr[10];
    char separador = ';';
    int contador = 0;
    for(size_t p=0, q=0; p!=oracion.npos; p=q){
        arr[contador] = oracion.substr(p+(p!=0),(q=oracion.find(separador, p+1))-p-(p!=0));
        contador++;
    }
    switch (opcion){
    case 0:
        AgregarPais(arr[0],arr[1]);
        break;
    case 1:
        AgregarCiudad(arr[0], arr[1], arr[2]);
        break;
    case 2:
        cout<<AgregarConexion(arr[0], arr[1],arr[2],arr[3],arr[4],arr[5],arr[6])<<endl;
        break;
    case 3:
        AgregarTipoTren(arr[0]);
        AgregarTren(arr[0],arr[1],arr[2],arr[3], arr[4], arr[5]);
        break;
    case 4:
        AgregarRuta(arr[0],arr[1], arr[2], arr[3], arr[4], arr[5], arr[6],arr[7]);
        break;
    case 5:
        AgregarAracciones(arr[0],arr[1], arr[2], arr[3], arr[4]);
        break;
    }
}

/**
 * Lee el archivo que le entra como parÃ¡metro y lo manda al separador.
 * @brief ServicioDeTrenes::lector
 * @param nombreArchivo
 * @param pos
 */

void ServicioDeTrenes::lector(string nombreArchivo, int pos){
    std::ifstream file(nombreArchivo.c_str());
    std::string cadena;
    while (getline(file, cadena)){
        separador(cadena, pos);
    }
    file.close();
}
/**
 * Carga los archivos dados y los manda al lector.
 * @brief ServicioDeTrenes::cargarArchivos
 */
void ServicioDeTrenes::cargarArchivos(){
    string archivos[] = {"Paises.txt","Ciudades.txt","Conexiones.txt","Trenes.txt","Rutas.txt"};
    for(int i = 0; i<5; i++){
        cout<<archivos[i]<<endl;
        lector(archivos[i], i);
    }
    administradores.leerArchivoAdministrador();
    usuarios.leerArchivoUsuario();
}

//bool ServicioDeTrenes::validaAdministrador(string pCodAdmin){
//    return administradores.ValidaAdministrador(pCodAdmin);
//}
//bool ServicioDeTrenes::validaUsuario(string pPasaporte){
//    return usuarios.ValidaUsuario(pPasaporte);
//}

string ServicioDeTrenes::AgregarPais(string pCodPais, string pNombre){
    string msg = "";
    if(!paises.validaPais(pCodPais)){
        // Se guarda el pais
        paises.InsertarFinal(pCodPais, pNombre);
        msgUltimoPaisInsertado = "Nombre: "+pNombre+"\n"+"Codigo: "+pCodPais;
        msg = "El pais "+pNombre+" ha sido agregado!";
    }else{
        // NO se guarda el país
        msg = "El pais "+pNombre+" ya esta registrado";
    }
    return msg;
}

string ServicioDeTrenes::AgregarCiudad(string pCodPais, string pCodCiudad, string pNombre){
    string msg = "";
    if(!paises.validaCiudad(pCodPais, pCodCiudad)){
        //Verifica que la ciudad exista
        paises.insertarCiudad(pCodPais, pCodCiudad, pNombre);
        msgUltimaCiudadInsertada = "Nombre: "+pNombre+"\n"+"Codigo: "+pCodPais;
        msg = "La ciudad "+pNombre+" ha sido agregada!";
    }else{
        // NO se guarda la ciudad
        msg ="La ciudad "+pNombre+"ya esta registrada";
    }
    return msg;
}

string ServicioDeTrenes::AgregarConexion(string CodPaisSalida, string CodCiudadSalida, string CodConexion, string CodPaisDest, string CodCiudadDest, string Tiempo, string pPrecio){
    string msg = "";
    if(paises.validaPais(CodPaisSalida)){
        if(paises.validaCiudad(CodPaisDest, CodCiudadDest)){
            if(!paises.validaConexion(CodPaisSalida, CodCiudadSalida,CodConexion)){
                //Si está la ciudad y el país, se agrega la conexión
                int tiempo = 0;
                istringstream(Tiempo)>>tiempo;
                int precio = 0;
                istringstream(pPrecio)>>precio;
                cout<<"Inserta"<<endl;
                paises.insertarConexion(CodPaisSalida, CodCiudadSalida, CodConexion, CodPaisDest, CodCiudadDest, tiempo, precio);
                return "La conexion se ha registrado exitosamente";
            }else{
                // NO se guarda la ciudad
                return "La conexion ya esta registrada";
            }
        }else{
            return "El pais o ciudad destino no existen";
        }
    }
    return  "El pais de salida no existe";
}


string ServicioDeTrenes::ValidarUsuario(string pPasaporte){
    string valido= usuarios.buscar(pPasaporte);
    return valido;

}

string ServicioDeTrenes::ValidaAdministrador(string pId){
    string valido= administradores.buscar(pId);
    return valido;
}

string ServicioDeTrenes::AgregarTipoTren(string pCodTipoTren){
    string msg = "";
    int codTipoTren = 0;
    istringstream(pCodTipoTren)>>codTipoTren;

    if(!trenes.validaTipoTren(codTipoTren)){
        // Se guarda el pais
        trenes.InsertaNodo(codTipoTren);

        msg = "El tipo de tren "+pCodTipoTren+" ha sido agregado!\n";
        msgUltimoTipoTrenInsertado = "Tipo de tren: "+pCodTipoTren+"\n";
    }else{
//         NO se guarda el Tipo
        msg = "El tipo de tren "+pCodTipoTren+" ya esta registrado";
    }
    return msg;
}

string ServicioDeTrenes::AgregarTren(string pCodTipoTren, string pCodTren, string pNombre, string pNumdeAsientos, string pPaisSalida, string pCiudadSalida){
    string msg = "";
    int codTipoTren = 0;
    istringstream(pCodTipoTren)>>codTipoTren;
    int codTren = 0;
    istringstream(pCodTren)>>codTren;
    int codPais= 0;
    istringstream(pPaisSalida)>>codPais;
    int codCiudad = 0;
    istringstream(pCiudadSalida)>>codCiudad;

    if(trenes.validaTipoTren(codTipoTren)){
        if(paises.validaCiudad(pPaisSalida, pCiudadSalida)){
            //Se guarda si la ciudad de punto de salida esta registrada
            if(!trenes.validaTren(codTipoTren, codTren)){
                // Se guarda el pais si no esta repetido
                trenes.InsertarTren(trenes.Raiz, codTipoTren, codTren, pNombre, pNumdeAsientos, codCiudad,codPais);
                msg = "El tren "+pNombre+" ha sido agregado!";
                msgUltimoTrenInsertado="TipoTren: "+pCodTipoTren+"\n"+"Nombre: "+pNombre+"\n"+"CodTren: "+pCodTren+"\n"+"Numero de Asientos: "+pNumdeAsientos+"\n"+"Pais de Salida: "+pPaisSalida+"\n"+"Ciudad de Salida: "+pCiudadSalida+"\n";
            }else{
                // NO se guarda el paÃ­s
                msg = "El tren "+pNombre+" ya esta registrado";
            }
        }else {
            msg = "La ciudad de partida del tren no exite";
        }

    }else{
        msg = "EL tipo de tren "+ pCodTipoTren+" no se encuentra registrado";
    }

    return msg;
}

string ServicioDeTrenes::AgregarRuta(string pCodTipoTren, string pCodTren, string pCodRuta, string pPaisSalida, string pCiudadSalida, string pPaisDest, string pCiudadDest, string pPrecio)
{
    string msg = "";
    int codTipoTren = 0;
    istringstream(pCodTipoTren)>>codTipoTren;
    int codTren = 0;
    istringstream(pCodTren)>>codTren;
    int codRuta = 0;
    istringstream(pCodRuta)>>codRuta;
    int paisSalida = 0;
    istringstream(pPaisSalida)>>paisSalida;
    int ciudadSalida = 0;
    istringstream(pCiudadSalida)>>ciudadSalida;
    int paisDestino = 0;
    istringstream(pPaisDest)>>paisDestino;
    int ciudadDestino = 0;
    istringstream(pCiudadDest)>>ciudadDestino;
    int precio = 0;
    istringstream(pPrecio)>>precio;
    if(trenes.validaTren(codTipoTren,codTren)){
        if(paises.validaCiudad(pPaisSalida, pCiudadSalida)){
            if(paises.validaCiudad(pPaisDest, pCiudadDest)){
                //VALIDAR SI EL TREN ESTA EN LA CIUDAD DE SALIDA
                if(trenes.validarCiudadSalidaRuta(codTipoTren,codTren,paisSalida, ciudadSalida)){
                        if(!trenes.validaRuta(codTipoTren, codTren, codRuta)){
//                            // Se guarda el pais
                            trenes.AgregarRuta(trenes.Raiz,codTipoTren, codTren, codRuta, paisSalida, ciudadSalida, paisDestino, ciudadDestino, precio);
                            msg = "La ruta se ha registrado exitosamente";
                        }else{
                            // NO se guarda el paÃƒÂ­s
                            msg = "La ruta ya estaba agregada";
                        }
                }else {
                    msg = "El pais y ciudad de salida de la ruta no corresponde al pais y ciudad de salida del tren";
                }
            }else{
                msg = "El la ciudad de destino no esta registrada en el pais indicado";
            }
        }else{
            msg = "El la ciudad de salida no esta registrada en el pais indicado";
        }
    }else {
        msg = "El tren no exite";
    }
    return msg;
}

string ServicioDeTrenes::AgregarAracciones(string CodPais, string CodCiudad, string codAtraccion, string nombre, string precio){
    string msg = "";
    if(paises.validaPais(CodPais)){
        if(paises.validaCiudad(CodPais, CodCiudad)){
            if(!paises.validarAtraccion(CodPais, CodCiudad, codAtraccion)){
                paises.insertarAtraccion(CodPais, CodCiudad, codAtraccion, nombre, precio);
                msg = "Se ha registrado la atraccion "+nombre;
            }else{
                msg="La atraccion ya se encuentra registrada\n";
            }
        }else{
            msg="la ciuad no se encuentra registrada\n";
        }
    }else{
        msg= "El pais no se encuentra registrado\n";
    }
    return msg;
}

string ServicioDeTrenes::ConsultarPaises(){
    msgConsultarPaises  = paises.Mostrar();
    return msgConsultarPaises;
}


string ServicioDeTrenes::ConsultarCiudades(string pCodPais){
    if(paises.validaPais(pCodPais)){
        return paises.MostrarCiudadesCodigo(pCodPais);
    }else{
        return "El país no existe";
    }
}

string ServicioDeTrenes::mostrarCiudades(string pNombrePais)
{
    return paises.MostrarCiudades(pNombrePais);
}

string ServicioDeTrenes::mostrarAtracciones(string pPais, string pCiudad)
{
    return paises.MostrarAtracciones(pPais,pCiudad);
}


string ServicioDeTrenes::ConsultarConexiones(string pCodPais){
    if(paises.validaPais(pCodPais)){
        cout<<"valido"<<endl;
        string mensaje = paises.ConsultarConexionesPais(pCodPais);
        return mensaje;
    }else{
        return "El pais no existe";
    }
}


string ServicioDeTrenes::ConsultarTrenes(int pTipoTren){
    msgConsultarTrenes = "";
    if(trenes.validaTipoTren(pTipoTren)){
        EncotrarTipoTren(trenes.Raiz,pTipoTren);
    }else{
        msgConsultarTrenes = "No se encontro el tipo de tren";
    }
    if(msgConsultarTrenes == ""){
        return "El tipo de tren no tiene trenes registrados";
    }else{
        return msgConsultarTrenes;
    }
}

void ServicioDeTrenes::EncotrarTipoTren(nodoTipoTren *R){
    if(R == nullptr){
        return ;
    }else{
        msgConsultarTrenes += to_string(R->TipoTren)+"\n";
        PreordenArbolTren(R->Trenes);
        EncotrarTipoTren(R->Hizq);
        EncotrarTipoTren(R->Hder);
    }
}

void ServicioDeTrenes::EncotrarTipoTren(nodoTipoTren *R, int codTipo)
{
    if(R == nullptr){
        return ;
    }else{
        cout<<R->TipoTren<<endl;
        if(R->TipoTren == codTipo){
            PreordenArbolTren(R->Trenes);
        }
        if(R->TipoTren > codTipo){
            EncotrarTipoTren(R->Hizq,codTipo);
        }
        if(R->TipoTren < codTipo){
            EncotrarTipoTren(R->Hder,codTipo);
        }
    }
}

void ServicioDeTrenes::PreordenArbolTren(nodoTren *R){
    if(R==nullptr){
        return;
    }else{
        msgConsultarTrenes+="  Nombre: "+R->Nombre+" CodTren: "+to_string(R->CodTren)+" Pais: "+(R->CodPaisSalida)+" Ciudad: "+(R->CodCiudadSalida)+"\n";
        PreordenArbolTren(R->Hizq);
        PreordenArbolTren(R->Hder);
    }
}

void ServicioDeTrenes::ConsultarUsuarios(){
//    usuarios.MostrarRaiz();
}

string ServicioDeTrenes::ConsultarNumAsientosTren(int pTipoTren, int pCodTren){
    msgConsultarNumAsientos = "";
    if(trenes.validaTipoTren(pTipoTren)){
        if(trenes.validaTren(pTipoTren,pCodTren)){
            EncotrarTipoTrenParaTren(trenes.Raiz,pTipoTren, pCodTren);
        }else{
            msgConsultarNumAsientos = "El tren no existe en el tipo de tren especificado";
        }
    }else{
        msgConsultarNumAsientos = "El tipo de tren no existe";
    }
    return msgConsultarNumAsientos;
}

void ServicioDeTrenes::EncotrarTipoTrenParaTren(nodoTipoTren *R,int pTipoTren, int pCodTren){
    if(R == nullptr){
        return ;
    }
    if(R->TipoTren == pTipoTren){
        EncontrarTren(R->Trenes, pCodTren);
        return ;
    }
    if(R->TipoTren>pTipoTren){
        EncotrarTipoTrenParaTren(R->Hizq, pTipoTren, pCodTren);
    }
    if(R->TipoTren<pTipoTren){
        EncotrarTipoTrenParaTren(R->Hder, pTipoTren, pCodTren);
    }
}

void ServicioDeTrenes::EncontrarTren(nodoTren *R,int pCodTren){
    if(R == nullptr){
        return ;
    }

    if(R->CodTren == pCodTren){
        msgConsultarNumAsientos+="Numero de asientos disponibles: "+R->numAsientos+"\n";
        return ;
    }else{
        if(R->CodTren>pCodTren){
            EncontrarTren(R->Hizq, pCodTren);
        }
        if(R->CodTren<pCodTren){
            EncontrarTren(R->Hder, pCodTren);
        }
    }
}

string ServicioDeTrenes::ConsultarRutas(int pTipoTren, int pCodTren){
    msgConsultarRutas = "";
    if(trenes.validaTipoTren(pTipoTren)){
        if(trenes.validaTren(pTipoTren,pCodTren)){
            EncotrarTipoTrenParaRuta(trenes.Raiz, pTipoTren, pCodTren);
        }else{
            msgConsultarRutas ="El tren no existe en el tipo de tren";
        }
    }else{
        msgConsultarRutas ="El tipo de tren no existe";
    }
    if(msgConsultarRutas == "" ){
        return "No hay rutas registradas";
    }
    return msgConsultarRutas;
}

void ServicioDeTrenes::EncotrarTipoTrenParaRuta(nodoTipoTren *R, int pTipoTren, int pCodTren){
    if(R == nullptr){
        return ;
    }
    if(R->TipoTren == pTipoTren){
        EncontrarTrenParaRuta(R->Trenes, pCodTren);
        return ;
    }
    if(R->TipoTren>pTipoTren){
        EncotrarTipoTrenParaRuta(R->Hizq, pTipoTren, pCodTren);
    }
    if(R->TipoTren<pTipoTren){
        EncotrarTipoTrenParaRuta(R->Hder, pTipoTren, pCodTren);
    }
}

void ServicioDeTrenes::EncontrarTrenParaRuta(nodoTren *R, int pCodTren){
    if(R == nullptr){
        return ;
    }

    if(R->CodTren == pCodTren){
        PreordenArbolRutas(R->rutas);
        return ;
    }else{
        if(R->CodTren>pCodTren){
            EncontrarTrenParaRuta(R->Hizq, pCodTren);
        }
        if(R->CodTren<pCodTren){
            EncontrarTrenParaRuta(R->Hder, pCodTren);
        }
    }
}

void ServicioDeTrenes::PreordenArbolRutas(NodoRuta *R){
    if(R==nullptr){
        return;
    }else{
        msgConsultarRutas+="CodRuta: "+to_string(R->codRuta)+" CodPaisSalida: "+to_string(R->codPais)+" CodCiudadSalida: "+to_string(R->codCiudad)+" CodPaisDestino: "+to_string(R->codPaisDest)+" CodCiudadDestino: "+to_string(R->codCiudadDest)+"\n";
        PreordenArbolRutas(R->hi);
        PreordenArbolRutas(R->hd);
    }
}

string ServicioDeTrenes::ModificarTren(int pTipo, int pCodTren, string pNombre){
    if(trenes.validaTipoTren(pTipo)){
        if(trenes.validaTren(pTipo, pCodTren)){
            trenes.modificarTren(trenes.Raiz, pTipo, pCodTren, pNombre);
            MsgUltimoTrenModificado = "Tipo De Tren: "+to_string(pTipo)+trenes.msgUltimoTrenModificado;
            return "El tren ha sido modificado exitosamente";
        }else{
            return "El Tren no existe\n";
        }
    }else{
        return "El tipo de tren no existe\n";
    }
}

string ServicioDeTrenes::ModificarNumAsientos(int pTipo, int pCodTren, string pNumAsientos){
    if(trenes.validaTipoTren(pTipo)){
        if(trenes.validaTren(pTipo, pCodTren)){
            trenes.modificarNumAsientos(trenes.Raiz, pTipo, pCodTren, pNumAsientos);
            MsgUltimoTrenModificado = "Tipo De Tren: "+to_string(pTipo)+trenes.msgUltimoTrenModificado;
            return "El numero de asientos del tren "+to_string(pCodTren)+" ahora es: "+pNumAsientos;
        }else{
            return "El Tren no existe";
        }
    }else{
        return "El tipo de tren no existe";
    }
}

string ServicioDeTrenes::ModificarEstadoMigratorio(string pPasaporte, int pEstadoMigratorio){
    if(pEstadoMigratorio == 1 or pEstadoMigratorio ==0){
        cout<<pPasaporte;
        string mensaje = usuarios.modificarEstadoMigratorio(pPasaporte,pEstadoMigratorio);
        return mensaje;
    }else{
        return "El estado migratorio es invalido";
    }
}


string ServicioDeTrenes::ModificarPrecio(int pTipo, int pCodTren, int pCodRuta, int precio){
    if(trenes.validaTren(pTipo, pCodTren)){
        trenes.buscarTipoTrenParaRutaModificar(trenes.Raiz,pTipo, pCodTren, pCodRuta, precio, 1);
        return "El precio de la ruta "+to_string(pCodRuta)+" ahora es: "+to_string(precio);
    }else{
        return "El tren no se ha encontrado!";
    }
}

string ServicioDeTrenes::ConsultarPrecioConexion(string Pais, string ciudad, string conexion){
    if(paises.validaPais(Pais)){
        if(paises.validaCiudad(Pais,ciudad)){
            if(paises.validaConexion(Pais,ciudad,conexion)){
                return paises.consultarPrecioConexion(Pais, ciudad,conexion);
            }else{
                return "La conexion no existe";
            }
        }else{
            return "La ciudad no existe";
        }
    }else{
        return "El pais no esta registrado";
    }
}

string ServicioDeTrenes::ConsultarPrecioRuta(int pTipoTren, int pCodTren, int pCodRuta){
    if(trenes.validaTipoTren(pTipoTren)){
        if(trenes.validaTren(pTipoTren, pCodTren)){
            if(trenes.validaRuta(pTipoTren, pCodTren, pCodRuta)){
                trenes.obtenerPrecio(pTipoTren, pCodTren, pCodRuta);
                return to_string(trenes.precio);
            }else{
              return "La ruta no se encuentra registrada";
            }
        }else{
            return "El tren no se encuentra registrado";
        }
    }else{
        return "El tipo de tren no existe";
    }
}


string ServicioDeTrenes::ModificarPrecioConexion(string pCodPais, string pCodCiudad, string pCodConexion, int precio){
    string msg = "";
    if(paises.validaPais(pCodPais)){
        if(paises.validaCiudad(pCodPais, pCodCiudad)){
            if(paises.validaConexion(pCodPais, pCodCiudad, pCodConexion)){
                paises.modificarPrecioConexion(pCodPais, pCodCiudad, pCodConexion, to_string(precio));
                msg= "Se ha modificado el precio de la conexio";

            }else{
                msg= "La conexion no se encuentra registrada";
            }
        }else{
            msg= "La ciudad no se encuentra registrada";
        }
    }else{
        msg= " El pais no se encuentra registrado";
    }
    return msg;
}

string ServicioDeTrenes::ModificarTiempoConexion(string pCodPais, string pCodCiudad, string pCodConexion, int tiempo){
    string msg = "";
    if(paises.validaPais(pCodPais)){
        if(paises.validaCiudad(pCodPais, pCodCiudad)){
            if(paises.validaConexion(pCodPais, pCodCiudad, pCodConexion)){
                paises.modificarTiempo(pCodPais, pCodCiudad, pCodConexion, to_string(tiempo));
                msg= "Se ha modificado el timepo de la conexion";

            }else{
                msg= "La conexion no se encuentra registrada";
            }
        }else{
            msg= "La ciudad no se encuentra registrada";
        }
    }else{
        msg= " El pais no se encuentra registrado";
    }
    return msg;
}


string ServicioDeTrenes::ReporteConsultarPaises(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Paises.txt");
    ficheroSalida <<"Reporte de paises: \n";
    ficheroSalida <<"***************************************\n";
    string mensaje = paises.Mostrar();
    ficheroSalida << mensaje;
    ficheroSalida.close();
    return mensaje;
}

string ServicioDeTrenes::ReporteConsultarCiudades(){

    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ciudades.txt");
    ficheroSalida <<"Reporte de Ciudades: \n";
    ficheroSalida <<"***************************************\n";
    string mensaje = paises.MostrarCiudades();
    ficheroSalida << mensaje;
    ficheroSalida.close();
    return mensaje;
}

string ServicioDeTrenes::ReporteConsultarConexiones(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Conexiones.txt");
    ficheroSalida <<"Reporte de Conexiones: \n";
    ficheroSalida <<"***************************************\n";
    string mensaje = paises.MostrarConexiones();
    ficheroSalida << mensaje;
    ficheroSalida.close();
    return mensaje;
}

string ServicioDeTrenes::ReporteConsultarTrenes(){
    msgConsultarTrenes = "";
    EncotrarTipoTren(trenes.Raiz);

    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Trenes.txt");
    ficheroSalida <<"Reporte de Trenes: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgConsultarTrenes;
    ficheroSalida.close();
    return  msgConsultarTrenes;
}

string ServicioDeTrenes::ReporteConsultarNumAsientosTren(int pTipoTren, int pCodTren){
    msgConsultarNumAsientos = "";
    EncotrarTipoTrenParaTren(trenes.Raiz,pTipoTren, pCodTren);

    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Numero asientos.txt");
    ficheroSalida <<"Reporte de numero  de asientos: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgConsultarNumAsientos;
    ficheroSalida.close();
    return msgConsultarNumAsientos;
}

string ServicioDeTrenes::reporteRutaMas()
{

    string msg = "Algo fallo";
    ofstream archivo;
    archivo.open("Reporte_de_rutas_mas_utilizadas.txt",ios::out);
    if(archivo.fail()){
        return msg;
    }else{
        msg = reservas.consultarRutasMasUtilizadas();
        archivo <<"Reporte de rutas mas utilizadas: \n";
        archivo <<"***************************************\n";
        archivo<<msg;
    }
    archivo.close();
    return msg;

}

string ServicioDeTrenes::reporteRutaMenos()
{
    string msg = "Algo fallo";
    ofstream archivo;
    archivo.open("Reporte_de_rutas_menos_utilizadas.txt",ios::out);
    if(archivo.fail()){
        return msg;
    }else{
        msg = reservas.consultarRutasMaenosUtilizadas();
        archivo <<"Reporte de rutaa menos utilizada: \n";
        archivo <<"***************************************\n";
        archivo<<msg;
    }
    archivo.close();
    return msg;
}

string ServicioDeTrenes::reportePaisMas(){
    string msg = "Algo fallo";
    ofstream archivo;
    archivo.open("Reporte_de_pais_mas_visitada.txt",ios::out);
    if(archivo.fail()){
        return msg;
    }else{
        msg = reservas.consultarPaisMasVisitados();
        archivo <<"Reporte de pais mas visitado: \n";
        archivo <<"***************************************\n";
        archivo<<msg;
    }
    archivo.close();
    return msg;
}

string ServicioDeTrenes::reporteCiudadMas(){
    string msg = "Algo fallo";
    ofstream archivo;
    archivo.open("Reporte_de_ciudad_mas_visitada.txt",ios::out);
    if(archivo.fail()){
        return msg;
    }else{
        msg = reservas.consultarCiudadMasVisitada();
        archivo <<"Reporte de ciudad mas visitada: \n";
        archivo <<"***************************************\n";
        archivo<<msg;
    }
    archivo.close();
    return msg;
}

string ServicioDeTrenes::reporteUsuariosMas()
{
    string msg = "Algo fallo";
    ofstream archivo;
    archivo.open("Reporte_de_usuario_mas_activo.txt",ios::out);
    if(archivo.fail()){
        return msg;
    }else{
        msg = reservas.consultarUsuarioMasActivo();
        archivo <<"Reporte de usuario mas activo: \n";
        archivo <<"***************************************\n";
        archivo<<msg;
    }
    archivo.close();
    return msg;
}

string ServicioDeTrenes::reporteUsuariosMenos()
{
    string msg = "Algo fallo";
    ofstream archivo;
    archivo.open("Reporte_de_usuario_menos_activo.txt",ios::out);
    if(archivo.fail()){
        return msg;
    }else{
        msg = reservas.consultarUsuarioMenosActivo();
        archivo <<"Reporte de usuario menos activo: \n";
        archivo <<"***************************************\n";
        archivo<<msg;
    }
    archivo.close();
    return msg;
}

string ServicioDeTrenes::reporteCantCompras(){
    string msg = "Algo fallo";
    ofstream archivo;
    archivo.open("Reporte_de_cantidad_compras_usuarios.txt",ios::out);
    if(archivo.fail()){
        msg = "Falla al crear el archivo";
    }else{
        msg = reservas.consultarCantCompras();
        archivo <<"Reporte de cantidad de compras por usuario: \n";
        archivo <<"***************************************\n";
        archivo<<msg;
    }
    archivo.close();
    return msg;
}

string ServicioDeTrenes::reporteTrenMas(){
    string msg = "Algo fallo";
    ofstream archivo;
    archivo.open("Reporte_de_tren_mas_utilizado.txt",ios::out);
    if(archivo.fail()){
        msg = "Falla al crear el archivo";
    }else{
        msg = reservas.consultarTrenMasUtilizado();
        archivo <<"Reporte de Tren mas utilizado: \n";
        archivo <<"***************************************\n";
        archivo<<msg;
    }
    archivo.close();
    return msg;
}
string ServicioDeTrenes::reporteTrenMenos(){
    string msg = "Algo fallo";
    ofstream archivo;
    archivo.open("Reporte_de_tren_menos_utilizado.txt",ios::out);
    if(archivo.fail()){
        msg = "Falla al crear el archivo";
    }else{
        msg = reservas.consultarTrenMenosUtilizado();
        archivo <<"Reporte de Tren menos utilizado: \n";
        archivo <<"***************************************\n";
        archivo<<msg;
    }
    archivo.close();
    return msg;
}

string ServicioDeTrenes::ReporteUltimoPaisInsertado(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultimo Pais Insertado.txt");
    ficheroSalida <<"Reporte Consultar Ultimo Pais Insertado: \n";
    ficheroSalida <<"***************************************\n";
    string mensaje = paises.obtenerUltimoPaisIngresado();
    ficheroSalida << mensaje;
    ficheroSalida.close();
    return mensaje;
}

string ServicioDeTrenes::ReporteUltimaCiudadInsertada(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultima Ciudad Insertada.txt");
    ficheroSalida <<"Reporte Consultar Ultima Ciudad Insertada: \n";
    ficheroSalida <<"***************************************\n";
    string mensaje = paises.obtenerUltimaCiudadIngresada();
    ficheroSalida << mensaje;
    ficheroSalida.close();
    return mensaje;
}

string ServicioDeTrenes::ReporteUltimaConexionInsertada(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultima Conexion Insertada.txt");
    ficheroSalida <<"Reporte Consultar Ultima Conexion Insertada: \n";
    ficheroSalida <<"***************************************\n";
    string mensaje = paises.obtenerUltimaConexionIngresada();
    ficheroSalida << mensaje;
    ficheroSalida.close();
    return mensaje;
}

string ServicioDeTrenes::ReporteUltimoTrenInsertado(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultimo Tren Insertado.txt");
    ficheroSalida <<"Reporte Consultar Ultimo Tren Insertado: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgUltimoTrenInsertado;
    ficheroSalida.close();
    return msgUltimoTrenInsertado;
}

string ServicioDeTrenes::ReporteUltimoTipoTrenInsertado(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultimo Tipo de Tren Insertado.txt");
    ficheroSalida <<"Reporte Consultar Ultimo Tipo de Tren Insertado: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgUltimoTipoTrenInsertado;
    ficheroSalida.close();
    return msgUltimoTipoTrenInsertado;
}

string ServicioDeTrenes::ReporteConsultarPrecioConexion(string pCodPais, string pCodCiudad, string pCodConexion){
    string mensaje = ConsultarPrecioConexion(pCodPais,pCodCiudad,pCodConexion);

    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Precio Conexion.txt");
    ficheroSalida <<"Reporte del precio de una conexion: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << mensaje;
    ficheroSalida.close();
    return mensaje;
}

string ServicioDeTrenes::realizarReservacion(string pComprador, string pCodTipoTren, string pCodRuta, string pCodTren, string pPasajeros, string pNumAsientos)
{
    string pasaportes[50];
    char separador = '-';
    int contador = 0;
    if(trenes.validaTren(stoi(pCodTipoTren),stoi(pCodTren))){
        if(trenes.validaRuta(stoi(pCodTipoTren),stoi(pCodTren),stoi(pCodRuta))){
            if(trenes.validaAsientos(stoi(pCodTipoTren),stoi(pCodTren),stoi(pNumAsientos))){
                bool realizar = true;
                if(realizar){
                    string codigo = reservas.InsertarFinal(pComprador, pCodTipoTren, pCodTren, pCodRuta, pPasajeros, pNumAsientos);
                    trenes.reducirAsientos(stoi(pCodTipoTren), stoi(pCodTren), stoi(pPasajeros));
                    reservas.Mostrar();
                    return "Se realizo la reserva. "+codigo;
                }else{
                    return "No se pudo realizar la reservación";
                }
            }else{
                return "El tren no tiene la cantidad de asientos suficientes para realiar su reserva";
            }
        }else{
            return "La ruta indicada no existe";
        }
    }else{
        return "El tren no existe";
    }
}

string ServicioDeTrenes::facturar(string pCodigo)
{
    return reservas.Facturar(pCodigo);
}

string ServicioDeTrenes::ValidarEM(string pPasaporte){
    string valido= usuarios.validarEstadoMigratorio(pPasaporte);
    return valido;

}

//*************************************************************************************

string ListaReserva::Facturar(string pCodReserva){
    nodoReserva *aux;
    if (primero== NULL)
        return "No hay reservas registradas";
    else
    {
        aux = primero;
         while(aux != NULL)
         {
             if(aux->codigoReserva == pCodReserva){
                 if(aux->isFacturado == false){
                     aux->isFacturado = true;
                     ofstream ficheroSalida;
                     string msg= "";
                     ficheroSalida.open ("Factura.txt");
                     msg += "Factura: "+ to_string(aux->consecutivo)+"\n";
                     msg += "*************\n";
                     msg+="Tipo de tren reservado: "+aux->codigoTipoTren+"\n"+ "Tren reservado: "+aux->codigoTren+"\n" + "Numero de ruta reservada: "+aux->codigoRuta+"\n";
                     msg+="Encargado de la reserva: "+aux->comprador+"\n"+ "Número de asientos reservados: "+to_string(aux->numAsientos);
                     int precio = trenes.obtenerPrecio(stoi(aux->codigoTipoTren),stoi(aux->codigoTren),stoi(aux->codigoRuta));
                     msg+="\n\n El monto a pagar seria de: " + to_string(precio*aux->pasajeros);
                     ficheroSalida << msg;
                     ficheroSalida.close();
                     return msg;
                 }else {
                     return "La reserva ya ha sido facturada!";
                 }

             }
             aux = aux->siguiente;
         }
         return "No se encontro el codigo de reservacion.";
    }
}

void ServicioDeTrenes::Krukal(){
    paises.Kruskal();
}

void ServicioDeTrenes::Dijkstra( string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada, int opcion){
    paises.Dijkstra(pPaisSalida, pCiudadSalida, pPaisLlegada, pCiudadLlegada, opcion);
}

string ServicioDeTrenes::BuscarRuta(int pTipoTren, int pCodTren, string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada){
    if(trenes.BuscarRuta( pTipoTren,  pCodTren,  pPaisSalida,  pCiudadSalida,  pPaisLlegada,  pCiudadLlegada)){
        return trenes.buscarRuta;
    }else{
        return NuevaRutaMenorPrecio(pPaisSalida,  pCiudadSalida,  pPaisLlegada,  pCiudadLlegada);
    }
}

bool ServicioDeTrenes::BuscarRutaDijsktra(string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada){
    return trenes.BuscarRutaDijsktra(pPaisSalida,  pCiudadSalida,  pPaisLlegada,  pCiudadLlegada);
}

string ServicioDeTrenes::NuevaRuta(string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada){
    if(paises.validaPais(pPaisSalida)){
        if(paises.validaCiudad(pPaisSalida,pCiudadSalida)){
            if(paises.validaPais(pPaisLlegada)){
                if(paises.validaCiudad(pPaisLlegada, pCiudadLlegada)){
                    return paises.Dijkstra(pPaisSalida, pCiudadSalida, pPaisLlegada, pCiudadLlegada, 1);
                }
            }
        }
    }
}

string ServicioDeTrenes::NuevaRutaMenorPrecio(string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada){
    if(paises.validaPais(pPaisSalida)){
        if(paises.validaCiudad(pPaisSalida,pCiudadSalida)){
            if(paises.validaPais(pPaisLlegada)){
                if(paises.validaCiudad(pPaisLlegada, pCiudadLlegada)){
                    return paises.Dijkstra(pPaisSalida, pCiudadSalida, pPaisLlegada, pCiudadLlegada, 1);
                }
            }
        }
    }
}

string ServicioDeTrenes::NuevaRutaMenorTiempo(string pPaisSalida, string pCiudadSalida, string pPaisLlegada, string pCiudadLlegada){
    if(paises.validaPais(pPaisSalida)){
        if(paises.validaCiudad(pPaisSalida,pCiudadSalida)){
            if(paises.validaPais(pPaisLlegada)){
                if(paises.validaCiudad(pPaisLlegada, pCiudadLlegada)){
                    return paises.Dijkstra(pPaisSalida, pCiudadSalida, pPaisLlegada, pCiudadLlegada, 0);
                }
            }
        }
    }
}


