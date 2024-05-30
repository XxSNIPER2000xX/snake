#ifndef SNAKE_H
#define SNAKE_H

#include "globals.h"
#include "playarea.h"

enum {
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct S_SnakeNode {
    i8 x;
    i8 y;
    i8 oldX;
    i8 oldY;
    i8 dir;
    struct S_SnakeNode *prev;
    struct S_SnakeNode *next;
} SnakeNode;

typedef struct S_SnakeList {
    SnakeNode *head;
} Snake;

void appendNode(Snake *snake, i8 x, i8 y);
void _boundCheck(Snake *snake);
void createNode(SnakeNode **newNode, i8 x, i8 y);
i8 getSnakeDir(Snake *snake);
void initSnake(Snake *snake);
void _moveSnake(Snake *snake);
void updateSnake(Snake *snake);
void updateSnakeOnArea(Snake *snake, PlayArea *area);

#endif /* SNAKE_H */
