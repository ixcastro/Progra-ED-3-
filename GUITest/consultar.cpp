#include "consultar.h"
#include "ui_consultar.h"

consultar::consultar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::consultar)
{
    ui->setupUi(this);
}

consultar::~consultar()
{
    delete ui;
}
