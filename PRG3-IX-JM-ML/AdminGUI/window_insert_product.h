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
    void setSelectHall(int n);
    explicit window_insert_product(QWidget *parent = nullptr);
    ~window_insert_product();

private slots:
    void on_save_clicked();

    void on_back_clicked();

private:
    Ui::window_insert_product *ui;
    int selectedHall = 0;
};

#endif // WINDOW_INSERT_PRODUCT_H
