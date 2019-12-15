#include<iostream>
#include<stdlib.h>
using namespace std;

int moveUp(int goal[][3], int initial[][3]);
int moveDown(int goal[][3], int initial[][3]);
int moveLeft(int goal[][3], int initial[][3]);
int moveRight(int goal[][3], int initial[][3]);
int minimum(int a, int b, int c, int d);
int check(int goal[][3], int initial[][3]);
int swap(int goal[][3], int initial[][3]);
void display(int goal[][3]);


void display(int goal[][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        cout << endl;
        for (j = 0; j < 3; j++)
        {
            cout << " " << goal[i][j];
        }
        cout << endl;
    }
}

int check(int goal[][3], int initial[][3])    //Checks if both arrays are same or different
{
    int counter = 0, i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (goal[i][j] != initial[i][j])
                counter++;

    return counter;
}

int swap(int goal[][3], int initial[][3])      //Swaps tiles
{

    int up, down, left, right;
    int temp, i = 0, j = 0, serial = 0;
    char ran[4];

    up = moveUp(goal, initial);
    down = moveDown(goal, initial);
    left = moveLeft(goal, initial);
    right = moveRight(goal, initial);
    int min = minimum(up, down, left, right);

    if (min == right)
        ran[serial++] = 'r';
    if (min == left)
        ran[serial++] = 'l';
    if (min == up)
        ran[serial++] = 'u';
    if (min == down)
        ran[serial++] = 'd';


    int sel = rand() % serial;
    char change = ran[sel];

    if (change == 'r')
    {
        for (i = 0; i < 3; i++)
            for (j = 0; j < 2; j++)
                if (goal[i][j] == 0)
                {
                    goal[i][j] = goal[i][j + 1];
                    goal[i][j + 1] = 0;
                    cout << "\nRight move!\n";
                    return 0;
                }
    }

    else if (change == 'l')
    {
        for (i = 0; i < 3; i++)
            for (j = 1; j < 3; j++)
                if (goal[i][j] == 0)
                {
                    goal[i][j] = goal[i][j - 1];
                    goal[i][j - 1] = 0;
                    cout << "\nLeft move!\n";
                    return 0;
                }
    }

    else if (change == 'u')
    {
        for (i = 1; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (goal[i][j] == 0)
                {
                    goal[i][j] = goal[i - 1][j];
                    goal[i - 1][j] = 0;
                    cout << "\nUp move!\n";
                    return 0;
                }
    }

    else if (change == 'd')
    {
        for (i = 0; i < 2; i++)
            for (j = 0; j < 3; j++)
                if (goal[i][j] == 0)
                {
                    goal[i][j] = goal[i + 1][j];
                    goal[i + 1][j] = 0;
                    cout << "\nDown move!\n";
                    return 0;
                }
    }

    return 0;
}

int moveUp(int goal[][3], int initial[][3])
{
    int temp[3][3], i, j;

    for (i = 0; i < 3; i++)         //Stores data of original array in temp
        for (j = 0; j < 3; j++)
            temp[i][j] = goal[i][j];

    for (i = 1; i < 3; i++)   //Swaps up
        for (j = 0; j < 3; j++)
            if (goal[i][j] == 0)
            {
                temp[i - 1][j] = 0;
                temp[i][j] = goal[i - 1][j];
            }
    return check(temp, initial);
}

int moveDown(int goal[][3], int initial[][3])
{
    int temp[3][3], i, j;

    for (i = 0; i < 3; i++)         //Stores data of original array in temp
        for (j = 0; j < 3; j++)
            temp[i][j] = goal[i][j];

    for (i = 0; i < 2; i++)   //Swaps down
        for (j = 0; j < 3; j++)
            if (goal[i][j] == 0)
            {
                temp[i + 1][j] = 0;
                temp[i][j] = goal[i + 1][j];
            }
    return check(temp, initial);
}

int moveLeft(int goal[][3], int initial[][3])
{
    int temp[3][3], i, j;

    for (i = 0; i < 3; i++)       //Stores data of original array in temp
        for (j = 0; j < 3; j++)
            temp[i][j] = goal[i][j];

    for (i = 0; i < 3; i++)   //Swap left
        for (j = 1; j < 3; j++)
            if (goal[i][j] == 0)
            {
                temp[i][j - 1] = 0;
                temp[i][j] = goal[i][j - 1];
            }
    return check(temp, initial);
}

int moveRight(int goal[][3], int initial[][3])
{
    int temp[3][3], i, j;

    for (i = 0; i < 3; i++)       //Stores data of original array in temp
        for (j = 0; j < 3; j++)
            temp[i][j] = goal[i][j];

    for (i = 0; i < 3; i++)   //Swap right
        for (j = 0; j < 2; j++)
            if (goal[i][j] == 0)
            {
                temp[i][j + 1] = 0;
                temp[i][j] = goal[i][j + 1];
            }
    return check(temp, initial);
}

int minimum(int a, int b, int c, int d)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    if (d < min)
        min = d;

    return min;
}

int main()
{
    //Initial state
    int goal[3][3] =
    {
                   {2,8,3},
                   {1,6,4},
                   {7,0,5}
    };

    //Goal state
    int initial[3][3] =
    {
                   {0,1,2},
                   {3,4,5},
                   {6,7,8}
    };


    int i, j;
    int d;
    int steps = 0;
    cout << "Goal State: \n" << endl;
    display(initial);
    cout << endl;
    cout << "\nInitial State: \n" << endl;
    display(goal);
    cout << "\n" << endl;

    while (1)
    {
        d = check(goal, initial);
        if (d == 0)
        {
            cout << "Total steps: " << steps;
            return 0;
        }

        steps++;
        cout << "Step: " << steps;
        swap(goal, initial);
        display(goal);
        cout << endl;


        system("PAUSE");    //Test per step
    }
}
