//Header file for the Dice class

#ifndef DICE_H
#define DICE_H
using namespace std;

class Dice 
{
  public:
  Dice();
  int d4();
  int d6();
  int d8();
  int d10();
  int d12();
  int d20();
  int d100();
  int dSpecific(int spec);
  void setAdvantage();
  void setDisvantage();
  
  private:
  bool advantage;
  bool disavantage;
  
};

#endif