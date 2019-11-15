#include "window_insert_client.h"
#include "ui_window_insert_client.h"
#include <QMessageBox>
#include "socketadmin.h"

window_insert_client::window_insert_client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_insert_client)
{
    ui->setupUi(this);
}

window_insert_client::~window_insert_client()
{
    delete ui;
}

void window_insert_client::on_pushButton_clicked()
{
    hide();
}

void window_insert_client::on_pushButton_2_clicked()
{
    if (ui->name->text() == "" || ui->ced->text() == "" ||
        ui->tel->text() == "" ||ui->correo->text() == "" || ui->city->text() == ""){
            QMessageBox* q = new QMessageBox();
            q->setText("Inserte texto");
            q->show();
    } else {

        QJsonObject recordObjects;
        recordObjects.insert("Cedula",QJsonValue::fromVariant(ui->ced->text().toInt()));
        recordObjects.insert("Nombre",QJsonValue::fromVariant(ui->name->text()));
        recordObjects.insert("CodigoCiudad",QJsonValue::fromVariant(ui->city->text().toInt()));
        recordObjects.insert("Phone",QJsonValue::fromVariant(ui->tel->text()));
        recordObjects.insert("Correo",QJsonValue::fromVariant(ui->correo->text()));

        QJsonObject record;
        record.insert("InsertarCliente",recordObjects);
        QJsonDocument docIN(record);
        QJsonDocument D = socketAdmin::getInstance()->request(docIN);

        QJsonObject ob = D.object();
        if(ob.take("Respuesta") == "T"){
            QMessageBox* q = new QMessageBox();
            q->setText("Se ha registrado el cliente");
            q->show();
        }else{
            QMessageBox* q = new QMessageBox();
            q->setText("Error, no se ha insertado el cliente");
            q->show();
        }

    }
}



