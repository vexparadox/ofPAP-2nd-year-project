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
    int enumValue;
    bool solid;
public:
    Tile(int enumValue, bool solid);
};

#endif /* Tile_hpp */
