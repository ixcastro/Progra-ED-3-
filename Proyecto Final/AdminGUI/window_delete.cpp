#include "window_delete.h"
#include "ui_window_delete.h"
#include "window_delete_client.h"
#include "window_delete_product.h"
#include "window_delete_brand.h"

window_delete::window_delete(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_delete)
{
    ui->setupUi(this);
}

window_delete::~window_delete()
{
    delete ui;
}

void window_delete::on_back_clicked()
{
    hide();
}

void window_delete::on_insertarCliente_clicked()
{
    window_delete_client* w = new window_delete_client();
    w->show();
}


void window_delete::on_insertarProd_clicked()
{
    window_delete_product*w = new window_delete_product();
    w->show();
}

void window_delete::on_insertarMarca_clicked()
{
    window_delete_brand*w = new window_delete_brand();
    w->show();
}

void window_delete::on_insertarPas_clicked()
{

}
