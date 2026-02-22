#include "PlayState.h"
#include "MainMenuState.h"
#include "raylib.h"
#include <memory>
#include <stdio.h>

// Players will prob connect here. (i.e. gamepads)
void PlayState::update(){
    if(IsKeyPressed(KEY_J))
        transition(std::make_unique<MainMenuState>());
    
    /*if(IsKeyPressed(KEY_UP)){
        plrs.push_back(std::make_unique<Player>(
            GetMouseX(), GetMouseY(), 
            Color{
                (unsigned char)GetRandomValue(0,255),
                (unsigned char)GetRandomValue(0,255),
                (unsigned char)GetRandomValue(0,255),
                255
            }
        ));
    }*/

    // manage players via gamepads
    
    for (int i = 0; i < GAME_MAXPLAYERS; i++) {
        if (plrs[i]) {
            if (IsGamepadAvailable(i))
                plrs[i]->update();
            else
                plrs[i].reset();
        }else{
            if (IsGamepadAvailable(i)) {
                // create one
                plrs[i] = std::make_unique<Player>(
                    GetMouseX(), GetMouseY(), 
                    Color{
                        (unsigned char)GetRandomValue(0,255),
                        (unsigned char)GetRandomValue(0,255),
                        (unsigned char)GetRandomValue(0,255),
                        255
                    }
                ); 
                plrs[i]->gamepad = i;
            }
        }
    }
}
void PlayState::render(){
    DrawText("PlayState\n\n\n\
        Connect a controller to spawn a player", 
        0, 0, 20, RED);
    ClearBackground(YELLOW);
    
    for (int i = 0; i < GAME_MAXPLAYERS; i++) 
        if (plrs[i]) plrs[i]->render();
    
}
void PlayState::enter(){}
void PlayState::exit(){}