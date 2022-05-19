#include <stdlib.h>
#include <stdio.h>
#include "init_game.h"

int store_game(Board* theBoard){
    FILE *history;
    history = fopen("history.txt","wt");
    if(!history){
        printf("File history.txt not exit!");
        exit(-1);
    }
    fprintf(history,"%d %d\n",theBoard->row,theBoard->col);
    int i,j;
    for(i=0;i<(theBoard->row);i++)
    {
        for(j=0;j<(theBoard->col);j++)
            fprintf(history,"%d",theBoard->cell[i][j]);
        fprintf(history,"\n");
    }
    fclose(history);
}

int main(int argc, char **argv ) {
//    if(args==0){
//        printf("Please enter the file's name");
//        exit(0);
//    }
    FILE *map;
    map = fopen("initial.txt", "r");
    if(!map){
        printf("File not exit!");
        exit(-1);
    }
    Board *theBoard = (Board *) malloc(sizeof(Board));
    create_game(map,theBoard);
    fclose(map);
    int cycle = 0;
    while(cycle<theBoard->step){
        printf("GAME%d\n",cycle);
        PrintCell(UpdateCell(theBoard));
        cycle++;
    }
    store_game(theBoard);
    FreeCell(theBoard);
    free(theBoard);
    return 0;
}

