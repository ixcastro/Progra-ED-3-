#include "w_porcentaje.h"
#include "ui_w_porcentaje.h"
#include "w_productos.h"
#include "ui_w_productos.h"
#include "library.h"
#include "qpushbutton.h"
#include "QVBoxLayout"
#include "QScrollArea"
#include "socketclient.h"

W_PORCENTAJE::W_PORCENTAJE(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_PORCENTAJE)
{
    ui->setupUi(this);
}

W_PORCENTAJE::~W_PORCENTAJE()
{
    delete ui;
}

void W_PORCENTAJE::shareButton(QJsonArray pData, string path){

    PATH = path ;
    int contador = 0;
    int posX = 100;
    int posY = 100;

    auto * layout = new QVBoxLayout(this);
    auto * scrollArea = new QScrollArea(this);
    scrollArea->resize(200,350);

    scrollArea->setWidgetResizable( true );
    layout->addWidget( scrollArea );

    auto * container = new QWidget();
    scrollArea->setWidget( container );
    layout = new QVBoxLayout(container);

    for(int i=0; i< pData.size(); i++){

        QPushButton* button;
        button = new QPushButton(pData[i].toString(), container);
        QString name = pData[i].toString();
        QObject::connect(button,SIGNAL(clicked()),this,SLOT(commonSlot()));
        button->setGeometry(QRect(QPoint(posX, posY),
                                  //size of the button
                                  QSize(100, 50)));
        layout->addWidget( button );
        posY = posY + 50;
        contador++;
        if (contador == 8){
            posX = posX + 100;
            posY = 100;
            contador = 0;
        }

    }

}



void W_PORCENTAJE::commonSlot(){


    QPushButton *b = (QPushButton*)sender();
    QString name = b->text();
    QStringList lista = name.split("-");
    PATH =  PATH +"-"+lista.first().toStdString();

    QString str = QString::fromUtf8(PATH.c_str());
    QStringList listaData = str.split("-");


    QJsonObject recordObjects;
    recordObjects.insert("Pasillo",QJsonValue::fromVariant(listaData[0].toInt()));
    recordObjects.insert("Producto",QJsonValue::fromVariant(listaData[1].toInt()));
    recordObjects.insert("Marca",QJsonValue::fromVariant(listaData[2].toInt()));

    QJsonObject record;
    record.insert("Porcentaje",recordObjects);
    QJsonDocument docIN(record);
    QJsonDocument D = SocketClient::getInstance()->request(docIN);
    QJsonObject ob = D.object();

    ui->lineEdit->setText(QJsonValue::fromVariant(ob.take("Porcentaje")).toString());

}




