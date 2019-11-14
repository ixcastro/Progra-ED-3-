#ifndef WLOGIN_H
#define WLOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WLogin; }
QT_END_NAMESPACE

class WLogin : public QMainWindow
{
    Q_OBJECT

public:
    WLogin(QWidget *parent = nullptr);
    ~WLogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WLogin *ui;
};
#endif // WLOGIN_H
