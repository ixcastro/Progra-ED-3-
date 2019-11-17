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

int menuClient::menuModificacion(){
    int i = 0;
    do{
        cout<<endl;

        cout<<BANNER<<endl;
        cout<<MENU<<endl;
        cout<<BANNER<<endl;

        cout<<"1. Insertar pasillo. "<<endl;
        cout<<"2. Insertar producto en pasillo. "<<endl;
        cout<<"3. Insertar marca. "<<endl;
        cout<<"4. Insertar cliente. "<<endl;
        cout<<"5. Modificar precio. "<<endl;
        cout<<"6. Modificar porcentaje impuesto. "<<endl;
        cout<<"7. Modificar canasta básica. "<<endl;
        cout<<"8. Volver. "<<endl;


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
        case 6:{
            return 6;
        }
        case 7:{
            return 7;
        }
        case 8:{
            return 8;
        }
        default: cout<<"Opcion invalida. "<<endl;
            i = 0;
        }
    }while(i < 8);
    return -1;
}


int menuClient::menuConsultas(){
    int i = 0;
    do{
        cout<<endl;

        cout<<BANNER<<endl;
        cout<<MENU<<endl;
        cout<<BANNER<<endl;

        cout<<"1. Consultar precio. "<<endl;
        cout<<"2. Consultar si un producto es de canasta basica. "<<endl;
        cout<<"3. Consultar el porcentaje de impuesto de un producto. "<<endl;
        cout<<"4. Facturar. "<<endl;
        cout<<"5. Revisar gondolas. "<<endl;
        cout<<"6. Verificar inventario. "<<endl;
        cout<<"7. Volver. "<<endl; //Mata el servidor

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
        case 6:{
            return 6;
        }
        case 7:{
            return 7;
        }
        case 8:{
            return 8;
        }
        default: cout<<"Opcion invalida. "<<endl;
            i = 0;
        }
    }while(i<7);
    return -1;
}

int menuClient::menuReportes(){
    int i = 0;
    do{
        cout<<endl;

        cout<<BANNER<<endl;
        cout<<MENU<<endl;
        cout<<BANNER<<endl;

        cout<<"1. Pasillo  mas visitado. "<<endl;
        cout<<"2. Pasillo menos visitado. "<<endl;
        cout<<"3. Marca mas vendida . "<<endl;
        cout<<"4. Productos mas vendidos en pasillo. "<<endl;
        cout<<"5. Cliente mas compro. "<<endl;
        cout<<"6. Cliente menos compro. "<<endl;
        cout<<"7. Producto mas cargo gondola. "<<endl;
        cout<<"8. Cliente mas facturo. "<<endl;
        cout<<"9. Marcas de un producto. "<<endl;
        cout<<"10. Factura de mayor monto. "<<endl;
        cout<<"11. Productos de un pasillo. "<<endl;
        cout<<"12. Clientes super. "<<endl;
        cout<<"13. Pasillos super. "<<endl;
        cout<<"14. Inventario super. "<<endl;
        cout<<"15. Volver. "<<endl;

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
        case 6:{
            return 6;
        }
        case 7:{
            return 7;
        }
        case 8:{
            return 8;
        }
        case 9:{
            return 9;
        }
        case 10:{
            return 10;
        }
        case 11:{
            return 11;
        }
        case 12:{
            return 12;
        }
        case 13:{
            return 13;
        }
        case 14:{
            return 14;
        }
        case 15:{
            return 15;
        }
        default: cout<<"Opcion invalida. "<<endl;
            i = 0;
        }
    }while(i<15);
    return -1;
}
