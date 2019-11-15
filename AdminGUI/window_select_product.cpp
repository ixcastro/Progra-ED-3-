#include "window_select_product.h"
#include "ui_window_select_product.h"
#include "window_insert_brand.h"
#include <QMessageBox>
#include <QPushButton>
#include "library.h"

window_select_product::window_select_product(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_select_product)
{
    ui->setupUi(this);
}

void window_select_product::setSelectedHall(int n){
    selectedHall = n;
}

window_select_product::~window_select_product()
{
    delete ui;
}

//Un commonSlot es para insertar y otro para seleccionar
void window_select_product::commonSlot(){
    QPushButton *b = (QPushButton*)sender();
    QString name = b->text();
    QStringList lista = name.split("-");

    window_insert_brand *w = new window_insert_brand();
    w->setSelectHall(lista.first().toInt());
    w->show();
}

//Producto elegido para insertar una marca
void window_select_product::commonSlotProds(){
    QPushButton *b = (QPushButton*)sender();
    QString name = b->text();
    QStringList lista = name.split("-");

    window_insert_brand *w = new window_insert_brand();
    w->setSelectHall(this->selectedHall);
    w->setSelectProd(lista.first().toInt());
    w->show();
}

void window_select_product::addButtonsProds(QJsonArray a){

    //int i = 0;
    int contador = 0;
    int posX = 100;
    int posY = 100;
    for (int i = 0; i < a.size(); i++) {
        QPushButton* button2;
        button2 = new QPushButton(a[i].toString(), this);

        QString name = a[i].toString();
        QObject::connect(button2,SIGNAL(clicked()),this,SLOT(commonSlotProds()));
        // set size and location of the button
        //locationof the button
        button2->setGeometry(QRect(QPoint(posX, posY),
        //size of the button
        QSize(100, 50)));

        // Connect button signal to appropriate slot
        //connect(button, SIGNAL (released()), this, SLOT (handleButton()));
        posY = posY + 50;
        contador++;
        if (contador == 8){
            posX = posX + 100;
            posY = 100;
            contador = 0;
        }
    }
}
