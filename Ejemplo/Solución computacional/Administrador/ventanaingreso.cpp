#include "ventanaingreso.h"
#include "ui_ventanaingreso.h"

VentanaIngreso::VentanaIngreso(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaIngreso)
{
    socket = new Socket();
    ui->setupUi(this);
}

VentanaIngreso::~VentanaIngreso()
{
    delete ui;
}

void VentanaIngreso::on_ingresar_clicked()
{
    socket->conexion();
    string texto = ui->txtId->toPlainText().toUtf8().constData();
    if(!texto.empty()){

        string mensaje = socket->controlador("0;"+texto);
        if (mensaje!="F"){
            if(mensaje != "Servidor no disponible... Intente de nuevo"){
                this->setVisible(false);
                socket->conexion();
                string paises = socket->controlador("-1");
                VentanaMenu *ventana = new VentanaMenu(paises);
                ventana->show();
            }else{
                QMessageBox::information(this,"Fatal","El servidor no se encuentra disponible");
            }
      }else{
          QMessageBox::information(this,"Error","No se encuentra registrado");
      }
    }else{
        QMessageBox::information(this,"Error","Debe ingresar el número de identificación");
        cout<<"No hay nada escrito"<<endl;
    }
}
