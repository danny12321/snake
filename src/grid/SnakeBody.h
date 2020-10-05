//
// Created by Danny on 2-10-2020.
//

#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H


#include <SDL2/SDL_render.h>
#include "GridItem.h"
#include "../Directions.h"

class SnakeBody : public GridItem {
private:
    SnakeBody* GetTail();
public:
    SnakeBody(int x, int y);
    void Move(Directions direction);
    void Move(int x, int y);
    SnakeBody* Eat();
    void Draw(SDL_Renderer* renderer, int width, int height, int margin) override;

    int GetScore();
};


#endif //SNAKE_SNAKEBODY_H
