#ifndef ASIAKAS_H
#define ASIAKAS_H
#include <string>
#include "pankkitili.h"
#include "luottotili.h"

class Asiakas
{
private:
    std::string nimi;
    Pankkitili* kayttotili;
    Luottotili* luottotili;


public:
    Asiakas(std::string, double);
    ~Asiakas();

    std::string getNimi();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
    bool tiliSiirto(double summa, Asiakas& vastaanottaja);
};

#endif // ASIAKAS_H
