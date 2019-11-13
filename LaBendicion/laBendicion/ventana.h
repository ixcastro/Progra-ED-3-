#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include <iostream>
#include "ventanamenu.h"

using namespace std;

namespace Ui {
class Ventana;
}

class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void on_ingresar_clicked();

private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H
