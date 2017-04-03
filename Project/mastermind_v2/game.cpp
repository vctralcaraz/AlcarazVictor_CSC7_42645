/* 
 * File:   game.cpp
 * Author: Victor Alcaraz
 * Created on April 3, 2017, 2:29 PM
 * Purpose: Implementation of game
 */

#include "game.h"

Game::Game()
{
    size = 4;
    
    encrypt();
    prntCde();
    guess();
}

Game::~Game()
{
    
}

// randomize a code
void Game::encrypt()
{
    int num = 0;
    
    for(int i = 0; i < size; i++)
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

// user's guess
void Game::guess()
{
    string userG;
    
    cout << "What is your guess? ";
    getline(cin, userG);
    
    vldte(userG);
}

// validation for the user guess
void Game::vldte(string g)
{
    if(g == code) cout << "Correct!" << endl;
    else cout << "Incorrect." << endl;
}