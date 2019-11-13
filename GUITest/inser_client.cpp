#include "inser_client.h"
#include "ui_inser_client.h"

inser_client::inser_client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inser_client)
{
    ui->setupUi(this);
}

inser_client::~inser_client()
{
    delete ui;
}
