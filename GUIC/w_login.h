#ifndef W_LOGIN_H
#define W_LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class W_Login; }
QT_END_NAMESPACE

class W_Login : public QMainWindow
{
    Q_OBJECT

public:
    W_Login(QWidget *parent = nullptr);
    ~W_Login();

private:
    Ui::W_Login *ui;
};
#endif // W_LOGIN_H
