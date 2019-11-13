#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //sean 5 la cantidad de pasillos
    addButtons(50);
}

int returnHall(QString s){
    int hall = 0;
    hall = s.toInt();
    return hall;

}

void MainWindow::addButtons(int b){

    int i = 0;
    int contador = 0;
    int posX = 100;
    int posY = 100;
    while (i<b) {
    // Create the button, make "this" the parent
        QPushButton* button;
        button = new QPushButton("My Button", this);
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
        i++;
    }
}





MainWindow::~MainWindow()
{
    delete ui;
}
