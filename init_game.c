#include "init_game.h"
#include <stdlib.h>
#include <stdio.h>

/* Name: InitialCell
   Input: the pointer of Board
   Function: use malloc to set memorry for cell board
*/
void InitialCell(Board *theBoard,FILE *file)
{
    fscanf(file, "%d %d %d %d", &theBoard->row, &theBoard->col,&theBoard->delay,&theBoard->cellSize);
    int i;
    theBoard->cell = (int **)malloc(theBoard->row * sizeof(int *));
    for (i = 0; i < theBoard->row; i++)
        theBoard->cell[i] = (int *)malloc(theBoard->col * sizeof(int));
}

/* Name: InitialCell_byclick
   Input: the pointer of Board
   Function: use malloc to set memorry for cell board
*/
void InitialCell_byclick(Board *theBoard)
{
    int i,j;
    theBoard->cell = (int **)malloc(theBoard->row * sizeof(int *));
    for (i = 0; i < theBoard->row; i++)
        theBoard->cell[i] = (int *)malloc(theBoard->col * sizeof(int));
    for(i = 0; i < theBoard->row; i++){
        for(j = 0; j < theBoard->col; j++){
            theBoard->cell[i][j] = 0;
        }
    }
}

/* Name: FreeCell
   Input: the pointer of Board
   Function: free the malloc memorry
*/
void FreeCell(Board *theBoard)
{
    for (int i = 0; i < theBoard->row; i++)
    {
        free(theBoard->cell[i]);
    }
    free(theBoard->cell);
    free(theBoard);
}

/* Name: SetCell
   Input: the pointer of Board
   Function: read the file and load the data to the structure
*/
void SetCell(Board *theBoard)
{
    char line[1000];
    FILE *map = fopen("initial.txt", "r");
    fgets(line, 1000, map);
    char c = fgetc(map);
    int cur_row = 0;
    int cur_col = 0;
    while (c != EOF)
    {
        switch (c)
        {
            case '0':
                theBoard->cell[cur_row][cur_col] = 0;
                break;
            case '1':
                theBoard->cell[cur_row][cur_col] = 1;
                break;
        }
        if (c != '\n')
        {
            cur_col++;
            if (cur_col >= theBoard->col)
            {
                cur_col = 0;
                cur_row++;
            }
        }
        c = fgetc(map);
    }
    fclose(map);
}

/* Name: PrintCell
   Input: the pointer of Board
   Function: print the cell board for debug and test
*/
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

/* Name: optionChoice
   Function: check if the input is valid, if not, return 0
*/
int optionChoice() {
    int option = -1;
    char line[80];
    // read in the current line as a string
    fgets(line,80,stdin);
    // atoi() converts string to integer, returns 0 if could not convert
    option = (int)atoi(line);
    return option;
}

/* Name: input_step
   Input: the pointer of Board
   Function: ask user to input the step value, if it is invalid, ask them to input again.
*/
int input_step(Board *theBoard){
    printf("Please enter the iteration steps you want(step>0):");
    int step = optionChoice();
    if (step==0){
        printf("Invalid step!");
        return 1;
    }else{
        theBoard->step = step;
        return 0;
    };
}
/* Name: init_game()
   Function: init game
*/
Board *init_game()
{
    Board *theBoard = (Board *)malloc(sizeof(Board)); // Allocate theBoard as pointer
    SDL_GetCurrentDisplayMode(0, &theBoard->info);			 // Get theBoard info
    theBoard->row = DEF_W;
    theBoard->col = DEF_H;
    FILE *map;
    map = fopen("initial.txt", "r");
    if (!map)
    {
        printf("File not exit!");
        exit(-1);
    }
    int step = input_step(theBoard);
    while(step){
        step = input_step(theBoard);
    }
    InitialCell(theBoard,map);
    SetCell(theBoard);
    fclose(map);
    return theBoard;
}

/* Name: init_game_byclick
   Function: init_game_byclick
*/
Board *init_game_byclick()
{
    Board *theBoard = (Board *)malloc(sizeof(Board)); // Allocate theBoard as pointer
    SDL_GetCurrentDisplayMode(0, &theBoard->info);			 // Get theBoard info
    theBoard->row = 20;
    theBoard->col = 20;
    theBoard->delay = 1000;
    theBoard->cellSize = 30;
    int step = input_step(theBoard);
    while(step){
        step = input_step(theBoard);
    }
    InitialCell_byclick(theBoard);
    return theBoard;
}
