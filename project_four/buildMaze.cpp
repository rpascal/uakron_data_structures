
#include <iostream>
#include <string>
#include <limits>
#include "./mazeCell/mazeCell.h"
#include "./maze/maze.h"
#include "./DisjSets/DisjSets.h"

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;

void twoRandom(int &n1, int &n2, int maxN);
bool isConnected(int n1, int n2);
void inputData(int &rows, int &cols, string &seeIteration);

int main(int argc, const char *argv[])
{
    int rows = 0;
    int cols = 0;
    string seeIteration;

    inputData(rows, cols, seeIteration);

    maze m(rows, cols);

    cout << "Hello world" << m.getRow() << "  " << m.getCol() << "  " << seeIteration << "  " << endl;
    return 0;
}

void inputData(int &rows, int &cols, string &seeIteration)
{

    for (;;)
    {
        cout << "Please enter the number of rows greater than 1: ";
        if (cin >> rows)
        {
            if (rows > 0)
            {
                break;
            }
            else
            {
                cout << "Please enter an integer greater than 1" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (;;)
    {
        cout << "Please enter the number of columns greater than 1: ";
        if (cin >> cols)
        {
            if (cols > 0)
            {
                // cout << endl;
                break;
            }
            else
            {
                cout << "Please enter an integer greater than 1" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (;;)
    {
        cout << "Would you like to see each iteration of the maze: ";
        if (cin >> seeIteration)
        {
            if (seeIteration == "n" || seeIteration == "y")
            {
                // cout << endl;
                break;
            }
            else
            {
                cout << "Please enter either 'y' or 'n'" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}