#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdint.h>

#include "raylib.h"

#define CELLSIZE        20
#define GRIDCOLS        20
#define GRIDROWS        20

#define SCREEN_H 	    480
#define SCREEN_W 	    640

#define GB_BACKGROUND   (Color){202, 220, 159, 255}
#define GB_BLACK        (Color){15, 25, 15, 255}
#define GB_GREEN        (Color){48, 98, 48, 255}

typedef uint8_t 	u8;
typedef uint16_t 	u16;
typedef uint32_t 	u32;
typedef uint64_t	u64;
typedef int8_t		i8;
typedef int16_t		i16;
typedef int32_t		i32;
typedef int64_t		i64;
typedef float		f32;
typedef double		f64;

enum {
    CELL,    
    SNAKE,
    FOOD
};

enum {
    GAMEOVER,
    RUNNING
};

extern u8 g_gameState;
extern u32 g_frameCounter;

#endif /* GLOBALS_H */
