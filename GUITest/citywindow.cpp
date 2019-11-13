#include "citywindow.h"
#include "ui_citywindow.h"

cityWindow::cityWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cityWindow)
{
    ui->setupUi(this);
}

cityWindow::~cityWindow()
{
    delete ui;
}
