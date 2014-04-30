#include "mouseisland.h"

Controller::Controller()
{
    eatenCount = 0;
    drownedCount = 0;
    starveCount = 0;
    winCount = 0;
}

bool Controller::readFile()
{
    string userFile = "";
    string holdStr = "";
    int holdInt;
    int lineCount = 0;

    cout << "Enter your filename: ";
    cin >> userFile;
    cout << endl;

    ifstream inFile(userFile.c_str());
    if(!inFile)
    {
        cout << "File could not be opened." << endl;
        return false;
    }
    ofstream outFile("MouseStats.txt");

    while (!inFile.eof())
    {
        lineCount++;

        if (lineCount == 1)  //Line one of file is map name
        {
            getline(inFile, holdStr);
            mapName = holdStr;
            //cout << "Map Name = " << mapName << endl;
        }
        if (lineCount == 2) //Line two of file is how many times sequence should be done
        {
            getline(inFile, holdStr);
            numberOfSimulations = atoi(holdStr.c_str());
        }
        if (lineCount == 3) // Line three of file is the length of the island
        {
            getline(inFile, holdStr);
            mapLength = atoi(holdStr.c_str());
        }
        if (lineCount == 4) //Line four of file is width of the island
        {
            getline(inFile, holdStr);
            mapWidth = atoi(holdStr.c_str());
        }

        if (lineCount >= 5)  //Lines five and above are the values of the spaces on the map
        {
           for (int i = 0; i < mapWidth; i++)
           {
               inFile >> holdInt;
               if((holdInt < -1)  || holdInt > 5)
               {
                   cout << "Please use appropriate numbers for the map" << endl;
                   return false;
               }
               //cout << holdInt << endl;
               mapValues.push_back(holdInt);
           }

        } //End of line count >= 5 loop

    }//end of eof loop

    inFile.close();
///Dunno why I print here
    for(int i = 0; i < mapValues.size(); i++)
    {
        cout << mapValues[i] << endl;
    }


    return true;
}

void Controller::initializeMap()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            islandMap[i][j] = emptySpace;//initializing every space to 5
        }
    }
}

void Controller::fillMap()
{
    int position = 0;

    for(int i = 0; i < mapLength; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            islandMap[i][j] = mapValues[position];
            if (islandMap[i][j] == food)
            {
                foodY = i;
                foodX = j;
                islandMap[i][j] = bridge;
            }
            else if (islandMap[i][j] == hole)
            {
                holeY = i;
                holeX = j;
                islandMap[i][j] = bridge;
            }
            position = position++;
        }
    }
}

void Controller::printMap()
{
    cout << endl;

    for (int i = 0; i < mapLength; i++)//change 20 to length
    {
        //cout << " | ";

        for (int j = 0; j < mapWidth; j++)//change 20 to width
        {
            if (islandMap[i][j] != 5)//is number != default value
            {
                if (islandMap[i][j] == -1)
                {
                    cout << "W" << " ";
                }
                else
                {
                    cout << islandMap[i][j] << " ";
                }
            }
        }
        cout << endl;
    }
    cout << "   ---------------------------------------" << endl;
    //cout << endl;
}

void Controller::moveAnimals()
{
    //myCat.findStart(islandMap);
    //myMouse.findStart(islandMap);
    myCat.moveCat(islandMap, mapLength, mapWidth);
    myMouse.moveMouse(islandMap, mapLength, mapWidth);

    myMouse.starveCountdown--;

    if (myMouse.yPos == holeY && myMouse.xPos == holeX) //mouse is safe from cat if in hole
    {
        myMouse.hidden = true;
    }
    else
    {
        myMouse.hidden = false;
    }
    if (myMouse.yPos == foodY && myMouse.xPos == foodX && !eatenFood )//will the mouse eat the food?
    {
        myMouse.starve = 100;
        foodY = 0;
        foodX = 0;
        eatenFood = true;
    }
    //if mouse and cat on same space, mouse dies (if he isn't in mousehole)
    if (myMouse.xPos == myCat.xPos && myMouse.yPos == myCat.xPos && myMouse.hidden == false)
    {
        cout << "EATEN!" << endl;
        eatenCount = eatenCount + myMouse.murdered;
        myMouse.dead = true;
    }

    if(myMouse.starveCountdown == 0)//if mouse is starving
    {
        myMouse.dead == true;
    }
}

void Controller::runSim()
{
    int currentSim = 0;
    readFile();

    while (currentSim != numberOfSimulations)
    {
        initializeMap();
        fillMap();
        printMap();
        myMouse.findStart(islandMap);
        myCat.findStart(islandMap);
        while (!myMouse.dead || !myMouse.won)
        {
            moveAnimals();
            printMap();
            if (myMouse.dead || myMouse.won)
            {
                break;
            }
        }
        starveCount = starveCount + myMouse.starve;
        drownedCount = drownedCount + myMouse.drown;
        eatenCount = eatenCount + myMouse.murdered;
        if (myMouse.won)
        {
            winCount++;
        }

        currentSim++;
    }

    cout << eatenCount << endl;
}
