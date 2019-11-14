#ifndef W_MENU_H
#define W_MENU_H

#include <QMainWindow>

namespace Ui {
class W_Menu;
}

class W_Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_Menu(QWidget *parent = nullptr);
    ~W_Menu();z

    private slots:
        void on_pushButton_clicked();

private:
    Ui::W_Menu *ui;
};

#endif // W_MENU_H
