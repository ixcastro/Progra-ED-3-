#include "insert_pas.h"
#include "ui_insert_pas.h"

insert_Pas::insert_Pas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::insert_Pas)
{
    ui->setupUi(this);
}

insert_Pas::~insert_Pas()
{
    delete ui;
}


void insert_Pas::on_back_clicked()
{
    //this->
    close();
}
