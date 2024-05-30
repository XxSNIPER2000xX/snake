#ifndef PLAYAREA_H
#define PLAYAREA_H

#include "globals.h"

typedef struct S_PlayArea {
    i8 offSetX;
    i8 offSetY;
    i8 playArea[GRIDROWS][GRIDCOLS];
} PlayArea;

void clearPlayArea(PlayArea *area); // used for updating frames, is slow make a better algo
void drawPlayArea(PlayArea *area);
void initPlayArea(PlayArea *area);

#endif /* PLAYAREA_H */
