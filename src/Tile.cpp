//
//  Tile.cpp
//  LabOF1
//
//  Created by William Meaton on 20/11/2015.
//
//

#include "Tile.hpp"


Tile::Tile(bool solid): solid(solid){

}

bool Tile::isSolid(){
    return solid;
}