#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "socket.h"
#include "clickablelabel.h"
#include "ciudades.h"
namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(string &pPaises, QWidget *parent = nullptr);
    ~Menu();
    void agregarPaises();

private slots:
    void MostrarInfoPais(QString pNombre);

    void on_txtConP_clicked();

    void on_txtConC_clicked();

    void on_txtConCo_clicked();

    void on_txtConT_clicked();

    void on_txtConPre_clicked();

    void on_txtConNA_clicked();

    void on_txtConR_clicked();

    void on_txtRes_clicked();

    void on_txtFac_clicked();

    void on_botCons_clicked();

    void on_botRes_clicked();

    void on_botFac_clicked();

    void on_botBR_clicked();

    void on_botBR_2_clicked();

private:
    Ui::Menu *ui;
    Socket *socket;
    string paises;
};

#endif // MENU_H
