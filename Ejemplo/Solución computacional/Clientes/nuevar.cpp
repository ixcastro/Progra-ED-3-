#include "nuevar.h"
#include "ui_nuevar.h"
#include <iostream>

using namespace std;


NuevaR::NuevaR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NuevaR)
{
    ui->setupUi(this);
}

NuevaR::~NuevaR()
{
    delete ui;
    socket = new Socket();
}


void NuevaR::on_btCancelarPrecio_5_clicked()
{
    string codPS= ui->txtCodPS->toPlainText().toUtf8().constData();
    string codCS= ui->txtCodCS->toPlainText().toUtf8().constData();
    string codPL= ui->txtCodPL->toPlainText().toUtf8().constData();
    string codCL= ui->txtCodCL->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!codPS.empty()&&!codCS.empty()&&!codPL.empty()&&!codCL.empty()){
        string msg = socket->controlador("61;"+codPS+";"+ codCS+";"+ codPL+";"+ codCL);
        QString qstr = QString::fromStdString(msg);
        QMessageBox::information(this,"Notificación",qstr);
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el número de identificación");
    }
}

void NuevaR::on_btCancelarPrecio_6_clicked()
{
    string codPS= ui->txtCodPS_2->toPlainText().toUtf8().constData();
    string codCS= ui->txtCodCS_2->toPlainText().toUtf8().constData();
    string codPL= ui->txtCodPL_2->toPlainText().toUtf8().constData();
    string codCL= ui->txtCodCL_2->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!codPS.empty()&&!codCS.empty()&&!codPL.empty()&&!codCL.empty()){
        string msg = socket->controlador("62;"+codPS+";"+ codCS+";"+ codPL+";"+ codCL);
        QString qstr = QString::fromStdString(msg);
        QMessageBox::information(this,"Notificación",qstr);
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el número de identificación");
    }
}

void NuevaR::on_btCancelarPrecio_7_clicked()
{
    string codPS= ui->txtCodPS_3->toPlainText().toUtf8().constData();
    string codCS= ui->txtCodCS_3->toPlainText().toUtf8().constData();
    string codPL= ui->txtCodPL_3->toPlainText().toUtf8().constData();
    string codCL= ui->txtCodCL_3->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!codPS.empty()&&!codCS.empty()&&!codPL.empty()&&!codCL.empty()){
        string msg = socket->controlador("63;"+codPS+";"+ codCS+";"+ codPL+";"+ codCL);
        QString qstr = QString::fromStdString(msg);
        QMessageBox::information(this,"Notificación",qstr);
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el número de identificación");
    }
}
