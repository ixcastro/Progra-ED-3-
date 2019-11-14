#include "w_compra.h"
#include "ui_w_compra.h"
#include "w_productos.h"
#include "ui_w_productos.h"
#include "library.h"
#include "qpushbutton.h"
#include "QVBoxLayout"
#include "QScrollArea"
#include "socketclient.h"
#include "w_cantidad.h"

W_COMPRA::W_COMPRA(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_COMPRA)
{
    ui->setupUi(this);
}

W_COMPRA::~W_COMPRA()
{
    delete ui;
}
void  W_COMPRA::shareButton(QJsonArray pData, string path){

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

void  W_COMPRA::ced(string ced){
     CED = ced;
}

void W_COMPRA::commonSlot(){

    QPushButton *b = (QPushButton*)sender();
    QString name = b->text();
    QStringList lista = name.split("-");


    // cout<<"->"<<lista[1].toStdString()<<endl;
     PATH =  PATH +"-"+lista.first().toStdString();
    W_CANTIDAD *a = new   W_CANTIDAD();
    cout<<"   "<<lista.first().toStdString()<<endl;
    a->ced(CED);
    a->PATH(PATH);
    a->show();

    cout<<"->"<<PATH<<endl;
}
