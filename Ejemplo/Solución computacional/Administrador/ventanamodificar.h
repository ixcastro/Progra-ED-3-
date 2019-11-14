#ifndef VENTANAMODIFICAR_H
#define VENTANAMODIFICAR_H

#include <QMainWindow>
#include <QIntValidator>
#include <QMessageBox>
#include "socket.h"
using namespace std;
namespace Ui {
class VentanaModificar;
}

class VentanaModificar : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaModificar(QWidget *parent = nullptr);
    ~VentanaModificar();

private slots:


    void on_btAceptarNumAsientos_clicked();

    void on_btAceptarPrecio_clicked();

    void on_btAceptarTiempo_clicked();

    void on_btAceptarRuta_clicked();

    void on_btAceptarTren_clicked();

    void on_btAceptarEstadoMigratorio_clicked();

private:
    Ui::VentanaModificar *ui;
    Socket *socket;
};

#endif // VENTANAMODIFICAR_H
