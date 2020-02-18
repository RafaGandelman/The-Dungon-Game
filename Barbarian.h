//Header file of the Barbarian class

#ifndef BARBARIAN_H
#define BARBARIAN_H
#include "Character.h"
#include "Dice.h"
#include <string>
#include <iostream>
using namespace std;

class Barbarian : public Character
{
  public:
  Barbarian();
  void setRageCount(int newRage);
  int getRageCount();
  void setTerrifyCount(int newTerr);
  int getTerrifyCount();
  void setRecklessCount(int newReck);
  int getRecklessCount();
  int toggleRage();
  void setStrength(int newStrength);
  int useReckless(int mArmorClass);
  int useTerrify();
  void untoggleRage();
  bool getTerrifyToggle();
  int attack(int mArmorClass);
  void takeDamage(int damage);
  void printCharSheet();
  void levelUp();
  int skill(int mArmorClass);
  
  
  private:
  int rageCount;
  int strength;
  int terrifyCount;
  int recklessCount;
  bool rageToggle;
  bool terrifyToggle;
  Dice barbDie;
};

#endif