#include "w_porcentaje.h"
#include "ui_w_porcentaje.h"

W_PORCENTAJE::W_PORCENTAJE(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_PORCENTAJE)
{
    ui->setupUi(this);
}

W_PORCENTAJE::~W_PORCENTAJE()
{
    delete ui;
}
