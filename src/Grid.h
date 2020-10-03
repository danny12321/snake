//
// Created by Danny on 2-10-2020.
//

#ifndef SNAKE_GRID_H
#define SNAKE_GRID_H

#include <list>
#include "grid/SnakeBody.h"

class Grid {
private:
    SDL_Renderer* _renderer;

    enum Direction {LEFT, RIGHT, UP, DOWN };
    Direction currdirection = RIGHT;

    SnakeBody* _head;
    SnakeBody* _tail;

    void DrawBody(SnakeBody* body);

    int columns = 30;
    int rows = 30;

public:
    Grid(SDL_Renderer* renderer);
    void Draw();

    void HandleInput(SDL_Event& event);
    void Update();

    void Eat();

    bool HasCrashed();
};


#endif //SNAKE_GRID_H
