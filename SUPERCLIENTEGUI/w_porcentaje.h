#ifndef W_PORCENTAJE_H
#define W_PORCENTAJE_H

#include <QMainWindow>

namespace Ui {
class W_PORCENTAJE;
}

class W_PORCENTAJE : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_PORCENTAJE(QWidget *parent = nullptr);
    ~W_PORCENTAJE();

private:
    Ui::W_PORCENTAJE *ui;
};

#endif // W_PORCENTAJE_H
