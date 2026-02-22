#pragma once
#include "State.h"
#include "../entities/Player.h"
#include "../defines.h"
#include <vector>
#include <memory>
class PlayState : public GameState{
private:
    std::unique_ptr<Player> plrs[GAME_MAXPLAYERS];
public:
    void update() override;
    void render() override;
    void enter() override;
    void exit() override;
};