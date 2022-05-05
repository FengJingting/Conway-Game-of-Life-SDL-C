// By izanbf1803		-		http://izanbf.es/
#include "init_game.h"
#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include <time.h>
#include <stdlib.h>

/* Name: store game
   Input: the pointer of Board
   Function: store the last iteration into history.txt
*/
int store_game(Board* theBoard){
    FILE *history;
    history = fopen("history.txt","wt");
    // if file not exits, throw an error
    if(!history){
        printf("File history.txt not exit!");
        exit(-1);
    }
    fprintf(history,"%d %d %d %d %d\n",theBoard->row,theBoard->col,theBoard->step,theBoard->delay,theBoard->cellSize);
    int i,j;
    for(i=0;i<(theBoard->row);i++)
    {
        for(j=0;j<(theBoard->col);j++)
            fprintf(history,"%d",theBoard->cell[i][j]);
        fprintf(history,"\n");
    }
    fclose(history);
}

int main(int argc, char **argv) // Inizialize all values
{
    // init the SDL theBoard
    SDL_Init(SDL_INIT_VIDEO);

    //init the game
    Board *theBoard = init_game();

    //init the theBoard content
    SDL_Window *win = SDL_CreateWindow("Conway's game of life", (theBoard->info.w >> 1) - (theBoard->row >> 1), (theBoard->info.h >> 1) - (theBoard->col >> 1),
                                       theBoard->row * theBoard->cellSize, theBoard->col * theBoard->cellSize, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event ev;

    //begin the iteration
    int circle = 0;
    unsigned char quit = 0, pause = 0;
    while (circle<theBoard->step&&quit==0)
    {
        circle++;
        while (SDL_PollEvent(&ev))
        {
            switch (ev.type)
            {
                case SDL_QUIT:
                    quit = 1;
                    break;
            }
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1); // Set color = white

        if (!pause){
            update(theBoard);
        }

        draw(theBoard, renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1); // Reset color to black
        SDL_RenderPresent(renderer);
        if (pause)
        {
            SDL_Delay(100000);
        }
        else
        {
            SDL_Delay(theBoard->delay);
        }
    }
    store_game(theBoard);
    FreeCell(theBoard); // Free all theBoard allocations
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}