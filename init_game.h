#include <SDL2/SDL.h>
#define DEF_W theBoard->info.w;
#define DEF_H theBoard->info.h;

// struct of board
typedef struct _Board
{
    int **cell;		 			 // dynamic array of cell
    int row;				         // row of board
    int col;					 // col of board
    int step;                    			 // iteration step
    int delay;					 // SDL Delay
    SDL_DisplayMode info;		 		 // Screen info: Freq, width, height
    int cellSize;				 	 // [NOT IMPLEMENTED] In pixels
}Board;

//initial cell
Board *init_game();
void InitialCell(Board *theBoard,FILE *file);
void FreeCell(Board *theBoard);
void SetCell(Board *theBoard,FILE *map);
void PrintCell(Board* theBoard);

//play game
void update(Board *theBoard);

//view game
void draw(Board *theBoard, SDL_Renderer *renderer);
void drawBoard(Board *theBoard, SDL_Renderer *pRenderer);

// utility
void clear();
int check_input(char* input);

// initial cell by click
Board *init_game_byclick();
void InitialCell_byclick(Board *theBoard);
void click_to_init(Board* theBoard,SDL_Renderer *renderer);