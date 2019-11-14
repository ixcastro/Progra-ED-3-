#include "wlogin.h"
#include "ui_wlogin.h"
#include  "library.h"
#include "socketclient.h"
#include "qmessagebox.h"
//#include "w_menu.h"

WLogin::WLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WLogin)
{
    ui->setupUi(this);
}

WLogin::~WLogin()
{
    delete ui;
}


void WLogin::on_pushButton_clicked()
{
    string msg = ui->lineEdit->text().toStdString();


    //getText
    QJsonObject recordObjects;
    recordObjects.insert("Cedula",msg.c_str());

    QJsonDocument docIN(recordObjects);

    QJsonDocument D = SocketClient::getInstance()->request(docIN);

    QJsonObject ob = D.object();
    if(ob.take("Respuesta") == "T"){
       // w_Menu *a = new  w_Menu();
       // a->show();
        //this->close();
    }else{
        QMessageBox* q = new QMessageBox();
        q->setText("Incorrecto");
        q->show();
    }

}
