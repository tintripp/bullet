#pragma once
#include "raylib.h"
#include "defines.h"
#include <algorithm>
#include <cmath>
namespace Utils {
    inline int getBufferMult() {
        int xmult = GetScreenWidth() / GAME_TARGET_WIDTH;
        int ymult = GetScreenHeight() / GAME_TARGET_HEIGHT;
        xmult = ymult = std::min(xmult, ymult);
        return xmult;
    }
    inline Rectangle getBufferRect() { 
        int mult = getBufferMult();

        float w = GAME_TARGET_WIDTH * mult;
        float h = GAME_TARGET_HEIGHT * mult;
        float x = std::floor((GetScreenWidth() - w) / 2.f);
        float y = std::floor((GetScreenHeight() - h) / 2.f);


        return Rectangle{x, y, w, h};
    }
    inline Vector2 bufferMousePosition() { 
        int mult = getBufferMult();
        Rectangle rect = getBufferRect();

        return Vector2{
            (GetMouseX() - rect.x) / mult, 
            (GetMouseY() - rect.y) / mult
        };
    }
}