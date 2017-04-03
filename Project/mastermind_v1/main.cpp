/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on April 3, 2017, 2:26 PM
 * Purpose: mastermind v1 - code generation
 */

#include "game.h"

int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0)));
    
    for(int i = 0; i < 10; i++)
    {
        cout << i + 1 << ". ";
        Game *game = new Game;

        delete game;
    }
    
    return 0;
}

