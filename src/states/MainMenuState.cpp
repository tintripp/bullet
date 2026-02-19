#include <memory>
#include "MainMenuState.h"
#include "PlayState.h"
#include "raylib.h"

// Players will prob connect here. (i.e. gamepads)
void MainMenuState::update(){
    if(IsKeyPressed(KEY_J)){
        transition(std::make_unique<PlayState>());
    }
}
void MainMenuState::render(){
    ClearBackground(YELLOW);
}
void MainMenuState::enter(){}
void MainMenuState::exit(){}