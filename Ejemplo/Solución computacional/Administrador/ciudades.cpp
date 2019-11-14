#include "ciudades.h"
#include "ui_ciudades.h"



Ciudades::Ciudades(string &pPais, string &ciudades, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ciudades)
{
    ui->setupUi(this);
    pais = pPais;
    this->ciudades = ciudades;
    cout<<this->ciudades<<endl;
    agregarCiudades();
    socket = new Socket();
}

Ciudades::~Ciudades()
{
    delete ui;
}

void Ciudades::agregarCiudades()
{
    QLabel* etiquetasPaises[18] = {ui->etiquetaPortugal,ui->etiquetaEspana,ui->etiquetaFrancia,
                                   ui->etiquetaSuiza,ui->etiquetaGranBretana,ui->etiquetaHolanda,
                                   ui->etiquetaTurquia,ui->etiquetaBelgica,ui->etiquetaItalia,
                                   ui->etiquetaGrecia,ui->etiquetaRepublicaCheca,ui->etiquetaPolonia,
                                   ui->etiquetaRumania,ui->etiquetaUcrania,ui->etiquetaBulgaria,
                                   ui->etiquetaFinlandia,ui->etiquetaSuecia,ui->etiquetaAlemania};
    for (int i = 0;i<18;i++) {
        cout<<"lo oculta"<<endl;
        etiquetasPaises[i]->setVisible(false);
    }
    cout<<"Por aqui"<<endl;
    string paises[18] = {"PORTUGAL","ESPANA","FRANCIA","SUIZA","GRAN BRETANA",
                                "HOLANDA","TURQUIA","BELGICA","ITALIA","GRECIA","REPUBLICA CHECA",
                                "POLONIA","RUMANIA","UCRANIA","BULGARIA","FINLANDIA","SUECIA",
                                 "ALEMANIA"};
    vector<vector<string>> ciudades;
    vector<vector<int>> x;
    vector<vector<int>> y;
    string portugal[11] = {"LISBOA","CASTELO BRANCO","ALBUFEIRA","OPORTO","SANTAREM","","","","",""};
    vector<string> p;
    for (int i = 0;i<11;i++) {
        p.push_back(portugal[i]);
    }
    ciudades.push_back(p);
    int portugalX[11] = {193,440,320,290,290,0,0,0,0,0,0};
    vector<int> pX;
    for (int i = 0;i<11;i++) {
        pX.push_back(portugalX[i]);
    }
    x.push_back(pX);
    int portugalY[11] = {339,240,520,110,300,0,0,0,0,0,0};
    vector<int> pY;
    for (int i = 0;i<11;i++) {
        pY.push_back(portugalY[i]);
    }
    y.push_back(pY);
    string espana[11] = {"MADRID","VALLADOLID","SANTIAGO","COMPOSTELA","SEVILLA","MALAGA","VALENCIA","BARCELONA","VILLADOLID","",""};
    vector<string> e;
    for (int i = 0;i<11;i++) {
        e.push_back(espana[i]);
    }
    ciudades.push_back(e);
    int espanaX[11] = {300,270,160,160,240,300,400,480,280,0,0};
    vector<int> eX;
    for (int i = 0;i<11;i++) {
        eX.push_back(espanaX[i]);
    }
    x.push_back(eX);
    int espanaY[11] = {250,180,100,120,420,440,290,180,160,0,0};
    vector<int> eY;
    for (int i = 0;i<11;i++) {
        eY.push_back(espanaY[i]);
    }
    y.push_back(eY);
    string francia[11] = {"TOULOUSE","MONTPELLIER","MARSELLA","LYON","NANTES","PARIS","MONACO","","","",""};
    vector<string> f;
    for (int i = 0;i<11;i++) {
        f.push_back(francia[i]);
    }
    ciudades.push_back(f);
    int franciaX[11] = {270,340,430,410,140,300,510,0,0,0,0};
    vector<int> fX;
    for (int i = 0;i<11;i++) {
        fX.push_back(franciaX[i]);
    }
    x.push_back(fX);
    int franciaY[11] = {410,440,420,300,230,150,410,0,0,0,0};
    vector<int> fy;
    for (int i = 0;i<11;i++) {
        fy.push_back(franciaY[i]);
    }
    y.push_back(fy);
    string suiza[11] = {"ZURICH","BERNA","GINEBRA","","","","","","","",""};
    vector<string> sui;
    for (int i = 0;i<11;i++) {
        sui.push_back(suiza[i]);
    }
    ciudades.push_back(sui);
    int suizaX[11] = {360,220,30,0,0,0,0,0,0,0,0};
    vector<int> suix;
    for (int i = 0;i<11;i++) {
        suix.push_back(suizaX[i]);
    }
    x.push_back(suix);
    int suizaY[11] = {160,260,420,0,0,0,0,0,0,0,0};
    vector<int> suiy;
    for (int i = 0;i<11;i++) {
        suiy.push_back(suizaY[i]);
    }
    y.push_back(suiy);
    string granBretana[11] = {"","","","","","","","","","",""};
    vector<string> gb;
    for (int i = 0;i<11;i++) {
        gb.push_back(granBretana[i]);
    }
    ciudades.push_back(gb);
    int granBretanaX[11] = {0,0,0,0,0,0,0,0,0,0,0};
    vector<int> gbx;
    for (int i = 0;i<11;i++) {
        gbx.push_back(granBretanaX[i]);
    }
    x.push_back(gbx);
    int granBretanaY[11] = {0,0,0,0,0,0,0,0,0,0,0};
    vector<int> gby;
    for (int i = 0;i<11;i++) {
        gby.push_back(granBretanaY[i]);
    }
    y.push_back(gby);
    string holanda[11] = {"ROTERDAM","LA HAYA","AMSTERDAM","","","","","","","",""};
    vector<string> h;
    for (int i = 0;i<11;i++) {
        h.push_back(holanda[i]);
    }
    ciudades.push_back(h);
    int holandaX[11] = {200,140,250,0,0,0,0,0,0,0,0};
    vector<int> hx;
    for (int i = 0;i<11;i++) {
        hx.push_back(holandaX[i]);
    }
    x.push_back(hx);
    int holandaY[11] = {340,300,230,0,0,0,0,0,0,0,0};
    vector<int> hy;
    for (int i = 0;i<11;i++) {
        hy.push_back(holandaY[i]);
    }
    y.push_back(hy);
    string turquia[11] = {"ANKARA","ESTAMBUL","BURSA","ANTALYA","ESMIRNA","ADANA","","","","",""};
    vector<string> t;
    for (int i = 0;i<11;i++) {
        t.push_back(turquia[i]);
    }
    ciudades.push_back(t);
    int turquiaX[11] = {230,110,110,170,70,310,0,0,0,0,0};
    vector<int> tx;
    for (int i = 0;i<11;i++) {
        tx.push_back(turquiaX[i]);
    }
    x.push_back(tx);
    int turquiaY[11] = {190,120,180,378,290,370,0,0,0,0,0};
    vector<int> ty;
    for (int i = 0;i<11;i++) {
        ty.push_back(turquiaY[i]);
    }
    y.push_back(ty);
    string belgica[11] = {"GANTE","BRUJAS","AMBERES","","","","","","","",""};
    vector<string> b;
    for (int i = 0;i<11;i++) {
        b.push_back(belgica[i]);
    }
    ciudades.push_back(b);
    int belgicaX[11] = {190,120,280,0,0,0,0,0,0,0,0};
    vector<int> bx;
    for (int i = 0;i<11;i++) {
        bx.push_back(belgicaX[i]);
    }
    x.push_back(bx);
    int belgicaY[11] = {160,110,110,0,0,0,0,0,0,0,0};
    vector<int> by;
    for (int i = 0;i<11;i++) {
        by.push_back(belgicaY[i]);
    }
    y.push_back(by);
    string italia[11] = {"NAPOLES","FLORENCIA","GENOVA","SAN MARINO","VENECIA","ROMA","TURIN","BOLONIA","BARI","MILAN",""};
    vector<string> ita;
    for (int i = 0;i<11;i++) {
        ita.push_back(italia[i]);
    }
    ciudades.push_back(ita);
    int italiaX[11] = {410,250,130,300,290,320,70,230,500,140,0};
    vector<int> itax;
    for (int i = 0;i<11;i++) {
        itax.push_back(italiaX[i]);
    }
    x.push_back(itax);
    int italiaY[11] = {300,150,140,150,90,250,110,140,280,80,0};
    vector<int> itay;
    for (int i = 0;i<11;i++) {
        itay.push_back(italiaY[i]);
    }
    y.push_back(itay);
    string grecia[11] = {"ATENAS","SALONICA","","","","","","","","",""};
    vector<string> gre;
    for (int i = 0;i<11;i++) {
        gre.push_back(grecia[i]);
    }
    ciudades.push_back(gre);
    int greciaX[11] = {230,210,0,0,0,0,0,0,0,0,0};
    vector<int> grex;
    for (int i = 0;i<11;i++) {
        grex.push_back(greciaX[i]);
    }
    x.push_back(grex);
    int greciaY[11] = {400,100,0,0,0,0,0,0,0,0,0};
    vector<int> grey;
    for (int i = 0;i<11;i++) {
        grey.push_back(greciaY[i]);
    }
    y.push_back(grey);
    string republicaCheca[11] = {"OSTRAVA","PRAGA","","","","","","","","",""};
    vector<string> re;
    for (int i = 0;i<11;i++) {
        re.push_back(republicaCheca[i]);
    }
    ciudades.push_back(re);
    int republicaChecaX[11] = {510,220,0,0,0,0,0,0,0,0,0};
    vector<int> rex;
    for (int i = 0;i<11;i++) {
        rex.push_back(republicaChecaX[i]);
    }
    x.push_back(rex);
    int republicaChecaY[11] = {280,220,0,0,0,0,0,0,0,0,0};
    vector<int> rey;
    for (int i = 0;i<11;i++) {
        rey.push_back(republicaChecaY[i]);
    }
    y.push_back(rey);
    string polonia[11] = {"KATOWICE","VARSOVIA","LUBLIN","BRESLAVIA","BIALYSTOCK","CRACOVIA","","","","",""};
    vector<string> po;
    for (int i = 0;i<11;i++) {
        po.push_back(polonia[i]);
    }
    ciudades.push_back(po);
    int poloniaX[11] = {300,400,500,160,520,360,0,0,0,0,0};
    vector<int> pox;
    for (int i = 0;i<11;i++) {
        pox.push_back(poloniaX[i]);
    }
    x.push_back(pox);
    int poloniaY[11] = {410,210,350,360,190,460,0,0,0,0,0};
    vector<int> poy;
    for (int i = 0;i<11;i++) {
        poy.push_back(poloniaY[i]);
    }
    y.push_back(poy);
    string rumania[11] = {"TIMISOARA","BUCAREST","IASI","","","","","","","",""};
    vector<string> ru;
    for (int i = 0;i<11;i++) {
        ru.push_back(rumania[i]);
    }
    ciudades.push_back(ru);
    int rumaniaX[11] = {50,380,470,0,0,0,0,0,0,0,0};
    vector<int> rux;
    for (int i = 0;i<11;i++) {
        rux.push_back(rumaniaX[i]);
    }
    x.push_back(rux);
    int rumaniaY[11] = {280,440,160,0,0,0,0,0,0,0,0};
    vector<int> ruy;
    for (int i = 0;i<11;i++) {
        ruy.push_back(rumaniaY[i]);
    }
    y.push_back(ruy);
    string ucrania[11] = {"KIEV","LEOPOLIS","KRIVOU ROG","ODESA","","","","","","",""};
    vector<string> ucr;
    for (int i = 0;i<11;i++) {
        ucr.push_back(ucrania[i]);
    }
    ciudades.push_back(ucr);
    int ucraniaX[11] = {290,170,360,320,0,0,0,0,0,0,0};
    vector<int> ucrx;
    for (int i = 0;i<11;i++) {
        ucrx.push_back(ucraniaX[i]);
    }
    x.push_back(ucrx);
    int ucraniaY[11] = {140,180,340,380,0,0,0,0,0,0,0};
    vector<int> ucry;
    for (int i = 0;i<11;i++) {
        ucry.push_back(ucraniaY[i]);
    }
    y.push_back(ucry);
    string bulgaria[11] = {"SOFIA","PLOVDIV","","","","","","","","",""};
    vector<string> bul;
    for (int i = 0;i<11;i++) {
        bul.push_back(bulgaria[i]);
    }
    ciudades.push_back(bul);
    int bulgariaX[11] = {90,240,0,0,0,0,0,0,0,0,0};
    vector<int> bulx;
    for (int i = 0;i<11;i++) {
        bulx.push_back(bulgariaX[i]);
    }
    x.push_back(bulx);
    int bulgariaY[11] = {280,390,0,0,0,0,0,0,0,0,0};
    vector<int> buly;
    for (int i = 0;i<11;i++) {
        buly.push_back(bulgariaY[i]);
    }
    y.push_back(buly);
    string finladia[11] = {"TAMPERE","TURKU","HELSINSKI","","","","","","","",""};
    vector<string> fin;
    for (int i = 0;i<11;i++) {
        fin.push_back(finladia[i]);
    }
    ciudades.push_back(fin);
    int finladiaX[11] = {200,120,230,0,0,0,0,0,0,0,0};
    vector<int> finx;
    for (int i = 0;i<11;i++) {
        finx.push_back(finladiaX[i]);
    }
    x.push_back(finx);
    int finladiaY[11] = {450,500,520,0,0,0,0,0,0,0,0};
    vector<int> finy;
    for (int i = 0;i<11;i++) {
        finy.push_back(finladiaY[i]);
    }
    y.push_back(finy);
    string suecia[11] = {"ESTOCOLMO","","","","","","","","","",""};
    vector<string> sue;
    for (int i = 0;i<11;i++) {
        sue.push_back(suecia[i]);
    }
    ciudades.push_back(sue);
    int sueciaX[11] = {340,0,0,0,0,0,0,0,0,0,0};
    vector<int> suex;
    for (int i = 0;i<11;i++) {
        suex.push_back(sueciaX[i]);
    }
    x.push_back(suex);
    int sueciaY[11] = {360,0,0,0,0,0,0,0,0,0,0};
    vector<int> suey;
    for (int i = 0;i<11;i++) {
        suey.push_back(sueciaY[i]);
    }
    y.push_back(suey);
    string alemania[11] = {"LICHTENSTEIN","MUNICH","HANNOVER","STTUGART","FRANKFORT","BREMEN","BERLIN","NUREMBERG","","",""};
    vector<string> ale;
    for (int i = 0;i<11;i++) {
        ale.push_back(alemania[i]);
    }
    ciudades.push_back(ale);
    int alemaniaX[11] = {210,390,310,210,150,190,490,380,0,0,0};
    vector<int> alex;
    for (int i = 0;i<11;i++) {
        alex.push_back(alemaniaX[i]);
    }
    x.push_back(alex);
    int alemaniaY[11] = {430,470,210,410,350,140,180,400,0,0,0};
    vector<int> aley;
    for (int i = 0;i<11;i++) {
        aley.push_back(alemaniaY[i]);
    }
    y.push_back(aley);
    cout<<"Termino"<<endl;
    for(size_t i = 0;i<18;i++){
        if(pais == paises[i]){
            etiquetasPaises[i]->setVisible(true);
            ClickableLabel *etiquetas[11];
            string arr[11];
            for (int m = 0;m<11;m++) {
                arr[m] = "";
            }
            char separador = '\n';
            int contador = 0;
            for(size_t p=0, q=0; p!=this->ciudades.npos; p=q){
                arr[contador] = this->ciudades.substr(p+(p!=0),(q=this->ciudades.find(separador, p+1))-p-(p!=0));
                cout<<arr[contador]<<endl;
                contador++;
            }
            cout<<"Separa"<<endl;
            int f = 0;
            while(/*arr[f] != "" &&*/ f<11){
                for(size_t d = 0;d<18;d++){
                    if(arr[f] == ciudades[i][d]){
                        cout<<"Llego :D"<<endl;
                        etiquetas[f] = new ClickableLabel(QString::fromStdString(ciudades[i][d]),this);
                        etiquetas[f]->setGeometry(x[i][d],y[i][d],0,0);
                        etiquetas[f]->adjustSize();
                        etiquetas[f]->setCursor(Qt::PointingHandCursor);
                        QObject::connect(etiquetas[f],&ClickableLabel::clicked,this,&Ciudades::mostrarAtracciones);
                        break;
                    }
                }
                f++;
            }
            return;
        }
    }
}

void Ciudades::mostrarAtracciones(QString pNombre)
{
    socket->conexion();
    string ciudad = pNombre.toUtf8().constData();
    string mensaje = socket->controlador("-3;"+pais+";"+ciudad);
    QMessageBox::information(this,"Información","Has seleccionado la ciudad: "+pNombre);
    Atracciones *ventana = new Atracciones();
    ventana->mostrarAtracciones(mensaje);
    ventana->show();
}
