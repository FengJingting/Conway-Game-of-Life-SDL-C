#include "init_game.h"
#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include <time.h>
#include <stdlib.h>

#include "init_game.h"
#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include <time.h>
#include <stdlib.h>

void draw(Board *theBoard, SDL_Renderer *renderer)
{
    for (int x = 0; x < theBoard->row; x++)
    {
        for (int y = 0; y < theBoard->col; y++)
        {
            if (theBoard->cell[x][y])
            {
                SDL_Rect rect;
                rect.x = x * theBoard->cellSize+x;
                rect.y = y * theBoard->cellSize+y;
                rect.w = theBoard->cellSize;
                rect.h = theBoard->cellSize;
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}
}