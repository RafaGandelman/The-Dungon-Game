//Implemetation file of Wizard class

#include <iostream>
#include "Wizard.h"
using namespace std;

Wizard::Wizard()
{
    fireball = 1;
    inteligence = 3;
    magicMissile = 3;
    mageArmor = 2;
    setHealth(15);
    setArmorClass(11);
}

//Special attack of Wizard class
//Autohits and deals a large amount of damage
int Wizard::castFireball()
{
    if (fireball <= 0)
    {
        cout << "You're out of Fireball scrolls. Please choose another skill." << endl;
        cout << "---------------------------------------" << endl;
        return -1;
    }
    fireball--;
    int fire = 0;
    cout << "As you finish the incantation, the scroll burns up and a ball of fire engulfs the enemy!" << endl;
    for (int i = 0 ; i < 8+inteligence ; i++)
    {
        fire = fire + wizDie.d8();
    }
    return fire;
}

//Speciall attack of Wizard class
//Autohist and deals a small amount of damage
int Wizard::castMagicMissile()
{
    if (magicMissile <= 0)
    {
        cout << "You're out of Magic Missile scrolls. Please choose another skill." << endl;
        cout << "---------------------------------------" << endl;
        return -1;
    }
    magicMissile--;
    int missile = 0;
    cout << "As you finish the incantation, the scroll fragments into missiles of enemy that fly towards the enemies weak points!" << endl;
    for (int i = 0 ; i<inteligence ; i++)
    {
        missile = missile + wizDie.d4() + getLevel();
    }
    return missile;
}

//Increases the player Armor Class
int Wizard::castMageArmor()
{
   if (mageArmor <= 0)
   {
       cout << "You're out of Armor of Agathys scrolls. Please choose another skill." << endl;
       cout << "---------------------------------------" << endl;
        return -1;
   }
   mageArmor--;
   cout << "As you finish the incantation, the scroll expands and a thin layer of magical energy now swirls around protecting you!" << endl;
   setArmorClass(getArmorClass()+inteligence);
   return 0;
}

//Setters and getters
void Wizard::setFireball(int newFireball)
{
    fireball = newFireball;
}

void Wizard::setMagicMissile(int newMagicMissile)
{
    magicMissile = newMagicMissile;
}

void Wizard::setMageArmor(int newMageArmor)
{
    mageArmor = newMageArmor;
}

int Wizard::getFireball()
{
    return fireball;
}

int Wizard::getMagicMissile()
{
    return magicMissile;
}

int Wizard::getMageArmor()
{
    return mageArmor;
}

void Wizard::setInteligence(int newInt)
{
    inteligence = newInt;
}

//Normal attack function, result plus bonus need to be higher than monster AC
int Wizard::attack(int mArmorClass)
{
    cout << "You swirl your fingers and a beam of freezing energy shoots towards your enemy!" << endl;
    if (wizDie.d20()+inteligence+(2*getLevel()) >= mArmorClass)
    {
        int ray = 0;
        for (int i = 0 ; i < getLevel() ; i++)
        {
            ray = ray + wizDie.d8();
        }
        ray = ray + inteligence;
        cout << "It hits!" << endl;
        return ray;
    }
    return 0;
}

void Wizard::takeDamage(int damage)
{
    if (damage == 0)
    {
        cout << "But you parry its attack!" << endl;
        return;
    }
    else
    {
        cout << "You take " << damage << " points of damage!" << endl;
    }
    setHealth(-1*damage);
}

void Wizard::printCharSheet()
{
     cout << getName() << " Level " << getLevel() << " wizard" << endl;
    cout << "Health: " << getHealth() << "   Armor Class: " << getArmorClass() << "   Gold: " << getGold() << endl;
    cout << "Fireball: " << getFireball() << "   Magic Missile: " << getMagicMissile() << "   Armor of Agathys: " << getMageArmor() << endl;
}

void Wizard::levelUp()
{
    setLevel();
    setHealth(-1*(getHealth()));
    setHealth(15*getLevel());
    setArmorClass(10+getLevel());
    setFireball(1+getLevel()+(getLevel()/3));
    setMageArmor(2+getLevel()+(getLevel()/3));
    setMagicMissile(2+(2*(getLevel())));
    setInteligence(2+getLevel());
}

int Wizard::skill(int mArmorClass)
{
    char out;
    string sOut;
    while (true)
    {
        cout << "---------------------------------------" << endl;
        cout << "Please select a skill:" << endl;
        cout << "f - Fireball: " << getFireball() << " left" << endl;
        cout << "m - Magic Missile: " << getMagicMissile() << " left" << endl;
        cout << "a - Armor of Agathys: " << getMageArmor() << " left" << endl;
        cout << "b - Back" << endl;
        cout << "---------------------------------------" << endl;
        getline(cin,sOut);
        out = sOut[0];
        if (out == 'f' || out == 'F' || out == 'm' || out == 'M' || out == 'a' || out == 'A' || out == 'b' || out == 'B')
        {
            out = tolower(out);
            break;
        }
        cout << "Invalid option. Please enter a valid option." << endl;
    }
    int recur;
    switch(out)
    {
        case 'f':
        {
            recur = castFireball();
            return recur;
            break;
        }
        case 'm':
        {
            recur = castMagicMissile();
            return recur;
        }
        case 'a':
        {
            recur = castMageArmor();
            if (recur == -1)
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