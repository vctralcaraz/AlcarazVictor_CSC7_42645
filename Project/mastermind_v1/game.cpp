/* 
 * File:   game.cpp
 * Author: Victor Alcaraz
 * Created on April 3, 2017, 2:29 PM
 * Purpose: Implementation of game
 */

#include "game.h"

Game::Game()
{    
    encrypt();
    
    prntCde();
}

Game::~Game()
{
    
}

// randomize a code
void Game::encrypt()
{
    int num = 0;
    
    for(int i = 0; i < 4; i++)
    {
        num = rand() % 6 + 1;   // a random number 1 - 6
        code += (num + 48);     // add the number to the code
    }
}

// print the code
void Game::prntCde()
{
    cout << "Code: " << code << endl;
}