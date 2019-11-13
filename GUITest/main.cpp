#include "mainwindow.h"
#include "adminmainwindow.h"
#include "report.h"
#include "insert.h"
#include "modify.h"
#include "deletewindow.h"
#include "citywindow.h"
#include "insert_pas.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AdminMainWindow w;
    w.show();

    return a.exec();
}
