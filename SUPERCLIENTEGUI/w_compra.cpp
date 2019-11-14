#include "w_compra.h"
#include "ui_w_compra.h"

W_COMPRA::W_COMPRA(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_COMPRA)
{
    ui->setupUi(this);
}

W_COMPRA::~W_COMPRA()
{
    delete ui;
}
