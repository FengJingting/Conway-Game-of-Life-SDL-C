//
// Created by udii on 2022-04-16.
//
typedef struct _Board{
    int col;
    int row;
    int step;
    int **cell;
}Board;

int create_game (const char *file,Board *theBoard);
Board* UpdateCell(Board* theBoard);
void PrintCell(Board* theBoard);
void InitialCell(Board* theBoard,int row,int col);
void FreeCell(Board* theBoard);
void SetCell(Board* theBoard,int col);