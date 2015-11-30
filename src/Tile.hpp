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
public:
    Tile(bool solid, int textureNum);
    bool isSolid();
    int getTextureNum();
};

#endif /* Tile_hpp */
