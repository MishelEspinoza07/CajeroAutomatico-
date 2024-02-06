#include <iostream>
#include <stdio.h>
using namespace std;

int Verifypassword() {
    int password;
    int correctPasword = 1234;
    int fails = 3;

    cout<<"Ingrese la constrasenia: \n";
    while (fails) {
        cin >> password;
        if (correctPasword == password) {
            return 1;
            
        } else {
            fails--;
            cout << "Tienes " << fails << " intentos\n";
        }
    }
    return 0;
}

int addMoney(){
    int mount;
    cout << "Monto a depositar: \n";
    cin >> mount;
    return mount;
}

void saldo(int money){
    cout<<"Usted cuenta con: "<< money << "$ de saldo\n";
}

int retirar(int money){
    int mount;
    cout<< "Cuanto desea retirar:\n";
    cin >> mount;
    if(money>=mount){
        return mount;
    }
    cout<<"Su retiro excede el saldo que tiene actualmente\n";
    return 0;
}

int main(){
    int options;
    int money = 0;
    bool end = 1;
    if(Verifypassword()){
        do {
            cout << "----------------------------------------------------------------\n";
            cout << "Elige una de las siguientes opciones opciones:\n";
            cout << "1. Aumentar saldo\n";
            cout << "2. Retirar\n";
            cout << "3. Ver mi saldo\n";
            cout << "4. Salir\n";
            cout << "----------------------------------------------------------------\n";
            cin >> options;
        switch (options)
        {
        case 1:
            money += addMoney();
            saldo(money);
            break;
        case 2:
            money -= retirar(money);
            saldo(money);
            break;
        case 3:
            saldo(money);
            break;
        case 4:
            end = 0;
            main();
        default:
            cout<<"Porfavor ingrese solo los numeros(1-3)\n";
            main();
        }
    }while (end);
    }else{
        cout<<"no puede ser\n";
    }
    

    return 0;
}