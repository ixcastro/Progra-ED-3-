#ifndef VENTANAMENU_H
#define VENTANAMENU_H

#include <QMainWindow>
#include <iostream>
#include "clickablelabel.h"
#include "ventanaagregar.h"
#include "ventanamodificar.h"
#include "ventanaconsultar.h"
#include "ciudades.h"
#include "ventanareportes.h"
#include "socket.h"

using namespace std;

namespace Ui {
class VentanaMenu;
}

class VentanaMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaMenu(string &pPaises, QWidget *parent = nullptr);
    ~VentanaMenu();
    void agregarPaises();

private slots:
    void on_btInsertar_clicked();
    void MostrarInfoPais(QString pNombre);

    void on_btModificar_clicked();

    void on_btConsultar_clicked();

    void on_btReportes_clicked();

private:
    Ui::VentanaMenu *ui;
    string paises;
    Socket *socket;
};

#endif // VENTANAMENU_H
