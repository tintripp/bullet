#pragma once
#include "State.h"
#include "../Level.h"
#include "../entities/Entity.h"
#include "raylib.h"
#include <vector>
class LevelEditorState : public GameState{
private:
    // contains data of a level we can then CONSTRUCT a level with!
    // then also export to a file with this data.

    // tiles is a vector. in level, it will be an array--
    // we do NOT know final lvl size when making it.
    std::vector<int> tiles; 
    std::vector<Entity> entities;
    Vector2 selection;
    int type;
    int w, h;
public:
    void update() override;
    void render() override;
    void enter() override;
    void exit() override;
};