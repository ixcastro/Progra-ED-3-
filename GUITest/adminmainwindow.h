#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = nullptr);
    ~AdminMainWindow();
    void close();


private slots:
    void on_close_destroyed();

    void on_close_clicked();

    void on_insert_clicked();

    void on_modify_clicked();

    void on_delete_2_clicked();

    void on_query_clicked();

    void on_report_clicked();

private:
    Ui::AdminMainWindow *ui;
};

#endif // ADMINMAINWINDOW_H
