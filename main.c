// By izanbf1803		-		http://izanbf.es/
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <stdlib.h>
#include "init_game.h"
/* Name: clear
   Input: None
   Function: use to clear redundant scanf
*/
void clear()
{
    char b;
    do
    {
        scanf("%c",&b);
    }
    while(b !='\n');
}


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
    fprintf(history,"%d %d %d %d\n",theBoard->row,theBoard->col,theBoard->delay,theBoard->cellSize);
    int i,j;
    for(i=0;i<(theBoard->row);i++)
    {
        for(j=0;j<(theBoard->col);j++)
            fprintf(history,"%d",theBoard->cell[i][j]);
        fprintf(history,"\n");
    }
    fclose(history);
}

/* Name: begin_interation
   Input: the pointer of Board and SDL_Renderer
   Function: the process of iteration
*/
void begin_interation(Board* theBoard,SDL_Renderer *renderer){

    SDL_Event ev;
    int circle = 0;
    unsigned char quit = 0, pause = 0;
    while (circle < theBoard->step && quit == 0)
    {
        while (SDL_PollEvent(&ev))
        {
            switch (ev.key.keysym.sym)
            {
                case SDLK_q:
                    quit = 1;
                    printf("Quit Game!");
                    break;
                case SDLK_p:
                    pause = 1;
                    break;
                case SDLK_o:
                    pause = 0;
                    break;
            }
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1); // Set color = white
        if (!pause)
        {
            update(theBoard);
            circle++;
        }
        draw(theBoard, renderer);
        SDL_SetRenderDrawColor(renderer,0,0,0,1); // Reset color to black
        SDL_RenderPresent(renderer);
        SDL_Delay(theBoard->delay);
    }

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
                    printf("click%d %d",x,y);
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

int main(int argc, char **argv) // Inizialize all values
{
    //tell user the operator of game
    printf("Welcome to Conway's Game of Life.");

    // let user to choose the way to initialize game
    int choice;
    printf("\n1) Default size version: Click to choose the initial status\n2) File version: load initial status from initial file\n Enter your choice:");
    scanf("%d",&choice);

    // init the theBoard content
    SDL_Init(SDL_INIT_VIDEO);
    Board *theBoard;
    if(choice == 1){
        clear();
        printf("\nclick the left button of mouse to initialize the cell\nInput s to began the game.\nInput q to quit the game.\nInput p to pause the game.\nInput o to restart the game.\n");
        theBoard = init_game_byclick();
        printf("%d",theBoard->step);
    }else{
        // init the game
        clear();
        printf("\nInput q to quit the game.\nInput p to pause the game.\nInput o to restart the game.\n");
        theBoard = init_game();
    }

    // init the SDL window
    SDL_Window *win = SDL_CreateWindow("Conway's game of life", (theBoard->info.w >> 1) - (theBoard->row >> 1), (theBoard->info.h >> 1) - (theBoard->col >> 1),
                                       theBoard->row * (theBoard->cellSize+1), theBoard->col * (theBoard->cellSize+1), SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);


    if (choice == 1){
        // init game by clicking the cell
        click_to_init(theBoard,renderer);
    }else{
        // begin the iteration
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1); // Set color = white
        PrintCell(theBoard);
        draw(theBoard, renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1); // Reset color to black
        SDL_RenderPresent(renderer);
        SDL_Delay(theBoard->delay);
        begin_interation(theBoard,renderer);
    }
    //PrintCell(theBoard);
    store_game(theBoard);
    FreeCell(theBoard); // Free all theBoard allocations
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}