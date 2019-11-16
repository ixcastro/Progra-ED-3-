#include "w_registro.h"
#include "ui_w_registro.h"
#include "library.h"
#include "socketclient.h"
#include "QMessageBox"
#include "w_login.h"

W_REGISTRO::W_REGISTRO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_REGISTRO)
{
    ui->setupUi(this);
}

W_REGISTRO::~W_REGISTRO()
{
    delete ui;
}

void W_REGISTRO::on_pushButton_clicked()
{
    string NOMBRE = ui->lineEdit_2->text().toStdString();
    int CED  = ui->lineEdit_3->text().toInt();//INT
    string TEL = ui->lineEdit_4->text().toStdString();
    string CORREO = ui->lineEdit_5->text().toStdString();
    int CIUDAD = ui->lineEdit_6->text().toInt();//INT

    QJsonObject recordObjects;

    recordObjects.insert("Cedula",QJsonValue::fromVariant(CED));
    recordObjects.insert("Nombre",QJsonValue::fromVariant(NOMBRE.c_str()));
    recordObjects.insert("CodigoCiudad",QJsonValue::fromVariant(CIUDAD));
    recordObjects.insert("Phone",QJsonValue::fromVariant(TEL.c_str()));
    recordObjects.insert("Correo",QJsonValue::fromVariant(CORREO.c_str()));


    QJsonObject record;
    record.insert("EncolarCliente",recordObjects);
    QJsonDocument docIN(record);
    QJsonDocument D = SocketClient::getInstance()->request(docIN);
    QJsonObject ob = D.object();
    if(ob.take("Respuesta")=="T"){
        QMessageBox* q = new QMessageBox();
        q->setText("Se ha tomado los datos del cliente");
        q->show();
        //cout<<"emcolado"<<endl;
    }else{
        QMessageBox* q = new QMessageBox();
        q->setText("Error");
        q->show();
    }




}

void W_REGISTRO::on_pushButton_2_clicked()
{



    W_LOGIN *a = new W_LOGIN();
    a->show();
    this->close();



}












