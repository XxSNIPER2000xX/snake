#include "food.h"
#include "globals.h"
#include "playarea.h"
#include "snake.h"
#include "update.h"

#include "raylib.h"

void update(Food *food, PlayArea *area, Snake *snake)
{
    clearPlayArea(area); // bad, design a better algo
    
    if(g_gameState == RUNNING) {
        if(food->alive != 1) {
            generateFood(food, area);    
        }

        updateSnake(snake);
        eatFood(food, snake);   
        updateSnakeOnArea(snake, area);
    }
     
     g_frameCounter++;
}

void eatFood(Food *food, Snake *snake)
{
    i8 x, y;    
    
    if((food->x == snake->head->x) && (food->y == snake->head->y)) {
        food->alive = 0;
        
        SnakeNode *node = snake->head;
        while(node != NULL) {
            x = node->oldX;
            y = node->oldY;
            node = node->next;            
        }
        appendNode(snake, x, y);    
    }  
}

void eatSnake(Snake *snake, PlayArea *area)
{
    
}
