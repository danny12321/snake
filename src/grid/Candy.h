//
// Created by Danny on 3-10-2020.
//

#ifndef SNAKE_CANDY_H
#define SNAKE_CANDY_H


#include "GridItem.h"

class Candy : public GridItem {
public:
    int x;
    int y;
    Candy(int x, int y);
};


#endif //SNAKE_CANDY_H
