#include "window_modify_percentage.h"
#include "ui_window_modify_percentage.h"
#include "library.h"
#include "socketadmin.h"

window_modify_percentage::window_modify_percentage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_modify_percentage)
{
    ui->setupUi(this);
    ui->halls->setEnabled(false);
    ui->prods->setEnabled(false);
    ui->marca->setEnabled(false);
    ui->pasilloButton->setEnabled(false);
    ui->prodButton->setEnabled(false);
    ui->marcaButton->setEnabled(false);
    ui->lineEdit->setEnabled(false);
}

window_modify_percentage::~window_modify_percentage()
{
    delete ui;
}

void window_modify_percentage::on_start_clicked()
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

void window_modify_percentage::on_pasilloButton_clicked()
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

void window_modify_percentage::on_prodButton_clicked()
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

void window_modify_percentage::on_marcaButton_clicked()
{
    QString name = ui->marca->currentText();

    QStringList lista = name.split("-");
    marca = lista.first().toInt();

    ui->marca->setEnabled(false);
    ui->marcaButton->setEnabled(false);
    ui->lineEdit->setEnabled(true);
}

void window_modify_percentage::on_save_clicked()
{
    if (ui->lineEdit->text() == "" ){
        QMessageBox *q = new QMessageBox();
        q->setText("Ingrese texto");
        q->show();
    } else {

        QJsonObject recordObjects;
        recordObjects.insert("IcodBran",QJsonValue::fromVariant(marca));
        recordObjects.insert("Ihall",QJsonValue::fromVariant(pasillo));
        recordObjects.insert("Icodprod",QJsonValue::fromVariant(producto));
        recordObjects.insert("Ipercentage",QJsonValue::fromVariant(ui->lineEdit->text()));


        QJsonObject record;
        record.insert("newPercentage",recordObjects);
        QJsonDocument docIN(record);
        QJsonDocument D = socketAdmin::getInstance()->request(docIN);

        QJsonObject ob = D.object();
        if (ob.take("Respuesta") == "T"){
            QMessageBox *q = new QMessageBox();
            q->setText("Porcentaje modificado");
            q->show();
        } else {
            QMessageBox *q = new QMessageBox();
            q->setText("Error, intente mas tarde");
            q->show();
        }
    }
}

void window_modify_percentage::on_back_clicked()
{
    hide();
}