#ifndef REPORT_H
#define REPORT_H

#include <QMainWindow>

namespace Ui {
class Report;
}

class Report : public QMainWindow
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = nullptr);
    ~Report();

private:
    Ui::Report *ui;
};

#endif // REPORT_H