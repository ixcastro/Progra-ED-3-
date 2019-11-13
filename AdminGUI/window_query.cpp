#include "window_query.h"
#include "ui_window_query.h"

window_query::window_query(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_query)
{
    ui->setupUi(this);
}

window_query::~window_query()
{
    delete ui;
}

void window_query::on_back_clicked()
{
    hide();
}
