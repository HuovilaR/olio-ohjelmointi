#include <iostream>
#include "chef.h"
#include "italianchef.h"
#include <string>

using namespace std;

int main()
{
    Chef gordon("Gordon");
    gordon.makeSalad(9);
    gordon.makeSoup(14);
    cout << endl;

    Chef mario("Mario");
    ItalianChef italianChef("Mario");

    mario.makeSalad(9);
    italianChef.askSecret("pizza", 12, 12);

    return 0;
}
