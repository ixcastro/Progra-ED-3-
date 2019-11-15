#include "window_query.h"
#include "ui_window_query.h"
#include "window_query_price.h"
#include "library.h"
#include "window_query_percentage.h"
#include "window_query_basket.h"

window_query::window_query(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_query)
{
    ui->setupUi(this);
}

window_query::~window_query()
{
    delete ui;
}

void window_query::on_back_clicked()
{
    hide();
}

void window_query::on_insertarPas_clicked()
{
    window_query_price* w = new window_query_price();
    w->show();
}

void window_query::on_insertarProd_clicked()
{
    window_query_percentage* w = new window_query_percentage();
    w->show();
}

void window_query::on_insertarMarca_clicked()
{
    window_query_basket* w = new window_query_basket();
    w->show();
}
