//Implemetation file of Character class

#include <string>
#include <iostream>
#include "Character.h"
using namespace std;

Character::Character()
{
    name = "";
    armorClass = 0;
    health = 0;
    gold = 0;
    level = 1;
}

//Setters and getters
void Character::setHealth(int changeHealth)
{
    health = health + changeHealth;
}

int Character::getHealth()
{
    return health;
}

void Character::changeGold(int change)
{
    gold = gold + change;
}

int Character::getGold()
{
    return gold;
}

void Character::setName(string newName)
{
    name = newName;
}

string Character::getName()
{
    return name;
}

void Character::setArmorClass(int newArmorClass)
{
    armorClass = newArmorClass;
}

int Character::getArmorClass()
{
    return armorClass;
}

void Character::setLevel()
{
    level++;
}
int Character::getLevel()
{
    return level;
}