#ifndef DEMO_WINDOW_H
#define DEMO_WINDOW_H

#include <SDL.h>
#include <vector>
#include "constants.h"
#include "Snake.h"

class Window {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    Window();
    void clear();
    void drawSnake(const Snake snake);
    void drawApple(const SDL_Rect &apple);
    void draw();
    void close();
};

#endif
