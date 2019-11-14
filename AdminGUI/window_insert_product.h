#ifndef WINDOW_INSERT_PRODUCT_H
#define WINDOW_INSERT_PRODUCT_H

#include <QMainWindow>

namespace Ui {
class window_insert_product;
}

class window_insert_product : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_insert_product(QWidget *parent = nullptr);
    ~window_insert_product();

private slots:
    void on_save_clicked();

private:
    Ui::window_insert_product *ui;
};

#endif // WINDOW_INSERT_PRODUCT_H
