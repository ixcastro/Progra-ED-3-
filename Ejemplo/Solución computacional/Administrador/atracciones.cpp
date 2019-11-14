#include "atracciones.h"
#include "ui_atracciones.h"

Atracciones::Atracciones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Atracciones)
{
    ui->setupUi(this);
}

Atracciones::~Atracciones()
{
    delete ui;
}

void Atracciones::mostrarAtracciones(string pAtracciones)
{
    ui->txtAtracciones->clear();
    ui->txtAtracciones->insertPlainText(QString::fromStdString(pAtracciones));
}

