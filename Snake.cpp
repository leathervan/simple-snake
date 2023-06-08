#include "Snake.h"

Snake::Snake() {
    SDL_Rect rect = {0, 0, SNAKE_CELL_SIZE, SNAKE_CELL_SIZE};
    this->head = rect;
    this->direction = Side::RIGHT;
}

void Snake::move() {
    this->setBodyCoordinates();
    switch (this->direction) {
        case Side::UP:
            this->head.y -= SNAKE_SPEED;
            if (this->head.y < 0) this->head.y = WINDOW_HEIGHT - SNAKE_CELL_SIZE;
            break;
        case Side::DOWN:
            this->head.y += SNAKE_SPEED;
            if (this->head.y >= WINDOW_HEIGHT) this->head.y = 0;
            break;
        case Side::LEFT:
            this->head.x -= SNAKE_SPEED;
            if (this->head.x < 0) this->head.x = WINDOW_WIDTH - SNAKE_CELL_SIZE;
            break;
        case Side::RIGHT:
            this->head.x += SNAKE_SPEED;
            if (this->head.x >= WINDOW_WIDTH) this->head.x = 0;
            break;
    }
}

bool Snake::isEat(const SDL_Rect &rect) {
    if (rect.x == this->head.x && rect.y == this->head.y) {
        SDL_Rect newRect = {0 - SNAKE_CELL_SIZE, 0 - SNAKE_CELL_SIZE, SNAKE_CELL_SIZE, SNAKE_CELL_SIZE};
        this->body.push_back(newRect);
        return true;
    }
    return false;
}

const std::vector<SDL_Rect> &Snake::getBody() const {
    return body;
}

void Snake::setDirection(Side direction) {
    int diff = static_cast<int>(this->direction) - static_cast<int>(direction);
    if (std::abs(diff) != 2) Snake::direction = direction;
}

const SDL_Rect &Snake::getHead() const {
    return head;
}

void Snake::setBodyCoordinates() {
    if (body.size() >= 2) {
        for (int i = this->body.size() - 1; i > 0; --i) {
            this->body[i].x = this->body[i - 1].x;
            this->body[i].y = this->body[i - 1].y;
        }
    }
    if (body.size() >= 1) {
        this->body[0].x = this->head.x;
        this->body[0].y = this->head.y;
    }
}

bool Snake::isMatchItself() {
    for (auto &r: this->body) {
        if (r.x == this->head.x && r.y == this->head.y) return true;
    }
    return false;
}
