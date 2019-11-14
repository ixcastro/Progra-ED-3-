#include "ventanaagregar.h"
#include "ui_ventanaagregar.h"

VentanaAgregar::VentanaAgregar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaAgregar)
{
    ui->setupUi(this);
    socket = new Socket();
}

VentanaAgregar::~VentanaAgregar()
{
    delete ui;
}

void VentanaAgregar::on_btAceptarPais_clicked()
{
    socket->conexion();
    string codigo = ui->txtCodPais->toPlainText().toUtf8().constData();
    string nombre = ui->txtNombrePais->toPlainText().toUtf8().constData();
    if(!codigo.empty() && !nombre.empty()){
        string mensaje = socket->controlador("1;"+codigo+";"+nombre);
        if(mensaje != "El pais "+nombre+" ya esta registrado"){
            QMessageBox::information(this,"Éxito",QString::fromStdString(mensaje));
        }else{
            QMessageBox::information(this,"Fallo",QString::fromStdString(mensaje));
        }
    }else {
        QMessageBox::information(this,"Error","Debe ingresar el nombre y el código");
    }
}

void VentanaAgregar::on_btAceptarCi_clicked()
{
    socket->conexion();
    string codigoPais = ui->txtCodPaisCiudad->toPlainText().toUtf8().constData();
    string codigoCiudad = ui->txtCodCiudad->toPlainText().toUtf8().constData();
    string nombre = ui->txtNombreCiudad->toPlainText().toUtf8().constData();
    if(!codigoPais.empty() && !codigoCiudad.empty() && !nombre.empty()){
        string mensaje = socket->controlador("2;"+codigoPais+";"+codigoCiudad+";"+nombre);
        if(mensaje != "La ciudad "+nombre+"ya esta registrada"){
            QMessageBox::information(this,"Éxito",QString::fromStdString(mensaje));
        }else{
            QMessageBox::information(this,"Fallo",QString::fromStdString(mensaje));
        }
    }else {
        QMessageBox::information(this,"Error","Debe llenar los espacios");
    }
}

void VentanaAgregar::on_btAceptarCo_clicked()
{
    socket->conexion();
    string codPaisSalida = ui->txtCodPaisSalida->toPlainText().toUtf8().constData();
    string codCiudadSalida = ui->txtCodCiudadSalida->toPlainText().toUtf8().constData();
    string codConexion = ui->txtCodConexion->toPlainText().toUtf8().constData();
    string codPaisDestino = ui->txtCodPaisDestino->toPlainText().toUtf8().constData();
    string codCiudadDestino = ui->txtCodCiudadDestino->toPlainText().toUtf8().constData();
    string tiempo = ui->txtTiempo->toPlainText().toUtf8().constData();
    string precio = ui->txtPrecio->toPlainText().toUtf8().constData();
    if(!codPaisSalida.empty() && !codCiudadSalida.empty() && !codConexion.empty()
            && !codPaisDestino.empty() && !codCiudadDestino.empty() && !tiempo.empty()
            && !precio.empty()){
        int t = atoi(tiempo.c_str());
        int p = atoi(precio.c_str());
        if(t>0 && p>0){
            string mensaje = socket->controlador("3;"+codPaisSalida+";"+codCiudadSalida+";"+codConexion+";"+codPaisDestino+";"+codCiudadDestino+";"+to_string(t)+";"+to_string(p));
            QMessageBox::information(this,"!",QString::fromStdString(mensaje));
        }else{
            QMessageBox::information(this,"Error","En el precio y el tiempo deben ser números enteros");
        }
    }else{
        QMessageBox::information(this,"!","Debe llenar todos los espacios");
    }
}

void VentanaAgregar::on_btAceptarTipo_clicked()
{
    socket->conexion();
    int tipo = atoi(ui->txtTipo->toPlainText().toUtf8().constData());
    if(tipo>0){
        string mensaje = socket->controlador("4;"+to_string(tipo));
        QMessageBox::information(this,"!",QString::fromStdString(mensaje));
    }else{
        QMessageBox::information(this,"Error","Código de tipo de tren inválido");
    }
}

