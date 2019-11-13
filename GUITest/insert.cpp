#include "insert_pas.h"
#include "insert.h"
#include "ui_insert.h"

insert::insert(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::insert)
{
    ui->setupUi(this);
}

insert::~insert()
{
    delete ui;
}


void insert::on_back_clicked()
{
    hide();
}


void insert::on_insertarPas_clicked()
{
    insert_Pas*w = new insert_Pas();
    w->show();
    //this->setEnabled(false);

    //if (w->close()){
    //    this->setEnabled(true);
    //}
}
