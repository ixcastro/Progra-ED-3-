#include "sistematrenes.h"

static arbolPaises paises;
static arbolTrenes trenes;
//static ArbolBUsuario usuarios;
//static ArbolBAdministrador administradores;
static ListaReserva reservas;

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
        AgregarConexion(arr[0], arr[1],arr[2],arr[3],arr[4],arr[5],arr[6]);
        break;
    case 3:
        AgregarTipoTren(arr[0]);
        AgregarTren(arr[0],arr[1],arr[2],arr[3], arr[4], arr[5]);
        break;
    case 4:
        AgregarRuta(arr[0],arr[1], arr[2], arr[3], arr[4], arr[5], arr[6],arr[7]);
        break;
    case 5:
        AgregarAdministrador(arr[0],arr[1]);
        break;
    case 6:
        AgregarUsuario(arr[0], arr[1], arr[2], arr[3], arr[4]);
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
    string archivos[] = {"Paises.txt","Ciudades.txt","Conexiones.txt","Trenes.txt","Rutas.txt","Administradores.txt","Usuarios.txt"};
    for(int i = 0; i<7; i++){
        cout<<archivos[i]<<endl;
        lector(archivos[i], i);
    }
}

//bool ServicioDeTrenes::validaAdministrador(string pCodAdmin){
//    return administradores.ValidaAdministrador(pCodAdmin);
//}
//bool ServicioDeTrenes::validaUsuario(string pPasaporte){
//    return usuarios.ValidaUsuario(pPasaporte);
//}

string ServicioDeTrenes::AgregarPais(string pCodPais, string pNombre){
    string msg = "";
    int codPais = 0;
    istringstream(pCodPais)>>codPais;
    if(!paises.validaPais(codPais)){
        // Se guarda el pais
        paises.InsertaNodo(codPais, pNombre);
        msg = "El pais "+pNombre+" ha sido agregado!";
        msgUltimoPaisInsertado = "Nombre: "+pNombre+"\n"+"CodPais: "+pCodPais+"\n";
    }else{
        // NO se guarda el paÃ­s
        msg = "El pais "+pNombre+" ya esta registrado";
    }
    return msg;
}

string ServicioDeTrenes::AgregarCiudad(string pCodPais, string pCodCiudad, string pNombre){
    string msg = "";
    int codPais = 0;
    istringstream(pCodPais)>>codPais;
    int codCiudad = 0;
    istringstream(pCodCiudad)>>codCiudad;
    if(paises.validaPais(codPais)){
        if(!paises.validaCiudad(codPais, codCiudad)){
            //Verifica que la ciudad exista
            paises.InsertarCiudad(paises.Raiz, codPais, codCiudad, pNombre);
            msg = "La ciudad "+pNombre+" ha sido agregada!";
            msgUltimaCiudadInsertada="Pais: "+pCodPais+"\n"+"Nombre: "+pNombre+"\n"+"CodCiudad: "+pCodCiudad+"\n";
        }else{
            // NO se guarda la ciudad
            msg ="La ciudad "+pNombre+"ya esta registrada";
        }
    }else{
        msg ="El pais "+pCodPais+" no se encuentra registrado\n";
    }
    return msg;
}

string ServicioDeTrenes::AgregarConexion(string CodPaisSalida, string CodCiudadSalida, string CodConexion, string CodPaisDest, string CodCiudadDest, string Tiempo, string pPrecio){
    string msg = "";
    int codPaisSalida = 0;
    istringstream(CodPaisSalida)>>codPaisSalida;
    int codCiudadSalida = 0;
    istringstream(CodCiudadSalida)>>codCiudadSalida;
    int codConexion = 0;
    istringstream(CodConexion)>>codConexion;
    int codPaisDest = 0;
    istringstream(CodPaisDest)>>codPaisDest;
    int codCiudadDest = 0;
    istringstream(CodCiudadDest)>>codCiudadDest;
    int precio = 0;
    istringstream(pPrecio)>>precio;
    if(!paises.validaConexion(codPaisSalida, codCiudadSalida,codConexion)){
        if(paises.validaCiudad(codPaisSalida, codCiudadSalida) && paises.validaCiudad(codPaisDest, codCiudadDest)){
            //Si estÃƒÂ¡ la ciudad y el pais, se agrega la conexion
                    paises.AgregarConexion(paises.Raiz,codPaisSalida, codCiudadSalida, codConexion, codPaisDest, codCiudadDest, Tiempo, precio);
                    msg = "La conexion se ha registrado exitosamente";
                    msgUltimaConexionInsertada=
                            "Codigo pais salida: "+CodPaisSalida+"\n"+
                            "Codigo ciudad de salida: "+to_string(codCiudadSalida)+"\n"+
                            "Codigo de conexion: "+to_string(codConexion)+"\n"+
                            "Codigo pais de destino: "+to_string(codPaisDest)+"\n"+
                            "Codigo ciudad de destino: "+to_string(codCiudadDest)+"\n"+
                            "Tiempo de viaje: "+to_string(precio);
        }else{
            msg="El pais o ciudad no existen";
        }
    }else{
        // NO se guarda la ciudad
        msg = "La conexion ya esta registrada";
    }
    return  msg;
}

