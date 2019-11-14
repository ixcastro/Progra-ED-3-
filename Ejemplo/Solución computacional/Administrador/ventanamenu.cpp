#include "ventanamenu.h"
#include "ui_ventanamenu.h"


VentanaMenu::VentanaMenu(string &pPaises, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaMenu)
{
    ui->setupUi(this);
    paises = pPaises;
    agregarPaises();
    socket = new Socket();
}

VentanaMenu::~VentanaMenu()
{
    delete ui;
}


void VentanaMenu::on_btInsertar_clicked()
{
    VentanaAgregar *ventana = new VentanaAgregar;
    ventana->show();
}

void VentanaMenu::agregarPaises(){
    string paises[18] = {"PORTUGAL","ESPANA","FRANCIA","SUIZA","GRAN BRETANA",
                                "HOLANDA","TURQUIA","BELGICA","ITALIA","GRECIA","REPUBLICA CHECA",
                                "POLONIA","RUMANIA","UCRANIA","BULGARIA","FINLANDIA","SUECIA",
                                 "ALEMANIA"};
    int x[18] = {40,110,170,219,118,190,470,183,273,355,250,300,364,400,371,320,270,230};
    int y[18] = {490,480,390,385,249,266,480,300,490,535,320,270,388,300,446,40,107,280};
    ClickableLabel *etiquetas[50];
    string arr[50];
    for (int i = 0;i<50;i++) {
        arr[i] = "";
    }
    char separador = '\n';
    int contador = 0;
    for(size_t p=0, q=0; p!=this->paises.npos; p=q){
        arr[contador] = this->paises.substr(p+(p!=0),(q=this->paises.find(separador, p+1))-p-(p!=0));
        cout<<arr[contador]<<endl;
        contador++;
    }

    int i = 0;
    while(arr[i]!= "" && i<50){
        for(int j = 0;j<18;j++){
            if(arr[i] == paises[j]){
                etiquetas[i] = new ClickableLabel(QString::fromStdString(paises[j]),this);
                etiquetas[i]->setGeometry(x[j],y[j],0,0);
                etiquetas[i]->adjustSize();
                etiquetas[i]->setCursor(Qt::PointingHandCursor);
                QObject::connect(etiquetas[i],&ClickableLabel::clicked,this,&VentanaMenu::MostrarInfoPais);
                break;
            }
        }
        i++;
    }
}

void VentanaMenu::MostrarInfoPais(QString pNombre){
    socket->conexion();
    string nombre = pNombre.toUtf8().constData();
    string ciudades = socket->controlador("-2;"+nombre);
    cout<<ciudades<<endl;
    if(ciudades != "El pais no tiene ciudades" && ciudades != "El pais no existe"){
        QMessageBox::information(this,"Info","Presionaste el país: "+pNombre);
        Ciudades *ventana = new Ciudades(nombre,ciudades);
        ventana->show();
    }else{
        QMessageBox::information(this,"Info",pNombre+" "+QString::fromStdString(ciudades));
    }
}

void VentanaMenu::on_btModificar_clicked()
{
    VentanaModificar *ventana = new VentanaModificar;
    ventana->show();
}

void VentanaMenu::on_btConsultar_clicked()
{
    VentanaConsultar *ventana = new VentanaConsultar;
    ventana->show();
}

void VentanaMenu::on_btReportes_clicked()
{
    VentanaReportes *ventana = new VentanaReportes();
    ventana->show();
}
