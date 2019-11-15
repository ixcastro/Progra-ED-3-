#include "w_select.h"
#include "w_login.h"
#include "ui_w_select.h"

W_SELECT::W_SELECT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_SELECT)
{
    ui->setupUi(this);
}

W_SELECT::~W_SELECT()
{
    delete ui;
}

//TRY AGAIN
void W_SELECT::on_pushButton_clicked()
{
    W_LOGIN *a = new W_LOGIN();
    a->show();
    this->close();
}


// REGISTRARSE
void W_SELECT::on_pushButton_2_clicked()
{

}
