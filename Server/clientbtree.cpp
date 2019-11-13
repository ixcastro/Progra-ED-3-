#include "clientbtree.h"
QJsonArray clientList;

ClientBTree::ClientBTree(){
    root = nullptr;
}

void ClientBTree::insert(Client *pClient){
    Client *i = nullptr;
    ClientBNode *c = nullptr;
    ClientBNode *n = nullptr;
    int flag;
    flag = setValue(pClient, root, &i, &c);
    if(flag){
        n = new ClientBNode(pClient);
        n->count = 1;
        n->value[1] = i;
        n->child[0] = root;
        n->child[1] = c;
        root = n;
    }
}

int ClientBTree::setValue(Client *pClient, ClientBNode *n, Client **p, ClientBNode **c){
    int k;
    if(n == nullptr){
        *p = pClient;
        c = nullptr;
        return 1;
    }else{
        if(searchNode(pClient, n, &k)){
            //cout<<"Key value already exists"<<endl;
            return 0;
        }
        if(setValue(pClient, n->child[k], p, c)){
            if(n->count < MAXI){
                fillNode(p, *c, n, k);
                return 0;
            }else{
                split(p, *c, n, k, p, c);
                return 1;
            }
        }
        return 0;
    }
}

ClientBNode* ClientBTree::search(Client* pClient, ClientBNode *r, int *pos){
    if(r == nullptr){
        return nullptr;
    }else{
        if(searchNode(pClient, r, pos)){
            return r;
        }else{
            return search(pClient, r->child[*pos], pos);
        }
    }
}

int ClientBTree::searchNode(Client *pClient, ClientBNode *n, int *pos){
    int code1 = pClient->getId();
    int code2 = n->value[1]->getId();
    if(code1 < code2){
        *pos = 0;
        return 0;
    }else{
        *pos = n->count;
        while((pClient->getId() < n->value[*pos]->getId()) && *pos>1){
            (*pos) --;
        }
        if(pClient->getId() == n->value[*pos]->getId()){
            return 1;
        }
        return 0;
    }
}

void ClientBTree::fillNode(Client **pClient, ClientBNode *c, ClientBNode *n, int k){
    int i;
    for(i = n->count; i>k; i--){
        n->value[i+1] = n->value[i];
        n->child[i+1] = n->child[i];
    }
    n->value[k+1] = *pClient;
    n->child[k+1] = c;
    n->count++;
}

void ClientBTree::split(Client **pClient, ClientBNode *c, ClientBNode *n, int k, Client **y, ClientBNode **newNode){
    int i, mid;
    if(k <= MINI){
        mid = MINI;
    }else{
        mid = MINI + 1;
    }

    *newNode = new ClientBNode();

    for(i = mid+1; i <= MAXI; i++){
        (*newNode)->value[i - mid] = n->value[i];
        (*newNode)->child[i - mid] = n->child[i];
    }

    (*newNode)->count = MAXI - mid;
    n->count = mid;

    if(k <= MINI){
        fillNode(pClient, c, n, k);
    }else{
        fillNode(pClient, c, *newNode, k - mid);
    }

    *y = n->value[n->count];
    (*newNode)->child[0] = n->child[n->count];
    n->count--;
}

void ClientBTree::show(){
    display(root);
}

void ClientBTree::display(ClientBNode *r){
    if(r != nullptr){
        int i;
        for(i = 0; i < r->count; i++){
            display(r->child[i]);
            cout << to_string(r->value[i+1]->getId()) <<  "\t";
        }
        display(r->child[i]);
    }
}

