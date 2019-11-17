#include "window_delete_product.h"
#include "ui_window_delete_product.h"
#include "library.h"
#include "socketadmin.h"

window_delete_product::window_delete_product(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_delete_product)
{
    ui->setupUi(this);
    ui->halls->setEnabled(false);
    ui->prods->setEnabled(false);
    ui->pasilloButton->setEnabled(false);
    ui->prodButton->setEnabled(false);
    ui->save->setEnabled(false);
}

window_delete_product::~window_delete_product()
{
    delete ui;
}

void window_delete_product::on_start_clicked()
{
    QJsonObject ob;
    ob.insert("Pasillo","");
    QJsonDocument doc(ob);
    QJsonDocument doc2 = socketAdmin::getInstance()->request(doc);
    QJsonArray arr = doc2.array();

    for(int i = 0; i < arr.size(); i++){
        ui->halls->addItem(arr[i].toString());
    }
    ui->halls->setEnabled(true);
    ui->pasilloButton->setEnabled(true);
}

void window_delete_product::on_pasilloButton_clicked()
{
    ui->halls->setEnabled(false);
    ui->pasilloButton->setEnabled(false);
    ui->prods->setEnabled(true);
    ui->prodButton->setEnabled(true);

    QString name = ui->halls->currentText();

    QStringList lista = name.split("-");
    pasillo = lista.first().toInt();

    QJsonObject ob;
    ob.insert("Producto",pasillo);
    QJsonDocument doc(ob);
    QJsonDocument doc2 = socketAdmin::getInstance()->request(doc);
    QJsonArray arr = doc2.array();

    for(int i = 0; i < arr.size(); i++){
        ui->prods->addItem(arr[i].toString());
    }
}

void window_delete_product::on_prodButton_clicked()
{
    ui->prods->setEnabled(false);
    ui->prodButton->setEnabled(false);
    ui->save->setEnabled(true);

    QString name = ui->prods->currentText();

    QStringList lista = name.split("-");
    producto = lista.first().toInt();

}

void window_delete_product::on_save_clicked()
{
    QJsonObject recordObjects;
    recordObjects.insert("Pasillo",pasillo);
    recordObjects.insert("Producto",producto);

    QJsonObject record;
    record.insert("EliminarProducto",recordObjects);
    QJsonDocument docIN(record);
    QJsonDocument D = socketAdmin::getInstance()->request(docIN);
    QJsonObject ob = D.object();
    if(ob.take("Respuesta") == "T"){
        QMessageBox* q = new QMessageBox();
        q->setText("Producto eliminado");
        q->show();
    }
}

void window_delete_product::on_back_clicked()
{
    hide();
}
