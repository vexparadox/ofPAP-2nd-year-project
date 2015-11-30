//
//  Tile.cpp
//  LabOF1
//
//  Created by William Meaton on 20/11/2015.
//
//

#include "Tile.hpp"


Tile::Tile(bool solid, int textureNum): solid(solid), textureNum(textureNum){

}

bool Tile::isSolid(){
    return solid;
}

int Tile::getTextureNum(){
    return textureNum;
}