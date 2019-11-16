#include "window_delete_hall.h"
#include "ui_window_delete_hall.h"
#include "library.h"
#include "socketadmin.h"

window_delete_hall::window_delete_hall(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_delete_hall)
{
    ui->setupUi(this);
    ui->pushButton_4->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
}

window_delete_hall::~window_delete_hall()
{
    delete ui;
}

void window_delete_hall::on_pushButton_clicked()
{
    QJsonObject ob;
    ob.insert("Pasillo","");
    QJsonDocument doc(ob);
    QJsonDocument doc2 = socketAdmin::getInstance()->request(doc);
    QJsonArray arr = doc2.array();

    for(int i = 0; i < arr.size(); i++){
        ui->comboBox->addItem(arr[i].toString());
    }
    ui->comboBox->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}

void window_delete_hall::on_pushButton_2_clicked()
{
    ui->comboBox->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_4->setEnabled(true);
    name = ui->comboBox->currentText();
}



void window_delete_hall::on_pushButton_4_clicked()
{
    cout<<name.toStdString()<<endl;
    QJsonObject recordObjects;
    QStringList lista = name.split("-");
    cout<<lista.first().toStdString()<<endl;
    recordObjects.insert("Pasillo",lista.first().toInt());
    QJsonObject record;
    record.insert("EliminarPasillo",recordObjects);
    QJsonDocument docIN(record);
    QJsonDocument D = socketAdmin::getInstance()->request(docIN);
    QJsonObject ob = D.object();
    if(ob.take("Respuesta") == "T"){
        QMessageBox* q = new QMessageBox();
        q->setText("Pasillo eliminado");
        q->show();
    }

}
