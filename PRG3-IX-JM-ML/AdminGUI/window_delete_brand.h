#ifndef WINDOW_DELETE_BRAND_H
#define WINDOW_DELETE_BRAND_H

#include <QMainWindow>

namespace Ui {
class window_delete_brand;
}

class window_delete_brand : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_delete_brand(QWidget *parent = nullptr);
    ~window_delete_brand();

private slots:
    void on_start_clicked();

    void on_pasilloButton_clicked();

    void on_prodButton_clicked();

    void on_marcaButton_clicked();

    void on_save_clicked();

    void on_back_clicked();

private:
    Ui::window_delete_brand *ui;
    int pasillo;
    int producto;
    int marca;
};

#endif // WINDOW_DELETE_BRAND_H
