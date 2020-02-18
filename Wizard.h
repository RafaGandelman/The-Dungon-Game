//Header file of the Wizard class

#ifndef WIZARD_H
#define WIZARD_H
#include "Character.h"
#include "Dice.h"
#include <string>
#include <iostream>
using namespace std;

class Wizard : public Character
{
  public:
  Wizard();
  int castFireball();
  int castMagicMissile();
  int castMageArmor();
  void setFireball(int newFireball);
  void setMagicMissile(int newMagicMissile);
  void setMageArmor(int newMageArmor);
  int getFireball();
  int getMagicMissile();
  int getMageArmor();
  void setInteligence(int newIntM);
  bool endBattle();
  int attack(int mArmorClass);
  void takeDamage(int damage);
  void printCharSheet();
  void levelUp();
  int skill(int mArmorClass);
  
  private:
  int fireball;
  int inteligence;
  int magicMissile;
  int mageArmor;
  Dice wizDie;
};

#endif