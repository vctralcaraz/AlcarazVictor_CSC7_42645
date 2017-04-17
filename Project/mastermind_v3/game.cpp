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
    nTry = 10;
    nGuess = 0;
    
    // initializing 2D arrays
//    cout << "Initializing "2D" arrays" << endl;
    table = new string[nTry];
    score = new int*[nTry];
    
    // adding placeholders for the table of guess
    string temp = "";
    
    for(int i = 0; i < size; i++)
        temp += "_ ";
    
    // initialing all scores to zero
    for(int i = 0; i < nTry; i++)
        score[i] = new int[2];
    
    for(int i = 0; i < nTry; i++)
        for(int j = 0; j < 2; j++)
            score[i][j] = 0;
    
//    cout << temp << endl;
    for(int i = 0; i < nTry; i++)
        table[i] = temp;
    
    // play the game
    plyGame();
}

Game::~Game()
{
    delete []table;
}

// Play the game
void Game::plyGame()
{
    bool gameOver = false;
    
    // encrypt the code
    encrypt();
    
    // play the game while a winning or losing condition isn't met
    while(!gameOver)
    {
        // print the table
        prntTbl();
        
        // *TEMP* print the code
        prntCde();
        
        // user guesses
        // return validated guess
        gameOver = guess();
        
        if(!gameOver && (nGuess + 1) > nTry) gameOver = true; 
        
        if(gameOver) prntTbl();
    }
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
bool Game::guess()
{
    // prompt user guess
    string userG;
    
    cout << "What is your guess? ";
    getline(cin, userG);
    nGuess++;
    addGess(userG);
    // validate user guess
    return vldte(userG);
}

// validation for the user guess
bool Game::vldte(string g)
{
    // initialize a boolean check array
    bool *check = new bool[size];
    
    for(int i = 0; i < size; i++)
        check[i] = false;
    
    // initialize an array of size of 2
    int *lineScr = new int[2];
    
    for(int i = 0; i < 2; i++)
        lineScr[i] = 0;
    
    // if the guess matches the code, then output correct
    if(g == code)
    {
        cout << "Correct!" << endl;
        lineScr[1] = 4;
        addScre(lineScr);
        
        delete [] lineScr;
        delete [] check;
        return true; // game is over
    }
    
    for(int i = 0; i < size; i++)
    {
        // check the number if it's in the same index
        if(!check[i] && g[i] == code[i])
        {
            lineScr[1]++;
            check[i] = true;
        }
        else    // check the number if it exists in the code
        {
            for(int j = 0; j < size; j++)
            {
                if(!check[j] && g[i] == code[j])
                {
                    lineScr[0]++;
                    check[j] = true;
                    break;
                }
            }
        }
    }
    
    addScre(lineScr);
    
    delete [] lineScr;
    delete [] check;
    return false;
}

// print the table
void Game::prntTbl()
{
    // print table by line
    for(int i = 0; i < nTry; i++)
    {
        cout << table[i] << "|| ";
        for(int j = 0; j < 2; j++)
            cout << score[i][j] << ' ';
        
        cout << endl;
    }
}

// add the guess to the table
void Game::addGess(string g)
{
    int temp = nTry - nGuess;
    table[temp] = "";
    for(int i = 0; i < size; i++)
    {
        table[temp] += g[i];
        table[temp] += ' ';
    }
}

// add the guesses score to the score array
void Game::addScre(int *s)
{
    int temp = nTry - nGuess;
    for(int i = 0; i < 2; i++)
        score[temp][i] = s[i];
}