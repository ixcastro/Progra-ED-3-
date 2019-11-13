#ifndef WINDOW_CITY_H
#define WINDOW_CITY_H

#include <QMainWindow>

namespace Ui {
class window_city;
}

class window_city : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_city(QWidget *parent = nullptr);
    ~window_city();

private slots:
    void on_back_clicked();

private:
    Ui::window_city *ui;
};

#endif // WINDOW_CITY_H
