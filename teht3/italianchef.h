#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include <string>
#include "chef.h"


using namespace std;

class ItalianChef : public Chef
{
private:
    string password = "pizza";
    int flour;
    int water;

    int makePizza(int flour, int water);

public:
    ItalianChef(string name);
    ~ItalianChef();

    bool askSecret(string password, int flour, int water);


};

#endif // ITALIANCHEF_H
