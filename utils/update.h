#ifndef UPDATE_H
#define UPDATE_H

#define NULL ((void *)0)

void eatFood(Food *food, Snake *snake);
void eatSnake(Snake *snake, PlayArea *area);
void update(Food *food, PlayArea *area, Snake *snake);

#endif /* UPDATE_H */
