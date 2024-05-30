#include "borderbox.h"
#include "globals.h"

#include "raylib.h"

Rectangle rec = { 36, 36, 409, 409};

void drawBorderBox() 
{
    DrawRectangleLinesEx(rec, 4, GB_BLACK);
}
