#include "w_login.h"
#include "ui_w_login.h"

W_Login::W_Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::W_Login)
{
    ui->setupUi(this);
}

W_Login::~W_Login()
{
    delete ui;
}

