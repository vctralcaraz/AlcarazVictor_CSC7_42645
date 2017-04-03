/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on April 3, 2017, 2:26 PM
 * Purpose: mastermind v1 - single user guess
 */

/********************************************************
 * 
 * This is a test of user input and minor validation
 * 
 *******************************************************/
#include "game.h"

int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0)));
    
    Game *game = new Game;

    delete game;
    
    return 0;
}