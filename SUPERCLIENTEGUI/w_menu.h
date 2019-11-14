#ifndef W_MENU_H
#define W_MENU_H

#include <QMainWindow>

namespace Ui {
class W_MENU;
}

class W_MENU : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_MENU(QWidget *parent = nullptr);
    ~W_MENU();

private slots:
    void on_pushButton_clicked();

private:
    Ui::W_MENU *ui;
};

#endif // W_MENU_H
