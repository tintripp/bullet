#pragma once
#include "../traits/Updatable.h"
#include "../traits/Renderable.h"
class Entity : public Updatable, public Renderable {
public:
    virtual void update() override = 0;
    virtual void render() override = 0;
};