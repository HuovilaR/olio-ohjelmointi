#include <iostream>
#include "asiakas.h"

using namespace std;

int main()
{
    Asiakas henkilo1("Aapeli", 1000);
    cout << "Kayttotilin saldo " << henkilo1.talletus(0) << endl;
    henkilo1.showSaldo();
    cout << endl;

    if (henkilo1.talletus(250)) {
        cout << "Pankkitili: talletus 250 tehty" << endl;
    }
     henkilo1.showSaldo();
    cout << endl;

    Asiakas henkilo2("Liisa", 1000);
    henkilo2.showSaldo();
    cout << endl;

    cout << "Pankkitili: " << henkilo1.getNimi()
         << " siirtaa 50 " << henkilo2.getNimi() << ":lle" << endl;

    if (henkilo1.tiliSiirto(50, henkilo2)) {
        cout << henkilo1.getNimi() << " Pankkitili: nosto 50 tehty" << endl;
        cout << henkilo2.getNimi() << " Pankkitili: talletus 50 tehty" << endl;
    }

    henkilo2.showSaldo();
    cout << endl;

    return 0;
}
