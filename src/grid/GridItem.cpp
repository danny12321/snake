//
// Created by Danny on 3-10-2020.
//

#include "GridItem.h"

bool GridItem::OnPlace(int x, int y) {
    if (x == this->x && y == this->y) {
        return true;
    } else if(Tail != nullptr) {
        return Tail->OnPlace(x,y);
    } else {
        return false;
    }
}
