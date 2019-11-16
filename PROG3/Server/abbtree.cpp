#include "abbtree.h"

QJsonArray hallList;
//------CONSTRUCTORS------//

ABBTree::ABBTree() {
    root = nullptr;
}

//------ADD------//

void ABBTree::insert(Hall *pHall){
    if(root == nullptr){
        root = new ABBNode(pHall);
    }else{
        ABBNode *newNode = new ABBNode(pHall);
        ABBNode *aux = getRoot();
        // int para saber qeu hijo insertar 1 es derecho 2 es izq
        int auxRSon = 0;
        bool iterator = true;

        while (iterator) {
            if(pHall->getCode() > aux->getHall()->getCode()){
                if(aux->getRightSon() == nullptr){
                    auxRSon = 1; // bandera de hijo der o izq
                    iterator = false;
                }else{
                    aux = aux->getRightSon();
                }
            }else{
                if(aux->getLeftSon() ==nullptr){
                    auxRSon = 2; // bandera de hijo der o izq
                    iterator = false;
                }else{
                    aux = aux->getLeftSon();
                }
            }
        }
        if(auxRSon == 1){// si quedo en hijo derecho
            aux->setRightSon(newNode);
          newNode->setOrientation(1);
        }else{
            aux->setLeftSon(newNode);
             newNode->setOrientation(2);
        }
    }
}

//--------EXTRA----------//

ABBNode* ABBTree::getRoot() {
    return root;
}

void ABBTree::setRoot(ABBNode* pData) {
    root = pData;
}



void ABBTree::inOrder(ABBNode* pData) {
    if (pData != nullptr) {
        inOrder(pData->getLeftSon());
        cout << "[  PASILLO  ";
        cout << pData->getHall()->getCode();
        cout << "  NOMBRE  ";
        cout <<pData->getHall()->getName().toStdString()<< "] -> ";
        cout << endl;
        inOrder(pData->getRightSon());
    }
}

bool ABBTree::exists(int pData) {
    ABBNode* aux = getRoot();
    while (aux) {
        if (aux->getHall()->getCode() == pData) {
            return true;
        } else if (aux->getHall()->getCode() < pData) {
            aux = aux->getRightSon();
        } else {
            aux = aux->getLeftSon();
        }
    }
    return false;
}

ABBNode* ABBTree::getNode(int pData) {
    ABBNode* aux = getRoot();
    while (aux) {
        if (aux->getHall()->getCode() == pData) {
            return aux;
        } else if (aux->getHall()->getCode() < pData) {
            aux = aux->getRightSon();
        } else {
            aux = aux->getLeftSon();
        }
    }
    return nullptr;
}

