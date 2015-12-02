//
//  Tile.hpp
//  LabOF1
//
//  Created by William Meaton on 20/11/2015.
//
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
//This is just a data class
//the worldMatrix is made up of Tile objects
//each tile holds it's current health, solid status and texture number
class Tile{
private:
    bool solid;
    int textureNum;
    int damageLevel = 0;
    int health;
public:
    Tile(bool solid, int textureNum, int health);
    bool isSolid();
    int getHealth();
    int getTextureNum();
    int getDamageLevel();
    void damageTile();
};

#endif /* Tile_hpp */
