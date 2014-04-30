#include "mouseisland.h"

Mouse::Mouse()
{
    starve = 0;
    drown = 0;
    murdered = 0;
    won = 0;
    prevSpace = 0;
    hidden = false;
    starveCountdown = 100;
}

void Mouse::findStart(int (&arr)[20][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (arr[i][j] == mousePos)
            {
                yPos = i;
                xPos = j;
            }
        }
    }
}

void Mouse::moveMouse(int (&arr)[20][20], int length, int width)
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
                if (arr[checkY-1][checkX] == water)
                {
                    drown++;
                    dead = true;
                    cout << "DROWNED!" << endl;
                }
                else if (arr[checkY-1][checkX] == food)
                {
                    starveCountdown = 100;
                }
                else if (arr[checkY-1][checkX] == catPos)
                {
                    dead = true;
                    cout << "EATEN!" << endl;
                }
                arr[yPos][xPos] = prevSpace;
                prevX = xPos;
                prevY = yPos;
                yPos--;
                arr[yPos][xPos] = catPos;
                validMove = true;
            }
            break;
        case 2:
            if (tempY + 1 < mapL)
            {
                if (arr[checkY+1][checkX] == water)
                {
                    drown++;
                    dead = true;
                    cout << "DROWNED!" << endl;
                }
                else if (arr[checkY+1][checkX] == food)
                {
                    starveCountdown = 100;
                }
                else if (arr[checkY+1][checkX] == catPos)
                {
                    dead = true;
                    cout << "EATEN!" << endl;
                }
                arr[yPos][xPos] = prevSpace;
                prevX = xPos;
                prevY = yPos;
                prevSpace = arr[prevY][prevX];
                yPos++;
                arr[yPos][xPos] = mousePos;
                validMove = true;
            }
            break;
        case 3:
            if (tempX + 1 < mapW)
            {
                if (arr[checkY][checkX+1] == water)
                {
                    drown++;
                    dead = true;
                    cout << "DROWNED!" << endl;
                }
                else if (arr[checkY][checkX+1] == food)
                {
                    starveCountdown = 100;
                }
                else if (arr[checkY][checkX+1] == catPos)
                {
                    dead = true;
                    cout << "EATEN!" << endl;
                }
                arr[yPos][xPos] = prevSpace;
                prevX = xPos;
                prevY = yPos;
                prevSpace = arr[prevY][prevX];
                xPos++;
                arr[yPos][xPos] = mousePos;
                validMove = true;
            }
            break;
        case 4:
            if (tempX - 1 > 0)
            {
                if (arr[checkY][checkX-1] == water)
                {
                    cout << "Drowned!!!" << endl;
                    drown++;
                    dead = true;
                }
                else if (arr[checkY][checkX-1] == food)
                {
                    starveCountdown = 100;
                }
                else if (arr[checkY][checkX-1] == catPos)
                {
                    cout << "Eaten!!!" << endl;
                    dead = true;
                }
                arr[yPos][xPos] = prevSpace;
                prevX = xPos;
                prevY = yPos;
                prevSpace = arr[prevY][prevX];
                xPos--;
                arr[yPos][xPos] = mousePos;
                validMove = true;
            }
            break;
        default:
            break;
        }
    }

    if(((yPos == 0 || yPos == length - 1) || (xPos == 0 || xPos == width - 1)) && arr[yPos][xPos] == bridge)
    {
        won = true;
    }
}
