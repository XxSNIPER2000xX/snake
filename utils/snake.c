#include <stdio.h>
#include <stdlib.h>

#include "globals.h"
#include "playarea.h"
#include "snake.h"

#include "raylib.h"

void initSnake(Snake *snake)
{
    snake->head = NULL;
    appendNode(snake, 11, 9);
    appendNode(snake, 12, 9);
    appendNode(snake, 13, 9);
    appendNode(snake, 14, 9);
}

void createNode(SnakeNode **newNode, i8 x, i8 y)
{
    *newNode = (SnakeNode *)malloc(sizeof(SnakeNode));
    if(*newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory, exit: 1\n");
        exit(1);
    }

    (*newNode)->x = x;
    (*newNode)->y = y;
    (*newNode)->oldX = x;
    (*newNode)->oldY = y;
    (*newNode)->dir = NONE;
    (*newNode)->prev = NULL;
    (*newNode)->next = NULL;
}

void appendNode(Snake *snake, i8 x, i8 y)
{
    SnakeNode *newNode;
    createNode(&newNode, x, y);

    if(snake->head == NULL) {
        snake->head = newNode;
    } else {
        SnakeNode *temp = snake->head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void _moveSnake(Snake *snake) 
{
    if(IsKeyPressed(KEY_W)) {
        snake->head->y -= 1;
        snake->head->dir = UP;
    }
    if(IsKeyPressed(KEY_S)) {
        snake->head->y += 1;
        snake->head->dir = DOWN;
    }
    if(IsKeyPressed(KEY_A)) {
        snake->head->x -= 1;
        snake->head->dir = LEFT;
    }
    if(IsKeyPressed(KEY_D)) {
        snake->head->x += 1;
        snake->head->dir = RIGHT;
    }
    
    /* this whole system needs to change
       currently the snake is moving based on the framerate
       but should be coded to work on a game tic rate
       this will allow much more fluid and less glitchly movement 
       also currently g_frameCounter is being updated in update.c
       but being checked in snake.c??? no one will ever understand
       or be able to read this code. - trust me it works bro */     
    
    if((g_frameCounter % 10) == 0) {
        switch(getSnakeDir(snake)) {
            case UP:
                snake->head->y -= 1;
                break;
            case DOWN:
                snake->head->y += 1;
                break;
            case LEFT:
                snake->head->x -= 1;
                break;
            case RIGHT:
                snake->head->x += 1;
                break;
        }
    }
}

void updateSnake(Snake *snake)
{       
    snake->head->oldX = snake->head->x;
    snake->head->oldY = snake->head->y;  
    
    _moveSnake(snake);
    SnakeNode *node = snake->head->next;
    
    if(snake->head->dir != NONE) {
        while((node != NULL)) {
            if(snake->head->oldX != snake->head->x) {
                node->oldX = node->x;
                node->x = node->prev->oldX;
            
                node->oldY = node->y;
                node->y = node->prev->oldY;
            }
        
            if( (snake->head->oldX == snake->head->x) && (snake->head->oldY != snake->head->y) ) {
                node->oldX = node->x;
                node->x = node->prev->oldX;
            
                node->oldY = node->y;
                node->y = node->prev->oldY;
            }
        
            node = node->next;
        }
    }
    //printf("oldX: %d\noldY: %d\n", snake->head->oldX, snake->head->oldY);
    //printf("X: %d\nY: %d\n", snake->head->x, snake->head->y);
}

i8 getSnakeDir(Snake *snake)
{
    return snake->head->dir;
}

void updateSnakeOnArea(Snake *snake, PlayArea *area)
{  
    SnakeNode *node = snake->head;
    _boundCheck(snake);
    while(node != NULL) {   
        area->playArea[node->y][node->x] = SNAKE;
        node = node->next;
    }   
}

void _boundCheck(Snake *snake)
{
    if(snake->head->x < 0) {
        snake->head->x = 0;
        g_gameState = GAMEOVER;
    }
    
    if(snake->head->x > GRIDROWS - 1) {
        snake->head->x = GRIDROWS - 1;
        g_gameState = GAMEOVER;
    }
    
     if(snake->head->y < 0) {
        snake->head->y = 0;
        g_gameState = GAMEOVER;
    }
    
    if(snake->head->y > GRIDCOLS - 1) {
        snake->head->y = GRIDCOLS - 1;
        g_gameState = GAMEOVER;
    }
}
