//Implemetation file of Dice class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Dice.h"
using namespace std;

Dice::Dice()
{
    srand(time(0));
    advantage = false;
    disavantage = false;
}

//Random number generators for each of the classic RPG dice
int Dice::d4()
{
    return (rand()%4)+1;
}

int Dice::d6()
{
    return (rand()%6)+1;
}

int Dice::d8()
{
    return (rand()%8)+1;
}

int Dice::d10()
{
    return (rand()%10)+1;
}

int Dice::d12()
{
    return (rand()%12)+1;
}

int Dice::d20()
{
    int die = 0, eDie = 0;
    die = (rand()%20)+1;
    //Rols twice and gets the highest score
    if (advantage == true)
    {
        eDie = (rand()%20)+1;
        advantage = false;
        if (die < eDie)
        {
            return eDie;
        }
    }
    //Rols twice and gets the lowest score
    if (disavantage == true)
    {
        eDie = (rand()%20)+1;
        disavantage = false;
        if (die > eDie)
        {
            return eDie;
        }
    }
    return die;
}

int Dice::d100()
{
    return (rand()%100)+1;
}

//Can produce a number between 1 and a specific max
int Dice::dSpecific(int spec)
{
    return (rand()%spec)+1;
}

void Dice::setAdvantage()
{
    advantage = true;
}

void Dice::setDisvantage()
{
    disavantage = true;
}