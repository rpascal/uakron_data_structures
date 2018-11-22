#include "maze.h"
#include "../mazeCell/mazeCell.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;
/**
 * Construct the disjoint sets object.
 */
maze::maze(int r, int c)
{
    row = r;
    col = c;

    int numCells = getTotal();

    for (int i = 0; i < numCells; ++i)
    {
        mazeCell c;

        if (i == 0)
        {
            c.setLeft(false);
            c.setTop(false);
        }
        else if (i == numCells - 1)
        {
            c.setRight(false);
            c.setBot(false);
        }
        theMaze.push_back(c);
    }
}

// returns true if neigh is cell's neighbor
//(i.e. in position left, right, top or bot
// with respect to cell)
bool maze::neighbors(int cell, int neigh) const
{
    int cellCol = determineColumn(cell);
    int cellRow = determineRow(cell);
    int neighCol = determineColumn(neigh);
    int neighRow = determineRow(neigh);

    int colDif = cellCol - neighCol;
    int rowDif = cellRow - neighRow;

    if (abs(colDif) > 1 || abs(rowDif) > 1)
    {
        return false;
    }

    return (colDif == -1 && rowDif == 0) || (colDif == 1 && rowDif == 0) || (colDif == 0 && rowDif == 1) || (colDif == 0 && rowDif == -1);
}

// get rid of cell's wall between cell and neighbor
// Note: this method should be invoked twice from the driver
// code to smashWall(a,b) and to smashWall(b,a)
void maze::smashWall(int cell, int neigh)
{

    int cellCol = determineColumn(cell);
    int cellRow = determineRow(cell);
    int neighCol = determineColumn(neigh);
    int neighRow = determineRow(neigh);

    int colDif = cellCol - neighCol;
    int rowDif = cellRow - neighRow;

    mazeCell &cellCell = theMaze[cell];
    mazeCell &neighCell = theMaze[neigh];

    if (colDif == 1 && rowDif == 0)
    {
        // Neighbor is to the left
        cellCell.setLeft(false);
        neighCell.setRight(false);
    }
    else if (colDif == -1 && rowDif == 0)
    {
        // Neighbor is to the right
        cellCell.setRight(false);
        neighCell.setLeft(false);
    }
    else if (colDif == 0 && rowDif == -1)
    {
        // Neighbor is below
        cellCell.setBot(false);
        neighCell.setTop(false);
    }
    else if (colDif == 0 && rowDif == 1)
    {
        // Neighbor is above
        cellCell.setTop(false);
        neighCell.setBot(false);
    }
}

//print the maze
void maze::printMaze()
{

    // Build the top layer
    for (int i = 0; i < getCol(); ++i)
    {
        if (i == 0)
        {
            cout << "  ";
        }
        else
        {
            cout << " _";
        }
    }

    cout << endl;
    int numCells = getTotal();

    for (std::vector<mazeCell>::iterator it = theMaze.begin(); it != theMaze.end(); ++it)
    {
        const int i = it - theMaze.begin();
        mazeCell c = *it;
        if ((i + 1) % getCol() == 0)
        {
            // Know its the right side
            cout << (c.getLeft() ? "|" : " ") << (c.getBot() ? "_" : " ") << (i == numCells - 1 ? " " : "|");
            cout << endl;
        }
        else if (i % getCol() == 0)
        {
            // Know its the left side
            cout << (i == 0 ? " " : "|") << (c.getBot() ? "_" : " ");
        }
        else
        {
            // Other Cell
            cout << (c.getLeft() ? "|" : " ") << (c.getBot() ? "_" : " ");
        }
    }
    cout << endl;
}
