#ifndef CITYWINDOW_H
#define CITYWINDOW_H

#include <QMainWindow>

namespace Ui {
class cityWindow;
}

class cityWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit cityWindow(QWidget *parent = nullptr);
    ~cityWindow();

private:
    Ui::cityWindow *ui;
};

#endif // CITYWINDOW_H
