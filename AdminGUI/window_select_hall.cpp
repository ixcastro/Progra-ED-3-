#include "window_select_hall.h"
#include "ui_window_select_hall.h"
#include "window_insert_product.h"
#include <QMessageBox>
#include <QPushButton>
#include "library.h"



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
        QPushButton* button2;
        button2 = new QPushButton(a[i].toString(), this);

        QString name = a[i].toString();
        QObject::connect(button2,SIGNAL(clicked()),this,SLOT(commonSlot()));
        returnHall(button2->text());
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

void window_select_hall::commonSlot(string s){
    QString QstrLinea = QString::fromStdString(s);
    QStringList lista = QstrLinea.split("-");
    cout<<"holaaa"<<endl;
    window_insert_product *w = new window_insert_product();
    w->setSelectHall(lista.first().toInt());
    w->show();

    QMessageBox *a = new QMessageBox();
    a->setText("picha");
    a->show();

}

void window_select_hall::commonSlot(){
    QPushButton *b = (QPushButton*)sender();
    QString name = b->text();
    QStringList lista = name.split("-");

    window_insert_product *w = new window_insert_product();
    w->setSelectHall(lista.first().toInt());
    w->show();
}

void window_select_hall::on_pushButton_clicked()
{

}