void ClientBTree::readFile(string fileName){
    ifstream file;
    string f = fileName;
    file.open(f,ios::in);

    string t;
    QString text;

    if(file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(!file.eof()){
        getline(file,t);
        text = QString::fromStdString(t);
        QStringList data = text.split(";");

        Client *newClient = new Client(data[0].split(" ")[0].toInt(),data[1], data[2].split(" ")[0].toInt(), data[3],data[4]);
        this->insert(newClient);
    }
}

void ClientBTree::toString(){
    toString(root);
}

void ClientBTree::toString(ClientBNode *r){
    if(r != nullptr){
        int i;
        for(i = 0; i<r->count; i++){
            toString(r->child[i]);
            string str = r->value[i+1]->toString();
            QJsonValue qStr = QString::fromStdString(str);
            clientList.append(qStr);
        }
        toString(r->child[i]);
    }
}


Client* ClientBTree::searchClient(int pCode, ClientBNode *r){
    if(r != nullptr){
        if(r->value[1]->getId() == pCode){
            return r->value[1];
        }else{
            int i = r->count;
            while(pCode < r->value[i]->getId() && i > 1){
                i--;
            }
            if(pCode == r->value[i]->getId()){
                return r->value[i];
            }else{
                return searchClient(pCode, r->child[i]);
            }
        }
    }
    return nullptr;
}

//----------------------------------TO_DELETE------------------------

int ClientBTree::searchNodeInt(int id, ClientBNode *n, int *pos){
    int code1 = id;
    int code2 = n->value[1]->getId();
    if(code1 < code2){
        *pos = 0;
        return 0;
    }else{
        *pos = n->count;
        while((id < n->value[*pos]->getId()) && *pos>1){
            (*pos) --;
        }
        if(id == n->value[*pos]->getId()){
            return 1;
        }
        return 0;
    }
}

void ClientBTree::del(int id){
    ClientBNode *tmp;
    if(!delAux(id,root)){
        cout<<"Value not found"<<endl;
    }else{
        if(root->count == 0){
            tmp = root;
            root = root->child[0];
            delete tmp;
        }
    }
}
int ClientBTree::delAux(int id, ClientBNode *r){
    int i;
    int flag;
    if(r == nullptr){
        return 0;
    }else{
        flag = searchNodeInt(id,r,&i);
        if(flag){
            if(r->child[i-1]){
                copySucc(r,i);
                flag = delAux(r->value[i]->getId(),r->child[i]);
                if(!flag){
                    cout<<"Value not found..."<<endl;
                }
            }else{
                clear(r,i);
            }
        }else{
            flag = delAux(id,r->child[i]);
        }
        if(r->child[i] != nullptr){
            if(r->child[i]->getCount() < MINI){
                restore(r,i);
            }
        }
    }
    return 0;
}

void ClientBTree::clear(ClientBNode *r, int k){
    int i;
    for(i = k+1; i<=r->getCount(); i++){
        r->value[i-1] = r->value[i];
        r->child[i-1] = r->child[i];
    }
    r->count --;
}

void ClientBTree::copySucc(ClientBNode *r, int i){
    ClientBNode *tmp = r->child[i];
    while(tmp->child[0]){
        tmp = tmp->child[0];
    }
    r->value[i] = tmp->value[1];
}

void ClientBTree::restore(ClientBNode *r, int i){
    if(i == 0){
        if(r->child[1]->count > MINI){
            leftShift(1);
        }else{
            merge(1);
        }
    }else{
        if(i == r->getCount()){
            if(r->child[i-1]->count > MINI){
                rightShift(i);
            }else{
                merge(i);
            }
        }else{
            if(r->child[i-1]->count > MINI){
                rightShift(i);
            }else{
                if(r->child[i+1]->count > MINI){
                    leftShift(i+1);
                }else{
                    merge(i);
                }
            }
        }
    }
}

void ClientBTree::rightShift(int k){
    int i;
    ClientBNode *tmp;
    tmp = root->child[k];

    for(i = tmp->getCount(); i>0; i--){
        tmp->value[i+1] = tmp->value[i];
        tmp->child[i+1] = tmp->child[i];
    }

    tmp->child[1] = tmp->child[0];
    tmp->count++;
    tmp->value[1] = root->value[k];
    tmp = root->child[k-1];
    root->value[k] = tmp->value[tmp->count];
    root->child[k]->child[0] = tmp->child[tmp->getCount()];
    tmp->count--;
}

void ClientBTree::leftShift(int k){
    ClientBNode *tmp;
    tmp = root->child[k-1];
    tmp->count++;
    tmp->value[tmp->getCount()] = root->value[k];
    tmp->child[tmp->count] = root->child[k]->child[0];
    tmp = root->child[k];
    root->value[k] = tmp->value[1];
    tmp->child[0] = tmp->child[1];
    tmp->count--;

    for(int i=1; i<=tmp->count; i++){
        tmp->value[i] = tmp->value[i+1];
        tmp->child[i] = tmp->child[i+1];
    }
}

void ClientBTree::merge(int k){
    ClientBNode *tmp1, *tmp2;
    tmp1 = root->child[k];
    tmp2 = root->child[k-1];
    tmp2->count++;
    tmp2->value[tmp2->count] = root->value[k];
    tmp2->child[tmp2->count] = tmp1->child[0];
    int i;
    for(i=1; i<=tmp1->getCount(); i++){
        tmp2->count++;
        tmp2->value[tmp2->count] = tmp1->value[i];
        tmp2->child[tmp2->count] = tmp1->child[i];
    }
    for(i=k; i<root->count; i++){
        root->value[i] = root->value[i+1];
        root->child[i] = root->child[i+1];
    }
    root->count--;
    delete tmp1;
}





















