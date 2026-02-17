#pragma once
#include "../traits/Updatable.h"
#include "../traits/Renderable.h"
class GameState : public Updatable, public Renderable {
public:
    virtual void update() override = 0;
    virtual void render() override = 0;
    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual ~GameState() = default;
};