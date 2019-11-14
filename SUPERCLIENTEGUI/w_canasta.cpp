#include "w_canasta.h"
#include "ui_w_canasta.h"

W_Canasta::W_Canasta(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_Canasta)
{
    ui->setupUi(this);
}

W_Canasta::~W_Canasta()
{
    delete ui;
}
