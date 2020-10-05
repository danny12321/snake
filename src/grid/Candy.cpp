//
// Created by Danny on 3-10-2020.
//

#include "Candy.h"

Candy::Candy(int x, int y) : x(x), y(y) {}

void Candy::Draw(SDL_Renderer *renderer, int width, int height, int margin) {
    margin = 20;
    SDL_Rect rect;
    rect.w = width - margin;
    rect.h = height - margin;
    rect.x = x * width + (margin / 2);
    rect.y = y * height + (margin / 2);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