string ServicioDeTrenes::AgregarAdministrador(string CodAdministrador, string pNombre){
    string msg = "";
    int codAdministrador = 0;
    istringstream(CodAdministrador)>>codAdministrador;
//    if(!administradores.ValidaAdministrador(CodAdministrador)){
        // Se guarda el administrador
//        administradores.InsertarAdministrador(codAdministrador, pNombre);
//        administradores.MostrarRaiz();
//        msg = "El administrador "+pNombre+" ha sido registrado";
//    }else{
        // NO se guarda el administrador
//        msg = "El administrador "+pNombre+" ya esta registrado";
//    }
    return msg;
}

string ServicioDeTrenes::AgregarUsuario(string CodPais, string CodCiudad, string Pasaporte, string Nombre, string EstadoMigratorio){
    string msg = "";
    int codPaisSalida = 0;
    istringstream(CodPais)>>codPaisSalida;
    int codCiudadSalida = 0;
    istringstream(CodCiudad)>>codCiudadSalida;
    int codPasaporte = 0;
    istringstream(Pasaporte)>>codPasaporte;
    if(paises.validaCiudad(codPaisSalida, codCiudadSalida)){
//        if(!usuarios.ValidaUsuario(Pasaporte)){
            // Se guarda el administrador
//            usuarios.InsertarUsuario(codPaisSalida, codCiudadSalida, codPasaporte, Nombre, EstadoMigratorio);
//            msg = "El usuario "+Nombre+" ha sido registrado";
//        }else{
//            // NO se guarda el administrador
//            msg = "El usuario " + Nombre+" ya esta registrado";
//        }
    }else{
        msg = "La ciudad no existe en el pais";
    }
    return msg;
}

string ServicioDeTrenes::ValidarUsuario(string pPasaporte){
    int pasaporte = 0;
    istringstream(pPasaporte)>>pasaporte;
//    pnodoUsuario usuario = new nodoUsuario(1,1,pasaporte,"","");
    return "";//usuarios.validarUsuario(usuario);

}

