#ifndef WINDOW_MODIFY_PRICE_H
#define WINDOW_MODIFY_PRICE_H

#include <QMainWindow>

namespace Ui {
class window_modify_price;
}

class window_modify_price : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_modify_price(QWidget *parent = nullptr);
    ~window_modify_price();

private slots:
    void on_start_clicked();

    void on_pasilloButton_clicked();

    void on_prodButton_clicked();

    void on_marcaButton_clicked();

    void on_back_clicked();

    void on_save_clicked();

private:
    Ui::window_modify_price *ui;
    int pasillo;
    int producto;
    int marca;
};

#endif // WINDOW_MODIFY_PRICE_H
