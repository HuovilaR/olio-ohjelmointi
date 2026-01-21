#include "chef.h"
#include <iostream>

using namespace std;

Chef::Chef(string name)
{
    chefName = name;
    cout << "Chef " << chefName <<" konstruktori"<< endl;
}
Chef::~Chef()
{
    cout << "Chef " << chefName << " Destruktori" << endl;
}

int Chef::makeSalad(int salad)
{
    int portions = salad / 5;

    cout << "Chef "<<chefName<<" with "<<salad<<" items can make salad "<< portions<< " portions"<< endl;
    return portions;

}
int Chef::makeSoup(int soup)
{
    int portions = soup / 3;

    cout << "Chef "<<chefName<<" with "<<soup<<" items can make soup "<< portions<< " portions"<< endl;
    return portions;

}
