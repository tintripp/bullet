#pragma once
#include "Entity.h"
#include "raylib.h"
class Player : public Entity {
public:
    float x,y;
    int w,h;
    Color c;
    int gamepad;

    Player(int x, int y, Color c);

    void update() override;
    void render() override;
};