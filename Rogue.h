//Header file of the Rogue class

#ifndef ROGUE_H
#define ROGUE_H
#include "Character.h"
#include "Dice.h"
#include <string>
#include <iostream>
using namespace std;

class Rogue : public Character
{
  public:
  Rogue();
  int doAssassinate(int mArmorClass);
  void setAssassinate(int newAssa);
  int getAssassinate();
  void doDodge();
  int getPoison();
  bool getPoisonActive();
  void setPoison(int newPoi);
  int doPoison(int mArmorClass);
  void setPoisonActive();
  void setDexterity(int newDex);
  int attack(int mArmorClass);
  void takeDamage(int damage);
  void printCharSheet();
  void levelUp();
  int skill(int mArmorClass);
  
  private:
  int assassinate;
  int dexterity;
  bool dodge;
  int poison;
  bool poisonActive;
  Dice rogDie;
};

#endif