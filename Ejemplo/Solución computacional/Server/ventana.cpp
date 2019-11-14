#include "ventana.h"
#include "ui_ventana.h"
#include "sistematrenes.h"
using namespace std;

static ServicioDeTrenes *trenes;

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
    trenes = new ServicioDeTrenes();
    trenes->cargarArchivos();
    string texto = ui->txtId->toPlainText().toUtf8().constData();
    if(!texto.empty()){
      if (trenes->ValidaAdministrador(texto)!="F"){
        this->setVisible(false);
        VentanaMenu *ventana = new VentanaMenu;
        ventana->show();
      }else{
        QMessageBox::information(this,"Error","No se encuentra registrado");
      }
    }else{
      QMessageBox::information(this,"Error","Debe ingresar el número de identificación");
      cout<<"No hay nada escrito"<<endl;
  }
}
