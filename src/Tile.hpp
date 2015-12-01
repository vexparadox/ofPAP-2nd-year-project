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

class Tile{
private:
    bool solid;
    int textureNum;
    int damageLevel = 0;
    int health;
public:
    Tile(bool solid, int textureNum);
    bool isSolid();

    int getTextureNum();
    int getDamageLevel();
    void damageTile();
};

#endif /* Tile_hpp */
