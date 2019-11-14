#include "buscarr.h"
#include "ui_buscarr.h"
#include <iostream>

using namespace std;
BuscarR::BuscarR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuscarR)
{
    ui->setupUi(this);
    socket = new Socket();
}

BuscarR::~BuscarR()
{
    delete ui;
}

void BuscarR::on_btCancelarPrecio_5_clicked()
{
    string codTT= ui->txtCodTT->toPlainText().toUtf8().constData();
    string codT= ui->txtCodT->toPlainText().toUtf8().constData();
    string codR= ui->txtCodPS->toPlainText().toUtf8().constData();
    string codNP= ui->txtCodCS->toPlainText().toUtf8().constData();
    string codNA= ui->txtCodPL->toPlainText().toUtf8().constData();
    string codPas= ui->txtCodCL->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!codTT.empty()&&!codT.empty()&&!codR.empty()&&!codNP.empty()&&!codNA.empty()&&!codPas.empty()){
        string msg = socket->controlador("60;"+codTT+";"+ codT+";"+ codR+";"+ codNP+";"+ codNA+";"+ codPas);
        QString qstr = QString::fromStdString(msg);
        QMessageBox::information(this,"Notificación",qstr);
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el número de identificación");
    }
}
