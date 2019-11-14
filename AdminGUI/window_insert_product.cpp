#include "window_insert_product.h"
#include "ui_window_insert_product.h"

window_insert_product::window_insert_product(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_insert_product)
{
    ui->setupUi(this);
}

window_insert_product::~window_insert_product()
{
    delete ui;
}

void window_insert_product::on_save_clicked()
{

}
