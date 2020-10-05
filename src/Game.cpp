//
// Created by Danny on 3-10-2020.
//

#include "Game.h"

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Init(3);

    while(running) {
        SDL_RenderClear(renderer);
        Update();
        grid->Draw(candy);
        grid->Draw(snake);
        SDL_RenderPresent(renderer);

        SDL_Delay(200);
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            /* handle your event here */
            HandleInput(event);

            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }
}

void Game::Init(int bodyLength){
    grid = new Grid(renderer);

    snake = new SnakeBody(0,0);
    for (int i = 0; i < bodyLength -1; ++i) {
        tail = snake->Eat();
    }

    PlaceCandy();
}

void Game::Update() {
    snake->Move(currdirection);
    bool hasCrashed = HasCrashed();

    if (hasCrashed) {
        std::cout << "Has Crashed!" << std::endl;
    }else if (candy->x == snake->x && candy->y == snake->y){
        snake->Eat();
        PlaceCandy();
    }
}

bool Game::HasCrashed() {
    GridItem *currBody = snake->Tail;

    while (currBody != nullptr) {
        if (currBody->x == snake->x && currBody->y == snake->y) {
            running = false;
            return true;
        }

        currBody = currBody->Tail;
    }

    return false;
}

void Game::HandleInput(SDL_Event &event){
    switch (event.key.keysym.scancode) {
        case SDL_SCANCODE_W:
            currdirection = UP;
            break;
        case SDL_SCANCODE_S:
            currdirection = DOWN;
            break;
        case SDL_SCANCODE_A:
            currdirection = LEFT;
            break;
        case SDL_SCANCODE_D:
            currdirection = RIGHT;
            break;
    }
}

void Game::PlaceCandy() {
    std::vector<int> place =  grid->GetFreePlace(snake);
    candy = new Candy(place[0], place[1]);
}

int Game::GetScore() {
    return snake->GetScore();
}
