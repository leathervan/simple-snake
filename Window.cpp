#include "Window.h"

Window::Window(){
    SDL_Init(SDL_INIT_VIDEO);
    this->window = SDL_CreateWindow("Moving Rectangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(window, -1, 0);
}

void Window::clear(){
    SDL_SetRenderDrawColor(this->renderer, 0, 100, 0, 255);
    SDL_RenderClear(this->renderer);
}

void Window::drawSnake(const Snake snake){
    SDL_SetRenderDrawColor(this->renderer, 255, 128, 0, 255);
    SDL_RenderFillRect(this->renderer, &snake.getHead());
    for( auto &rect : snake.getBody()){
        SDL_RenderFillRect(this->renderer, &rect);
    }
}

void Window::drawApple(const SDL_Rect &apple) {
    SDL_SetRenderDrawColor(this->renderer, 200, 0, 0, 255);
    SDL_RenderFillRect(this->renderer, &apple);
}

void Window::draw() {
    SDL_RenderPresent(this->renderer);
}
void Window::close(){
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}