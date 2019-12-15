#include<iostream>
#include<stdlib.h>
using namespace std;

int moveUp(int in[][3], int g[][3]);
int moveDown(int in[][3], int g[][3]);
int moveLeft(int in[][3], int g[][3]);
int moveRight(int in[][3], int g[][3]);
int minimum(int a, int b, int c, int d);
int check(int in[][3], int g[][3]);
int swap(int in[][3], int g[][3]);
void display(int in[][3]);


void display(int in[][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        cout << endl;
        for (j = 0; j < 3; j++)
        {
            cout << " " << in[i][j];
        }
        cout << endl;
    }
}

int check(int in[][3], int g[][3])    //Checks if both arrays are same or different
{
    int counter = 0, i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (in[i][j] != g[i][j])
                counter++;

    return counter;
}

int swap(int in[][3], int g[][3])      //Swaps tiles
{

    int up, down, left, right;
    int temp, i = 0, j = 0, serial = 0;
    char ran[4];

    up = moveUp(in, g);
    down = moveDown(in, g);
    left = moveLeft(in, g);
    right = moveRight(in, g);
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
                if (in[i][j] == 0)
                {
                    in[i][j] = in[i][j + 1];
                    in[i][j + 1] = 0;
                    cout << "\nRight move!\n";
                    return 0;
                }
    }

    else if (change == 'l')
    {
        for (i = 0; i < 3; i++)
            for (j = 1; j < 3; j++)
                if (in[i][j] == 0)
                {
                    in[i][j] = in[i][j - 1];
                    in[i][j - 1] = 0;
                    cout << "\nLeft move!\n";
                    return 0;
                }
    }

    else if (change == 'u')
    {
        for (i = 1; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (in[i][j] == 0)
                {
                    in[i][j] = in[i - 1][j];
                    in[i - 1][j] = 0;
                    cout << "\nUp move!\n";
                    return 0;
                }
    }

    else if (change == 'd')
    {
        for (i = 0; i < 2; i++)
            for (j = 0; j < 3; j++)
                if (in[i][j] == 0)
                {
                    in[i][j] = in[i + 1][j];
                    in[i + 1][j] = 0;
                    cout << "\nDown move!\n";
                    return 0;
                }
    }

    return 0;
}

int moveUp(int in[][3], int g[][3])
{
    int temp[3][3], i, j;

    for (i = 0; i < 3; i++)         //Stores data of original array in temp
        for (j = 0; j < 3; j++)
            temp[i][j] = in[i][j];

    for (i = 1; i < 3; i++)   //Swaps up
        for (j = 0; j < 3; j++)
            if (in[i][j] == 0)
            {
                temp[i - 1][j] = 0;
                temp[i][j] = in[i - 1][j];
            }
    return check(temp, g);
}

int moveDown(int in[][3], int g[][3])
{
    int temp[3][3], i, j;

    for (i = 0; i < 3; i++)         //Stores data of original array in temp
        for (j = 0; j < 3; j++)
            temp[i][j] = in[i][j];

    for (i = 0; i < 2; i++)   //Swaps down
        for (j = 0; j < 3; j++)
            if (in[i][j] == 0)
            {
                temp[i + 1][j] = 0;
                temp[i][j] = in[i + 1][j];
            }
    return check(temp, g);
}

int moveLeft(int in[][3], int g[][3])
{
    int temp[3][3], i, j;

    for (i = 0; i < 3; i++)       //Stores data of original array in temp
        for (j = 0; j < 3; j++)
            temp[i][j] = in[i][j];

    for (i = 0; i < 3; i++)   //Swap left
        for (j = 1; j < 3; j++)
            if (in[i][j] == 0)
            {
                temp[i][j - 1] = 0;
                temp[i][j] = in[i][j - 1];
            }
    return check(temp, g);
}

int moveRight(int in[][3], int g[][3])
{
    int temp[3][3], i, j;

    for (i = 0; i < 3; i++)       //Stores data of original array in temp
        for (j = 0; j < 3; j++)
            temp[i][j] = in[i][j];

    for (i = 0; i < 3; i++)   //Swap right
        for (j = 0; j < 2; j++)
            if (in[i][j] == 0)
            {
                temp[i][j + 1] = 0;
                temp[i][j] = in[i][j + 1];
            }
    return check(temp, g);
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
    int in[3][3];
    int val;
    cout << "Enter values for initial state: ";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> val;
                in[j][i] = val;
            }
        }
    //Goal state
    int g[3][3] =
    {
                   {0,1,2},
                   {3,4,5},
                   {6,7,8}
    };


    int i, j;
    int d;
    int steps = 0;
    cout << "Goal State: \n" << endl;
    display(g);
    cout << endl;
    cout << "\nInitial State: \n" << endl;
    display(in);
    cout << "\n" << endl;

    while (1)
    {
        d = check(in, g);
        if (d == 0)
        {
            cout << "Total steps: " << steps;
            return 0;
        }

        steps++;
        cout << "Step: " << steps;
        swap(in, g);
        display(in);
        cout << endl;


        system("PAUSE");    //Test per step
    }
}
