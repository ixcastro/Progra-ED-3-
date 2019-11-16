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
    cout<<"START"<<ui->lineEdit_2->text().toStdString()<<endl;

    QJsonObject recordObjects;
    recordObjects.insert("START",QJsonValue::fromVariant( ui->lineEdit->text()));
    recordObjects.insert("FINAL",QJsonValue::fromVariant( ui->lineEdit_2->text()));
    QJsonObject record;
    record.insert("DJ",recordObjects);
    QJsonDocument docIN(record);
    QJsonDocument D = socketAdmin::getInstance()->request(docIN);
    QJsonObject ob = D.object();

    if(ob.take("Respuesta") == "F"){
        QMessageBox* q = new QMessageBox();
        q->setText("Error");
        q->show();
    }else{
        QMessageBox* q = new QMessageBox();
        q->setText("DOCUMENTO GENERADO");
        q->show();
//        QStringList propertyNames;
//        propertyNames.append(ob["Respuesta"].toString());
//        cout<< propertyNames.first().toStdString()<<endl;
//        qWarning() << tr("QJsonObject[appName] of description: ") << ob.take("Respuesta");
//         QJsonValue subobj = ob["Respuesta"];
//         qWarning() << subobj.toString();

      //  ui->listWidget->addItem("");
    }



}
