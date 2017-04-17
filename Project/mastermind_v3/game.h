/* 
 * File:   game.h
 * Author: Victor Alcaraz
 * Created on April 3, 2017, 2:29 PM
 * Purpose: Specification of game
 */

#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Game {
private:
    string code;    // The code to be broken
    int size;       // size of the code
    string *table;  // "2D" array that holds the table of guesses
    int **score;    // 2D array that holds the guesses score
    int nTry;       // number of tries in the game
    int nGuess;     // guess number
    
public:
    Game();     // constructor
    ~Game();    // destructor
    
    void encrypt();         // code making
    void prntCde();         // code printing
    void prntTbl();         // table printing
    bool guess();           // user input (guess)
    bool vldte(string);     // validate the guess
    void addGess(string);   // add guess to the table
    void addScre(int *);    // add the guesses score to the score array
    void plyGame();         // play the game
};

#endif /* GAME_H */