#include "init_game.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

/* Name: click_to_init
   Input: the pointer of Board and SDL_Renderer
   Function: click the cell to init the game
*/
void click_to_init(Board* theBoard,SDL_Renderer *renderer){
	int b_exit = 1;
	int x = 0;
	int y = 0;
	SDL_Event event;
 	while(b_exit)
    {
    	SDL_SetRenderDrawColor(renderer, 143, 143, 255, 1);
		drawBoard(theBoard, renderer);
		SDL_RenderPresent(renderer);
        SDL_WaitEvent(&event);
        switch (event.type)
        {
			// click the cell to init the game
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					y = event.button.x;
					x = event.button.y;
					x /= 31;
					y /= 31;
					//printf("click%d %d",x,y);
					theBoard->cell[x][y] = 1;
				}
            break;

			// click q means 
        	case SDL_KEYDOWN:
            	switch (event.key.keysym.sym)
            	{
            		case SDLK_s:
                		printf("key down s and began the game\n");
                		// begin the iteration
				SDL_RenderClear(renderer);
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1); // Set color = white
    				draw(theBoard, renderer);
    				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1); // Reset color to black
    				SDL_RenderPresent(renderer);
    				SDL_Delay(theBoard->delay);
				SDL_RenderClear(renderer);
                		begin_interation(theBoard,renderer);
                b_exit = 0;
                break;
                }
            break;
        
        }
    }
}
