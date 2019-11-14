#ifndef VENTANACONSULTAR_H
#define VENTANACONSULTAR_H

#include <QWidget>
#include <QIntValidator>
#include <QMessageBox>
#include "socket.h"

using namespace std;

namespace Ui {
class VentanaConsultar;
}

class VentanaConsultar : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaConsultar(QWidget *parent = nullptr);
    ~VentanaConsultar();


private slots:

    void on_btnConsT_3_clicked();

    void on_btConsR_3_clicked();

    void on_btConsPre_2_clicked();

    void on_btCancelarPrecio_6_clicked();

    void on_btCancelarPrecio_7_clicked();

private:
    Ui::VentanaConsultar *ui;
    Socket *socket;
};

#endif // VENTANACONSULTAR_H
