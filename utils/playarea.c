#include "globals.h"
#include "playarea.h"

#include "raylib.h"

void initPlayArea(PlayArea *area)
{
    area->offSetX = 2;   
    area->offSetY = 2;
    for(i8 row = 0; row < GRIDROWS; row++) {
        for(i8 col = 0; col < GRIDCOLS; col++)
            area->playArea[row][col] = 0;
    }
}

void drawPlayArea(PlayArea *area)
{
    for(i8 row = 0; row < GRIDROWS; row++) {
        for(i8 col = 0; col < GRIDCOLS; col++) {
            switch(area->playArea[row][col]) {
                case SNAKE:
                   DrawRectangle((col + area->offSetX) * CELLSIZE + 1, (row + area->offSetY) * CELLSIZE + 1, CELLSIZE - 1, CELLSIZE - 1, GB_GREEN);
                    break;
                case FOOD:
                    DrawRectangle((col + area->offSetX) * CELLSIZE + 1, (row + area->offSetY) * CELLSIZE + 1, CELLSIZE - 1, CELLSIZE - 1, GB_BLACK);
                    break; 
                default:
                    DrawRectangle((col + area->offSetX) * CELLSIZE + 1, (row + area->offSetY) * CELLSIZE + 1, CELLSIZE - 1, CELLSIZE - 1, GB_BACKGROUND);            
            }
        }
    }
}

void clearPlayArea(PlayArea *area) {
    for(i8 row = 0; row < GRIDROWS; row++) {
        for(i8 col = 0; col < GRIDCOLS; col++) {
            if(area->playArea[row][col] != FOOD)
                area->playArea[row][col] = CELL;
        }
    }
}
