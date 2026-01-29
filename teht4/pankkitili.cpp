#include "pankkitili.h"
#include <iostream>

using namespace std;

Pankkitili::Pankkitili(const std::string owner){
    omistaja = owner;
    saldo = 0;

}
bool Pankkitili::deposit(double s){
    if (s <= 0){
        return false;
    }
    saldo += s;
        return true;
}

bool Pankkitili::withdraw(double s){
    if (s <= 0){
        return false;
    }
    if (saldo < s){
        return false;
    }
    saldo -= s;
    return true;
}
double Pankkitili::getBalance()const{
    return saldo;
}
