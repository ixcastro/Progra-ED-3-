#ifndef WINDOW_SELECT_HALL_H
#define WINDOW_SELECT_HALL_H

#include <QMainWindow>
#include <QJsonArray>
#include "string"
using namespace std;

namespace Ui {
class window_select_hall;
}

class window_select_hall : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_select_hall(QWidget *parent = nullptr);
    ~window_select_hall();

    void addButtons(QJsonArray);


public slots:
    void on_pushButton_clicked();
    void commonSlot(string);
    void commonSlot();

private:
    Ui::window_select_hall *ui;
};

#endif // WINDOW_SELECT_HALL_H
