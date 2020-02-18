//Implemetation file of Barbarian class

#include <string>
#include <iostream>
#include "Barbarian.h"
using namespace std;

Barbarian::Barbarian()
{
    rageCount = 2;
    strength = 3;
    terrifyCount = 1;
    recklessCount = 5;
    rageToggle = false;
    terrifyToggle = false;
    setHealth(20);
    setArmorClass(13);
}

//Setters and getters
int Barbarian::getRageCount()
{
    return rageCount;
}

void Barbarian::setRageCount(int newRage)
{
    rageCount = newRage;
}

int Barbarian::getTerrifyCount()
{
    return terrifyCount;
}

void Barbarian::setTerrifyCount(int newTerr)
{
    terrifyCount = newTerr;
}

int Barbarian::getRecklessCount()
{
    return recklessCount;
}

void Barbarian::setRecklessCount(int newReck)
{
    recklessCount = newReck;
}

//Changes rageToggle from false to true 
int Barbarian::toggleRage()
{
    if (rageToggle == true)
    {
        cout << "You're already raging. Please choose another skill" << endl;
        cout << "---------------------------------------" << endl;
        return -1;
    }
    if (rageCount <= 0)
    {
        cout << "You're out of rages. Please choose another skill." << endl;
        cout << "---------------------------------------" << endl;
        return -1;
    }
    cout << "Rahhhh" << endl;
    rageToggle = true;
    rageCount--;
    return 0;
}

//Changes rageToggle from true to false
void Barbarian::untoggleRage()
{
    rageToggle = false;
}

void Barbarian::setStrength(int newStrength)
{
    strength = newStrength;
}

//Special attack of the Barbarian class
//Similar to the attack function, but with more damage and a greater chance to hit
int Barbarian::useReckless(int mArmorClass)
{
    if (recklessCount <= 0)
    {
        cout << "You are out of heavy attacks. Please choose another skill." << endl;
        cout << "---------------------------------------" << endl;
        return -1;
    }
    cout << "You swing your greataxe with all your weight behind the attack!" << endl;
    barbDie.setAdvantage();
    if (barbDie.d20()+strength+(2*getLevel()) >= mArmorClass)
    {
        cout << "It hits!" << endl;
        return barbDie.d12()+strength+getLevel();
    }
    return 0;
}

//Changes terrify from true to false, or false to true and if terrify is false checks if the enemy will flee
int Barbarian::useTerrify()
{
    if (terrifyToggle == true)
    {
        terrifyToggle = false;
        return 0;
    }
    if (terrifyCount <= 0)
    {
        cout << "You are out of terrify. Please choose another skill." << endl;
        cout << "---------------------------------------" << endl;
        return -1;
    }
    cout << "You scream towards the enemy!";
    if (barbDie.d20()+strength+getLevel() > 10)
    {
        cout << " And it runs away in fear" << endl;
        terrifyToggle = true;
        terrifyCount--;
        return 1;
    }
    cout << " But its resolve is stronger..." << endl;
}

bool Barbarian::getTerrifyToggle()
{
    return terrifyToggle;
}

//Normal attack function, result plus bonus need to be higher than monster AC
int Barbarian::attack(int mArmorClass)
{
    cout << "You swing you're large axe!" << endl;
    if (barbDie.d20()+strength+(2*getLevel()) >= mArmorClass)
    {
        cout << "It hits!" << endl;
        return barbDie.d12()+strength;
    }
    return 0;
}

//Reduces the player current health
void Barbarian::takeDamage(int damage)
{
    //Rage reduces by half damage taken
    if (rageToggle==true)
    {
        damage = damage/2;
    }
    if (damage == 0)
    {
        cout << "But you parry it with your blade!" << endl;
    }
    else
    {
        cout << "You take " << damage << " points of damage!" << endl;
        cout << "It hurts but you're might is stronger!" << endl;
    }
    setHealth(-1*damage);
}


void Barbarian::printCharSheet()
{
    cout << getName() << " Level " << getLevel() << " barbarian" << endl;
    cout << "Health: " << getHealth() << "   Armor Class: " << getArmorClass() << "   Gold: " << getGold() << endl;
    cout << "Rages: " << getRageCount() << "   Terrify: " << getTerrifyCount() << "   Heavy Attack: " << getRecklessCount() << endl;
}

void Barbarian::levelUp()
{
    setLevel();
    setHealth(-1*(getHealth()));
    setHealth(20*getLevel());
    setArmorClass(12+getLevel());
    setRageCount(1+getLevel()+(getLevel()/3));
    setTerrifyCount(getLevel()+(getLevel()/3));
    setRecklessCount(3+(2*(getLevel())));
    setStrength(2+getLevel());
}

//Used in the fight menu in dungeon.cpp
int Barbarian::skill(int mArmorClass)
{
    char out;
    string sOut;
    while (true)
    {
        cout << "---------------------------------------" << endl;
        cout << "Please select a skill:" << endl;
        cout << "r - Rage: " << getRageCount() << " left" << endl;
        cout << "t - Terrify: " << getTerrifyCount() << " left" << endl;
        cout << "h - Heavy Attack: " << getRecklessCount() << " left" << endl;
        cout << "b - Back" << endl;
        cout << "---------------------------------------" << endl;
        getline(cin,sOut);
        out = sOut[0];
        if (out == 'r' || out == 'R' || out == 't' || out == 'T' || out == 'h' || out == 'H' || out == 'b' || out == 'B')
        {
            out = tolower(out);
            break;
        }
        cout << "Invalid option. Please enter a valid option." << endl;
    }
    int recur;
    switch(out)
    {
        case 'r':
        {
            recur = toggleRage();
            if (recur == -1)
            {
                return recur;
            }
            return -2;
            break;
        }
        case 't':
        {
            recur = useTerrify();
            if (recur == -1)
            {
                return recur;
            }
            return -2;
            break;
        }
        case 'h':
        {
            recur = useReckless(mArmorClass);
            return recur;
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