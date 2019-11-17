#include "w_pathdj.h"
#include "ui_w_pathdj.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "socketadmin.h"

W_PATHDJ::W_PATHDJ(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_PATHDJ)
{
    ui->setupUi(this);
}

W_PATHDJ::~W_PATHDJ()
{
    delete ui;
}


// VERIFICA SI LAS CIUDADES SON CORRECTAS
void W_PATHDJ::on_pushButton_clicked()
{


    //
    cout<<"START"<<ui->lineEdit->text().toStdString()<<endl;
    cout<<"FINAL"<<ui->lineEdit_2->text().toStdString()<<endl;

    QJsonObject recordObjects;
    recordObjects.insert("START",QJsonValue::fromVariant( ui->lineEdit->text()));
    recordObjects.insert("FINAL",QJsonValue::fromVariant( ui->lineEdit_2->text()));
    QJsonObject record;
    record.insert("DJ",recordObjects);
    QJsonDocument docIN(record);
    QJsonDocument D = socketAdmin::getInstance()->request(docIN);
    QJsonObject ob = D.object();

    QString g = ob.take("Respuesta").toString();
    g.toStdString();

    cout<<g.toStdString()<<endl;

    //if(ob.take("Respuesta").toString() != ""){
        QMessageBox* q = new QMessageBox();
//        q->setText("DOCUMENTO GENERADO");
//        q->show();
        ui->listWidget->addItem("");
        ui->listWidget->addItem(g);
//    }else{
//        QMessageBox* q = new QMessageBox();
//        q->setText("Error");
//        q->show();

//       // ui->lineEdit_3->setText(g);
//    }



}
