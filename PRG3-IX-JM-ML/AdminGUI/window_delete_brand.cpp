#include "window_delete_brand.h"
#include "ui_window_delete_brand.h"
#include "library.h"
#include "socketadmin.h"

window_delete_brand::window_delete_brand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_delete_brand)
{
    ui->setupUi(this);
    ui->halls->setEnabled(false);
    ui->prods->setEnabled(false);
    ui->marca->setEnabled(false);
    ui->pasilloButton->setEnabled(false);
    ui->prodButton->setEnabled(false);
    ui->marcaButton->setEnabled(false);
}

window_delete_brand::~window_delete_brand()
{
    delete ui;
}

void window_delete_brand::on_start_clicked()
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

void window_delete_brand::on_pasilloButton_clicked()
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

void window_delete_brand::on_prodButton_clicked()
{
    ui->prods->setEnabled(false);
    ui->prodButton->setEnabled(false);
    ui->marca->setEnabled(true);
    ui->marcaButton->setEnabled(true);

    QString name = ui->prods->currentText();

    QStringList lista = name.split("-");
    producto = lista.first().toInt();

    QJsonObject recordObjects;
    recordObjects.insert("Pasillo",QJsonValue::fromVariant(pasillo));
    recordObjects.insert("Producto",QJsonValue::fromVariant(producto));

    QJsonObject record;
    record.insert("Marca",recordObjects);

    QJsonDocument doc(record);
    QJsonDocument doc2 = socketAdmin::getInstance()->request(doc);
    QJsonArray arr = doc2.array();

    for(int i = 0; i < arr.size(); i++){
        ui->marca->addItem(arr[i].toString());
    }
}

void window_delete_brand::on_marcaButton_clicked()
{
    QString name = ui->marca->currentText();

    QStringList lista = name.split("-");
    marca = lista.first().toInt();

    ui->marca->setEnabled(false);
    ui->marcaButton->setEnabled(false);
    ui->save->setEnabled(true);
}

void window_delete_brand::on_save_clicked()
{
    QJsonObject recordObjects;
    recordObjects.insert("Pasillo",pasillo);
    recordObjects.insert("Producto",producto);
    recordObjects.insert("Marca",marca);

    QJsonObject record;
    record.insert("EliminarMarca",recordObjects);
    QJsonDocument docIN(record);
    QJsonDocument D = socketAdmin::getInstance()->request(docIN);
    QJsonObject ob = D.object();
    if(ob.take("Respuesta") == "T"){
        QMessageBox* q = new QMessageBox();
        q->setText("Marca eliminada");
        q->show();
    }
    //request de eliminado
}

void window_delete_brand::on_back_clicked()
{

}
