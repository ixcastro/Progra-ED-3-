#include "w_select.h"
#include "w_login.h"
#include "ui_w_select.h"
#include "w_registro.h"

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
     W_REGISTRO *a = new   W_REGISTRO ();
     a->show();
     this->close();

}
