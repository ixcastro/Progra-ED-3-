#include "w_cantidad.h"
#include "ui_w_cantidad.h"

W_CANTIDAD::W_CANTIDAD(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_CANTIDAD)
{
    ui->setupUi(this);
}

W_CANTIDAD::~W_CANTIDAD()
{
    delete ui;
}


void W_CANTIDAD::PATH(string Path){
    PATHC = Path;
}


void W_CANTIDAD::on_pushButton_clicked()
{
    ui->lineEdit->text().toStdString();




}
