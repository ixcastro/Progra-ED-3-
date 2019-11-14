#include "w_cantidad.h"
#include "ui_w_cantidad.h"
#include "socketclient.h"
#include "library.h"
#include <QMessageBox>
#include "QJsonValue"

W_CANTIDAD::W_CANTIDAD(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_CANTIDAD)
{
    ui->setupUi(this);
}

W_CANTIDAD::~W_CANTIDAD()
{
    delete ui;
}


void W_CANTIDAD::PATH(string Path){
    PATHC = Path;
}

void W_CANTIDAD::ced(string ced){
    CED = ced;
}


void W_CANTIDAD::on_pushButton_clicked()
{
    ui->lineEdit->text().toStdString();
    cout<<"CED "<<CED<<endl;
    QString dataPath = QString::fromStdString(PATHC);
    QStringList lista = dataPath.split("-");

    QJsonObject recordObject;
    recordObject.insert("Cedula",QJsonValue::fromVariant(CED.c_str()));
    recordObject.insert("CantidadCompra",QJsonValue::fromVariant( ui->lineEdit->text()));
    recordObject.insert("Pasillo",QJsonValue::fromVariant(lista[0]));
    recordObject.insert("Producto",QJsonValue::fromVariant(lista[1]));
    recordObject.insert("Marca",QJsonValue::fromVariant(lista[2]));

    QJsonObject recordObjectOtro;
    recordObjectOtro.insert("Comprar", recordObject);

    QJsonDocument docIN( recordObjectOtro);
    QJsonDocument D = SocketClient::getInstance()->request(docIN);
    QJsonObject ob = D.object();

    //    QJsonValue a;
    //    QJsonValue QJsonObject::value(const QString &key) const


    string g ;
    QJsonArray npcArray = ob["Respuesta"].toArray();


    QString s = "";
    for(int i=0; i< npcArray.size(); i++){

        s +=   npcArray[i].toString();
    }

    cout<<"ESTA ES LA RESPUESTA : "<<s.toStdString()<<endl;

    if(ob.take("Respuesta") == "A"
            ){
        QMessageBox* q = new QMessageBox();
        q->setText("A");
        q->show();

    }else if(ob.take("Respuesta") =="B"){
        QMessageBox* q = new QMessageBox();
        q->setText("Producto en el carrito");
        q->show();
    }else{
        QMessageBox* q = new QMessageBox();
        q->setText("X");
        q->show();

    }





}
