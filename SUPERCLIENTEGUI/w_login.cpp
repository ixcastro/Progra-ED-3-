#include "w_login.h"
#include "ui_w_login.h"
#include  "library.h"
#include "socketclient.h"
#include "qmessagebox.h"
#include "w_menu.h"
#include "w_select.h"

W_LOGIN::W_LOGIN(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::W_LOGIN)
{
    ui->setupUi(this);
}

W_LOGIN::~W_LOGIN()
{
    delete ui;
}


void W_LOGIN::on_pushButton_clicked()
{
    string msg = ui->lineEdit->text().toStdString();


    //getText
    QJsonObject recordObjects;
    recordObjects.insert("Cedula",msg.c_str());

    QJsonDocument docIN(recordObjects);

    QJsonDocument D = SocketClient::getInstance()->request(docIN);

    QJsonObject ob = D.object();
    if(ob.take("Respuesta") == "T"){
        W_MENU *a = new   W_MENU();
        a->ced(msg.c_str());
        a->show();
        this->close();
    }else{
        W_SELECT *a = new W_SELECT();
        a->show();
        this->close();
    }
}
