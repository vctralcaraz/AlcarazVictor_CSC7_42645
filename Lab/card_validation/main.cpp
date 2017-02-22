/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on February 22, 2017, 11:30 AM
 * Purpose:  Luhn Algorithm
 */

//System Libraries Here
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void printV(vector<string> &);
char randomN();

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    srand(static_cast<unsigned int>(time(0)));
    
    string orignal; // original number for validation
    int total;      // total sum of the number
    int mod;        // modulo number for verification
    int i = 1;      // iterations
    
    vector<string> cNumbers;
    do {
        orignal = "";
        total = 0;
        
        for(int i = 0; i < 16; i++)
        {
            orignal += randomN();
        }

//        cout << "Original: " << orignal << endl;

        string temp;    // temp string to hold the modified original

        int length = orignal.length(); // length of the original number
        temp.append(orignal, 0, length - 1);

//        cout << "Temp: " << temp << endl;

        int tLength = temp.length();   // length of the temp string

        bool toggle = true;
        int tNum;
        for(int i = tLength - 1; i >= 0; i--)
        {
            tNum = temp[i] - 48;
            if(toggle)
            {
                tNum *= 2;
                if(tNum > 9) tNum -= 9;
                toggle = false;
            }
            else
            {
                toggle = true;
            }
            total += tNum;
        }

        mod = total % 10;

//        cout << endl << "Mod: " << mod << endl;
        if(mod == orignal[orignal.length() - 1] - 48)
            cNumbers.push_back(orignal);
    }while(i++ < 100000);
    
    printV(cNumbers);
    cout << "Number of Valid 16-Digit Credit Card Numbers: " << cNumbers.size() << endl;
    //Exit
    return 0;
}

void printV(vector<string> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

char randomN()
{
    return rand() % 10 + 48;
}