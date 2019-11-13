#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <QString>
#include <QStringList>
#include <fstream>

//#include "libery.h"

using namespace std;

class City{
    private:
        QString cityName;
        int code;
        int numMatrix;
        bool isVisited;

    public:

        City();
        City(int pCode,int pNum, QString pName);

        QString city();

        int getCode();
        int getNumMatrix();
        QString getName();
        bool getVisit();

        void setCode(int);
        void setVisited(bool);
        void setName(QString);
        void setNum(int);

        string toString();
};

class CityNode{
    City *data;
    CityNode *next;
    CityNode *previous;

public:
    CityNode();
    CityNode(City*);
    City *getCity();
    CityNode *getNext();
    CityNode *getPrevious();

    friend class CityList;
};

//---------------------------------------------------------------------------------------

class CityList{
    CityNode *first;
public:
    CityList();
    void insert(City*);
    bool isEmpty();
    void readFile(string);
    string toString();
    void print();
    bool exists(int);
    int numVertex(int);
};


#endif // CITY_H

