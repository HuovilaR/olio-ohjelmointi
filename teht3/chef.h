#ifndef CHEF_H
#define CHEF_H
#include <string>

using namespace std;

class Chef
{
protected:
    string chefName;

public:
    Chef(string name);
    ~Chef();
    void setChefName(string);
    string getChefName();

    int makeSalad(int salad);
    int makeSoup(int soup);
};

#endif // CHEF_H
