#include "ingresar.h"
#include "ui_ingresar.h"


Ingresar::Ingresar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ingresar)
{
    socket = new Socket();
    ui->setupUi(this);
}

Ingresar::~Ingresar()
{
    delete ui;
}

void Ingresar::on_ingresar_clicked()
{
    socket->conexion();
    string texto = ui->txtId->toPlainText().toUtf8().constData();
    if(!texto.empty()){
        string mensaje = socket->controlador("50;"+texto);
        cout<<mensaje<<endl;
      if (mensaje != "F"){
        this->setVisible(false);
        socket->conexion();
        string paises = socket->controlador("-1");
        Menu *ventana = new Menu(paises);
        ventana->show();
      }else{
        QMessageBox::information(this,"Error","No se encuentra registrado");
      }
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el número de identificación");
      cout<<"No hay nada escrito"<<endl;
    }
}
