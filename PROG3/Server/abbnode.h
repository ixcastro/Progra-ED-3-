#ifndef NODABB_H
#define NODABB_H
#include "hall.h"
#include "avltree.h"
#include "hall.h"

class ABBNode{
public:
    ABBNode();
    ABBNode(Hall*);
    //------GETS---------//

    int getOrientation();
    AVLTree* getProducts();
    ABBNode* getRightSon();
    ABBNode* getLeftSon();

    Hall *getHall();
    string getType();

    //------SETS---------//
    void setName(string pData);
    void setCodHall(int pDataHall);

    void setAVL(AVLTree* pDataSonR);
    AVLTree* getAVL();
    void setRightSon(ABBNode* pDataSonR);
    void setLeftSon(ABBNode* pDataSonL);
    void setOrientation(int pData);


    //-----------EXTRA--------------------------//
    bool itsRepitedHall(ABBNode* pRoot,int pData);
    void insertProduct(Product*);
    ABBNode* getNode(ABBNode *pRoot, int pData);

private:
    Hall *hall;
    ABBNode* RS;
    ABBNode* LR;
    AVLTree* products;
    string type;
    int Orientation;
};

#endif // NODABB_H
