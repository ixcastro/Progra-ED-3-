#include "w_canasta.h"
#include "ui_w_canasta.h"
#include "w_productos.h"
#include "ui_w_productos.h"
#include "library.h"
#include "qpushbutton.h"
#include "QVBoxLayout"
#include "QScrollArea"
#include "socketclient.h"


W_Canasta::W_Canasta(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_Canasta)
{
    ui->setupUi(this);
}

W_Canasta::~W_Canasta()
{
    delete ui;
}

void W_Canasta::shareButton(QJsonArray pData, string path){

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



void W_Canasta::commonSlot(){

    QPushButton *b = (QPushButton*)sender();
    QString name = b->text();
    QStringList lista = name.split(" ");

    for(int i =0; i<lista.size();i++){
       // if(lista[i]==":"){
            cout<<lista[i].toStdString()<<endl;
        //}
    }


    PATH =  PATH +"-"+lista[2].toStdString();

    cout<<"->"<<PATH<<endl;
}




