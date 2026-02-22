#include "Game.h"
#include "Utils.h"
#include "raylib.h"
#include "defines.h"
#include "states/MainMenuState.h"
#include <ctime>
#include <iostream>

Game::Game(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(
        GAME_TARGET_WIDTH * GAME_TARGET_INITSCALE, 
        GAME_TARGET_HEIGHT * GAME_TARGET_INITSCALE, 
        GAME_TITLE
    );
    SetWindowMinSize(GAME_TARGET_WIDTH, GAME_TARGET_HEIGHT);
    SetRandomSeed((unsigned int)time(NULL));
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    buffer = LoadRenderTexture(GAME_TARGET_WIDTH, GAME_TARGET_HEIGHT);
    
    // set init state
    setState(std::make_unique<MainMenuState>());
}

Game::~Game(){
    UnloadRenderTexture(buffer);
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
    BeginTextureMode(buffer);
        if (state) state->render();
    EndTextureMode();

    BeginDrawing();
        ClearBackground(BLACK);

        DrawTexturePro(
            buffer.texture, 
            Rectangle{0, 0, GAME_TARGET_WIDTH, -GAME_TARGET_HEIGHT},
            Utils::getBufferRect(),
            Vector2{0, 0}, 0, WHITE
        );
    EndDrawing();
}