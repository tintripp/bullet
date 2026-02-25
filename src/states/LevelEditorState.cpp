#include "MainMenuState.h"
#include "LevelEditorState.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "../Utils.h"
#include "../defines.h"
#include "raylib.h"
#include <memory>

void LevelEditorState::update(){

    // Eventually this will playtest the level.
    // We should pass in the level object we made to this state!
    if(IsKeyPressed(KEY_ENTER))
        transition(std::make_unique<PlayState>());
    if(IsKeyPressed(KEY_ESCAPE))
        transition(std::make_unique<MainMenuState>());
    
}
void LevelEditorState::render(){
    ClearBackground(BLACK);
    DrawText("LEVEL EDITOR", 0, 0, 20, RED);

    Vector2 mp = Utils::bufferMousePosition();
    DrawRectangle(
        (int)(mp.x / TILE_SIZE) * TILE_SIZE, 
        (int)(mp.y / TILE_SIZE) * TILE_SIZE, 
        TILE_SIZE, 
        TILE_SIZE, 
        Color{255,255,255,64}
    );
}
void LevelEditorState::enter(){
    w = 64;
    h = 64;
    tiles.resize(h * w);

}
void LevelEditorState::exit(){}
