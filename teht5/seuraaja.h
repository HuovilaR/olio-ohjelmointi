#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <string>

class Seuraaja
{
private:
    std::string nimi;

public:
    Seuraaja* next = nullptr;
    Seuraaja(std::string n);
    std::string getNimi();
    void paivitys(std::string p);
};

#endif // SEURAAJA_H
