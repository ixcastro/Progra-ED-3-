#include "mysocket.h"
#include "window_insert_hall.h"
#include "ui_window_insert_hall.h"
#include "socketadmin.h"
#include <QMessageBox>

window_insert_hall::window_insert_hall(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_insert_hall)
{
    ui->setupUi(this);
}

window_insert_hall::~window_insert_hall()
{
    delete ui;
}

void window_insert_hall::on_back_clicked()
{
    hide();
}

void window_insert_hall::on_save_clicked()
{
    int pCod = 23;
    string pName = "frutas";
    //getText
    QJsonObject recordObjects;
    recordObjects.insert("CodPas",QJsonValue::fromVariant(pCod));
    recordObjects.insert("Nombre",QString::fromStdString(pName));
    QJsonObject record;
    record.insert("RegistrarPasillo",recordObjects);
    QJsonDocument docIN(record);

    QJsonDocument D = socketAdmin::getInstance()->request(docIN);

    QJsonObject ob = D.object();
    if(ob.take("Respuesta") == "T"){
        QMessageBox* q = new QMessageBox();
        q->setText("Correcto");
        q->show();
    }else{
        QMessageBox* q = new QMessageBox();
        q->setText("Incorrecto");
        q->show();
    }

}
