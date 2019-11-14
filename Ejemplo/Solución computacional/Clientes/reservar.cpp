#include "reservar.h"
#include "ui_reservar.h"

Reservar::Reservar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reservar)
{
    ui->setupUi(this);
    socket = new Socket();
}

Reservar::~Reservar()
{
    delete ui;
}

void Reservar::on_btAP_clicked()
{
    AgregarP *ventana = new AgregarP;
    ventana->show();
}

void Reservar::on_btReservar_clicked()
{
    string codTT= ui->txtCodTT->toPlainText().toUtf8().constData();
    string codT= ui->txtCodT->toPlainText().toUtf8().constData();
    string codR= ui->txtCodR->toPlainText().toUtf8().constData();
    string codNP= ui->txtCodNP->toPlainText().toUtf8().constData();
    string codNA= ui->txtCodNA->toPlainText().toUtf8().constData();
    string codPas= ui->txtCodPas->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!codTT.empty()&&!codT.empty()&&!codR.empty()&&!codNP.empty()&&!codNA.empty()&&!codPas.empty()){
        string msg = socket->controlador("58;"+codPas+";"+ codTT+";"+ codR+";"+ codT+";"+ codNP+";"+ codNA);
        QString qstr = QString::fromStdString(msg);
        QMessageBox::information(this,"Notificación",qstr);
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el número de identificación");
    }
}
