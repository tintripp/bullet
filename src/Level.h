#pragma once 
enum TileType{
    TILETYPE_AIR = 0,
    TILETYPE_GROUND
};

class Level{
private:
    int w, h;
    int tiles[];
    
public:
    // complete constructor( requires tiles arr, entities arr, w, h )
    Level();
    // ALSO, make load from file constructor (load file contents, call complete constructor)
    
    int getWidth();
    int getHeight();

};