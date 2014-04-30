//Jacob Daniel
//4/29/14
//CS 240
//Mouse Island Take Two

#include "mouseisland.h"

void initializeBoard(int a[][20]);
void printMap(int a[][20]);
void fillWithVector(int length, int width, vector<int> vec, int (&arr)[20][20]);

int main()
{
    srand(time(NULL));
    /**int length = 4;
    int width = 5;
    int test[20][20];
    initializeBoard(test);
    vector <int> testVec;
    int position = 0;
    for (int i = 0; i < 20; i++)
    {
        testVec.push_back(3);
    }
    //printBoard(test);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            test[i][j] = 0;
        }
    }
    fillWithVector(length,width,testVec, test);

    for(int i = 0; i <length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            test[i][j] = testVec[position];
            position = position++;
        }
    }


    printMap(test);
    */

    /*Controller bob;
    bob.readFile();
    bob.initializeMap();
    bob.fillMap();
    bob.printMap();
    bob.moveAnimals();
    bob.printMap();
    bob.moveAnimals();
    bob.printMap();

    bob.moveAnimals();
    bob.printMap();*/

    Controller joe;
    joe.runSim();

    return 0;
}

void initializeBoard(int a[][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            a[i][j] = 9;//initializing everything to 9
        }
    }
}

void fillWithVector(int length, int width, vector<int> vec, int (&arr)[20][20])//fills array with values from a vec
{
    int position = 0;

    for(int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            arr[i][j] = vec[position];
            position = position++;
        }
    }
}

void printMap(int a[20][20])
{
    cout << endl;

    for (int i = 0; i < 20; i++)//change 20 to length
    {
        //cout << " | ";

        for (int j = 0; j < 20; j++)//change 20 to width
        {
            if (a[i][j] != 9)//is number != default value
            {
                cout << a[i][j] << " | ";
            }
        }
        cout <<endl;
    }
    cout << "   ---------------------------------------" << endl;
    //cout << endl;
}

