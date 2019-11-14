#include "w_menu.h"
#include "ui_w_menu.h"
#include  "library.h"
#include "socketclient.h"
#include "qmessagebox.h"

W_Menu::W_Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_Menu)
{
    ui->setupUi(this);
}

W_Menu::~W_Menu()
{
    delete ui;
}

void W_Menu::on_pushButton_clicked()
{

}
