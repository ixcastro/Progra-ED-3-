#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"
#include "insert.h"
#include "modify.h"
#include "deletewindow.h"
#include "report.h"
#include "consultar.h"

AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

void AdminMainWindow::close(){
    exit(0);
}

void AdminMainWindow::on_insert_clicked()
{
    insert*w = new insert();
    w->show();
}

void AdminMainWindow::on_modify_clicked()
{
    modify*w = new modify();
    w->show();
}

void AdminMainWindow::on_delete_2_clicked()
{
    deleteWindow *w = new deleteWindow();
    w->show();
}

void AdminMainWindow::on_query_clicked()
{
    consultar *w = new consultar();
    w->show();
}

void AdminMainWindow::on_report_clicked()
{
    Report *w = new Report();
    w->show();
}
