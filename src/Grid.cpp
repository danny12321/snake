//
// Created by Danny on 2-10-2020.
//

#include <SDL2/SDL.h>
#include <iostream>
#include "Grid.h"


Grid::Grid(SDL_Renderer *renderer) {
    _renderer = renderer;
}

void Grid::Draw(GridItem *body) {
    GridItem *currBody = body;

    while (currBody != nullptr) {
        DrawBody(currBody);
        currBody = currBody->Tail;
    }
}

void Grid::DrawBody(GridItem *body) {
    int width;
    int height;
    int margin = 2;
    SDL_GetRendererOutputSize(_renderer, &width, &height);
    int block_width = width / columns;
    int block_height = height / rows;

    body->Draw(_renderer, block_width, block_height, margin);
}

std::vector<int> Grid::GetFreePlace(GridItem* body) {
    std::vector<std::vector<int>> places;

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < columns; ++x) {
            if (!body->OnPlace(x, y)) {
                std::vector<int> place {x, y};
                places.push_back(place);
            }
        }
    }

    int n = rand() % places.size();
    return places[n];
}