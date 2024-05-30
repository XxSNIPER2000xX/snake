#include <stdlib.h>
#include <time.h>

#include "utils/borderbox.h"
#include "utils/food.h"
#include "utils/globals.h"
#include "utils/playarea.h"
#include "utils/snake.h"
#include "utils/update.h"

#include "raylib.h"

int main(void)
{   
    Food        food;  
    PlayArea    playArea;
    Snake       snake;
   
    initPlayArea(&playArea);
    initSnake(&snake);
    InitWindow(SCREEN_W, SCREEN_H, "snake");

    srand(time(NULL));

	SetTargetFPS(30);
	while(!WindowShouldClose()) {      
        
        switch(g_gameState) {
            case GAMEOVER:
                goto cleanup;
                break;
            case RUNNING:
                update(&food, &playArea, &snake);
                break;       
        }
        
		BeginDrawing();
			ClearBackground(GB_BACKGROUND);
            drawPlayArea(&playArea);
            //DrawLine(SCREEN_W / 2, 0, SCREEN_W / 2, SCREEN_H, RED);
            //DrawLine(0, SCREEN_H / 2, SCREEN_W, SCREEN_H / 2, GREEN);
            drawBorderBox();
		EndDrawing();
	}

cleanup:
    SnakeNode *node = snake.head;
    while(node != NULL) {
        free(node);
        node = node->next;
    }
    snake.head = NULL;
    CloseWindow();
	return 0;
}
