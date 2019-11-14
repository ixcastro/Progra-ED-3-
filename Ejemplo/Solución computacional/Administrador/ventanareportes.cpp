#include "ventanareportes.h"
#include "ui_ventanareportes.h"

VentanaReportes::VentanaReportes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaReportes)
{
    ui->setupUi(this);
    socket = new Socket();
    ui->txtCodTipoTren->setValidator(new QIntValidator(0,10000,this));
    ui->txtCodTren->setValidator(new QIntValidator(0,10000,this));
}

VentanaReportes::~VentanaReportes()
{
    delete ui;
}

void VentanaReportes::on_btGenerarReportePaises_clicked()
{
    socket->conexion();
    ui->txtPaises->clear();
    string mensaje = socket->controlador("19");
    ui->txtPaises->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Paises.txt");
    ficheroSalida <<"Reporte de paises: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteCiudades_clicked()
{
    socket->conexion();
    ui->txtCiudades->clear();
    string mensaje = socket->controlador("20");
    ui->txtCiudades->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ciudades.txt");
    ficheroSalida <<"Reporte de Ciudades: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteConexiones_clicked()
{
    socket->conexion();
    ui->txtConexiones->clear();
    string mensaje = socket->controlador("21");
    ui->txtConexiones->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Conexiones.txt");
    ficheroSalida <<"Reporte de Conexiones: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteTrenes_clicked()
{
    socket->conexion();
    ui->txtTrenes->clear();
    string mensaje = socket->controlador("22");
    ui->txtTrenes->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Trenes.txt");
    ficheroSalida <<"Reporte de Trenes: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReportePrecios_clicked()
{
    ui->txtPrecio->clear();
    string pais = ui->txtCodPais->text().toUtf8().constData();
    string ciudad = ui->txtCodCiudad->text().toUtf8().constData();
    string conexion = ui->txtCodConexion->text().toUtf8().constData();
    if(!pais.empty() && !ciudad.empty() && !conexion.empty()){
        socket->conexion();
        string mensaje = socket->controlador("23;"+pais+";"+ciudad+";"+conexion);
        ui->txtPrecio->insertPlainText(QString::fromStdString(mensaje));
        ofstream ficheroSalida;
        ficheroSalida.open ("Reporte Consultar Precio Conexion.txt");
        ficheroSalida <<"Reporte del precio de una conexion: \n";
        ficheroSalida <<"***************************************\n";
        ficheroSalida << mensaje;
        ficheroSalida.close();
    }else{
        QMessageBox::information(this,"Error","Debe llenar los espacios");
    }
}

void VentanaReportes::on_btGenerarReportePrecios_2_clicked()
{
    ui->txtPrecio_2->clear();
    socket->conexion();
    int tipo = stoi(ui->txtCodTipoTren->text().toUtf8().constData());
    int tren = stoi(ui->txtCodTren->text().toUtf8().constData());
    if(tipo > 0 && tren >0 ){
        string mensaje = socket->controlador("24;"+to_string(tipo)+";"+to_string(tren));
        ui->txtPrecio_2->insertPlainText(QString::fromStdString(mensaje));
        ofstream ficheroSalida;
        ficheroSalida.open ("Reporte Consultar Numero asientos.txt");
        ficheroSalida <<"Reporte de numero  de asientos: \n";
        ficheroSalida <<"***************************************\n";
        ficheroSalida << mensaje;
        ficheroSalida.close();
    }else{
        QMessageBox::information(this,"Error","Debe llenar los espacios");
    }
}

void VentanaReportes::on_btGenerarReporteUltimoPais_clicked()
{
    socket->conexion();
    ui->txtUltimoPais->clear();
    string mensaje = socket->controlador("25");
    ui->txtUltimoPais->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultimo Pais Insertado.txt");
    ficheroSalida <<"Reporte Consultar Ultimo Pais Insertado: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteUltimaCiudad_clicked()
{
    socket->conexion();
    ui->txtUltimaCiudad->clear();
    string mensaje = socket->controlador("26");
    ui->txtUltimaCiudad->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultima Ciudad Insertada.txt");
    ficheroSalida <<"Reporte Consultar Ultima Ciudad Insertada: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteUltimaConexion_clicked()
{
    socket->conexion();
    ui->txtUltimaConexion->clear();
    string mensaje = socket->controlador("27");
    ui->txtUltimaConexion->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultima Conexion Insertada.txt");
    ficheroSalida <<"Reporte Consultar Ultima Conexion Insertada: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteUltimoTipo_clicked()
{
    socket->conexion();
    ui->txtUltimoTipo->clear();
    string mensaje = socket->controlador("28");
    ui->txtUltimoTipo->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultimo Tipo de Tren Insertado.txt");
    ficheroSalida <<"Reporte Consultar Ultimo Tipo de Tren Insertado: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteUltimoTren_clicked()
{
    socket->conexion();
    ui->txtUltimoTren->clear();
    string mensaje = socket->controlador("29");
    ui->txtUltimoTren->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida.open ("Reporte Consultar Ultimo Tren Insertado.txt");
    ficheroSalida <<"Reporte Consultar Ultimo Tren Insertado: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida << mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteRutaMas_clicked()
{
    socket->conexion();
    ui->txtUltimoRutaMas->clear();
    string mensaje = socket->controlador("30");
    ui->txtUltimoRutaMas->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida <<"Reporte de rutas mas utilizadas: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida<<mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteRutaMenos_clicked()
{
    socket->conexion();
    ui->txtUltimoRutaMas->clear();
    string mensaje = socket->controlador("31");
    ui->txtUltimoRutaMas->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida <<"Reporte de rutas menos utilizadas: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida<<mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReportePaisMas_clicked()
{
    socket->conexion();
    ui->txtPaisMas->clear();
    string mensaje = socket->controlador("32");
    ui->txtPaisMas->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida <<"Reporte de pais mas visitado: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida<<mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteCiudadMas_clicked()
{
    socket->conexion();
    ui->txtCiudadMas->clear();
    string mensaje = socket->controlador("33");
    ui->txtCiudadMas->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida <<"Reporte de ciudad mas visitada: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida<<mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteUsuarioMas_clicked()
{
    socket->conexion();
    ui->txtUsuarioMas->clear();
    string mensaje = socket->controlador("34");
    ui->txtUsuarioMas->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida <<"Reporte del usuario mas activo: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida<<mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteUsuarioMenos_clicked()
{
    socket->conexion();
    ui->txtUsuarioMenos->clear();
    string mensaje = socket->controlador("35");
    ui->txtUsuarioMenos->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida <<"Reporte del usuario menos activo: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida<<mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteCantComprasUsuario_clicked()
{
    socket->conexion();
    ui->txtCantComprasUsuario->clear();
    string mensaje = socket->controlador("36");
    ui->txtCantComprasUsuario->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida <<"Reporte de cantidad de compras por usuario: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida<<mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteTrenMas_clicked()
{
    socket->conexion();
    ui->txtTrenMas->clear();
    string mensaje = socket->controlador("37");
    ui->txtTrenMas->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida <<"Reporte de tren mas utilizado: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida<<mensaje;
    ficheroSalida.close();
}

void VentanaReportes::on_btGenerarReporteTrenMenos_clicked()
{
    socket->conexion();
    ui->txtTrenMenos->clear();
    string mensaje = socket->controlador("38");
    ui->txtTrenMenos->insertPlainText(QString::fromStdString(mensaje));
    ofstream ficheroSalida;
    ficheroSalida <<"Reporte de tren mas utilizado: \n";
    ficheroSalida <<"***************************************\n";
    ficheroSalida<<mensaje;
    ficheroSalida.close();
}
