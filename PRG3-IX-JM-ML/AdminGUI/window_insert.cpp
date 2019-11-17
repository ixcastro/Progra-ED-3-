#include "window_insert_client.h"
#include "window_insert_hall.h"
#include "window_insert.h"
#include "ui_window_insert.h"
#include "window_select_hall.h"
#include "socketadmin.h"
#include "window_insert_brand.h"
#include <QMessageBox>

window_insert::window_insert(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_insert)
{
    ui->setupUi(this);
}

window_insert::~window_insert()
{
    delete ui;
}

void window_insert::on_insertarPas_clicked()
{
    window_insert_hall *w = new window_insert_hall();
    w->show();
}

void window_insert::on_insertarProd_clicked()
{
    QJsonObject record;
    record.insert("Pasillo","");
    QJsonDocument docIN(record);
    QJsonDocument D = socketAdmin::getInstance()->request(docIN);
    QJsonArray a = D.array();

    window_select_hall *w = new window_select_hall();
    w->addButtons(a);
    w->show();
}

void window_insert::on_insertarMarca_clicked()
{
    QJsonObject record;
    record.insert("Pasillo","");
    QJsonDocument docIN(record);
    QJsonDocument D = socketAdmin::getInstance()->request(docIN);
    QJsonArray a = D.array();

    window_select_hall *w = new window_select_hall();
    w->addButtonsHalls(a);
    w->show();
}

void window_insert::on_insertarCliente_clicked()
{
    window_insert_client *w = new window_insert_client();
    w->show();

}

void window_insert::on_back_clicked()
{
    hide();
}

void window_insert::on_solicitudes_clicked()
{
    QJsonObject record;
    record.insert("RegistrarCliente","");
    QJsonDocument docIN(record);
    QJsonDocument D = socketAdmin::getInstance()->request(docIN);
    QJsonObject ob = D.object();

    QMessageBox* q = new QMessageBox();
    q->setText(ob.take("Respuesta").toString());
    q->show();
}
