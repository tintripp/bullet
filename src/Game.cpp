#include "Game.h"
#include "raylib.h"
#include "states/PlayState.h"
Game::Game(){
    const int screenWidth = 800;
    const int screenHeight = 450;
    SetConfigFlags(FLAG_WINDOW_TOPMOST); 

    InitWindow(screenWidth, screenHeight, "ONE bullet");

    SetTargetFPS(60);

    // set init state
    setState(std::make_unique<PlayState>());
}

Game::~Game(){
    CloseWindow();
}

void Game::loop(){
    while (!WindowShouldClose()){
        if (state->ready())
            setState(std::move(state->next));
        update();
        render();
    }
}

void Game::setState(std::unique_ptr<GameState> newState){
    if (state)
        state->exit();
    state = std::move(newState);
    state->enter();
}

void Game::update() {
    if (state) state->update();
}

void Game::render() {
    BeginDrawing();
        if (state) state->render();
    EndDrawing();
}