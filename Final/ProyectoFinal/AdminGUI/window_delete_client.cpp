#include "window_delete_client.h"
#include "ui_window_delete_client.h"

window_delete_client::window_delete_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window_delete_client)
{
    ui->setupUi(this);
}

window_delete_client::~window_delete_client()
{
    delete ui;
}

void window_delete_client::on_pushButton_clicked()
{
    if(ui->pushButton->text() == ""){
        QMessageBox* q = new QMessageBox();
        q->setText("Inserte la cedula a eliminar");
        q->show();
    }else{
        QJsonObject ob;
        ob.insert("EliminarCliente",QJsonValue::fromVariant(ui->lineEdit->text().toInt()));
        QJsonDocument doc(ob);

        QJsonDocument answer = socketAdmin::getInstance()->request(doc);

        QJsonObject ans = answer.object();
        QMessageBox* q = new QMessageBox();
        if(ans.take("Respuesta") == "T"){
            q->setText("Cliente eliminado.");
        }else{
            q->setText("No se pudo eliminar el cliente.");
        }
        q->show();
    }
}

void window_delete_client::on_pushButton_2_clicked()
{
    hide();
}
