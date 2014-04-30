#include "mouseisland.h"

Animal::Animal()
{
    xPos = 0;
    yPos = 0;
    prevX = 0;
    prevY = 0;
    prevSpace = 0;
    dead = false;
}


void Animal::setXPos(int newX)
{
    xPos = newX;
}
void Animal::setYPos(int newY)
{
    yPos = newY;
}
void Animal::setPrevSpace(tiles newTile)
{
    prevSpace = newTile;
}

bool Animal::getDead()
{
    return dead;
}
