#include "window_report_prodpas.h"
#include "ui_window_report_prodpas.h"
#include "library.h"
#include "socketadmin.h"

window_report_prodPas::window_report_prodPas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_report_prodPas)
{
    ui->setupUi(this);
    ui->save->setEnabled(false);
    ui->halls->setEnabled(false);
    ui->pasilloButton->setEnabled(false);
}

window_report_prodPas::~window_report_prodPas()
{
    delete ui;
}

void window_report_prodPas::on_start_clicked()
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

void window_report_prodPas::on_pasilloButton_clicked()
{
    QString name = ui->halls->currentText();

    QStringList lista = name.split("-");
    pasillo = lista.first().toInt();
    ui->save->setEnabled(true);
    ui->halls->setEnabled(false);
    ui->pasilloButton->setEnabled(false);
}

void window_report_prodPas::on_save_clicked()
{
    //request on server
    QJsonObject recordObjects;
    recordObjects.insert("Reporte","ProductosPasillo");
    recordObjects.insert("xProductos",pasillo);

    QJsonDocument docIN(recordObjects);
    QJsonDocument D = socketAdmin::getInstance()->request(docIN);

    QJsonObject ob = D.object();

    QMessageBox *q = new QMessageBox();
    q->setText(ob.take("Respuesta").toString());
    q->show();
}

void window_report_prodPas::on_back_clicked()
{
    hide();
}
