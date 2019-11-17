#ifndef WINDOW_MODIFY_BASKET_H
#define WINDOW_MODIFY_BASKET_H

#include <QMainWindow>

namespace Ui {
class window_modify_basket;
}

class window_modify_basket : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_modify_basket(QWidget *parent = nullptr);
    ~window_modify_basket();

private slots:
    void on_pasilloButton_clicked();

    void on_prodButton_clicked();

    void on_marcaButton_clicked();

    void on_back_clicked();

    void on_save_clicked();

    void on_start_clicked();

private:
    Ui::window_modify_basket *ui;
    int pasillo;
    int producto;
    int marca;
};

#endif // WINDOW_MODIFY_BASKET_H
