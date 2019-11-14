#ifndef VENTANAINGRESO_H
#define VENTANAINGRESO_H

#include <QMainWindow>
#include <iostream>
#include <QMessageBox>
#include "ventanamenu.h"
#include "socket.h"

using namespace std;

namespace Ui {
class VentanaIngreso;
}

class VentanaIngreso : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaIngreso(QWidget *parent = nullptr);
    ~VentanaIngreso();

private slots:
    void on_ingresar_clicked();

private:
    Ui::VentanaIngreso *ui;
    Socket *socket;
};

#endif // VENTANAINGRESO_H
