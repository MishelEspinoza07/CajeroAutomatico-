#include <iostream>
#include <stdio.h>
#include <limits>
#include <cstdlib>
using namespace std;

class Account{
    public:
    int correctPassword;
    int fails;
    Account(int correctPass, int failsCount){
        correctPassword = correctPass;
        fails = failsCount;
    }

    int Verifypassword() {
    int password;
    cout<<"Ingrese la contraseña: \n";
    while (fails) {
        if (!(cin >> password)) { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Por favor, ingrese solo números.\n";
        }
        else if (correctPassword == password) {
            return 1;
        } else {
            fails--;
            cout << "Tienes " << fails << " intentos\n";
        }
    }
    return 0;
}
};

class ATM{
public:
    int addMoney(){
    int mount;
    cout << "Monto a depositar: \n";
    while (!(cin >> mount)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Por favor, ingrese solo números.\n";
        cout << "Monto a depositar: \n";
    }
    return mount;
}

void balance(int money){
    cout<<"Usted cuenta con: "<< money << "$ de saldo\n";
}

int withdraw(int money){
    int mount;
    cout<< "Cuanto desea retirar:\n";
    while (!(cin >> mount)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Por favor, ingrese solo números.\n";
        cout << "Monto a retirar: \n";
    }
    if(money>=mount){
        return mount;
    }
    cout<<"Su retiro excede el saldo que tiene actualmente\n";
    return 0;
}
};

int main(){
    int options;
    int money = 0;
    bool end = 1;
    Account account = Account(1234,3);
    ATM atm = ATM();

    if(account.Verifypassword()){
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
            money += atm.addMoney();
            atm.balance(money);
            break;
        case 2:
            money -= atm.withdraw(money);
            atm.balance(money);
            break;
        case 3:
            atm.balance(money);
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