#include "game.h"
using namespace std;

Game::Game(int maxNumber) {

    srand(time(NULL));
    randomNumber = rand() % maxNumber + 1;

    this->maxNumber = maxNumber;
    numOfGuesses = 0;
    playerGuess = 0;
}
Game::~Game(){
}
void Game::play(){

    while (playerGuess != randomNumber){
        cout << "Arvaa numero valilta 1 ja "<< maxNumber << endl;
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess < randomNumber){
            cout << "Liian matala" << endl;
        }
        else if (playerGuess > randomNumber){
            cout << "Liian korkea" << endl;
        }
        else {
            cout << "oikein!" << endl;
            cout << "sait oikein " << numOfGuesses << " arvauksella" <<endl;

            }
        }
    }

