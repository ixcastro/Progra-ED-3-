#include "facturar.h"
#include "ui_facturar.h"
#include <string>
#include <sstream>
#include <fstream>

Facturar::Facturar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Facturar)
{
    ui->setupUi(this);
    socket = new Socket();
}

Facturar::~Facturar()
{
    delete ui;
}

void Facturar::on_btFacturar_clicked()
{
    string codF= ui->txtCodFactura->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!codF.empty()){
        string msg = socket->controlador("59;"+codF);
        QString qstr = QString::fromStdString(msg);
        ofstream ficheroSalida;
        ficheroSalida.open ("Factura.txt");
        ficheroSalida << msg;
        ficheroSalida.close();
        QMessageBox::information(this,"Notificación",qstr);
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el número de identificación");
    }
}
