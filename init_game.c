//
// Created by udii on 2022-04-16.
//

#include "init_game.h"
#include <stdlib.h>
#include <stdio.h>
#define DEAD 0
#define ALIVE 1

void InitialCell(Board* theBoard,int row,int col)
{
    int i;
    theBoard->cell=(int**)malloc(row*sizeof(int*));
    for(i=0;i<row;i++)
        theBoard->cell[i]=(int*)malloc(col*sizeof(int));
    theBoard->row=row;
    theBoard->col=col;
}
void FreeCell(Board* theBoard)
{
    int i;
    for(i=0;i<(theBoard->row);i++)
        free(theBoard->cell[i]);
    free(theBoard->cell);
}
void SetCell(Board* theBoard,int col)
{
    char line[1000];
    FILE *file = fopen("initial.txt", "r");
    fgets(line,1000,file);
    char c = fgetc(file);
    int cur_row = 0;
    int cur_col = 0;
    while(c != EOF){
        switch(c){
            case '0':
                theBoard->cell[cur_row][cur_col] = DEAD;
                break;
            case '1':
                theBoard->cell[cur_row][cur_col] = ALIVE;
                break;
        }
        if(c != '\n'){
            cur_col++;
            if(cur_col>=col){
                cur_col= 0;
                cur_row++;
            }
        }
        c = fgetc(file);
    }
}
void PrintCell(Board* theBoard)
{
    printf("\n");
    int i,j;
    for(i=0;i<(theBoard->row);i++)
    {
        for(j=0;j<(theBoard->col);j++)
            printf("%d",theBoard->cell[i][j]);
        printf("\n");
    }
    printf("\n");
}
int input_step(Board *theBoard){
    printf("Please enter the iteration steps you want:");
    scanf("%d",&theBoard->step);
}
int create_game (const char *file,Board *theBoard){
    fscanf(file,"%d %d",&theBoard->row,&theBoard->col);
    input_step(theBoard);
    printf("There are %d rows,%d cols,%d steps\n",theBoard->row,theBoard->col,theBoard->step);
    InitialCell(theBoard,theBoard->row,theBoard->col);
    SetCell(theBoard,theBoard->col);
    return 0;
}








