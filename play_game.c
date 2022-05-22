#include "init_game.h"
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <stdlib.h>

/* Name: update
   Input: the pointer of Board
   Function: upadate and iterate the cell board depending on the rules
*/
void update(Board *theBoard)
{
    int i, j;
    // 8 directions around one cell
    const int movDir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
    for (i = 0; i < theBoard->row; i++)
    {
        for (j = 0; j < theBoard->col; j++)
        {
            int cellNum = 0;
            for (int n = 0; n < 8; n++)
            {
                int x = i + movDir[n][0];
                int y = j + movDir[n][1];
                if (x < 0 || x > (theBoard->row - 1) || y < 0 || y > (theBoard->col - 1))
                {
                    if (n == 7)
                    {
                        break;
                    }
                    continue;
                }
                if ((theBoard->cell[x][y]) == -1 || (theBoard->cell[x][y]) == 1)
                {
                    cellNum++;
                }
            }
            // bigger than 3 neighbor, die
            if (cellNum > 3 && (theBoard->cell[i][j] == 1))
            {
                (theBoard->cell[i][j]) = -1;
            } // exactly 3 neighbor,alive
            else if (cellNum == 3 && (theBoard->cell[i][j] == 0))
            {
                (theBoard->cell[i][j]) = 2;
            } // less than 2,die
            else if (cellNum < 2 && (theBoard->cell[i][j] == 1))
            {
                (theBoard->cell[i][j]) = -1;
            }
        }
    }
    for (i = 0; i < (theBoard->row); i++)
    {
        for (j = 0; j < (theBoard->col); j++)
        {
            if (theBoard->cell[i][j] == 2)
            {
                theBoard->cell[i][j] = 1;
            }
            else if (theBoard->cell[i][j] == -1)
            {
                theBoard->cell[i][j] = 0;
            }
        }
    }
}