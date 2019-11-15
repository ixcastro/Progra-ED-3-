#include "window_insert_brand.h"
#include "ui_window_insert_brand.h"
#include "library.h"
#include "socketadmin.h"
#include <QMessageBox>

window_insert_brand::window_insert_brand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_insert_brand)
{
    ui->setupUi(this);
}

void window_insert_brand::setSelectHall(int n){
    selectedHall = n;
}

void window_insert_brand::setSelectProd(int n){
    selectedProd = n;
}

window_insert_brand::~window_insert_brand()
{
    delete ui;
}

void window_insert_brand::on_pushButton_2_clicked()
{
    hide();
}

void window_insert_brand::on_save_clicked()
{
    if (ui->code->text() == "" || ui->name->text() == "" ||
        ui->price->text() == "" ||ui->stock->text() == "" ||
        ui->basket->text() == "" ||ui->gondola->text() == "" ){
            QMessageBox* q = new QMessageBox();
            q->setText("Inserte texto");
            q->show();
    } else {

        //Primer request
        QJsonObject recordObjects;
        recordObjects.insert("IcodBran",QJsonValue::fromVariant(ui->code->text().toInt()));
        recordObjects.insert("Ihall",QJsonValue::fromVariant(this->selectedHall));
        recordObjects.insert("Iprod",QJsonValue::fromVariant(this->selectedProd));
        recordObjects.insert("Iprecio",QJsonValue::fromVariant(ui->price->text().toInt()));
        recordObjects.insert("Icantidad",QJsonValue::fromVariant(ui->gondola->text().toInt()));
        recordObjects.insert("Nombre",QJsonValue::fromVariant(ui->name->text()));

        QJsonObject record;
        record.insert("RegistrarMarcaGondola",recordObjects);
        QJsonDocument docIN(record);
        QJsonDocument D = socketAdmin::getInstance()->request(docIN);

        QJsonObject ob = D.object();
        if(ob.take("Respuesta") == "T"){
            //Segundo request
            QJsonObject recordObjects2;
            recordObjects2.insert("IcodBran",QJsonValue::fromVariant(ui->code->text().toInt()));
            recordObjects2.insert("Ihall",QJsonValue::fromVariant(this->selectedHall));
            recordObjects2.insert("Iprod",QJsonValue::fromVariant(this->selectedProd));
            recordObjects2.insert("IisBask",QJsonValue::fromVariant(ui->basket->text().toInt()));
            recordObjects2.insert("Icantidad",QJsonValue::fromVariant(ui->stock->text().toInt()));
            recordObjects2.insert("Nombre",QJsonValue::fromVariant(ui->name->text()));

            QJsonObject record2;
            record2.insert("RegistrarMarcaInventario",recordObjects2);
            QJsonDocument docIN2(record2);
            QJsonDocument D2 = socketAdmin::getInstance()->request(docIN2);

            QJsonObject ob2 = D2.object();
            if(ob2.take("Respuesta") == "T"){
                QMessageBox* q = new QMessageBox();
                q->setText("Se ha registrado la marca");
                q->show();
            }else{
                QMessageBox* q = new QMessageBox();
                q->setText("Ocurrio un error en la insercion");
                q->show();
            }

        }else{
            QMessageBox* q = new QMessageBox();
            q->setText("Error existe una marca con este codigo");
            q->show();
        }
    }
}
