#include "agregarp.h"
#include "ui_agregarp.h"

AgregarP::AgregarP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgregarP)
{
    ui->setupUi(this);
    socket = new Socket();
}

AgregarP::~AgregarP()
{
    delete ui;
}

void AgregarP::on_btAceptar_clicked()
{
    string numP= ui->txtId->toPlainText().toUtf8().constData();
    socket->conexion();
    if(!numP.empty()){
        string mensaje = socket->controlador("57;"+ numP);
        cout<<mensaje<<endl;
      if (mensaje == "T"){
        QMessageBox::information(this,"Exito","Pasajero sin problemas migratorio");
      }else{
        QMessageBox::information(this,"Error","Pasajero con problemas migratorio");
      }
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el número de pasaporte");
      cout<<"No hay nada escrito"<<endl;
    }
    //ui->txtConsultarT->insertPlainText(QString::fromStdString(msg));
   // ui->txtConsultarT->setReadOnly(true);
}
