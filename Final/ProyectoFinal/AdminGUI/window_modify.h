#ifndef WINDOW_MODIFY_H
#define WINDOW_MODIFY_H

#include <QMainWindow>

namespace Ui {
class window_modify;
}

class window_modify : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_modify(QWidget *parent = nullptr);
    ~window_modify();

private slots:
    void on_back_clicked();

private:
    Ui::window_modify *ui;
};

#endif // WINDOW_MODIFY_H
