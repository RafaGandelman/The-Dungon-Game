//Header file for Monster class

#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"
#include "Dice.h"
#include <iostream>
#include <string>
using namespace std;

class Monster : public Character
{
  public:
  Monster();
  void setMonster(int number);
  void setDesciption(string newDesc);
  void getDescription();
  void setBonus(int newBonus);
  int getBonus();
  void setDamageDie(int newDie);
  void takeDamage(int damage);
  int attack(int mArmorClass);
  
  
  private:
  int damageDie;
  int bonus;
  string description;
  Dice monsDie;
};

#endif