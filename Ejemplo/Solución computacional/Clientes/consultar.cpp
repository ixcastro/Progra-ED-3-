#include "consultar.h"
#include "ui_consultar.h"

Consultar::Consultar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Consultar)
{
    ui->setupUi(this);
    socket = new Socket();
}

Consultar::~Consultar()
{
    delete ui;
}



void Consultar::on_btConsPaises_clicked()
{
    socket->conexion();
    string msg = socket->controlador("51");
    ui->txtConsultarPaises->insertPlainText(QString::fromStdString(msg));
    ui->txtConsultarPaises->setReadOnly(true);
}

void Consultar::on_btCons_clicked()
{
    socket->conexion();
    string msg = socket->controlador("51");
    ui->txtConsultarPaises->insertPlainText(QString::fromStdString(msg));
    ui->txtConsultarPaises->setReadOnly(true);
}

void Consultar::on_btnConsT_clicked()
{
    string codTT= ui->txtCodT->toPlainText().toUtf8().constData();
    socket->conexion(); 
    if(!codTT.empty()){
        string msg = socket->controlador("54;"+ codTT);
        ui->txtConsultarT->insertPlainText(QString::fromStdString(msg));
        ui->txtConsultarT->setReadOnly(true);
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el tipo de tren"); 
    }
}

void Consultar::on_btConsNA_clicked()
{
    string codTT= ui->txtCodTT->toPlainText().toUtf8().constData();
    string codT= ui->txtCodT_2->toPlainText().toUtf8().constData();
    socket->conexion(); 
    if(!codTT.empty()&&!codT.empty()){
        string msg = socket->controlador("55;"+ codTT+ ";" +codT);
        ui->txtCNA->insertPlainText(QString::fromStdString(msg));
        ui->txtCNA->setReadOnly(true);
    }else{
      QMessageBox::information(this,"Error","Debe ingresar lo solicitado");
    }
}

void Consultar::on_btConsR_clicked()
{
    string codTT= ui->txtCodTTren->toPlainText().toUtf8().constData();
    string codT= ui->txtCodTren->toPlainText().toUtf8().constData();
    socket->conexion(); 
    if(!codTT.empty()&&!codT.empty()){
        string msg = socket->controlador("56;"+ codTT+ ";" +codT);
        ui->txtRutas->insertPlainText(QString::fromStdString(msg));
        ui->txtRutas->setReadOnly(true);
    }else{
      QMessageBox::information(this,"Error","Debe ingresar lo solicitado");
    }
}

void Consultar::on_btCancelarPrecio_5_clicked()
{
    string codP= ui->txtCodPaisSalida_2->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!codP.empty()){
        string msg = socket->controlador("16;"+ codP);
        ui->textEdit_2->insertPlainText(QString::fromStdString(msg));
        ui->textEdit_2->setReadOnly(true);
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el tipo de tren");
    }
}

void Consultar::on_btCancelarPrecio_4_clicked()
{
    ui->textEdit_3->clear();
    string pais = ui->txtCodPaisSalida_3->toPlainText().toUtf8().constData();
    if(!pais.empty()){
        socket->conexion();
        string mensaje = socket->controlador("15;"+pais);
        ui->textEdit_3->insertPlainText(QString::fromStdString(mensaje));
        ui->textEdit_3->setReadOnly(true);
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el código del país");
    }
}

void Consultar::on_btConsPre_clicked()
{
    ui->txtConsPrec->clear();
    string pais = ui->txtPais->toPlainText().toUtf8().constData();
    string ciudad = ui->txtCiudad->toPlainText().toUtf8().constData();
    string conexion = ui->txtCone->toPlainText().toUtf8().constData();
    if(!pais.empty() && !ciudad.empty() && !conexion.empty()){
        socket->conexion();
        string mensaje = socket->controlador("100;"+pais+";"+ciudad+";"+conexion);
        ui->txtConsPrec->insertPlainText(QString::fromStdString(mensaje));
    }else{
        QMessageBox::information(this, "Error", "Debe llenar el espacio solicitado");
    }
}
