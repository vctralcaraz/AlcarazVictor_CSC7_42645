/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on March 6th, 2017, 12:48 PM
 * Purpose:  Luhn Algorithm
 */

//System Libraries Here
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool validCC(string, int);
void printV(vector<string> &, vector<string> &, vector<string> &, vector<string> &, vector<string> &);
char randomN();

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    srand(static_cast<unsigned int>(time(0)));
    
    string orignal; // original number for validation
    int cLength;    // length of the card number
    int j = 0;      // index
    int tValid = 0; // total valid cards
    
    vector<string> mcard;   // vector to hold mastercard numbers
    vector<string> visa;    // vector to hold visa numbers
    vector<string> discvr;  // vector to hold discover numbers
    vector<string> amEx;    // vector to hold american express numbers
    vector<string> all;     // vector to hold all card numbers
    
    do {
        orignal = "";
        
        cLength = rand() % 6 + 13; // getting a number between 13 and 19
        
        // generating the random card number
        for(int i = 0; i < cLength; i++)
        {
            orignal += randomN();
        }

        if(validCC(orignal, cLength))
        {
            switch(cLength)
            {
                case 13:
                case 14:
                {
                    if(orignal[0] == '4')
                    {
                        visa.push_back(orignal);
                        all.push_back(orignal);
                        tValid++;
                    }
                    break;
                }
                
                case 15:
                {
                    if(orignal[0] == '4')
                    {
                        visa.push_back(orignal);
                        all.push_back(orignal);
                        tValid++;
                    }
                    else if(orignal[0] == '3')
                    {
                        if(orignal[1] == '4' || orignal[1] == '7')
                        {
                            amEx.push_back(orignal);
                            all.push_back(orignal);
                            tValid++;
                        }
                    }
                    break;
                }
                
                case 16:
                {
                    if(orignal[0] == '4')
                    {
                        visa.push_back(orignal);
                        all.push_back(orignal);
                        tValid++;
                    }
                    else if(orignal[0] == '5')
                    {
                        if(orignal[1] == '1' || orignal[1] == '2' || orignal[1] == '3' || orignal[1] == '4' || orignal[1] == '5')
                        {
                            mcard.push_back(orignal);
                            all.push_back(orignal);
                            tValid++;
                        }
                    }
                    else if(orignal[0] == '6')
                    {
                        if(orignal[1] == '4')
                        {
                            if(orignal[2] == '4' || orignal[2] == '5' || orignal[2] == '6' || orignal[2] == '7' || orignal[2] == '8' || orignal[2] == '9')
                            {
                                discvr.push_back(orignal);
                                all.push_back(orignal);
                                tValid++;
                            }
                        }
                        else if(orignal[1] == '5')
                        {
                            discvr.push_back(orignal);
                            all.push_back(orignal);
                            tValid++;
                        }
                    }
                    break;
                }
                
                case 17:
                case 18:
                case 19:
                {
                    if(orignal[0] == '5')
                    {
                        if(orignal[1] == '1' || orignal[1] == '2' || orignal[1] == '3' || orignal[1] == '4' || orignal[1] == '5')
                        {
                            mcard.push_back(orignal);
                            all.push_back(orignal);
                            tValid++;
                        }
                    }
                    break;
                }
            }
        }
    }while(tValid < 10000);
    
    int newValid = 0;
    int newInvalid = 0;
    
    while(j < 10000)
    {
        string temp = all[j];
//        if(j == 5000)
//            cout << "before: " << all[j] << endl;
        
        int change = rand() % temp.length(); // choosing which character to change
        bool updown = rand() % 2; // 1 = plus 1, 0 = minus 1;
        
        temp[change] = randomN();
//        if(updown) temp[change]++;
//        else temp[change]--;
        
        // number validation
//        if(temp[change] > '9') temp[change] -= 2;
//        else if(temp[change] < '0') temp[change] += 2;
        
//        if(j == 5000)
//            cout << "after:  " << temp << endl;
        
        // increment valid vs invalid
        if(validCC(temp, temp.length()))
            newValid++;
        else newInvalid++;
        
        j++;
    }
    
    cout << "  Valid after 1 number change: " << setw(4) << newValid << endl;
    cout << "Invalid after 1 number change: " << setw(4) << newInvalid << endl;
    printV(mcard, visa, discvr, amEx, all);
    //Exit
    return 0;
}

/************************************************
 * s -> card string
 * n -> length of that card string
 ************************************************
 * Purpose:
 *      -> Validate card string
 ***********************************************/
bool validCC(string s, int n)
{
    int total = 0;      // total sum of the number
    int mod;            // modulo number for verification
    
    string temp = "";   // temp string to hold the modified original

    temp.append(s, 0, n - 1);

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
    
    if(mod == s[n - 1] - 48)
        return true;
    return false;
}

/************************************************
 * m -> mastercard vector
 * v -> visa vector
 * d -> discover vector
 * a -> american express vector
 * c -> all vector
 ************************************************
 * Purpose:
 *      -> Print all vectors
 ***********************************************/
void printV(vector<string> &m, vector<string> &v, vector<string> &d, vector<string> &a, vector<string> &c)
{
    cout << "MasterCard Validated Cards:" << endl;
    for(int i = 0; i < m.size(); i++)
        cout << m[i] << endl;
    
    cout << endl << "Visa Validated Cards:" << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    
    cout << endl << "Discover Validated Cards:" << endl;
    for(int i = 0; i < d.size(); i++)
        cout << d[i] << endl;
    
    cout << endl << "American Express Validated Cards:" << endl;
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    
    cout << endl << "All Validated Cards:" << endl;
    for(int i = 0; i < c.size(); i++)
        cout << c[i] << endl;
}

/************************************************
 * Purpose:
 *      -> Generate random numbers as characters
 ***********************************************/
char randomN()
{
    return rand() % 10 + 48;
}