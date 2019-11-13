#include "window_city.h"
#include "ui_window_city.h"

window_city::window_city(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_city)
{
    ui->setupUi(this);
}

window_city::~window_city()
{
    delete ui;
}

void window_city::on_back_clicked()
{
    hide();
}
