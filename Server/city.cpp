#include "city.h"

City::City() {
    code = 0;
    cityName = "";
    numMatrix = 0;
}

City::City(int pCode,int pNum, QString pName){
    code = pCode;
    cityName = pName;
    numMatrix = pNum;
}

string City::toString(){
    return "Codigo: " + to_string(code) +
        "\tNombre: " + cityName.toStdString();
}

int City::getCode(){
    return code;
}

bool City::getVisit(){
    return isVisited;
}

QString City::getName(){
    return cityName;
}

void City::setCode(int pCode){
    code = pCode;
}

void City::setName(QString pName){
    cityName = pName;
}

void City::setVisited(bool v){
    isVisited = v;
}

int City::getNumMatrix(){
    return numMatrix;
}


//*************************Nodo Ciudad******************************************************************
CityNode::CityNode(){
    data = nullptr;
    next = previous = nullptr;
}
CityNode::CityNode(City *pData){
    data = pData;
    next = previous = nullptr;
}

City* CityNode::getCity(){
    return data;
}

CityNode* CityNode::getNext(){
    return next;
}

CityNode* CityNode::getPrevious(){
    return previous;
}
//*************************Lista Doble Circular*********************************************************

CityList::CityList(){
    first = nullptr;
}

void CityList::insert(City *pData){
    if(isEmpty()){
        first = new CityNode(pData);
        first->next = first;
        first->previous = first;
    }else{
        if(!exists(pData->getCode())){
            CityNode *newCity = new CityNode(pData);
            newCity->next = first;
            newCity->previous = first->previous;
            first->previous->next = newCity;
            first->previous = newCity;
        }
    }
}

bool CityList::isEmpty(){
    return first == nullptr;
}

void CityList::readFile(string fileName){
    ifstream file;
    string f = "";
    f =  fileName;
    file.open(f,ios::in);

    string t;
    QString text;

    if (file.fail()){
            cout<<"No se pudo abrir el archivo"<<endl;
            exit(1);
    }

    int i = 0;
    while(!file.eof()){
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        if(!this->exists(data[0].split(" ")[0].toInt())){
            City *newCity = new City(data[0].split(" ")[0].toInt(),i, data[1]);
            this->insert(newCity);
            i++;
        }
    }

    //this->print();
}

string CityList::toString(){
    if(isEmpty()){
        return "No hay ciudades registradas. ";
    }else{
        CityNode *aux = first;
        string text = "";
        while(aux->next != nullptr){
            text += aux->data->toString() + "\n";
            aux = aux->next;
        }
        text += aux->data->toString() + "\n";
        return text;
    }
}

void CityList::print(){
    if(isEmpty()){
        cout<<"No hay ciudades registradas. "<<endl;
    }else{
        CityNode *aux = first;
        while(aux->next != first){
            cout<<aux->data->toString()<<endl;
            aux = aux->next;
        }
        cout<<aux->data->toString()<<endl;
    }
}

bool CityList::exists(int pCode){
    if(isEmpty()){
        return false;
    }else{
        CityNode *aux = first;
        while(aux->next != first){
            if(aux->data->getCode() == pCode){
                return true;
            }
            aux = aux->next;
        }
        return aux->data->getCode() == pCode;
    }
}

int CityList::numVertex(int code){
    if(isEmpty()){
        return -1;
    }else{
        CityNode *aux = first;
        while(aux->next != first){
            if(aux->data->getCode() == code){
                return aux->getCity()->getNumMatrix();
            }
            aux = aux->next;
        }
        return -1;
    }
}


