//Implemetation file of Map class

#include "Map.h"
#include <iostream>
#include <string>
using namespace std;

Map::Map()
{
    level = 1;
    location[0] = 0;
    location [1] = 0;
    level1();
}

//Changes the map array to be equal to new level and changes the position to be the starting position for that level
void Map::level1()
{
    char level1[20][30] = {{' ','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','#'},
                           {'#','#','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','#'},
                           {'S','-','-','-','-','-','#','#','#','#','-','-','-','-','-','-','-','-','-','#','#','#','#','-','-','-','-','-','-','#'},
                           {'S','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','#'},
                           {'#','#','-','-','-','-','#','#','#','#','-','-','-','-','-','-','-','-','-','#','#','#','#','-','-','-','-','-','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','#'},
                           {' ','#','#','#','#','#','#',' ',' ','#','-','-','-','-','-','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','#'},
                           {' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','-','#','#','#'},
                           {'#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','-','#',' ',' '},
                           {'#','-','-','-','-','-','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','-','#','#','#'},
                           {'#','-','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','#'},
                           {'#','-','-','-','-','-','#','#','#','#','-','-','-','-','-','-','-','-','-','#','#','#','#','-','-','-','-','-','-','#'},
                           {'#','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','#'},
                           {'#','-','-','-','-','-','#','#','#','#','-','-','-','-','-','-','-','-','-','#','#','#','#','-','-','-','-','-','-','#'},
                           {'#','-','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','#'},
                           {'#','-','-','-','-','-','#',' ',' ','#','#','#','#','#','-','#','#','#','#','#',' ',' ','#','-','-','-','-','-','-','#'},
                           {'#','-','-','-','-','-','#',' ',' ',' ',' ',' ',' ','#','-','#',' ',' ',' ',' ',' ',' ','#','-','-','-','-','-','-','#'},
                           {'#','-','-','-','-','-','#',' ',' ',' ',' ',' ',' ','#','-','#',' ',' ',' ',' ',' ',' ','#','-','-','-','-','-','-','#'},
                           {'#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','-','#',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#'}};
    for (int i = 0 ; i < 20 ; i++)
    {
        for (int j = 0 ; j < 30; j++)
        {
            map[i][j] = level1[i][j];
        }
    }
    level = 1;
    location[0] = 19;
    location[1] = 14;
    map[location[0]][location[1]] = '@';
}

//Changes the map array to be equal to new level and changes the position to be the starting position for that level
void Map::level2()
{
    char level2[20][30] = {{' ','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','#'},
                           {'#','#','-','-','-','-','#',' ',' ','#','-','#','#','#','#','#','#','#','-','#',' ',' ','#','-','-','-','-','-','-','#'},
                           {'-','-','-','-','-','-','#','#','#','#','-','#','-','-','-','#','-','#','#','#','#','#','#','-','-','#','#','#','-','#'},
                           {'-','-','-','-','-','-','-','-','-','-','-','-','-','#','-','#','-','-','-','-','-','-','-','-','-','#','-','#','-','#'},
                           {'#','#','-','-','-','-','#','#','#','#','-','#','#','#','-','#','-','-','#','#','#','#','#','-','-','#','-','#','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','-','#','-','-','-','#','#','-','#','#',' ',' ','#','-','-','#','-','#','-','#'},
                           {' ','#','#','#','#','#','#',' ',' ','#','-','#','-','-','-','-','-','-','-','#',' ',' ','#','-','-','#','-','-','-','#'},
                           {' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','-','#','#','#'},
                           {' ','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','-','#',' ',' '},
                           {' ','#','-','-','-','-','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','-','#','#','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','-','#','-','-','-','-','-','#','-','#',' ',' ','#','-','-','-','-','#','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','-','#','-','#','#','#','-','#','-','#',' ',' ','#','#','#','#','-','#','-','#'},
                           {'#','#','-','-','-','-','#','#','#','#','-','#','-','#','-','-','-','#','-','#','#','#','#','-','-','#','-','#','-','#'},
                           {'S','-','-','-','-','-','-','-','-','-','-','-','-','#','-','#','-','#','-','-','-','-','-','-','-','#','-','-','-','#'},
                           {'#','#','-','-','-','-','#','#','#','#','-','#','#','#','-','#','-','-','-','#','#','#','#','-','#','#','-','#','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','-','-','#','-','-','#','-','#','-','#',' ',' ','#','-','#','#','-','#','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#','-','-','#','#','#','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','-','-','-','-','-','-','#'},
                           {' ','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#'}};
    for (int i = 0 ; i < 20 ; i++)
    {
        for (int j = 0 ; j < 30; j++)
        {
            map[i][j] = level2[i][j];
        }
    }
    level = 2;
    location[0] = 4;
    location[1] = 0;
    map[location[0]][location[1]] = '@';
}

//Changes the map array to be equal to new level and changes the position to be the starting position for that level
void Map::level3()
{
    char level2[20][30] = {{'#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                           {'#','T','-','-','-','-','#',' ',' ','#','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','#'},
                           {'#','T','-','-','-','-','#',' ',' ','#','-','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','-','#'},
                           {'#','T','-','-','-','-','#','#','#','#','#','#','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','#','-','#'},
                           {'#','T','-','-','-','-','-','-','-','-','-','-','-','-','#','#','#','#','#','#','#','#','#','#','#','-','#','#','-','#'},
                           {'#','T','-','-','-','-','#','#','#','#','#','#','#','#','#','-','-','-','-','-','-','-','#','-','#','-','-','#','-','#'},
                           {'#','T','-','-','-','-','#',' ',' ','#','-','-','-','-','#','-','-','-','-','-','-','-','-','-','#','#','-','#','-','#'},
                           {'#','#','#','#','#','#','#',' ',' ','#','-','#','-','-','#','#','#','#','#','#','#','-','#','-','-','-','-','#','-','#'},
                           {' ',' ',' ',' ',' ',' ',' ',' ',' ','#','-','#','-','#','#','-','-','-','-','-','#','-','#','-','#','#','#','#','-','#'},
                           {' ','#','#','#','#','#','#',' ',' ','#','-','#','-','-','#','-','#','#','#','-','#','-','#','-','#','-','-','#','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','-','#','#','#','#','-','#','-','-','-','#','-','#','-','-','-','-','#','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','-','-','-','-','#','-','#','-','-','-','#','#','#','-','#','#','-','#','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','#','#','#','-','#','-','#','#','#','-','-','-','-','-','#','-','-','#','-','#'},
                           {'#','#','-','-','-','-','#','#','#','#','-','-','#','-','#','-','-','-','#','#','#','#','#','-','#','-','#','#','-','#'},
                           {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','#','#','#','#','#','-','-','-','-','-','#','-','-','#','-','#'},
                           {'#','#','-','-','-','-','#','#','#','#','#','-','#','-','#','-','-','-','#','-','-','-','#','-','#','#','-','#','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','#','-','#','-','#','#','#','-','#','#','-','-','#','-','#','-','-','#','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','#','-','#','-','-','-','-','-','-','#','#','#','#','-','#','#','#','#','-','#'},
                           {' ','#','-','-','-','-','#',' ',' ','#','-','-','#','-','#','#','#','#','-','-','-','-','-','-','-','-','-','-','-','#'},
                           {' ','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
    for (int i = 0 ; i < 20 ; i++)
    {
        for (int j = 0 ; j < 30; j++)
        {
            map[i][j] = level2[i][j];
        }
    }
    level = 3;
    location[0] = 14;
    location[1] = 0;
    map[location[0]][location[1]] = '@';
}

//Asks for player input, checks for validity of movement and then moves player
void Map::move()
{
    char out;
    string sOut;
    printMap();
    while (true)
    {
        cout << "---------------------------------------" << endl;
        cout << "Please select a direction:" << endl;
        cout << "w - Up" << endl;
        cout << "s - Down" << endl;
        cout << "a - Left" << endl;
        cout << "d - Right" << endl;
        cout << "---------------------------------------" << endl;
        getline(cin,sOut);
        out = sOut[0];
        if (out == 'w' || out == 'W' || out == 's' || out == 'S' || out == 'a' || out == 'A' || out == 'd' || out == 'D')
        {
            out = tolower(out);
            break;
        }
        cout << "Invalid option. Please enter a valid option." << endl;
    }
    switch(out)
    {
        case 'w':
        {
            if (map[location[0]-1][location[1]] == '-')
            {
                map[location[0]][location[1]] = '-';
                location[0] = location[0]-1;
                map[location[0]][location[1]] = '@';
                break;
            }
            cout << "Invalid direction. Please enter a valid direction." << endl;
            move();
            break;
        }
        case 's':
        {
            if (map[location[0]+1][location[1]] == '-')
            {
                map[location[0]][location[1]] = '-';
                location[0] = location[0]+1;
                map[location[0]][location[1]] = '@';
                break;
            }
            cout << "Invalid direction. Please enter a valid direction." << endl;
            move();
            break;
        }
        case 'a':
        {
            if (map[location[0]][location[1]-1] == '-'  || map[location[0]][location[1]-1] == 'T')
            {
                map[location[0]][location[1]] = '-';
                location[1] = location[1]-1;
                map[location[0]][location[1]] = '@';
                break;
            }
            if (map[location[0]][location[1]-1] == 'S')
            {
                if (level == 1)
                {
                    level2();
                    break;
                }
                if (level == 2)
                {
                    level3();
                    break;
                }
            }
            cout << "Invalid direction. Please enter a valid direction." << endl;
            move();
            break;
        }
        case 'd':
        {
            if (map[location[0]][location[1]+1] == '-')
            {
                map[location[0]][location[1]] = '-';
                location[1] = location[1]+1;
                map[location[0]][location[1]] = '@';
                break;
            }
            cout << "Invalid direction. Please enter a valid direction." << endl;
            move();
            break;
        }
    }
}

//Prints the map in an area of 9x9 centered on the player
void Map::printMap()
{
    int maxY = 0;
    int minY = 0;
    int maxX = 0;
    int minX = 0;
    if (getLocationY()-4 <= 0)
    {
        maxY = 0;
    }
    else
    {
        maxY = getLocationY()-4;
    }
    if (getLocationY()+4 >= 19)
    {
        minY = 19;
    }
    else
    {
        minY = getLocationY()+4;
    }
    if (getLocationX()-4 <= 0)
    {
        maxX = 0;
    }
    else
    {
        maxX = getLocationX()-4;
    }
    if (getLocationX()+4 >= 29)
    {
        minX = 29;
    }
    else
    {
        minX = getLocationX()+4;
    }
    for (int i = maxY ; i <= minY ; i++)
    {
        for (int j = maxX ; j <= minX ; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

//Getters
int Map::getLocationY()
{
    return location[0];
}

int Map::getLocationX()
{
    return location[1];
}

int Map::getMapLevel()
{
    return level;
}

void Map::setMapLevel(int newLevel)
{
    switch(newLevel)
    {
        case 1:
        {
            level1();
            break;
        }
        case 2:
        {
            level2();
            break;
        }
        case 3:
        {
            level3();
            break;
        }
        default:
        {
            break;
        }
    }
}

void Map::setLocation(int y , int x)
{
    map[location[0]][location[1]] = '-';
    location[0] = y;
    location[1] = x;
    map[location[0]][location[1]] = '@';
}