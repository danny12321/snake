#include <iostream>
#include "Game.h"


#undef main

int main() {
    std::cout << "Starting Snake" << std::endl;
    Game game;
    std::cout << "Snake died with score " << game.GetScore() << std::endl;
    return 0;
}
