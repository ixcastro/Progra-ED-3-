#ifndef INGRESAR_H
#define INGRESAR_H

#include <QWidget>
#include <QMessageBox>
#include "socket.h"
#include "menu.h"
#include <iostream>

using namespace std;
namespace Ui {
class Ingresar;
}

class Ingresar : public QWidget
{
    Q_OBJECT

public:
    explicit Ingresar(QWidget *parent = nullptr);
    ~Ingresar();

private slots:
    void on_ingresar_clicked();

private:
    Ui::Ingresar *ui;
    Socket *socket;
};

#endif // INGRESAR_H
