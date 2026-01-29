#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include <iostream>
#include<string>
#include "pankkitili.h"


class Luottotili : public Pankkitili{
protected:
    double luottoRaja = 0;

public:
    Luottotili(std::string, double);
    bool deposit(double raja)override;
    bool withdraw(double raja)override;

    double getLuottoRaja() const;
};

#endif // LUOTTOTILI_H
