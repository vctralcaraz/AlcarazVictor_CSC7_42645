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
    
public:
    Game();         // constructor
    ~Game();        // destructor
    
    void encrypt(); // code making
    void prntCde(); // code printing

};

#endif /* GAME_H */

