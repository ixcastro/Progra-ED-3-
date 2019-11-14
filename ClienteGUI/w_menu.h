#ifndef W_MENU_H
#define W_MENU_H

#include <QMainWindow>

namespace Ui {
class w_Menu;
}

class w_Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit w_Menu(QWidget *parent = nullptr);
    ~w_Menu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::w_Menu *ui;
};

#endif // W_MENU_H
