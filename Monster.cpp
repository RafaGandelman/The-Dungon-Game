//Implemetation file of Monster class

#include <iostream>
#include <string>
#include <fstream>
#include "Monster.h"



void split (string mother , char delimiter , string currentLine[]);

Monster::Monster()
{
    damageDie = 0;
    bonus = 0;
}

//Reads stats from monsterManual.txt file and looks for monster index, once matched copies the information to the corespondent variable
void Monster::setMonster(int number)
{
    fstream inFile;
    inFile.open("monsterManual.txt");
    if (inFile.fail())
    {
        cout << "missing monsterManual.txt" << endl;
        exit(0);
    }
    string line;
    string currentLine[7];
    while(getline(inFile,line))
    {
        if (line != "")
        {
            split(line , ',' , currentLine);
            if (stoi(currentLine[0]) == number)
            {
                setName(currentLine[1]);
                setHealth(-1*(getHealth()));
                setHealth(stoi(currentLine[2]));
                setArmorClass(stoi(currentLine[3]));
                bonus = stoi(currentLine[4]);
                damageDie = stoi(currentLine[5]);
                description = currentLine[6];
                return;
            }
        }
    }
    
}

//Setters and getters
void Monster::setDesciption(string newDesc)
{
    description = newDesc;
}

void Monster::getDescription()
{
    cout << description << endl;
}

void Monster::setBonus(int newBonus)
{
    bonus = newBonus;
}

int Monster::getBonus()
{
    return bonus;
}

void Monster::setDamageDie(int newDie)
{
    damageDie = newDie;
}

//Reduces the monster health
void Monster::takeDamage(int damage)
{
    if (damage <= 0)
    {
        cout << "But it dodges out of the way" << endl;
    }
    else
    {
        cout << "The " << getName() << " takes " << damage << " points of damage!" << endl;
    }
    setHealth(-1*(damage));
}

//Normal attack function with the difference that each monster has a different damage die and so the attack must check and roll accondingly
int Monster::attack(int mArmorClass)
{
    int damage = 0;
    switch(damageDie)
    {
        case 4:
        {
            damage = monsDie.d4();
            break;
        }
        case 6:
        {
            damage = monsDie.d6();
            break;
        }
        case 8:
        {
            damage = monsDie.d8();
            break;
        }
        case 10:
        {
            damage = monsDie.d10();
            break;
        }
        default:
        {
            break;
        }
    }
    getDescription();
    if (monsDie.d20()+bonus >= mArmorClass)
    {
        cout << "It hits!" << endl;
        return damage+bonus;
    }
    return 0;
    
}


//split.cpp from hmwk4 modified for this problem
//Function will split a string into smaller segments and save each segment in the array
void split (string mother , char delimiter , string currentLine[])
{
   int index = 0, position = 0, start = 0;
   int size = mother.length();
   for (int i = 0 ; i < size ; i++)
   {
      position = i - start;
      //Check if delimiter is in the beguining and ignores it
      if (i== 0 && mother[i] == delimiter)
      {
         start = 1;
      }
      else if (mother[i] == delimiter)
      {
         string match = mother.substr(start, position);
         //check if there are two delimiters side by side and ignores the second
         if (match.length() == 0)
         {
            start = i + 1;
         }
         else
         {
            currentLine[index] = match;
            start = i + 1;
            index++;
         }
      }
   }
   //Check for segments after last delimiter or delimiter at the end of string (ignoring delimiters at the end of string)
   if (mother[size] != delimiter)
   {
      position = size - start;
      currentLine[index] = mother.substr(start, position);
   }
}