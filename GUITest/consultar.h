#ifndef CONSULTAR_H
#define CONSULTAR_H

#include <QMainWindow>

namespace Ui {
class consultar;
}

class consultar : public QMainWindow
{
    Q_OBJECT

public:
    explicit consultar(QWidget *parent = nullptr);
    ~consultar();

private:
    Ui::consultar *ui;
};

#endif // CONSULTAR_H
