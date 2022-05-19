#include "init_game.h"
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <stdlib.h>

void drawBoard(Board *theBoard, SDL_Renderer *pRenderer)
{
	for (int x = 0; x < theBoard->row; x++)
	{
		for (int y = 0; y < theBoard->col; y++)
		{
				SDL_Rect rect;
				rect.x = x * theBoard->cellSize+x;
				rect.y = y * theBoard->cellSize+y;
				rect.w = theBoard->cellSize;
				rect.h = theBoard->cellSize;
				SDL_RenderFillRect(pRenderer, &rect);
			
		}
	}
}
void drawfile(Board *theBoard, SDL_Renderer *renderer)
{
	for (int x = 0; x < theBoard->row; x++)
	{
		for (int y = 0; y < theBoard->col; y++)
		{
			if (theBoard->cell[x][y])
			{
				SDL_Rect rect;
				rect.y = y * theBoard->cellSize+x;
				rect.x = x * theBoard->cellSize+y;
				rect.w = theBoard->cellSize;
				rect.h = theBoard->cellSize;
				//printf("%d %d  ",rect.x,rect.y);
				SDL_RenderFillRect(renderer, &rect);
			}
		}
	}
}
void draw(Board *theBoard, SDL_Renderer *renderer)
{
	for (int x = 0; x < theBoard->row; x++)
	{
		for (int y = 0; y < theBoard->col; y++)
		{
			if (theBoard->cell[x][y])
			{
				SDL_Rect rect;
				rect.x = y * theBoard->cellSize+y;
				rect.y = x * theBoard->cellSize+x;
				rect.w = theBoard->cellSize;
				rect.h = theBoard->cellSize;
				//printf("%d %d  ",rect.x,rect.y);
				SDL_RenderFillRect(renderer, &rect);
			}
		}
	}
}
