//
// Created by Danny on 3-10-2020.
//

#ifndef SNAKE_GRIDITEM_H
#define SNAKE_GRIDITEM_H


#include <SDL2/SDL_render.h>

class GridItem {
public:
    GridItem* Tail = nullptr;
    int x;
    int y;
    virtual void Draw(SDL_Renderer* renderer, int width, int height, int margin) = 0;

    bool OnPlace(int x, int y);
};


#endif //SNAKE_GRIDITEM_H
