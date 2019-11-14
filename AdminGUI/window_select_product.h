#ifndef WINDOW_SELECT_PRODUCT_H
#define WINDOW_SELECT_PRODUCT_H

#include <QMainWindow>

namespace Ui {
class window_select_product;
}

class window_select_product : public QMainWindow
{
    Q_OBJECT

public:

    explicit window_select_product(QWidget *parent = nullptr);
    ~window_select_product();

private:
    Ui::window_select_product *ui;

};

#endif // WINDOW_SELECT_PRODUCT_H
