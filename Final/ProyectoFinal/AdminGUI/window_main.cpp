#include "window_main.h"
#include "window_report.h"
#include "window_modify.h"
#include "window_insert.h"
#include "window_delete.h"
#include "window_query.h"
#include "window_city.h"
#include "ui_window_main.h"

window_main::window_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_main)
{
    ui->setupUi(this);
}

window_main::~window_main()
{
    delete ui;
}

void window_main::on_insert_clicked()
{
    window_insert*w = new window_insert();
    w->show();
}

void window_main::on_modify_clicked()
{
    window_modify*w = new window_modify();
    w->show();
}

void window_main::on_delete_2_clicked()
{
    window_delete *w = new window_delete();
    w->show();
}

void window_main::on_query_clicked()
{
    window_query *w = new window_query();
    w->show();
}

void window_main::on_check_clicked()
{

}

void window_main::on_stock_clicked()
{

}

void window_main::on_report_clicked()
{
    window_report *w = new window_report();
    w->show();
}

void window_main::on_city_clicked()
{
    window_city *w = new window_city();
    w->show();
}

void window_main::on_close_clicked()
{
    exit(0);
}

void window_main::on_refresh_clicked()
{
    ui->queueClient->clear();

    QJsonObject ob;
    ob.insert("ClientesCola","");
    QJsonDocument doc(ob);
    QJsonDocument doc2 = socketAdmin::getInstance()->request(doc);
    QJsonArray arr = doc2.array();

    for(int i=0; i<arr.size(); i++){
        ui->queueClient->addItem(arr[i].toString());
    }

    QMessageBox *q = new QMessageBox();
    if(arr.size() == 0){
        q->setText("No hay clientes en la cola.");
    }else{
        q->setText("Cola actualizada.");
    }
    q->show();
}

void window_main::on_bill_clicked(){
    QJsonObject ob;
    ob.insert("Facturar","");
    QJsonDocument doc(ob);
    QJsonDocument doc2 = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = doc2.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}


