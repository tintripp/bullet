#pragma once 
#include <map>
#include <string>

enum TileType{
    TILETYPE_AIR = 0,
    TILETYPE_GROUND,
    TILETYPE_LAVA,


    //always last
    TILETYPECOUNT
};
const std::map<int, std::string> TILETYPENAMES = {
    {TileType::TILETYPE_AIR, "Air"},
    {TileType::TILETYPE_GROUND, "Ground"},
    {TileType::TILETYPE_LAVA, "Lava"}
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