#include "init_game.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
void SetCell(Board *theBoard,FILE *map)
{
	char line[1000];
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

/* Name: input_step
   Input: the pointer of Board
   Function: ask user to input the step value, if it is invalid, ask them to input again.
*/
int input_step(Board *theBoard)
{
	printf("\nEnter the iteration steps you want \nif you input 0,the game will keep running till you press q:\n");
	char step[5] = {0};
	scanf("%s", &step);
	if(strspn(step,"0123456789") != strlen(step))
	{
		printf("Invalid step!");
        return -1;
    }
        
	if (atoi(step)< 0)
	{
		printf("Invalid step!");
		return -1;
	}
	else if (atoi(step) == 0)
	{
		theBoard->step = 1000;
	}
	else
	{
		theBoard->step = atoi(step);
	};
	return 0;
}


/* Name: init_game()
   Function: init game
*/
Board *init_game()
{
	// initialize the board 
	Board *theBoard = (Board *)malloc(sizeof(Board)); // Allocate theBoard as pointer
	SDL_GetCurrentDisplayMode(0, &theBoard->info);			 // Get theBoard info
	theBoard->row = DEF_W;
	theBoard->col = DEF_H;

	// ask user to choose the file they want to initialzie
	printf("\na)Open the initial file.\nb)Open the history file.\nEnter your choice:");
	char fileoption[5];
	scanf("%s",fileoption);
	int ifContinue = check_input(fileoption);
    while(ifContinue){
    		printf("\nEnter your choice:");
		scanf("%s",fileoption);
		ifContinue = check_input(fileoption);	
	};
	FILE *map;
	if (strcmp(fileoption,"a")==0){
		map = fopen("initial.txt", "r");
	}else{
		map = fopen("history.txt", "r");
	}
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
	SetCell(theBoard,map);
	fclose(map);
	return theBoard;
}
