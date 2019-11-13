#include "menuclient.h"

menuClient::menuClient()
{

}


void menuClient::setFlag(bool pBool){
    flag = pBool;

}

bool menuClient::getFlag(){
    return flag;
}




int menuClient::shareMenuCliente(){
    int i = 0;
    do{
        cout<<endl;

        cout<<BANNER<<endl;
        cout<<MENU<<endl;
        cout<<BANNER<<endl;

        cout<<"1. Consultar un precio . "<<endl;
        cout<<"2. Consultar si un producto es de la canasta . "<<endl;
        cout<<"3. Consultar el % impuesto de un producto. "<<endl;
        cout<<"4. Comprar. "<<endl;
        cout<<"5. Salir. "<<endl;


        cout<<BANNER<<endl;
        cout<<"Elija una opcion: ";
        cin>>i;
        switch (i) {
        case 1:{
            return 1;
        }
        case 2: {
             return 2;
        }
        case 3:{
             return 3;
        }
        case 4:{
             return 4;
        }
        case 5:{
            return 5;
        }
        default: cout<<"Opcion invalida. "<<endl;
            i = 0;
        }
    }while(i < 5);
    return -1;
}

int menuClient::shareMenuClienteNoRegistrado(){
    int i = 0;
    do{
        cout<<endl;

        cout<<BANNER<<endl;
        cout<<MENU<<endl;
        cout<<BANNER<<endl;

        cout<<"1. Consultar un precio . "<<endl;
        cout<<"2. Consultar si un producto es de la canasta . "<<endl;
        cout<<"3. Consultar el % impuesto de un producto. "<<endl;
        cout<<"4. Registrarse. "<<endl;
        cout<<"5. Salir. "<<endl;

        cout<<BANNER<<endl;
        cout<<"Elija una opcion: ";
        cin>>i;
        switch (i) {
        case 1:{
            return 1;
        }
        case 2: {
             return 2;
        }
        case 3:{
             return 3;
        }
        case 4:{
             return 4;
        }
        case 5:{
            return 5;
        }
        default: cout<<"Opcion invalida. "<<endl;
            i = 0;
        }
    }while(i<5);
    return -1;
}

