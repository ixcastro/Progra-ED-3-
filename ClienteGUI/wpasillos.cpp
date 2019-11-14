#include "wpasillos.h"
#include "ui_wpasillos.h"
#include "library.h"
#include "qpushbutton.h"
#include "QVBoxLayout"
#include "QScrollArea"
#include "socketclient.h"


wPasillos::wPasillos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wPasillos)
{
    ui->setupUi(this);
}




void wPasillos::shareButton(QJsonArray pData){

    int contador = 0;
    int posX = 100;
    int posY = 100;

    auto * layout = new QVBoxLayout(this);
    auto * scrollArea = new QScrollArea(this);
    scrollArea->resize(200,400);

    scrollArea->setWidgetResizable( true );
    layout->addWidget( scrollArea );

    auto * container = new QWidget();
    scrollArea->setWidget( container );
    layout = new QVBoxLayout(container);

    for(int i=0; i< pData.size(); i++){

        QPushButton* button;
        button = new QPushButton(pData[i].toString(), container);
        QString name = pData[i].toString();
       // QObject::connect(button,SIGNAL(clicked()),this,SLOT(commonSlot()));
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


void wPasillos::commonSlot(){

    //QPushButton *b = (QPushButton*)sender();
   // QString name = b->text();
//    QJsonObject recordObject;
//    recordObject.insert("Pasillo","");
//    QJsonDocument docIN(recordObject);
//    QJsonDocument D = SocketClient::getInstance()->request(docIN);
//    QJsonArray ob = D.array();

    cout<<"aja"<<endl;
}


wPasillos::~wPasillos()
{
    delete ui;
}
