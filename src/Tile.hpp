//
//  Tile.hpp
//  LabOF1
//
//  Created by William Meaton on 16/11/2015.
//
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
#include "ofMain.h"

class Tile{
public:
    ofPoint position;
    Tile(ofPoint position);
    void display();
};

#endif /* Tile_hpp */
