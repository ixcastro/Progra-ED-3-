#ifndef W_MENU_H
#define W_MENU_H
#include "library.h"
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

    void ced(string ced);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::W_MENU *ui;
    string CED;
};

#endif // W_MENU_H