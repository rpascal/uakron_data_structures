#include "maze.h"

/**
 * Construct the disjoint sets object.
 */
maze::maze(int r, int c)
{
    row = r;
    col = c;
}

// returns true if neigh is cell's neighbor
//(i.e. in position left, right, top or bot
// with respect to cell)
bool maze::neighbors(int cell, int neigh) const
{
}

// get rid of cell's wall between cell and neighbor
// Note: this method should be invoked twice from the driver
// code to smashWall(a,b) and to smashWall(b,a)
void maze::smashWall(int cell, int neigh)
{
}

//print the maze
void maze::printMaze()
{
}
