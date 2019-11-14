#include "w_login.h"
#include "ui_w_login.h"

W_LOGIN::W_LOGIN(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::W_LOGIN)
{
    ui->setupUi(this);
}

W_LOGIN::~W_LOGIN()
{
    delete ui;
}