void VentanaAgregar::on_btAceptarTren_clicked()
{
    socket->conexion();
    int codTipo = atoi(ui->txtTipoTren->toPlainText().toUtf8().constData());
    int codTren = atoi(ui->txtCodigoTren->toPlainText().toUtf8().constData());
    string nombre = ui->txtNombreTren->toPlainText().toUtf8().constData();
    int numAsientos = atoi(ui->txtNumAsientos->toPlainText().toUtf8().constData());
    string paisSalida = ui->txtPaisSalidaTren->toPlainText().toUtf8().constData();
    string ciudadSalida = ui->txtCiudadSalidaTren->toPlainText().toUtf8().constData();
    if(codTipo > 0 && codTren>0 && !nombre.empty() && numAsientos>0 && !paisSalida.empty() && !ciudadSalida.empty()){
        string mensaje = socket->controlador("5;"+to_string(codTipo)+";"+to_string(codTren)+";"+nombre+";"+to_string(numAsientos)+";"+paisSalida+";"+ciudadSalida);
        if(mensaje == "El tren "+nombre+" ha sido agregado!"){
            QMessageBox::information(this,"Éxito!",QString::fromStdString(mensaje));
        }else{
            QMessageBox::information(this,"!",QString::fromStdString(mensaje));
        }
    }else{
        if(codTipo <=0 || codTipo<=0 || numAsientos<=0){
            QMessageBox::information(this,"Error","Los espacios de código de tipo de tren, código de tren y el número de asientos debe ser numéricos");
        }else{
            QMessageBox::information(this,"!","Todos los espacios deben llenarse");
        }
    }
}

void VentanaAgregar::on_btAceptarRuta_clicked()
{
    socket->conexion();
    int codTipo = atoi(ui->txtCodTipoRuta->toPlainText().toUtf8().constData());
    int codTren = atoi(ui->txtCodTrenRuta->toPlainText().toUtf8().constData());
    int codRuta = atoi(ui->txtCodRuta->toPlainText().toUtf8().constData());
    string paisSalida = ui->txtCodPaisSalidaRuta->toPlainText().toUtf8().constData();
    string ciudadSalida = ui->txtCodCiudadSalidaRuta->toPlainText().toUtf8().constData();
    string paisDestino = ui->txtCodPaisDestinoRuta->toPlainText().toUtf8().constData();
    string ciudadDestino = ui->txtCodCiudadDestinoRuta->toPlainText().toUtf8().constData();
    int precio = atoi(ui->txtPrecioRuta->toPlainText().toUtf8().constData());
    if(codTipo > 0 && codTren >0 && codRuta>0 && precio >0){
        if(!paisSalida.empty() && !ciudadSalida.empty() && !paisDestino.empty() && !ciudadDestino.empty()){
            string mensaje = socket->controlador("6;"+to_string(codTipo)+";"+to_string(codTren)+";"+
                                                 to_string(codRuta)+";"+paisSalida+";"+ciudadSalida+";"+
                                                 paisDestino+";"+ciudadDestino+";"+to_string(precio));
            if(mensaje == "La ruta se ha registrado exitosamente"){
                QMessageBox::information(this,"Éxito",QString::fromStdString(mensaje));
            }else{
                QMessageBox::information(this,"!¡",QString::fromStdString(mensaje));
            }
        }else{
            QMessageBox::information(this,"Error","Todos los espacios deben llenarse");
        }
    }else{
        QMessageBox::information(this,"Error","Los espacios de código de tipo de tren, código de tren, código de ruta y precio debe ser numéricos");
    }
}

void VentanaAgregar::on_btAceptarAtraccion_clicked()
{
    socket->conexion();
    string pais = ui->txtCodPaisAtraccion->toPlainText().toUtf8().constData();
    string ciudad = ui->txtCodCiudadAtraccion->toPlainText().toUtf8().constData();
    string codAtraccion = ui->txtCodAtraccion->toPlainText().toUtf8().constData();
    string nombre = ui->txtNombreAtraccion->toPlainText().toUtf8().constData();
    int precio = atoi(ui->txtPrecioAtraccion->toPlainText().toUtf8().constData());
    if(precio >0){
        if(!pais.empty() && !ciudad.empty() && !codAtraccion.empty() && !nombre.empty()){
            string mensaje = socket->controlador("7;"+pais+";"+ciudad+";"+codAtraccion+";"+nombre+";"+to_string(precio));
            QMessageBox::information(this,"!",QString::fromStdString(mensaje));
        }
    }else{
        QMessageBox::information(this,"Error","El precio debe ser un valor numérico");
    }
}
