#ifndef W_CANTIDAD_H
#define W_CANTIDAD_H
#include "library.h"
#include <QMainWindow>

namespace Ui {
class W_CANTIDAD;
}

class W_CANTIDAD : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_CANTIDAD(QWidget *parent = nullptr);
    ~W_CANTIDAD();
    void PATH(string Path);
    void ced(string ced);

private slots:
    void on_pushButton_clicked();

private:
    Ui::W_CANTIDAD *ui;
    string PATHC;
    string CED;
};

#endif // W_CANTIDAD_H
