#include "window_select_product.h"
#include "ui_window_select_product.h"

window_select_product::window_select_product(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_select_product)
{
    ui->setupUi(this);
}

window_select_product::~window_select_product()
{
    delete ui;
}
