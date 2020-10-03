//
// Created by Danny on 2-10-2020.
//

#include <SDL2/SDL.h>
#include <iostream>
#include "Grid.h"

Grid::Grid(SDL_Renderer *renderer) {
    _renderer = renderer;
    _head = new SnakeBody(5, 5);
    _tail = _head;

    for (int i = 0; i < 3; ++i) {
        Eat();
    }
}

void Grid::Update() {
    int currX = _head->x;
    int currY = _head->y;

    if (currdirection == UP) {
        currY--;
    } else if (currdirection == DOWN) {
        currY++;
    } else if (currdirection == LEFT) {
        currX--;
    } else if (currdirection == RIGHT) {
        currX++;
    }

    _head->Move(currX, currY);
    bool hasCrashed = HasCrashed();

    if (hasCrashed) {
        std::cout << "Has Crashed!" << std::endl;
    }
}

bool Grid::HasCrashed() {
    SnakeBody *currBody = _head->Tail;

    while (currBody != nullptr) {
        if (currBody->x == _head->x && currBody->y == _head->y) {
            return true;
        }

        currBody = currBody->Tail;
    }

    return false;
}

void Grid::Eat() {
    _tail->Tail = new SnakeBody(_tail->x, _tail->y);
    _tail = _tail->Tail;
}

void Grid::Draw() {
    SnakeBody *currBody = _head;

    while (currBody != nullptr) {
        DrawBody(currBody);
        currBody = currBody->Tail;
    }
}

void Grid::DrawBody(SnakeBody *body) {
    int width;
    int height;
    SDL_GetRendererOutputSize(_renderer, &width, &height);

    SDL_Rect rect;
    int block_width = width / columns;
    int block_height = height / rows;

    rect.w = block_width - 4;
    rect.h = block_height - 4;
    rect.x = body->x * block_width + 2;
    rect.y = body->y * block_height + 2;

    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(_renderer, &rect);
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
}

void Grid::HandleInput(SDL_Event &event) {
    switch (event.key.keysym.scancode) {
        case SDL_SCANCODE_W:
            currdirection = UP;
            break;
        case SDL_SCANCODE_S:
            currdirection = DOWN;
            break;
        case SDL_SCANCODE_A:
            currdirection = LEFT;
            break;
        case SDL_SCANCODE_D:
            currdirection = RIGHT;
            break;
    }
}
