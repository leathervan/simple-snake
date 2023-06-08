#ifndef DEMO_SNAKE_H
#define DEMO_SNAKE_H

#include <SDL.h>
#include <vector>
#include "constants.h"
#include <cmath>

class Snake {
private:
    SDL_Rect head;
    std::vector<SDL_Rect> body;
    Side direction;
public:
    Snake();

    void move();

    bool isEat(const SDL_Rect &rect);

    bool isMatchItself();

    const SDL_Rect &getHead() const;

    const std::vector<SDL_Rect> &getBody() const;

    void setDirection(Side direction);

private:
    void setBodyCoordinates();
};


#endif //DEMO_SNAKE_H
