#pragma once
#include "State.h"
#include "../Level.h"
#include "../entities/Entity.h"
#include <vector>
class LevelEditorState : public GameState{
private:
    // contains data of a level we can then CONSTRUCT a level with!
    // then also export to a file with this data.

    // tiles is a vector. in level, it will be an array
    // because: we do NOT know final lvl size when making it.
    std::vector<int> tiles; 
    std::vector<Entity> entities;
    int w, h;
public:
    void update() override;
    void render() override;
    void enter() override;
    void exit() override;
};