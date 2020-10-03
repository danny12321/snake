//
// Created by Danny on 2-10-2020.
//

#include "SnakeBody.h"

void SnakeBody::Move(int x, int y) {
    if(Tail != nullptr) {
        Tail->Move(this->x, this->y);
    }

    this->x = x;
    this->y = y;
}

SnakeBody::SnakeBody(int x, int y) {
    this->x = x;
    this->y = y;
}
