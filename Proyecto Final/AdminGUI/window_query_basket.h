#ifndef WINDOW_QUERY_BASKET_H
#define WINDOW_QUERY_BASKET_H

#include <QMainWindow>

namespace Ui {
class window_query_basket;
}

class window_query_basket : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_query_basket(QWidget *parent = nullptr);
    ~window_query_basket();

private slots:
    void on_start_clicked();

    void on_pasilloButton_clicked();

    void on_prodButton_clicked();

    void on_marcaButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::window_query_basket *ui;
    int pasillo;
    int producto;
    int marca;
};

#endif // WINDOW_QUERY_BASKET_H
