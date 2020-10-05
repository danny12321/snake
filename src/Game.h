//
// Created by Danny on 3-10-2020.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <SDL2/SDL.h>
#include "Grid.h"
#include "Directions.h"
#include "grid/Candy.h"
#include <iostream>

class Game {
private:
    SDL_Renderer* renderer;
    Directions currdirection = RIGHT;
    SnakeBody* snake;
    SnakeBody* tail;
    Candy* candy;
    Grid* grid;
    bool running = true;

    void Init(int bodyLength);
    void HandleInput(SDL_Event& e);

public:
    Game();

    void Update();

    bool HasCrashed();

    void PlaceCandy();

    int GetScore();
};


#endif //SNAKE_GAME_H
