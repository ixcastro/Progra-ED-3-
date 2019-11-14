#include "window_modify.h"
#include "ui_window_modify.h"

window_modify::window_modify(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_modify)
{
    ui->setupUi(this);
}

window_modify::~window_modify()
{
    delete ui;
}

void window_modify::on_back_clicked()
{
    hide();
}
