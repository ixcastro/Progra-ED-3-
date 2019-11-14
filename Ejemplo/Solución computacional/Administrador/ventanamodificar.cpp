#include "ventanamodificar.h"
#include "ui_ventanamodificar.h"

VentanaModificar::VentanaModificar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaModificar)
{
    ui->setupUi(this);
    socket = new Socket();
    ui->txtNumAsientos->setValidator(new QIntValidator(0,10000,this));
    ui->txtCodTrenAsientos->setValidator(new QIntValidator(0,10000,this));
    ui->txtCodTipoTrenAsientos->setValidator(new QIntValidator(0,10000,this));
    ui->txtPrecioNuevo->setValidator(new QIntValidator(0,10000,this));
    ui->txtNuevoTiempo->setValidator(new QIntValidator(0,10000,this));
    ui->txtCodTipoTrenRuta->setValidator(new QIntValidator(0,10000,this));
    ui->txtCodTrenRuta->setValidator(new QIntValidator(0,10000,this));
    ui->txtCodRuta->setValidator(new QIntValidator(0,10000,this));
    ui->txtNuevoPrecioRuta->setValidator(new QIntValidator(0,10000,this));
    ui->txtCodTipoTren->setValidator(new QIntValidator(0,10000,this));
    ui->txtCodTren->setValidator(new QIntValidator(0,10000,this));
}

VentanaModificar::~VentanaModificar()
{
    delete ui;
}

void VentanaModificar::on_btAceptarNumAsientos_clicked()
{
    socket->conexion();
    int codTipoTren = atoi(ui->txtCodTipoTrenAsientos->text().toUtf8().constData());
    int codTren = atoi(ui->txtCodTrenAsientos->text().toUtf8().constData());
    int numAsientos = atoi(ui->txtNumAsientos->text().toUtf8().constData());
    if(codTipoTren > 0 && codTren > 0 && numAsientos>0){
        string mensaje = socket->controlador("10;"+to_string(codTipoTren)+";"+to_string(codTren)+";"+to_string(numAsientos));
        if(mensaje == "El numero de asientos del tren "+to_string(codTren)+" ahora es: "+to_string(numAsientos)){
            QMessageBox::information(this,"Éxito",QString::fromStdString(mensaje));
        }else{
            QMessageBox::information(this,"Falló",QString::fromStdString(mensaje));
        }
    }else{
        QMessageBox::information(this,"Error","Todos los campos deben llenarse con números enteros");
    }
}

void VentanaModificar::on_btAceptarPrecio_clicked()
{
    socket->conexion();
    string codPais = ui->txtCodPaisPrecio->text().toUtf8().constData();
    string codCiudad = ui->txtCodCiudadPrecio->text().toUtf8().constData();
    string codConexion = ui->txtCodConexionPrecio->text().toUtf8().constData();
    int precio = atoi(ui->txtPrecioNuevo->text().toUtf8().constData());
    if(!codPais.empty()&& !codCiudad.empty() && !codConexion.empty()){
        if(precio > 0 ){
            string mensaje = socket->controlador("8;"+codPais+";"+codCiudad+";"+codConexion+";"+to_string(precio));
            QMessageBox::information(this,"!",QString::fromStdString(mensaje));
        }else{
            QMessageBox::information(this,"Error","El precio es inválido");
        }
    }else{
        QMessageBox::information(this,"Error","Todos los espacios deben llenarse");
    }
}

void VentanaModificar::on_btAceptarTiempo_clicked()
{
    socket->conexion();
    string codPaisSalida = ui->txtCodPaisSalida->toPlainText().toUtf8().constData();
    string codCiudadSalida = ui->txtCodCiudadSalida->toPlainText().toUtf8().constData();
    string codConexion = ui->txtCodConexion->toPlainText().toUtf8().constData();
    int nuevoTiempo = atoi(ui->txtNuevoTiempo->text().toUtf8().constData());
    if(!codPaisSalida.empty() && !codCiudadSalida.empty() && !codConexion.empty()){
        if(nuevoTiempo > 0 ){
            string mensaje = socket->controlador("9;"+codPaisSalida+";"+codCiudadSalida+";"+codConexion+";"+to_string(nuevoTiempo));
            QMessageBox::information(this,"!",QString::fromStdString(mensaje));
        }else{
            QMessageBox::information(this,"Error","El tiempo es inválido");
        }
    }else{
        QMessageBox::information(this,"Error","Todos los espacios deben llenarse");
    }

}

void VentanaModificar::on_btAceptarRuta_clicked()
{
    socket->conexion();
    int codTipoTren = atoi(ui->txtCodTipoTrenRuta->text().toUtf8().constData());
    int codTren = atoi(ui->txtCodTrenRuta->text().toUtf8().constData());
    int codRuta = atoi(ui->txtCodRuta->text().toUtf8().constData());
    int nuevoPrecio = atoi(ui->txtNuevoPrecioRuta->text().toUtf8().constData());
    if(codTipoTren > 0 && codTren > 0 && codRuta>0 && nuevoPrecio > 0){
        string mensaje = socket->controlador("11;"+to_string(codTipoTren)+";"+to_string(codTren)+";"+to_string(codRuta)+";"+to_string(nuevoPrecio));
        if(mensaje != "El tren no se ha encontrado!"){
            QMessageBox::information(this,"Éxito",QString::fromStdString(mensaje));
        }else{
            QMessageBox::information(this,"Falló",QString::fromStdString(mensaje));
        }
    }else{
        QMessageBox::information(this,"Error","Todos los campos deben llenarse con números enteros");
    }
}

void VentanaModificar::on_btAceptarTren_clicked()
{
    socket->conexion();
    int codTipoTren = atoi(ui->txtCodTipoTren->text().toUtf8().constData());
    int codTren = atoi(ui->txtCodTren->text().toUtf8().constData());
    string nombre = ui->txtNombreTren->text().toUtf8().constData();
    if(codTipoTren > 0 && codTren > 0){
        if(!nombre.empty()){
            string mensaje = socket->controlador("12;"+to_string(codTipoTren)+";"+to_string(codTren)+";"+nombre);
            if(mensaje == "El tren ha sido modificado exitosamente"){
                QMessageBox::information(this,"Éxito",QString::fromStdString(mensaje));
            }else{
                QMessageBox::information(this,"Fallo",QString::fromStdString(mensaje));
            }
        }else{
            QMessageBox::information(this,"Error","Debe llenar todos los espacios");
        }
    }else{
        QMessageBox::information(this,"Error","Debe llenar todos los espacios y el espacio de los códigos son números enteros");
    }
}

void VentanaModificar::on_btAceptarEstadoMigratorio_clicked()
{
    socket->conexion();
    string pasaporte = ui->txtPasaporte->text().toUtf8().constData();
    int estado = atoi(ui->comboEstado->currentText().toUtf8().constData());
    if(!pasaporte.empty()){
        string mensaje = socket->controlador("13;"+pasaporte+";"+to_string(estado));
        if(mensaje == "El estado migratorio ha sido modificado!"){
            QMessageBox::information(this,"Éxito",QString::fromStdString(mensaje));
        }else {
            QMessageBox::information(this,"Fallo",QString::fromStdString(mensaje));
        }
    }else{
        QMessageBox::information(this,"Error","Debe llenar el espacio del pasaporte");
    }
}
