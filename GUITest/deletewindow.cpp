#include "deletewindow.h"
#include "ui_deletewindow.h"

deleteWindow::deleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deleteWindow)
{
    ui->setupUi(this);
}

deleteWindow::~deleteWindow()
{
    delete ui;
}
