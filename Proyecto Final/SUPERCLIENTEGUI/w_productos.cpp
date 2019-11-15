#include "w_productos.h"
#include "ui_w_productos.h"
#include "library.h"
#include "qpushbutton.h"
#include "QVBoxLayout"
#include "QScrollArea"
#include "socketclient.h"
#include "w_marca.h"
#include "w_canasta.h"
#include "w_porcentaje.h"
#include "w_compra.h"

W_Productos::W_Productos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_Productos)
{
    ui->setupUi(this);
}

W_Productos::~W_Productos()
{
    delete ui;
}

void W_Productos::ced(string ced){
    CED = ced;
}

void  W_Productos::shareButton(QJsonArray pData,int pNum,string path){

    PATH = path;
    NUM =pNum;
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


void W_Productos::commonSlot(){

    cout<<"NUM : "<<NUM<<endl;



    QPushButton *b = (QPushButton*)sender();
    QString name = b->text();
    QStringList lista = name.split("-");

    QJsonObject recordObject;

    //- int pas - int prod

    cout<<"path "<<PATH<<endl;
    stringstream PASILLO(PATH);

    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;
    PASILLO >> x;

    recordObject.insert("Pasillo",x);
    recordObject.insert("Producto",lista.first().toInt());
    QJsonObject recordObjectOtro;
    recordObjectOtro.insert("Marca",recordObject);
    QJsonDocument docIN(recordObjectOtro);
    QJsonDocument D = SocketClient::getInstance()->request(docIN);
    QJsonArray ob = D.array();

    //CONSULTAR UN PRECIO
    if(NUM==1){
        PATH = PATH +"-"+ lista.first().toStdString();
        W_MARCA *a = new  W_MARCA();
        a->shareButton(ob,PATH);
        a->show();
    }

    // CANASTA BASICA
    if(NUM==2){
        PATH = PATH +"-"+ lista.first().toStdString();
        W_Canasta *a = new   W_Canasta();
        a->shareButton(ob,PATH);
        a->show();

    }

    //IMPUESTO
    if(NUM==3){
        PATH = PATH +"-"+ lista.first().toStdString();
        W_PORCENTAJE *a = new  W_PORCENTAJE();
        a->shareButton(ob,PATH);
        a->show();

    }

    //COMPRA
    if(NUM==4){
        cout<<"==>"<<CED<<endl;
        cout<<"==>"<<CED<<endl;
        PATH = PATH +"-"+ lista.first().toStdString();
        W_COMPRA *a = new   W_COMPRA();
        a->ced(CED);
        a->shareButton(ob,PATH);
        a->show();

    }

    this->close();

}




