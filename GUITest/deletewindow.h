#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QMainWindow>

namespace Ui {
class deleteWindow;
}

class deleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteWindow(QWidget *parent = nullptr);
    ~deleteWindow();

private:
    Ui::deleteWindow *ui;
};

#endif // DELETEWINDOW_H
