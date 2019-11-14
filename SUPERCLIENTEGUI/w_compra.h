#ifndef W_COMPRA_H
#define W_COMPRA_H

#include <QMainWindow>

namespace Ui {
class W_COMPRA;
}

class W_COMPRA : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_COMPRA(QWidget *parent = nullptr);
    ~W_COMPRA();

private:
    Ui::W_COMPRA *ui;
};

#endif // W_COMPRA_H
