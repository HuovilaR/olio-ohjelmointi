#include "asiakas.h"
#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"

using namespace std;

Asiakas::Asiakas(string n, double luottoraja) {
    nimi = n;
    kayttotili = new Pankkitili(nimi);
    luottotili = new Luottotili(nimi, luottoraja);

    cout<< "Pankkitili luotu " << nimi << ":lle" << endl;
    cout << "Luottotili luotu " << nimi <<":lle, luottoraja on " << luottoraja << endl;
    cout << "Asiakkuus luotu " << nimi << endl;
}
Asiakas::~Asiakas(){

    delete kayttotili;
    delete luottotili;
}
string Asiakas::getNimi(){

    return nimi;
}
void Asiakas::showSaldo(){

    cout << "Kayttotilin saldo: "<< kayttotili->getBalance() << endl;

    double kaytettava = luottotili->getBalance() + luottotili->getLuottoRaja();
    cout << "Luottotilin saldo: "<< kaytettava << endl;
}

bool Asiakas::talletus(double summa){
    return kayttotili->deposit(summa);
}

bool Asiakas::nosto(double summa){
    return kayttotili->withdraw(summa);
}

bool Asiakas::luotonMaksu(double summa){
    return luottotili->deposit(summa);
}

bool Asiakas::luotonNosto(double summa){
    return luottotili->withdraw(summa);
}

bool Asiakas::tiliSiirto(double summa, Asiakas& vastaanottaja){
    if (summa <= 0)
        return false;

    if (!kayttotili->withdraw(summa))
        return false;

    if (!vastaanottaja.talletus(summa)){
        kayttotili->deposit(summa);
        return false;
    }

    cout << "Tilisiirto " << summa << "" << nimi << " -> " << vastaanottaja.getNimi() << endl;

    return true;
}
