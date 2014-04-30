#ifndef MOUSEISLAND_H
#define MOUSEISLAND_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstdlib>

using namespace std;

enum tiles{
    bridge = 0,
    mousePos = 1,
    catPos = 2,
    food = 3,
    hole = 4,
    water = -1,
    emptySpace = 5
};

class Animal
{
public:
    Animal();
    void findStart(int (&arr)[20][20]);
    int getXPos();
    int getYPos();
    int getPrevX();
    int getPrevY();
    int getPrevSpace();
    bool getDead();
    void setXPos(int newX);
    void setYPos(int newY);
    void setPrevSpace(tiles newTile);
    int xPos;
    int yPos;
    bool dead;

protected:
    int prevX;
    int prevY;
    int prevSpace;
};

class Mouse:public Animal
{
public:
    Mouse();
    void moveMouse(int (&arr)[20][20], int length, int width);
    void findStart(int (&arr)[20][20]);
    int getXPos();
    int getYPos();
    int getPrevX();
    int getPrevY();
    int getPrevSpace();
    void setXPos();
    void setYPos();
    void setPrevX();
    void setPrevY();
    void setPrevSpace();
    int starve;
    int drown;
    int murdered;
    int won;
    int starveCountdown;
    bool hidden;
};

class Cat:public Animal
{
public:
    Cat();
    void moveCat(int (&arr)[20][20], int length, int width);
    void findStart(int (&arr)[20][20]);
};

class Controller
{
public:
    Controller();
    void runSim();
    bool readFile();
    void initializeMap();
    void fillMap();
    void printMap();
    void moveAnimals();
    void setPositions();

private:
    Mouse myMouse;
    Cat myCat;
    vector <int> mapValues;
    int islandMap[20][20];
    string mapName;
    int mapLength;
    int mapWidth;
    int eatenCount;
    int drownedCount;
    int starveCount;
    int winCount;
    int numberOfSimulations;
    int holeY;
    int holeX;
    int foodX;
    int foodY;
    bool eatenFood;//has the food been eaten?
    bool inHole;//is the mouse in the hole?
};





#endif // MOUSEISLAND