string ServicioDeTrenes::ValidaAdministrador(string pId){
    int id = 0;
    istringstream(pId)>>id;
//    pnodoAdministrador administrador = new nodoAdministrador(id,"");
    return "";//administradores.validarAdministrador(administrador);
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
        if(paises.validaCiudad(codPais, codCiudad)){
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
        if(paises.validaCiudad(paisSalida, ciudadSalida)){
            if(paises.validaCiudad(paisDestino, ciudadDestino)){
                //VALIDAR SI EL TREN ESTA EN LA CIUDAD DE SALIDA
                if(trenes.validarCiudadSalidaRuta(codTipoTren,codTren,paisSalida, ciudadSalida)){
                    if(paises.ConsultarConexionesParaRuta(paisSalida,ciudadSalida,paisDestino,ciudadDestino)){
                        if(!trenes.validaRuta(codTipoTren, codTren, codRuta)){
//                            // Se guarda el pais
                            trenes.AgregarRuta(trenes.Raiz,codTipoTren, codTren, codRuta, paisSalida, ciudadSalida, paisDestino, ciudadDestino, precio);
                            msg = "La ruta se ha registrado exitosamente";
                        }else{
                            // NO se guarda el paÃƒÂ­s
                            msg = "La ruta ya estaba agregada";
                        }
                    }else{
                        msg = "No existe conexion entre el punto de salida y el punto de destino";
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

string ServicioDeTrenes::ConsultarPaises(){
    msgConsultarPaises  = "";
    PreordenArbolPais(paises.Raiz);
    return msgConsultarPaises;
}

void ServicioDeTrenes::PreordenArbolPais(nodoPais *R){

    if(R==nullptr){
        return;
    }else{
        msgConsultarPaises+="Nombre: "+R->Nombre+" CodPais: "+to_string(R->CodPais)+"\n";
        PreordenArbolPais(R->Hizq);
        PreordenArbolPais(R->Hder);
    }
}

string ServicioDeTrenes::ConsultarCiudades(int pCodPais){
    msgConsultarCiudades = "";
    if(paises.validaPais(pCodPais)){
        EncontrarPais(paises.Raiz, pCodPais);
    }else{
        msgConsultarCiudades = "No se encontro el pais indicado";
    }
    return msgConsultarCiudades;
}

void ServicioDeTrenes::EncontrarPais(nodoPais *R, int pCodPais){
    if(R == nullptr){
        return ;
    }
    if(R->CodPais == pCodPais){
        PreordenArbolCiudad(R->Ciudades);
        return ;
    }
    if(R->CodPais>pCodPais){
        EncontrarPais(R->Hizq, pCodPais);
    }
    if(R->CodPais<pCodPais){
        EncontrarPais(R->Hder, pCodPais);
    }
}

void ServicioDeTrenes::PreordenArbolCiudad(nodoCiudad *R){
    if(R==nullptr){
        return;
    }else{
        msgConsultarCiudades+="Nombre: "+R->Nombre+" CodCiudad: "+to_string(R->CodCiudad)+"\n";
        PreordenArbolCiudad(R->Hizq);
        PreordenArbolCiudad(R->Hder);
    }
}

string ServicioDeTrenes::ConsultarConexiones(int pCodPais, int pCodCiudad){
    msgConsultarConexiones = "";
    if(paises.validaPais(pCodPais)){
        if(paises.validaCiudad(pCodPais,pCodCiudad)){
            EncontrarPaisParaConexion(paises.Raiz, pCodPais, pCodCiudad);
        }else{
            msgConsultarConexiones = "La ciudad no existe";
        }
    }else{
        msgConsultarConexiones = "El pais no existe";
    }
    return msgConsultarConexiones;
}

void ServicioDeTrenes::EncontrarPaisParaConexion(nodoPais *R, int pCodPais, int pCodCiudad){
    if(R == nullptr){
        return ;
    }else{
        if(R->CodPais == pCodPais){
            EncontrarCiudadParaConexion(R->Ciudades, pCodCiudad );
            return ;
        }else{
            if(R->CodPais>pCodPais){
                EncontrarPaisParaConexion(R->Hizq, pCodPais, pCodCiudad);
            }
            if(R->CodPais<pCodPais){
                EncontrarPaisParaConexion(R->Hder, pCodPais, pCodCiudad);
            }
        }
    }
}

void ServicioDeTrenes:: EncontrarCiudadParaConexion(nodoCiudad *R, int pCodCiudad){
    if(R == nullptr){
        return ;
    }

    if(R->CodCiudad == pCodCiudad){
       PreordenArbolConexion(R->conexiones);
        return ;
    }else{
        if(R->CodCiudad>pCodCiudad){
            EncontrarCiudadParaConexion(R->Hizq, pCodCiudad);
        }
        if(R->CodCiudad<pCodCiudad){
            EncontrarCiudadParaConexion(R->Hder, pCodCiudad);
        }
    }
}

void ServicioDeTrenes::PreordenArbolConexion(nodoConexion *R){
    if(R==nullptr){
        return;
    }else{
        msgConsultarConexiones+="CodConexion: "+to_string(R->codigoConexion)+" CodPaisDestino: "+to_string(R->codigoPaisDest)+" CodCiudadDestino: "+to_string(R->codigoCiudadDest)+"\n";
        PreordenArbolConexion(R->HI);
        PreordenArbolConexion(R->HD);
    }
}

string ServicioDeTrenes::ConsultarTrenes(int pTipoTren){
    msgConsultarTrenes = "";
    if(trenes.validaTipoTren(pTipoTren)){
        EncotrarTipoTren(trenes.Raiz, pTipoTren);
    }else{
        msgConsultarTrenes = "No se encontro el tipo de tren";
    }
    return msgConsultarTrenes;
}

void ServicioDeTrenes::EncotrarTipoTren(nodoTipoTren *R, int pTipoTren){
    if(R == nullptr){
        return ;
    }
    if(R->TipoTren == pTipoTren){
        PreordenArbolTren(R->Trenes);
        return ;
    }
    if(R->TipoTren>pTipoTren){
        EncotrarTipoTren(R->Hizq, pTipoTren);
    }
    if(R->TipoTren<pTipoTren){
        EncotrarTipoTren(R->Hder, pTipoTren);
    }
}

void ServicioDeTrenes::PreordenArbolTren(nodoTren *R){
    if(R==nullptr){
        return;
    }else{
        msgConsultarTrenes+="Nombre: "+R->Nombre+" CodTren: "+to_string(R->CodTren)+" Pais: "+to_string(R->CodPaisSalida)+" Ciudad: "+to_string(R->CodCiudadSalida)+"\n";
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
            return "El Tren no existe\n";
        }
    }else{
        return "El tipo de tren no existe\n";
    }
}

string ServicioDeTrenes::ModificarEstadoMigratorio(int pPasaporte, string pEstadoMigratorio){
    if(pEstadoMigratorio == "1" or pEstadoMigratorio =="0"){
        cout<<pPasaporte;
//        pnodoUsuario usuario = new nodoUsuario(1,1,pPasaporte,"1",pEstadoMigratorio);
//        usuarios.Modificar(usuario);
        return "El estado migratorio ha sido modificado!\n";
    }else{
        return "El estado migratorio es invalido\n";
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

string ServicioDeTrenes::ConsultarPrecioConexion(int Pais, int ciudad, int conexion){
    paises.msgConsultarConexion = "";
    if(paises.validaPais(Pais)){
        if(paises.validaCiudad(Pais,ciudad)){
            paises.buscarPaisParaConexion(paises.Raiz,Pais,ciudad,conexion, 2, 0);
        }else{
            return "La ciudad no se encuentra registrada";
        }
    }else{
        return "El pais no se encuentra registrado";
    }
    if(paises.msgConsultarConexion == ""){
        return "La conexion no se encuentra registrada";
    }
    return paises.msgConsultarConexion;
}


string ServicioDeTrenes::ModificarPrecioConexion(int pCodPais, int pCodCiudad, int pCodConexion, int precio){
    paises.msgConsultarConexion = "";
    if(paises.validaCiudad(pCodPais, pCodPais)){
        paises.buscarPaisParaConexion(paises.Raiz, pCodPais, pCodCiudad, pCodConexion, 3, precio);
    }else{
        return "No se ha encontrado la ciudad";
    }

    if(paises.msgConsultarConexion == ""){
        return "La conexion no existe";
    }
    return paises.msgConsultarConexion;
}

string ServicioDeTrenes::ModificarTiempoConexion(int pCodPais, int pCodCiudad, int pCodConexion, int tiempo){
    paises.msgConsultarConexion="";
    if(paises.validaCiudad(pCodPais, pCodPais)){
        paises.buscarPaisParaConexion(paises.Raiz, pCodPais, pCodCiudad, pCodConexion, 4, tiempo);
    }else{
        return "No se ha encontrado la ciudad";
    }
    if(paises.msgConsultarConexion == ""){
        return "La conexion no existe";
    }
    return paises.msgConsultarConexion;
}


void ServicioDeTrenes::ReporteConsultarPaises(){
    msgConsultarPaises="";
    PreordenArbolPais(paises.Raiz);


    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Paises.txt");
    ficheroSalida <<"Reporte de paises: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgConsultarPaises;
    ficheroSalida.close();
}

void ServicioDeTrenes::ReporteConsultarCiudades(int pCodPais){
    msgConsultarCiudades="";
    EncontrarPais(paises.Raiz, pCodPais);

    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ciudades.txt");
    ficheroSalida <<"Reporte de Ciudades: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgConsultarCiudades;
    ficheroSalida.close();
}

void ServicioDeTrenes::ReporteConsultarConexiones(int pCodPais, int pCodCiudad){
    msgConsultarConexiones="";
    EncontrarPaisParaConexion(paises.Raiz, pCodPais,pCodCiudad);

    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Conexiones.txt");
    ficheroSalida <<"Reporte de Conexiones: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgConsultarConexiones;
    ficheroSalida.close();
}

void ServicioDeTrenes::ReporteConsultarTrenes(int pTipoTren){
    msgConsultarTrenes = "";
    EncotrarTipoTren(trenes.Raiz, pTipoTren);

    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Trenes.txt");
    ficheroSalida <<"Reporte de Trenes: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgConsultarTrenes;
    ficheroSalida.close();
}

void ServicioDeTrenes::ReporteConsultarNumAsientosTren(int pTipoTren, int pCodTren){
    msgConsultarNumAsientos = "";
    EncotrarTipoTrenParaTren(trenes.Raiz,pTipoTren, pCodTren);

    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Numero asientos.txt");
    ficheroSalida <<"Reporte de numero  de asientos: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgConsultarNumAsientos;
    ficheroSalida.close();
}

string ServicioDeTrenes::reporteRutaMas()
{

    string msg = "";
    ofstream archivo;
    archivo.open("Reporte_de_rutas_mas_utilizadas.txt",ios::out);
    if(archivo.fail()){
        msg = "Falla al crear el archivo";
    }else{
        archivo<<reservas.consultarRutasMasUtilizadas();
        msg = "Archivo creado!";
    }
    archivo.close();
    return msg;

}

string ServicioDeTrenes::reporteRutaMenos()
{
    string msg = "";
    ofstream archivo;
    archivo.open("Reporte_de_rutas_menos_utilizadas.txt",ios::out);
    if(archivo.fail()){
        msg = "Falla al crear el archivo";
    }else{
        archivo<<reservas.consultarRutasMaenosUtilizadas();
        msg = "Archivo creado!";
    }
    archivo.close();
    return msg;
}

string ServicioDeTrenes::reporteUsuariosMas()
{
    string msg = "";
    ofstream archivo;
    archivo.open("Reporte_de_usuario_mas_activo.txt",ios::out);
    if(archivo.fail()){
        msg = "Falla al crear el archivo";
    }else{
        archivo<<reservas.consultarUsuarioMasActivo();
        msg = "Archivo creado!";
    }
    archivo.close();
    return msg;
}

string ServicioDeTrenes::reporteUsuariosMenos()
{
    string msg = "";
    ofstream archivo;
    archivo.open("Reporte_de_usuario_menos_activo.txt",ios::out);
    if(archivo.fail()){
        msg = "Falla al crear el archivo";
    }else{
        archivo<<reservas.consultarUsuarioMenosActivo();
        msg = "Archivo creado!";
    }
    archivo.close();
    return msg;
}

string ServicioDeTrenes::reporteCantCompras(){
    string msg = "";
    ofstream archivo;
    archivo.open("Reporte_de_cantidad_compras_usuarios.txt",ios::out);
    if(archivo.fail()){
        msg = "Falla al crear el archivo";
    }else{
        archivo<<reservas.consultarCantCompras();
        msg = "Archivo creado!";
    }
    archivo.close();
    return msg;
}

string ServicioDeTrenes::reporteTrenMas(){
    string msg = "";
    ofstream archivo;
    archivo.open("Reporte_de_tre_mas_utilizado.txt",ios::out);
    if(archivo.fail()){
        msg = "Falla al crear el archivo";
    }else{
        archivo<<reservas.consultarTrenMasUtilizado();
        msg = "Archivo creado!";
    }
    archivo.close();
    return msg;
}
string ServicioDeTrenes::reporteTrenMenos(){
    string msg = "";
    ofstream archivo;
    archivo.open("Reporte_de_tre_menos_utilizado.txt",ios::out);
    if(archivo.fail()){
        msg = "Falla al crear el archivo";
    }else{
        archivo<<reservas.consultarTrenMenosUtilizado();
        msg = "Archivo creado!";
    }
    archivo.close();
    return msg;
}
string ServicioDeTrenes::reporteCiudadMas(){
    string msg = "";
    ofstream archivo;
    archivo.open("Reporte_de_ciudad_mas_visitada.txt",ios::out);
    if(archivo.fail()){
        msg = "Falla al crear el archivo";
    }else{
        archivo<<reservas.consultarCiudadMasVisitada();
        msg = "Archivo creado!";
    }
    archivo.close();
    return msg;
}

void ServicioDeTrenes::ReporteUltimoPaisInsertado(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultimo Pais Insertado.txt");
    ficheroSalida <<"Reporte Consultar Ultimo Pais Insertado: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgUltimoPaisInsertado;
    ficheroSalida.close();
}

void ServicioDeTrenes::ReporteUltimaCiudadInsertada(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultima Ciudad Insertada.txt");
    ficheroSalida <<"Reporte Consultar Ultima Ciudad Insertada: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgUltimaCiudadInsertada;
    ficheroSalida.close();
}

void ServicioDeTrenes::ReporteUltimaConexionInsertada(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultima Conexion Insertada.txt");
    ficheroSalida <<"Reporte Consultar Ultima Conexion Insertada: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgUltimaConexionInsertada;
    ficheroSalida.close();
}

void ServicioDeTrenes::ReporteUltimoTrenInsertado(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultimo Tren Insertado.txt");
    ficheroSalida <<"Reporte Consultar Ultimo Tren Insertado: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgUltimoTrenInsertado;
    ficheroSalida.close();
}

void ServicioDeTrenes::ReporteUltimoTipoTrenInsertado(){
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultimo Tipo de Tren Insertado.txt");
    ficheroSalida <<"Reporte Consultar Ultimo Tipo de Tren Insertado: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << msgUltimoTipoTrenInsertado;
    ficheroSalida.close();
}

void ServicioDeTrenes::ReporteConsultarPrecioConexion(int pCodPais, int pCodCiudad, int pCodConexion){
    paises.msgConsultarConexion = "";
    ConsultarPrecioConexion(pCodPais,pCodCiudad,pCodConexion);

    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Precio Conexion.txt");
    ficheroSalida <<"Reporte del precio de una conexion: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << paises.msgConsultarConexion;
    ficheroSalida.close();
}

string ServicioDeTrenes::realizarReservacion(string pComprador, string pCodTipoTren, string pCodRuta, string pCodTren, string pPasajeros, string pNumAsientos, string pPasaportes)
{
    string pasaportes[50];
    char separador = '-';
    int contador = 0;
    for(size_t p=0, q=0; p!=pPasaportes.npos; p=q){
        pasaportes[contador] = pPasaportes.substr(p+(p!=0),(q=pPasaportes.find(separador, p+1))-p-(p!=0));
        contador++;
    }
    if(trenes.validaTren(stoi(pCodTipoTren),stoi(pCodTren))){
        if(trenes.validaRuta(stoi(pCodTipoTren),stoi(pCodTren),stoi(pCodRuta))){
            if(trenes.validaAsientos(stoi(pCodTipoTren),stoi(pCodTren),stoi(pNumAsientos))){
                bool realizar = true;
                int cant = 0;
                while(pasaportes[cant] != "" && cant < contador){
                    cant++;
                }
//                for (int i = 0;i<cant;i++) {
//                    if(usuarios.ValidaReserva(pPasaportes[i],pCodPaisSalida,pCodCiudadSalida)){
//                        realizar = true;
//                    }else{
//                        return "El pasajero con pasaporte "+pPasaportes[i]+" tiene el estado migratorio manchado o no se encuentra en el punto de salida";
//                    }
//                }
                if(realizar){
                    string codigo = reservas.InsertarFinal(pComprador, pCodTipoTren, pCodTren, pCodRuta, pPasajeros, pNumAsientos, pasaportes);
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
                     int precio = trenes.obtenerPrecio(stoi(aux->codigoTipoTren),stoi(aux->codigoTren),stoi(aux->codigoRuta));
                     return "El monto a pagar seria de: " + to_string(precio*aux->pasajeros);
                 }else {
                     return "La reserva ya ha sido facturada!";
                 }

             }
             aux = aux->siguiente;
         }
         return "No se encontro el codigo de reservacion.";
    }
}
