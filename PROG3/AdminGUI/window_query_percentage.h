#ifndef WINDOW_QUERY_PERCENTAGE_H
#define WINDOW_QUERY_PERCENTAGE_H

#include <QMainWindow>

namespace Ui {
class window_query_percentage;
}

class window_query_percentage : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_query_percentage(QWidget *parent = nullptr);
    ~window_query_percentage();

private slots:
    void on_start_clicked();

    void on_pasilloButton_clicked();

    void on_prodButton_clicked();

    void on_marcaButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::window_query_percentage *ui;
    int pasillo;
    int producto;
    int marca;
};

#endif // WINDOW_QUERY_PERCENTAGE_H
