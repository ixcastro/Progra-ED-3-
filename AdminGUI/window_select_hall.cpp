#include "window_select_hall.h"
#include "ui_window_select_hall.h"
#include "window_insert_product.h"
#include <QMessageBox>
#include <QPushButton>



window_select_hall::window_select_hall(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_select_hall)
{
    ui->setupUi(this);
    //selectedHall = 0;
    //addButtons(5);
}

window_select_hall::~window_select_hall()
{
    delete ui;
}

int returnHall(QString s){
    int hall = 0;
    hall = s.toInt();
    return hall;

}

void window_select_hall::addButtons(QJsonArray a){

    //int i = 0;
    int contador = 0;
    int posX = 100;
    int posY = 100;
    for (int i = 0; i < a.size(); i++) {
        QPushButton* button;
        button = new QPushButton(a[i].toString(), this);


        connect(button,SIGNAL(clicked()),this, SLOT(commonSlot(button->text())));
        returnHall(button->text());
        // set size and location of the button
        //locationof the button
        button->setGeometry(QRect(QPoint(posX, posY),
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

void window_select_hall::commonSlot(QString s){
    QString QstrLinea = s;
    QStringList lista = QstrLinea.split('-');

    window_insert_product *w = new window_insert_product();
    w->setSelectHall(lista.first().toInt());
    w->show();

}
