#ifndef WINDOW_MODIFY_PERCENTAGE_H
#define WINDOW_MODIFY_PERCENTAGE_H

#include <QMainWindow>

namespace Ui {
class window_modify_percentage;
}

class window_modify_percentage : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_modify_percentage(QWidget *parent = nullptr);
    ~window_modify_percentage();

private slots:
    void on_marcaButton_clicked();

    void on_start_clicked();

    void on_pasilloButton_clicked();

    void on_prodButton_clicked();

    void on_save_clicked();

    void on_back_clicked();

private:
    Ui::window_modify_percentage *ui;
    int pasillo;
    int producto;
    int marca;
};

#endif // WINDOW_MODIFY_PERCENTAGE_H
