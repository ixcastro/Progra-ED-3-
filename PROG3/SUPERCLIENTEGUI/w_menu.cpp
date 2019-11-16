#include "w_menu.h"
#include "ui_w_menu.h"
#include  "library.h"
#include "socketclient.h"
#include "w_pasillos.h"
#include "w_login.h"

W_MENU::W_MENU(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_MENU)
{
    ui->setupUi(this);
}

W_MENU::~W_MENU()
{
    delete ui;
}

void W_MENU::on_pushButton_clicked()
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

void W_MENU::on_pushButton_2_clicked()
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

void W_MENU::on_pushButton_3_clicked()
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

void W_MENU::ced(string ced){
     CED = ced;
}


void W_MENU::on_pushButton_4_clicked()
{
    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PASILLO------//
    //-----------------INDICA-QUE-QUEREMOS-VER-LOS-PASILLOS--//

    QJsonObject recordObject;
    recordObject.insert("Pasillo","");
    QJsonDocument docIN(recordObject);
    QJsonDocument D = SocketClient::getInstance()->request(docIN);
    QJsonArray ob = D.array();

    W_PASILLOS *a = new  W_PASILLOS();
    a->ced(CED);
    a->shareButton(ob,4);
    a->show();


}

void W_MENU::on_pushButton_5_clicked()
{
    W_LOGIN *a = new W_LOGIN();
    a->show();
    this->close();
    this->close();
}
