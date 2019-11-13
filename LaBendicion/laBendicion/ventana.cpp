#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::on_ingresar_clicked()
{
    std::string texto = ui->txtId->toPlainText().toUtf8().constData();
    cout<<texto<<endl;
    this->setVisible(false);
    VentanaMenu *ventana = new VentanaMenu;
    ventana->show();
}
