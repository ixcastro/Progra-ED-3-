#ifndef NUEVAR_H
#define NUEVAR_H
#include <QMessageBox>
#include "socket.h"
#include <QWidget>

namespace Ui {
class NuevaR;
}

class NuevaR : public QWidget
{
    Q_OBJECT

public:
    explicit NuevaR(QWidget *parent = nullptr);
    ~NuevaR();

private slots:
    void on_btCancelarPrecio_5_clicked();

    void on_btCancelarPrecio_6_clicked();

    void on_btCancelarPrecio_7_clicked();

private:
    Ui::NuevaR *ui;
    Socket *socket;
};

#endif // NUEVAR_H
