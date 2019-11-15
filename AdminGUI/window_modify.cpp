#include "window_modify.h"
#include "ui_window_modify.h"
#include "window_modify_basket.h"
#include "window_modify_percentage.h"
#include "window_modify_price.h"

window_modify::window_modify(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_modify)
{
    ui->setupUi(this);
}

window_modify::~window_modify()
{
    delete ui;
}

void window_modify::on_back_clicked()
{
    hide();
}

void window_modify::on_precio_clicked()
{
    window_modify_price*w = new window_modify_price();
    w->show();
}

void window_modify::on_porcentaje_clicked()
{
    window_modify_percentage*w = new window_modify_percentage();
    w->show();
}

void window_modify::on_canasta_clicked()
{
    window_modify_basket*w = new window_modify_basket();
    w->show();
}
