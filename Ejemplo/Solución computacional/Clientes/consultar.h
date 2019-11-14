#ifndef CONSULTAR_H
#define CONSULTAR_H

#include <QWidget>
#include <QMessageBox>
#include "socket.h"

namespace Ui {
class Consultar;
}

class Consultar : public QWidget
{
    Q_OBJECT

public:
    explicit Consultar(QWidget *parent = nullptr);
    ~Consultar();

private slots:
    void on_btConsPaises_clicked();

    void on_btCons_clicked();

    void on_btnConsT_clicked();

    void on_btConsNA_clicked();

    void on_btConsR_clicked();

    void on_btCancelarPrecio_5_clicked();

    void on_btCancelarPrecio_4_clicked();

    void on_btConsPre_clicked();

private:
    Ui::Consultar *ui;
    Socket *socket;
};

#endif // CONSULTAR_H
