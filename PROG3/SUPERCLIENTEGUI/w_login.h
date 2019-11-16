#ifndef W_LOGIN_H
#define W_LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class W_LOGIN; }
QT_END_NAMESPACE

class W_LOGIN : public QMainWindow
{
    Q_OBJECT

public:
    W_LOGIN(QWidget *parent = nullptr);
    ~W_LOGIN();

private slots:
    void on_pushButton_clicked();

private:
    Ui::W_LOGIN *ui;
};
#endif // W_LOGIN_H
