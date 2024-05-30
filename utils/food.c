#include "stdlib.h"

#include "food.h"
#include "globals.h"
#include "playarea.h"

void _randPos(Food *food) 
{
    food->x = rand() % GRIDCOLS;
    food->y = rand() % GRIDROWS;
}

void generateFood(Food *food, PlayArea *area) 
{
    food->alive = 1;
    _randPos(food);
    area->playArea[food->y][food->x] = FOOD;
}
