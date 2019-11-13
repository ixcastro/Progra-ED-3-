#ifndef WINDOW_REPORT_H
#define WINDOW_REPORT_H

#include <QMainWindow>

namespace Ui {
class window_report;
}

class window_report : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_report(QWidget *parent = nullptr);
    ~window_report();

private slots:
    void on_pushButton_26_clicked();

private:
    Ui::window_report *ui;
};

#endif // WINDOW_REPORT_H
