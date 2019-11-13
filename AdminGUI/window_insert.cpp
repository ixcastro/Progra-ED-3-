#include "window_insert_client.h"
#include "window_insert_hall.h"
#include "window_insert.h"
#include "ui_window_insert.h"

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

}

void window_insert::on_insertarMarca_clicked()
{

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
