#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <iostream>
#include <string>

class Pankkitili
{
protected:
    std::string omistaja;
    double saldo = 0;

public:
    Pankkitili(const std::string omistaja);
    double getBalance() const;
    virtual bool deposit(double s);
    virtual bool withdraw(double s);

};

#endif // PANKKITILI_H
