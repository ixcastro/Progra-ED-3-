#include "window_insert_product.h"
#include "ui_window_insert_product.h"
#include "socketadmin.h"
#include <QMessageBox>
#include <iostream>

using namespace std;

window_insert_product::window_insert_product(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_insert_product)
{
    ui->setupUi(this);
}

window_insert_product::~window_insert_product()
{
    delete ui;
}

void window_insert_product::on_save_clicked()
{
    if (ui->codeLine->text() == "" || ui->nameLine->text() == ""){
        QMessageBox* q = new QMessageBox();
        q->setText("Inserte texto");
        q->show();
    } else {
        int pCodProd = ui->codeLine->text().toInt();
        string pName = ui->nameLine->text().toStdString();

        QJsonObject recordObjects;
        recordObjects.insert("Ihall",QJsonValue::fromVariant(this->selectedHall));
        recordObjects.insert("Iprod",QJsonValue::fromVariant(pCodProd));
        recordObjects.insert("nameProd",QString::fromStdString(pName));
        QJsonObject record;
        record.insert("RegistrarProducto",recordObjects);
        QJsonDocument docIN(record);
        QJsonDocument D = socketAdmin::getInstance()->request(docIN);

        QJsonObject ob = D.object();
        if(ob.take("Respuesta") == "T"){
            QMessageBox* q = new QMessageBox();
            q->setText("Se ha registrado el producto");
            q->show();
        }else{
            QMessageBox* q = new QMessageBox();
            q->setText("Error existe un producto con este codigo");
            q->show();
        }
    }
}

void window_insert_product::setSelectHall(int n){
    selectedHall = n;
}
void window_insert_product::on_back_clicked()
{
    hide();
}
