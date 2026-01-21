#include "italianchef.h"
#include <iostream>

using namespace std;

ItalianChef::ItalianChef(string name) : Chef(name)
{
    cout << "ItalianChef " << chefName << "konstruktori" << endl;
}
ItalianChef::~ItalianChef()
{
    cout << "ItalianChef " << chefName << "Destruktori" << endl;
}
int ItalianChef::makePizza(int flour, int water)
{
    int portions = min(flour / 5, water / 5);

    cout<< "ItalianChef " <<chefName<< " with " <<flour<< " flour and "<<water<<" water can make "<<portions<<" pizzas"<<endl;
    return portions;
}
bool ItalianChef::askSecret(string salasana, int flour, int water) {
    if (salasana == password) {
        cout << "Salasana oikein" << endl;
        makePizza(flour, water);
        return true;
    } else {
        cout << "Väärä salasana!" << endl;
        return false;
    }
}
