//Header of the Character class

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
using namespace std;

class Character
{
    public:
    Character();
    void setHealth(int changeHealth);
    int getHealth();
    void changeGold(int change);
    int getGold();
    void setName(string newName);
    string getName();
    void setArmorClass(int newArmorClass);
    int getArmorClass();
    void setLevel();
    int getLevel();
    
    
    private:
    string name;
    int level;
    int health;
    int armorClass;
    int gold;

};

#endif