#ifndef WINDOW_QUERY_PRICE_H
#define WINDOW_QUERY_PRICE_H

#include <QMainWindow>

#include <iostream>

namespace Ui {
class window_query_price;
}

class window_query_price : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_query_price(QWidget *parent = nullptr);
    ~window_query_price();

private slots:
    void on_pushButton_clicked();

    void on_start_clicked();

    void on_pasilloButton_clicked();

    void on_prodButton_clicked();

    void on_marcaButton_clicked();

private:
    Ui::window_query_price *ui;
    int pasillo;
    int producto;
    int marca;
};

#endif // WINDOW_QUERY_PRICE_H
