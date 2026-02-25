#include "MainMenuState.h"
#include "PlayState.h"
#include "LevelEditorState.h"
#include "raylib.h"
#include <memory>

void MainMenuState::update(){
    if(IsKeyPressed(KEY_K))
        transition(std::make_unique<LevelEditorState>());
    
}
void MainMenuState::render(){
    ClearBackground(BLUE);
    DrawText("Main menu \nK: enter LEVELEDITORSTATE", 0, 0, 20, WHITE);
}
void MainMenuState::enter(){}
void MainMenuState::exit(){}