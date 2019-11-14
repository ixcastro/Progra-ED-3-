#ifndef VENTANAAGREGAR_H
#define VENTANAAGREGAR_H

#include <QMainWindow>
#include <iostream>
#include <QMessageBox>
#include "socket.h"

using namespace std;

namespace Ui {
class VentanaAgregar;
}

class VentanaAgregar : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaAgregar(QWidget *parent = nullptr);
    ~VentanaAgregar();

private slots:
    void on_btAceptarPais_clicked();

    void on_btAceptarCi_clicked();

    void on_btAceptarCo_clicked();

    void on_btAceptarTipo_clicked();

    void on_btAceptarTren_clicked();

    void on_btAceptarRuta_clicked();

    void on_btAceptarAtraccion_clicked();

private:
    Ui::VentanaAgregar *ui;
    Socket *socket;
};

#endif // VENTANAAGREGAR_H
