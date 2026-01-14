#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <ctime>

class Game
{
public:
    Game(int maxNumber);
    ~Game();

    void play();

private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

    void printGameResults();
};

#endif // GAME_H
