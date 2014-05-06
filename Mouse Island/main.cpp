//Jacob Daniel
//4/29/14
//CS 240
//Mouse Island OOP Style

#include "mouseisland.h"

using namespace std;

void initializeBoard(int a[][20]);
void printMap(int a[][20]);
void fillWithVector(int length, int width, vector<int> vec, int (&arr)[20][20]);

int main()
{
    srand(time(NULL));

    Controller MouseIsland;
    MouseIsland.runSim();

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

void controllerTestDriver()
{
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
}
