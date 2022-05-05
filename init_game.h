#include <SDL.h>
#define DEF_W theBoard->info.w;
#define DEF_H theBoard->info.h;

// struct of board
typedef struct _Board
{
    int **cell;		 			 // dynamic array of cell
    int row;				     // row of board
    int col;					 // col of board
    int step;                    // iteration step
    int delay;					 // SDL Delay
    SDL_DisplayMode info;		 // Screen info: Freq, width, height
    int cellSize;				 // [NOT IMPLEMENTED] In pixels
}Board;

void InitialCell(Board *theBoard,FILE *file);
void FreeCell(Board *theBoard);
void SetCell(Board *theBoard);
void PrintCell(Board* theBoard);
void update(Board *theBoard);
Board *init_game();
void draw(Board *theBoard, SDL_Renderer *renderer);