#include "luottotili.h"
#include"pankkitili.h"
#include <iostream>
#include <string>

using namespace std;

Luottotili::Luottotili(std::string omistaja, double raja)
    : Pankkitili(omistaja){

    if (raja > 0){
        luottoRaja = raja;
}   else{
    luottoRaja = 0;

    }
}
bool Luottotili::deposit(double summa){
    if (summa <= 0) {
        return false;
}
    saldo += summa;

    if (saldo > 0) {
        saldo = 0;
}

    return true;
}
bool Luottotili::withdraw(double summa)
{
    if (summa <= 0) {
        return false;
    }

    if (saldo - summa < -luottoRaja) {
        return false;
    }

    saldo -= summa;
    return true;
}
double Luottotili::getLuottoRaja() const
{
    return luottoRaja;
}
