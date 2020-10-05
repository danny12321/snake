//
// Created by Danny on 2-10-2020.
//

#ifndef SNAKE_GRID_H
#define SNAKE_GRID_H

#include <list>
#include <vector>
#include "grid/SnakeBody.h"
#include  <random>

class Grid {
private:
    SDL_Renderer* _renderer;

    void DrawBody(GridItem* body);

    int columns = 20;
    int rows = 20;

public:
    Grid(SDL_Renderer* renderer);
    void Draw(GridItem *body);

    std::vector<int> GetFreePlace(GridItem* body);
};


#endif //SNAKE_GRID_H
