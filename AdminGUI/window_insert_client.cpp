#include "window_insert_client.h"
#include "ui_window_insert_client.h"

window_insert_client::window_insert_client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_insert_client)
{
    ui->setupUi(this);
}

window_insert_client::~window_insert_client()
{
    delete ui;
}

void window_insert_client::on_pushButton_clicked()
{
    hide();
}
