#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum)
{

    int arvaus = 0;
    int arvausten_maara = 0;

    int luku = rand() % maxnum + 1;

    while (arvaus != luku){
        cout << "Arvaa numero" << endl;
        cin >> arvaus;
        arvausten_maara++;

        if (arvaus < luku){
            cout << "Liian matala" << endl;
        }
        else if (arvaus > luku){
            cout << "Liian korkea" << endl;
        }
        else {
            cout << "oikein!" << endl;
            cout << "sait oikein " << arvausten_maara << " arvauksella" <<endl;
        }
    }
    return arvausten_maara;
}
int main() {
    srand(time(nullptr));

    int tulos = game(40);

    return 0;
}
