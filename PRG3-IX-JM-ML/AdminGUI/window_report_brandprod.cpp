#include "window_report_brandprod.h"
#include "ui_window_report_brandprod.h"
#include "library.h"
#include "socketadmin.h"

window_report_brandProd::window_report_brandProd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_report_brandProd)
{
    ui->setupUi(this);
    ui->save->setEnabled(false);
    ui->halls->setEnabled(false);
    ui->pasilloButton->setEnabled(false);
    ui->prods->setEnabled(false);
    ui->prodButton->setEnabled(false);
}

window_report_brandProd::~window_report_brandProd()
{
    delete ui;
}

void window_report_brandProd::on_start_clicked()
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

void window_report_brandProd::on_pasilloButton_clicked()
{
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

    ui->prods->setEnabled(true);
    ui->prodButton->setEnabled(true);
}

void window_report_brandProd::on_prodButton_clicked()
{
    QString name = ui->prods->currentText();

    QStringList lista = name.split("-");
    producto = lista.first().toInt();
    ui->save->setEnabled(true);
}

void window_report_brandProd::on_save_clicked()
{
    //request on server
    QJsonObject recordObjects;
    recordObjects.insert("Reporte","MarcasProducto");
    recordObjects.insert("xPasillo",pasillo);
    recordObjects.insert("xProducto",producto);

    QJsonDocument docIN(recordObjects);
    QJsonDocument D = socketAdmin::getInstance()->request(docIN);

    QJsonObject ob = D.object();

    QMessageBox *q = new QMessageBox();
    q->setText(ob.take("Respuesta").toString());
    q->show();
}

void window_report_brandProd::on_back_clicked()
{
    hide();
}