void ABBTree::readHallFile(string fileName){
    ifstream file;
    file.open(fileName, ios::in);

    string t;
    QString text;

    if(file.fail()){
        cout<<"No se pudo abrir el archivo. "<<endl;
        exit(1);
    }

    while(!file.eof()){
        getline(file, t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        if(!exists(data[0].split(" ")[0].toInt())){
            Hall *newHall = new Hall(data[0].split(" ")[0].toInt(), data[1]);
            //cout<<newHall->toString()<<endl;
            insert(newHall);
        }
    }
}

//void ABBTree::addHallData(string pCod, string pName){

//}


void ABBTree::readProdFile(string fileName){
    ifstream file;
    file.open(fileName,ios::in);

    string t;
    QString text;

    if (file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(!file.eof()){
        //SPLIT DATA
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        if(this->exists(data[0].toInt())){
            ABBNode *aux = getNode(data[0].toInt());
            if(!aux->getProducts()->exists(data[1].toInt())){
                Product *newProduct = new Product(data[1].toInt(), data[2].toStdString());
                //cout<<newProduct->toString()<<endl;
                aux->insertProduct(newProduct);
            }
        }
    }
}

void ABBTree::readBrandFile(string fileName){
    ifstream file;
    file.open(fileName,ios::in);

    string t;
    QString text;

    if (file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(!file.eof()){
        //SPLIT DATA
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        if(this->exists(data[0].toInt())){
            ABBNode *aux = getNode(data[0].toInt());
            if(aux->getProducts()->exists(data[1].toInt())){
                AVLNode *aux2 = aux->getProducts()->getProduct(data[1].toInt());
                if(!aux2->getRN()->exists(data[2].toInt())){
                    Brand *newBrand = new Brand(data[2].toInt(), data[3], data[4].toInt(), data[5].toInt());
                    aux2->insertBrand(newBrand);

                }

            }
        }
    }
}

void ABBTree::print(ABBNode *r){
    if(r != nullptr){
        print(r->getLeftSon());
        cout<<"Pasillo: "<<endl;
        cout<<r->getHall()->toString();
        cout<<"\tProductos: "<<endl;
        r->getProducts()->print(r->getProducts()->getRoot());
        cout<<endl<<endl;
        print(r->getRightSon());
    }
}


void ABBTree::getHall(ABBNode *r){
    if(r != nullptr){
        getHall(r->getLeftSon());
        string str = r->getHall()->toString();
        QJsonValue qStr = QString::fromStdString(str);
        hallList.append(qStr);
        getHall(r->getRightSon());
    }

}

string ABBTree::getFlagStop(){
    return FlagStop;
}

string ABBTree::getFlagProcess(){
    return FlagProcess;
}

void ABBTree::setFlagStop(string Data){
    FlagStop = Data;
}

void ABBTree::setFlagProcess(string Data){
    FlagProcess = Data;
}



//--------------------BORRADO----------------------------//



void ABBTree::deleteABBData(int pData){
    cout<<"ELIMINADO "<< pData<<endl;
    ABBNode* aux;
    ABBNode* auxF=nullptr;
    ABBNode* auxMaxR;
    // verifica si el dato existe

    if(exists(pData)){


        cout<<"EL DATO EXISTE"<<endl;
        aux = getNode(pData);// obtenemos el nodo que queremos eliminar

        if(getfather(pData)->getHall()->getCode() == pData){

            if (aux->getLeftSon()!=nullptr){
                 auxF = aux->getLeftSon();
            }
            else if (aux->getRightSon()!=nullptr){
                 auxF = aux->getRightSon();
            }else{
                setRoot(nullptr);
            }

            aux->getHall()->setCode(auxF->getHall()->getCode());
            aux->getHall()->setName(auxF->getHall()->getName());

            if(auxF->getOrientation()==1 && aux->getRightSon()==nullptr){
                aux->setRightSon(nullptr);
            }
            else if(auxF->getOrientation()==1 && auxF->getRightSon()!=nullptr){// si es hijo izq
                aux->setRightSon(auxF->getRightSon());
            }

            else if(auxF->getOrientation()==2 && aux->getLeftSon()==nullptr){
                aux->setLeftSon(nullptr);
            }
            else if(auxF->getOrientation()==2 && auxF->getLeftSon()!=nullptr){// si es hijo izq
                aux->setLeftSon(auxF->getLeftSon());
            }




        }

        //si es una hoja
        else if(aux->getLeftSon()==nullptr && aux->getRightSon()==nullptr){
            cout<<"EL DATO ES UNA HOJA"<<endl;

            auxF = getfather(pData);// obtenemos el padre
            // si es hijo derecho
            if(aux->getOrientation()==1){
                auxF->setRightSon(nullptr);
            }else{// si es hijo izq
                auxF->setLeftSon(nullptr);
            }

        }
        // si tengo hijo izq pero no derecho
        else if(aux->getLeftSon()!=nullptr && aux->getRightSon()==nullptr){
             cout<<"si tengo hijo izq pero no derecho"<<endl;

            auxF = getfather(pData);// obtenemos el padre
            // si es hijo derecho
            if(aux->getOrientation()==1){
                auxF->setRightSon(aux->getLeftSon());
            }else{// si es hijo izq
                auxF->setLeftSon(aux->getLeftSon());
            }

        }
        // si tengo hijo derecho pero no izq
        else if(aux->getLeftSon()==nullptr &&aux->getRightSon()!=nullptr){
             cout<<"si tengo hijo derecho pero no izq"<<endl;
            auxF = getfather(pData);// obtenemos el padre
            // si es hijo derecho
            if(aux->getOrientation()==1){
                auxF->setRightSon(aux->getRightSon());
            }else{// si es hijo izq
                auxF->setLeftSon(aux->getRightSon());
            }

        }
        // SI TENGO HIJOS Y NO SOY LA RAIZ
        else if(aux->getLeftSon()!=nullptr &&aux->getRightSon()!=nullptr && aux->getHall()->getCode()!=getRoot()->getHall()->getCode()){
            cout<<"SI TENGO HIJOS Y NO SOY LA RAIZ"<<endl;
            int MaxR;
            // busco el max R
            auxMaxR = getMaxR(aux->getLeftSon());
            // guardo su orientacion
            MaxR = auxMaxR->getOrientation();
            // guardo al papa de max R
            auxF = getfather(auxMaxR->getHall()->getCode());// obtenemos el padre

            // cambio el nodo
            aux->getHall()->setCode(auxMaxR->getHall()->getCode());
            aux->getHall()->setName(auxMaxR->getHall()->getName());


            if(auxMaxR->getLeftSon()!=nullptr){
                // cambio el nodo
                auxMaxR->getHall()->setCode(auxMaxR->getLeftSon()->getHall()->getCode());
                auxMaxR->getHall()->setName(auxMaxR->getLeftSon()->getHall()->getName());
                auxMaxR->setLeftSon(nullptr);
            }
            else{
                auxF->setLeftSon(nullptr);
                auxF->setLeftSon(nullptr);
            }

            // goback(aux);
        }
        else{

            cout<<"SI SOY LA RAIZ"<<endl;
            int MaxR;
            // busco el max R
            auxMaxR = getMaxR(aux->getLeftSon());
            // guardo su orientacion
            MaxR = auxMaxR->getOrientation();
            // guardo al papa de max R
            auxF = getfather(auxMaxR->getHall()->getCode());// obtenemos el padre

            // cambio el nodo
            aux->getHall()->setCode(auxMaxR->getHall()->getCode());
            aux->getHall()->setName(auxMaxR->getHall()->getName());


            if(auxMaxR->getLeftSon()!=nullptr){
                // cambio el nodo
                auxMaxR->getHall()->setCode(auxMaxR->getLeftSon()->getHall()->getCode());
                auxMaxR->getHall()->setName(auxMaxR->getLeftSon()->getHall()->getName());
                auxMaxR->setLeftSon(nullptr);
            }
            else{
                auxF->setRightSon(nullptr);
            }
            setRoot(aux);
            aux->setOrientation(0);
        }
        // showGoback(aux);
    }
    else{
        cout<<"El dato "<<pData<<" no existe"<<endl;
    }
}


ABBNode* ABBTree::getMaxR(ABBNode* pData){
    ABBNode* aux = pData;
    while(aux->getRightSon()!=nullptr){
        aux= aux->getRightSon();
    }
    return aux;
}


//----------------------------[GET-FATHER-]------------------------------------//
// OBTIENE EL PADRE DE UN NODO DADO//
ABBNode* ABBTree::getfather(int pDataSon) {
    ABBNode* auxR = getRoot();// VAR DE LA RAIZ
    cout<<"Raiz del arbol "<< auxR->getHall()->getCode()<<endl;
    cout<<"elemento buscado "<< pDataSon<<endl;
    bool pBreak = true; //BOOL DEL CICLO
    while (pBreak) {

        if(auxR->getHall()->getCode() ==pDataSon){
            break;
        }
        // SI YA LLEGO A UN EXTREMO O SI YA ENCONTRO EL DATOBUSCADOA
        if (((auxR->getRightSon() != nullptr) && (auxR->getRightSon()->getHall()->getCode() == pDataSon)) |
                ((auxR->getLeftSon() != nullptr) && (auxR->getLeftSon()->getHall()->getCode() == pDataSon))
               //|(auxR->getRightSon() != nullptr)&&((auxR->getLeftSon() != nullptr) && (auxR->getLeftSon()->getProduct()->getCode() == pDataSon))
                ) {
            pBreak = false; // SALE DEL CICLO
             cout<<"Break"<< endl;
        } else if (auxR->getHall()->getCode() < pDataSon) {// SI EL DATO BUSCADOES MAYOR AL COMPARADO
            auxR = auxR->getRightSon();// ME VOY A LA DER
              cout<<"Derecha"<< endl;
        } else if (auxR->getHall()->getCode() > pDataSon) {// SINO
             cout<<"IZQ"<< endl;
            auxR = auxR->getLeftSon();// A LA IZQ
        }

    }
    return auxR;// AL TERMINAR RETORNA EL NODOD ENCOTRADO
}





