#ifndef FOOD_H
#define FOOD_H

#include "globals.h"
#include "playarea.h"

typedef struct S_Food {
    i8 alive;
    i8 x;
    i8 y;
} Food;

void _randPos(Food *food);
void generateFood(Food *food, PlayArea *area);

#endif /* FOOD_H */
