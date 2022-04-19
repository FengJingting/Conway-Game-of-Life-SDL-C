#include <stdlib.h>
#include <stdio.h>
#include <libgen.h>
#include "init_game.h"


void InitialCELL(Board* theBoard,int row,int col)
{
    int i;
    theBoard->cell=(int**)malloc(row*sizeof(int*));
    for(i=0;i<row;i++)
        theBoard->cell[i]=(int*)malloc(col*sizeof(int));
    theBoard->row=row;
    theBoard->col=col;
}
void FreeMatrix(Board* theBoard)
{
    int i;
    for(i=0;i<(theBoard->row);i++)
        free(theBoard->cell[i]);
    free(theBoard->cell);
}
void SetMatrix(Board* theBoard,int row,int col)
{
    int i,j;
    for(i=0;i<(theBoard->row);i++)
    {
        for(j=0;j<(theBoard->col);j++)
            theBoard->cell[i][j]=i+j;
    }
}
void PrintMatrix(Board* theBoard)
{
    int i,j;
    for(i=0;i<(theBoard->row);i++)
    {
        for(j=0;j<(theBoard->col);j++)
            printf(" %3.0f",theBoard->cell[i][j]);
        printf("\n");
    }
}
Board* create_game (const char *file,Board *theBoard){
    char row[5];
    fscanf(file,"%d %d %d",&theBoard->row,&theBoard->col,&theBoard->step);
    printf("There are %d rows,%d cols, %d steps\n",theBoard->row,theBoard->col,theBoard->step);
    InitialCELL(theBoard,theBoard->row,theBoard->col);
    SetMatrix(theBoard,theBoard->row,theBoard->col);
    PrintMatrix(theBoard);
    return theBoard;
}

int main(int argc, char **argv ) {
//    FILE *map;
//    if (argv[0] == NULL) {
//        printf("Enter an input map.\n");
//        return -1;
//    }
//    map = fopen(argv[0],"r");
//    if(map==NULL){
//        return -1;
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
    FreeMatrix(theBoard);
    return 0;

}
