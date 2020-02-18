//header file for Map class

#ifndef MAP_H
#define MAP_H
#include <iostream>
using namespace std;

class Map
{
    public:
    Map();
    void level1();
    void level2();
    void level3();
    void move();
    void printMap();
    int getLocationY();
    int getLocationX();
    int getMapLevel();
    void setMapLevel(int newLevel);
    void setLocation(int y , int x);
    
    
    private:
    char map[20][30];
    int location[2];
    int level;
    
};

#endif