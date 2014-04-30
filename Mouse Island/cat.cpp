#include "mouseisland.h"

Cat::Cat()
{
    dead = false;
    prevSpace = bridge;
}

void Cat::findStart(int (&arr)[20][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (arr[i][j] == catPos)
            {
                yPos = i;
                xPos = j;
            }
        }
    }
}

void Cat::moveCat(int (&arr)[20][20], int length, int width)
{
    bool validMove = false;
    int mapW = width - 1;
    int mapL = length - 1;
    while (!validMove)
    {
        int direction = rand() % 4 + 1;
        int tempX = xPos;
        int tempY = yPos;
        int checkX = xPos;
        int checkY = yPos;

        switch (direction)
        {
        case 1:
            if (tempY - 1 > 0)
            {
                if (arr[checkY-1][checkX] != water)
                {
                    arr[yPos][xPos] = bridge;
                    yPos--;
                    arr[yPos][xPos] = catPos;
                    validMove = true;
                }
            }
            break;
        case 2:
            if (tempY + 1 < mapL)
            {
                if (arr[checkY+1][checkX] != water)
                {
                    arr[yPos][xPos] = bridge;
                    yPos++;
                    arr[yPos][xPos] = catPos;
                    validMove = true;
                }
            }
            break;
        case 3:
            if (tempX + 1 < mapW)
            {
                if (arr[checkY][checkX+1] != water)
                {
                    arr[yPos][xPos] = bridge;
                    xPos++;
                    arr[yPos][xPos] = catPos;
                    validMove = true;
                }
            }
            break;
        case 4:
            if (tempX - 1 > 0)
            {
                if (arr[checkY][checkX-1] == water)
                {
                    arr[yPos][xPos] = bridge;
                    xPos--;
                    arr[yPos][xPos] = catPos;
                    validMove = true;
                }
            }
            break;
        default:
            break;
        }
    }
}
