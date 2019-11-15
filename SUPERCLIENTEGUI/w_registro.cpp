#include "w_registro.h"
#include "ui_w_registro.h"

W_REGISTRO::W_REGISTRO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_REGISTRO)
{
    ui->setupUi(this);
}

W_REGISTRO::~W_REGISTRO()
{
    delete ui;
}

void W_REGISTRO::on_pushButton_clicked()
{

}
