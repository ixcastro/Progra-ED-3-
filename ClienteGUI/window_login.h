#ifndef WINDOW_LOGIN_H
#define WINDOW_LOGIN_H

#include <QMainWindow>

namespace Ui {
class window_login;
}

class window_login : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_login(QWidget *parent = nullptr);
    ~window_login();

private slots:
    void on_back_clicked();

private:
    Ui::window_login *ui;
};

#endif // WINDOW_CITY_H
