#include "window_report.h"
#include "ui_window_report.h"

window_report::window_report(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_report)
{
    ui->setupUi(this);
}

window_report::~window_report()
{
    delete ui;
}

void window_report::on_pushButton_26_clicked()
{
    hide();
}
