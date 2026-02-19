#pragma once
#include "State.h"
class MainMenuState : public GameState{
    void update() override;
    void render() override;
    void enter() override;
    void exit() override;
};