//
// Created by Danny on 2-10-2020.
//

#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H


#include "GridItem.h"

class SnakeBody : public GridItem {
private:

public:
    SnakeBody* Tail = nullptr;

    SnakeBody(int x, int y);
    void Move(int x, int y);
};


#endif //SNAKE_SNAKEBODY_H
