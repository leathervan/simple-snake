#ifndef DEMO_CONSTANTS_H
#define DEMO_CONSTANTS_H

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int SNAKE_CELL_SIZE = 40;
const int WIDTH_CELL_AMOUNT = WINDOW_WIDTH / SNAKE_CELL_SIZE - 1;
const int HEIGHT_CELL_AMOUNT = WINDOW_HEIGHT / SNAKE_CELL_SIZE - 1;
const int SNAKE_SPEED = 40;

enum class Side {
    UP,
    RIGHT,
    DOWN,
    LEFT,
};

#endif
