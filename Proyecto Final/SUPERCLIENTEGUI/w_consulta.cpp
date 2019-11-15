#include "w_consulta.h"
#include "ui_w_consulta.h"
#include  "library.h"
#include "socketclient.h"
#include "w_pasillos.h"
#include "w_login.h"

W_CONSULTA::W_CONSULTA(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_CONSULTA)
{
    ui->setupUi(this);
}

W_CONSULTA::~W_CONSULTA()
{
    delete ui;
}

void W_CONSULTA::on_pushButton_clicked()
{
    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PASILLO------//
    //-----------------INDICA-QUE-QUEREMOS-VER-LOS-PASILLOS--//

    QJsonObject recordObject;
    recordObject.insert("Pasillo","");
    QJsonDocument docIN(recordObject);
    QJsonDocument D = SocketClient::getInstance()->request(docIN);
    QJsonArray ob = D.array();

    W_PASILLOS *a = new  W_PASILLOS();
    a->shareButton(ob,1);
    a->show();
}



void W_CONSULTA::on_pushButton_2_clicked()
{
    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PASILLO------//
    //-----------------INDICA-QUE-QUEREMOS-VER-LOS-PASILLOS--//

    QJsonObject recordObject;
    recordObject.insert("Pasillo","");
    QJsonDocument docIN(recordObject);
    QJsonDocument D = SocketClient::getInstance()->request(docIN);
    QJsonArray ob = D.array();

    W_PASILLOS *a = new  W_PASILLOS();
    a->shareButton(ob,2);
    a->show();

}


void W_CONSULTA::on_pushButton_3_clicked()
{
    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PASILLO------//
    //-----------------INDICA-QUE-QUEREMOS-VER-LOS-PASILLOS--//

    QJsonObject recordObject;
    recordObject.insert("Pasillo","");
    QJsonDocument docIN(recordObject);
    QJsonDocument D = SocketClient::getInstance()->request(docIN);
    QJsonArray ob = D.array();

    W_PASILLOS *a = new  W_PASILLOS();
    a->shareButton(ob,3);
    a->show();

}

void W_CONSULTA::on_pushButton_4_clicked()
{
    W_LOGIN *a = new W_LOGIN();
    a->show();
    this->close();
}
