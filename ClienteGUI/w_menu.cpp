#include "w_menu.h"
#include "ui_w_menu.h"
#include  "library.h"
#include "socketclient.h"
#include "qmessagebox.h"
#include "wpasillos.h"

w_Menu::w_Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::w_Menu)
{
    ui->setupUi(this);
}

w_Menu::~w_Menu()
{
    delete ui;
}

void w_Menu::on_pushButton_clicked()
{

    //------SE-ESCRIBE-EL-JSON-PARA-EL-DATO-DEL-PASILLO------//
    //-----------------INDICA-QUE-QUEREMOS-VER-LOS-PASILLOS--//

    QJsonObject recordObject;
    recordObject.insert("Pasillo","");
    QJsonDocument docIN(recordObject);
    QJsonDocument D = SocketClient::getInstance()->request(docIN);
    QJsonArray ob = D.array();

    wPasillos *a = new   wPasillos();
    a->shareButton(ob);
    a->show();



}
