//#include <QCoreApplication>
//#include "adminmenu.h"
//#include"myserver.h"

////int main(){

////    MyServer Server;
////    Server.StartServer();

//////    adminMenu admM;
//////    admM.shareFiles();
//////    admM.shareLogin();

////    return 0;
////}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);


//    MyServer Server;
//    Server.StartServer();



//    return a.exec();
//}

//----------------------GRAFO-------------------//


#include <QCoreApplication>
#include "grafo.h"


int main(){
    City *a = new City(11,0,"A");
    City *b = new City(11,1,"B");
    City *c = new City(11,2,"C");
    City *d = new City(11,3,"D");
    City *e = new City(11,4,"E");
    City *f = new City(11,5,"F");
    City *g = new City(11,6,"G");

    vector<Connection*> connections;
    connections.push_back(new Connection(a,b,1));
    connections.push_back(new Connection(a,c,5));
    connections.push_back(new Connection(c,d,2));
    connections.push_back(new Connection(b,d,3));
    connections.push_back(new Connection(d,f,1));
    connections.push_back(new Connection(d,e,7));
    connections.push_back(new Connection(e,g,1));
    connections.push_back(new Connection(f,g,2));
    connections.push_back(new Connection(f,c,4));



    vector<City*> cities;
    cities.push_back(a);
    cities.push_back(b);
    cities.push_back(c);
    cities.push_back(d);
    cities.push_back(e);
    cities.push_back(f);
    cities.push_back(g);


    Grafo *gr = new Grafo(7,cities,connections);
    gr->getConnections();
    //------------------------JM--------------------//
    gr->dijkstra("A","G");
    //------------------------JM--------------------//


    //    vector<vector<int>> v = gr->kruskal();
    //    gr->printKruskal(v);


    //    //gr->primAlgorithm();
    //    gr->prim();


}


























//-------------JM---------------//
//#include <QCoreApplication>
//#include "adminmenu.h"
//#include"myserver.h"
//#include "avltree.h"
//#include "avlnode.h"
//#include "brand.h"

//int main(){
////    AVLTree *avl = new AVLTree();
////    avl->insert(new Product(80,"L"));
////    avl->insert(new Product(20,"L"));
////    avl->insert(new Product(95,"L"));
////    avl->insert(new Product(7,"L"));
////    avl->insert(new Product(45,"L"));
////    avl->insert(new Product(90,"L"));
////    avl->insert(new Product(120,"L"));
////    avl->insert(new Product(5,"L"));
////    avl->insert(new Product(14,"L"));

////    avl->show(avl->getRoot());
////    cout<<"raiz " << avl->getRoot()->getProduct()->getCode()<<endl;

////    avl->deleteAVLData(7);
////    cout<<endl;
////    cout<<"-------------"<<endl;
////    cout<<endl;

////    avl->show(avl->getRoot());
////    cout<<"raiz " << avl->getRoot()->getProduct()->getCode()<<endl;




//    RNTree *avl = new RNTree();
//    avl->insert(new Brand(80,"L",1,1));
//    avl->insert(new Brand(20,"L",1,1));
//    avl->insert(new Brand(95,"L",1,1));
//    avl->insert(new Brand(7,"L",1,1));
//    avl->insert(new Brand(45,"L",1,1));
//    avl->insert(new Brand(90,"L",1,1));
//    avl->insert(new Brand(120,"L",1,1));
//    avl->insert(new Brand(5,"L",1,1));
//    avl->insert(new Brand(14,"L",1,1));

//    avl->show(avl->getRoot());
//    cout<<"raiz " << avl->getRoot()->getBrand()->getCode()<<endl;

//    avl->deleteRNData(95);
//    cout<<endl;
//    cout<<"-------------"<<endl;
//    cout<<endl;

//    avl->show(avl->getRoot());
//    cout<<"raiz " << avl->getRoot()->getBrand()->getCode()<<endl;


//    return 0;
//}

////int main(int argc, char *argv[])
////{
////    QCoreApplication a(argc, argv);


////    MyServer Server;
////    Server.StartServer();



////    return a.exec();
////}

