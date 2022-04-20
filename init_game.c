//
// Created by udii on 2022-04-16.
//

#include "init_game.h"
#include <stdlib.h>
#include <stdio.h>
#define DEAD 0
#define ALIVE 1

Board* UpdateCell(Board* theBoard){
    int i,j;
    int movDir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                  {0, -1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
    for(i=0;i<(theBoard->row);i++)
    {
        for(j=0;j<(theBoard->col);j++){
            int cellNum = 0;
            for(int n=0;n<8;n++){
                int x = i+movDir[n][0];
                int y = j+movDir[n][1];
                if (x < 0 || x > theBoard->row - 1 || y < 0 || y > theBoard->col - 1){
                    if(n == 7){
                        break;
                    }
                    continue;
                }
                if ( (theBoard->cell[x][y]) == -1 || (theBoard->cell[x][y]) == 1){
                    cellNum ++;
                }

            if (cellNum > 3 && (theBoard->cell[i][j]) == 1){
                (theBoard->cell[i][j]) = -1;
            }else if(cellNum == 3 && (theBoard->cell[i][j]) == 0){
                (theBoard->cell[i][j]) = 2;
            }else if(cellNum < 2 && (theBoard->cell[i][j]) == 1){
                (theBoard->cell[i][j]) = -1;
            }
            }
        }

    }

    for(i=0;i<(theBoard->row);i++){
        for(j=0;j<(theBoard->col);j++){
            if( theBoard->cell[i][j]==2){
                theBoard->cell[i][j] = 1;
            }
            if( theBoard->cell[i][j]==-1){
                theBoard->cell[i][j] = 0;
            }
        }
    }
    return  theBoard;
}
