//
// Created by Danny on 2-10-2020.
//

#include "SnakeBody.h"

void SnakeBody::Move(Directions direction) {
    auto tail = GetTail();

    if (tail != nullptr) {
        tail->Move(this->x, this->y);
    }

    if (direction == UP) {
        y--;
    } else if (direction == DOWN) {
        y++;
    } else if (direction == LEFT) {
        x--;
    } else if (direction == RIGHT) {
        x++;
    }
}

void SnakeBody::Move(int x, int y) {
    auto tail = GetTail();

    if (tail != nullptr) {
        tail->Move(this->x, this->y);
    }

    this->x = x;
    this->y = y;
}

SnakeBody::SnakeBody(int x, int y) {
    this->x = x;
    this->y = y;
}

SnakeBody* SnakeBody::Eat() {
    auto tail = GetTail();
    if (tail != nullptr) {
        return tail->Eat();
    } else {
        Tail = new SnakeBody(x, y);
        return (SnakeBody*) Tail;
    }
}
void SnakeBody::Draw(SDL_Renderer* renderer, int width, int height, int margin) {
    SDL_Rect rect;
    rect.w = width - margin;
    rect.h = height - margin ;
    rect.x = x * width + (margin / 2);
    rect.y = y * height + (margin / 2);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

SnakeBody* SnakeBody::GetTail() {
    return (SnakeBody*) Tail;
}

int SnakeBody::GetScore() {
    auto tail = GetTail();
    if (tail != nullptr) {
        return 1 + tail->GetScore();
    }

    return 1;
}
