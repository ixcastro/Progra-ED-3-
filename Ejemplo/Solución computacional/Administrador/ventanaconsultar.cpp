#include "ventanaconsultar.h"
#include "ui_ventanaconsultar.h"

VentanaConsultar::VentanaConsultar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaConsultar)
{
    ui->setupUi(this);
    socket = new Socket();
    ui->textEdit_5->setReadOnly(true);
    ui->txtConsPrec_2->setReadOnly(true);
    ui->txtRutas_3->setReadOnly(true);
    ui->txtConsultarT_3->setReadOnly(true);
}

VentanaConsultar::~VentanaConsultar()
{
    delete ui;
}

void VentanaConsultar::on_btnConsT_3_clicked()
{
    ui->txtConsultarT_3->clear();
    string codTT= ui->txtCodT_5->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!codTT.empty()){
        string msg = socket->controlador("18;"+ codTT);
        cout<<msg<<endl;
        if(msg==" "){
            ui->txtConsultarT_3->insertPlainText("No se hayaron trenes");
        }else{
            ui->txtConsultarT_3->insertPlainText(QString::fromStdString(msg));
        }
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el tipo de tren");
    }
}

void VentanaConsultar::on_btConsR_3_clicked()
{
    string codTT= ui->txtCodTTren_3->toPlainText().toUtf8().constData();
    string codT= ui->txtCodTren_3->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!codTT.empty()&&!codT.empty()){
        string msg = socket->controlador("17;"+ codTT+ ";" +codT);
        ui->txtRutas_3->insertPlainText(QString::fromStdString(msg));
    }else{
      QMessageBox::information(this,"Error","Debe ingresar lo solicitado");
    }
}

void VentanaConsultar::on_btConsPre_2_clicked()
{
    string codTT= ui->txtTT->toPlainText().toUtf8().constData();
    string codT= ui->txtT->toPlainText().toUtf8().constData();
    string codR= ui->txtR->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!codTT.empty()&&!codT.empty()&&!codR.empty()){
        string msg = socket->controlador("14;"+ codTT+ ";" +codT+ ";" +codR);
        ui->txtConsPrec_2->insertPlainText(QString::fromStdString(msg));
    }else{
      QMessageBox::information(this,"Error","Debe ingresar lo solicitado");
    }
}

void VentanaConsultar::on_btCancelarPrecio_6_clicked()
{
    ui->textEdit_4->clear();
    string pais = ui->txtCodPaisSalida_5->toPlainText().toUtf8().constData();
    if(!pais.empty()){
        socket->conexion();
        string mensaje = socket->controlador("15;"+pais);
        ui->textEdit_4->insertPlainText(QString::fromStdString(mensaje));
    }else{
        QMessageBox::information(this, "Error", "Debe llenar el espacio solicitado");
    }
}

void VentanaConsultar::on_btCancelarPrecio_7_clicked()
{
    string codP= ui->txtCodPaisSalida_7->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!codP.empty()){
        string msg = socket->controlador("16;"+ codP);
        ui->textEdit_5->insertPlainText(QString::fromStdString(msg));
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el tipo de tren");
    }
}
