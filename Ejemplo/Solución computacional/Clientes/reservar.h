#ifndef RESERVAR_H
#define RESERVAR_H

#include <QWidget>
#include "socket.h"
#include "agregarp.h"

namespace Ui {
class Reservar;
}

class Reservar : public QWidget
{
    Q_OBJECT

public:
    explicit Reservar(QWidget *parent = nullptr);
    ~Reservar();

private slots:
    void on_btAP_clicked();

    void on_btReservar_clicked();

private:
    Ui::Reservar *ui;
    Socket *socket;
};

#endif // RESERVAR_H
