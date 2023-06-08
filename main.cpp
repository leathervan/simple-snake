#include <SDL.h>
#include <random>
#include "Window.h"
#include "Snake.h"

void getRandApple(const Snake snake, SDL_Rect &rect);

int main(int argc, char *args[]) {
    Window window;
    Snake snake;
    SDL_Rect apple = {SNAKE_CELL_SIZE * 2, SNAKE_CELL_SIZE * 2, SNAKE_CELL_SIZE, SNAKE_CELL_SIZE};

    bool quit = false;
    SDL_Event event;

    Uint32 startTime = SDL_GetTicks();

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        snake.setDirection(Side::UP);
                        break;
                    case SDLK_DOWN:
                        snake.setDirection(Side::DOWN);
                        break;
                    case SDLK_LEFT:
                        snake.setDirection(Side::LEFT);
                        break;
                    case SDLK_RIGHT:
                        snake.setDirection(Side::RIGHT);
                        break;
                }
            }
        }
        Uint32 currentTime = SDL_GetTicks();
        Uint32 deltaTime = currentTime - startTime;

        if (deltaTime >= 200) {
            snake.move();
            startTime = currentTime;
        }

        if (snake.isEat(apple)) getRandApple(snake, apple);
        if (snake.isMatchItself()) quit = true;

        window.clear();
        window.drawApple(apple);
        window.drawSnake(snake);
        window.draw();
    }

    window.close();

    return 0;
}

void getRandApple(const Snake snake, SDL_Rect &rect) {
    int x, y;
    bool isMatch = true;

    std::random_device rd;
    std::mt19937 gen(rd());

    while (isMatch) {
        isMatch = false;
        std::uniform_int_distribution<int> dist(0, WIDTH_CELL_AMOUNT);
        x = dist(gen) * SNAKE_CELL_SIZE;
        dist = std::uniform_int_distribution<int>(0, HEIGHT_CELL_AMOUNT);
        y = dist(gen) * SNAKE_CELL_SIZE;

        if (snake.getHead().x == x && snake.getHead().y == y) isMatch = true;
        for (auto &r: snake.getBody()) {
            if (r.x == x && r.y == y) isMatch = true;
        }
    }

    rect = {x, y, SNAKE_CELL_SIZE, SNAKE_CELL_SIZE};
}