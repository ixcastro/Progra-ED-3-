#include "window_login.h"
#include "ui_window_login.h"
#include "socketadmin.h"
#include <QMessageBox>
#include "window_main.h"

window_logIn::window_logIn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_logIn)
{
    ui->setupUi(this);
}

window_logIn::~window_logIn()
{
    delete ui;
}

void window_logIn::on_ingresar_clicked()
{
    if(ui->lineEdit->text() == "" ){
        QMessageBox* q = new QMessageBox();
        q->setText("Inserte texto");
        q->show();
    } else {
        int pCod = ui->lineEdit->text().toInt();

        QJsonObject record;
        record.insert("CodAdmin",pCod);
        QJsonDocument docIN(record);
        QJsonDocument D = socketAdmin::getInstance()->request(docIN);

        QJsonObject ob = D.object();
        if(ob.take("Respuesta") == "T"){
            window_main* w = new window_main();
            w->show();
            this->hide();

        }else{
            QMessageBox* q = new QMessageBox();
            q->setText("Error");
            q->show();
        }
    }
}
