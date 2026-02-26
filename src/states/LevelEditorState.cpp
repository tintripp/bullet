#include "MainMenuState.h"
#include "LevelEditorState.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "../Utils.h"
#include "../defines.h"
#include "raylib.h"
#include "raymath.h"
#include <memory>
#include <iostream>

void LevelEditorState::update(){

    // Eventually this will playtest the level.
    // We should pass in the level object we made to this state!
    if(IsKeyPressed(KEY_ENTER))
        transition(std::make_unique<PlayState>());
    if(IsKeyPressed(KEY_ESCAPE))
        transition(std::make_unique<MainMenuState>());

    if(IsKeyPressed(KEY_BACKSPACE))
        std::fill(tiles.begin(), tiles.end(), 0);

    if(IsKeyPressed(KEY_E))
        type = (type + 1) % TileType::TILETYPECOUNT;

    // selection tile in tile coords
    selection = Utils::bufferMousePosition();
    selection.x /= TILE_SIZE;
    selection.y /= TILE_SIZE;

    //place
    std::size_t location = ((int)selection.y * w) + (int)selection.x;
    if (location >= 0 && location < tiles.size() && selection.x < w){
        int& tile = tiles.at(location);
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            tile = type;
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
            tile = TileType::TILETYPE_AIR;
    }
    
}
void LevelEditorState::render(){
    ClearBackground(BLACK);
    DrawText(
        (
            "LEVEL EDITOR\nCurrent type: "+
            TILETYPENAMES.at(type)+" (E to switch)"
        ).c_str(), 0, 0, 10, RED
    );

    // draw all tiles
    for (std::size_t i = 0; i < tiles.size(); i++) {
        int x = i % w;
        int y = (i - x) / w;

        if (tiles.at(i) == TileType::TILETYPE_GROUND){
            DrawRectangle(
                x * TILE_SIZE, 
                y * TILE_SIZE, 
                TILE_SIZE, 
                TILE_SIZE, 
                Color{0,180,0,255}
            );
        }
        if (tiles.at(i) == TileType::TILETYPE_LAVA){
            DrawRectangle(
                x * TILE_SIZE, 
                y * TILE_SIZE, 
                TILE_SIZE, 
                TILE_SIZE, 
                Color{255,0,0,255}
            );
        }

    }

    // cursor
    if (selection.x >= 0 && selection.x < w && selection.y >= 0 && selection.y < h)
    DrawRectangle(
        (int)selection.x * TILE_SIZE, 
        (int)selection.y * TILE_SIZE, 
        TILE_SIZE, 
        TILE_SIZE, 
        Color{255,255,255,64}
    );
}
void LevelEditorState::enter(){
    type = TileType::TILETYPE_GROUND;
    w = 64;
    h = 64;
    tiles.resize(h * w);
}
void LevelEditorState::exit(){}
