#include "window_delete.h"
#include "ui_window_delete.h"

window_delete::window_delete(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_delete)
{
    ui->setupUi(this);
}

window_delete::~window_delete()
{
    delete ui;
}

void window_delete::on_back_clicked()
{
    hide();
}
