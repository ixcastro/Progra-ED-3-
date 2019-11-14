#ifndef AGREGARP_H
#define AGREGARP_H

#include <QWidget>
#include <QMessageBox>
#include "socket.h"

namespace Ui {
class AgregarP;
}

class AgregarP : public QWidget
{
    Q_OBJECT

public:
    explicit AgregarP(QWidget *parent = nullptr);
    ~AgregarP();

private slots:
    void on_btAceptar_clicked();

private:
    Ui::AgregarP *ui;
    Socket *socket;
};

#endif // AGREGARP_H
