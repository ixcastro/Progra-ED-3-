#ifndef WINDOW_LOGIN_H
#define WINDOW_LOGIN_H

#include <QMainWindow>

namespace Ui {
class window_logIn;
}

class window_logIn : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_logIn(QWidget *parent = nullptr);
    ~window_logIn();

private slots:
    void on_ingresar_clicked();

private:
    Ui::window_logIn *ui;
};

#endif // WINDOW_LOGIN_H
