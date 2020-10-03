//
// Created by Danny on 3-10-2020.
//

#include "Game.h"

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    auto* grid = new Grid(renderer);

    bool running = true;

    while(running) {
        SDL_RenderClear(renderer);
        grid->Update();
        grid->Draw();
        SDL_RenderPresent(renderer);


        SDL_Delay(200);
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            /* handle your event here */
            grid->HandleInput(event);

            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }
}