//Implemetation file of Rogue class

#include <string>
#include <iostream>
#include "Rogue.h"
using namespace std;

Rogue::Rogue()
{
    assassinate = 1;
    dexterity = 3;
    poison = 3;
    poisonActive = false;
    dodge = false;
    setHealth(12);
    setArmorClass(15);
}

//Special attack for Rogue class
//Deals huge amounts of damage
int Rogue::doAssassinate(int mArmorClass)
{
    if (assassinate <= 0)
    {
        cout << "You're out of assassinates. Please choose another skill." << endl;
        cout << "---------------------------------------" << endl;
        return -1;
    }
    assassinate--;
    rogDie.setAdvantage();
    cout << "You try to find and opening in your enemy defences to deal a killing blow!" << endl;
    if (rogDie.d20()+dexterity+(2*getLevel()) >= mArmorClass)
    {
        int sneak = 0;
        for (int i = 0 ; i<10 ; i++)
        {
            sneak = sneak+rogDie.d4();
        }
        sneak = sneak+sneak;
        cout << "It hits!" << endl;
        return rogDie.d4()+sneak+dexterity;
    }
    return 0;
}

void Rogue::setAssassinate(int newAssa)
{
    assassinate = newAssa;
}

int Rogue::getAssassinate()
{
    return assassinate;
}

//Changes dodge from possitive to negative and from negative to positive
void Rogue::doDodge()
{
    if (dodge == true)
    {
        dodge = false;
        return;
    }
    if (dodge == false)
    {
        cout << "You prepare for the enemy next attack!" << endl;
        dodge = true;
    }
}

int Rogue::getPoison()
{
    return poison;
}

void Rogue::setPoison(int newPoi)
{
    poison = newPoi;
}

//Fhanges poison from positive to negative and from negative to positive
void Rogue::setPoisonActive()
{
    if (poisonActive == true)
    {
        poisonActive = false;
        return;
    }
    if (poisonActive == false)
    {
        poisonActive = true;
    }
}

bool Rogue::getPoisonActive()
{
    return poisonActive;
}

//Special attack of the Rogue class
//Changes base attack for the remainder of the fight
int Rogue::doPoison(int mArmorClass)
{
    if (poisonActive == true)
    {
        cout << "Your enemy is already poisoned. Please choose another skill." << endl;
        cout << "---------------------------------------" << endl;
        return -1;
    }
    if (poison <= 0)
    {
        cout << "You are out of poison darts. Please choose another skill." << endl;
        cout << "---------------------------------------" << endl;
        return -1;
    }
    cout << "You blow your poison covered dart towards your enemy!" << endl;
    if (rogDie.d20()+dexterity+(2*getLevel()) >= mArmorClass)
    {
        cout << "It hits!" << endl;
        setPoisonActive();
        poison--;
        return rogDie.d4()+rogDie.d6()+dexterity+rogDie.d8();
    }
    return 0;
}

void Rogue::setDexterity(int newDex)
{
    dexterity = newDex;
}

//Normal attacl function, result plus bonus need to be higher than monster AC
int Rogue::attack(int mArmorClass)
{
     cout << "You slice your dagger towards your enemy!" << endl;
     if (rogDie.d20()+dexterity+(2*getLevel()) >= mArmorClass)
    {
        cout << "It hits!" << endl;
        if (poisonActive == true)
        {
            return rogDie.d4()+rogDie.d6()+dexterity+rogDie.d8();
        }
        return rogDie.d4()+rogDie.d6()+dexterity;
    }
    return 0;
}

//Reduces the player curent health
void Rogue::takeDamage(int damage)
{
    if (damage > 0 && dodge == true)
    {
        cout << "But you manege to jump out of the way at the last second!" << endl;
    }
    else if (damage > 0)
    {
        cout << "You take " << damage << " points of damage." << endl;
    }
    if (damage == 0)
    {
        cout << "You parry the attack!!" << endl;
    }
    //If dodge is true player takes no damage
    if (dodge==true)
    {
        doDodge();
        return;
    }
    else
    {
        setHealth(-1*damage);
    }
}

void Rogue::printCharSheet()
{
    cout << getName() << " Level " << getLevel() << " rogue" << endl;
    cout << "Health: " << getHealth() << "   Armor Class: " << getArmorClass() << "   Gold: " << getGold() << endl;
    cout << "Assassinate: " << getAssassinate() << "   Poison: " << getPoison() << endl;
}

void Rogue::levelUp()
{
    setLevel();
    setHealth(-1*(getHealth()));
    setHealth(12*getLevel());
    setArmorClass(14+getLevel());
    setAssassinate(getLevel()+(getLevel()/3));
    setPoison(2+getLevel()+(getLevel()/3));
    setDexterity(2+getLevel());
}

//Used in the fight menu in dungeon.cpp
int Rogue::skill(int mArmorClass)
{
    char out;
    string sOut;
    while (true)
    {
        cout << "---------------------------------------" << endl;
        cout << "Please select a skill:" << endl;
        cout << "a - Assassinate: " << getAssassinate() << " left" << endl;
        cout << "d - Dodge" << endl;
        cout << "p - Poison: " << getPoison() << " left" << endl;
        cout << "b - Back" << endl;
        cout << "---------------------------------------" << endl;
        getline(cin,sOut);
        out = sOut[0];
        if (out == 'a' || out == 'A' || out == 'd' || out == 'D' || out == 'p' || out == 'P' || out == 'b' || out == 'B')
        {
            out = tolower(out);
            break;
        }
        cout << "Invalid option. Please enter a valid option." << endl;
    }
    int recur;
    switch(out)
    {
        case 'a':
        {
            recur = doAssassinate(mArmorClass);
            if (recur == -1)
            {
                skill(mArmorClass);
            }
            else
            {
                return recur;
            }
            return -2;
            break;
        }
        case 'd':
        {
            doDodge();
            return -2;
            break;
        }
        case 'p':
        {
            recur = doPoison(mArmorClass);
            if (recur == -1)
            {
                skill(mArmorClass);
                break;
            }
            else
            {
                return recur;
            }
            return -2;
            break;
        }
        case 'b':
        {
            return -1;
            break;
        }
        default:
        {
            break;
        }
    }
    
}