#include "seuraaja.h"
#include <iostream>

using namespace std;


Seuraaja::Seuraaja(string n) : nimi(n), next(nullptr)
{
    cout << "luodaaan seuraaja " << nimi << endl;
}

string Seuraaja::getNimi(){

    return nimi;
}
void Seuraaja::paivitys(string p){
    cout << nimi << " sai viestin " << p << endl;
}
