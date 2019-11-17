#ifndef WINDOW_DELETE_PRODUCT_H
#define WINDOW_DELETE_PRODUCT_H

#include <QMainWindow>

namespace Ui {
class window_delete_product;
}

class window_delete_product : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_delete_product(QWidget *parent = nullptr);
    ~window_delete_product();

private slots:
    void on_start_clicked();

    void on_pasilloButton_clicked();

    void on_prodButton_clicked();

    void on_save_clicked();

    void on_back_clicked();

private:
    Ui::window_delete_product *ui;
    int pasillo;
    int producto;
};

#endif // WINDOW_DELETE_PRODUCT_H
