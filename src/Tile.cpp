//
//  Tile.cpp
//  LabOF1
//
//  Created by William Meaton on 20/11/2015.
//
//

#include "Tile.hpp"


Tile::Tile(bool solid, int textureNum, int health): solid(solid), textureNum(textureNum), health(health){

}

bool Tile::isSolid(){
    return solid;
}

int Tile::getTextureNum(){
    return textureNum;
}

int Tile::getDamageLevel(){
    return damageLevel;
}

void Tile::damageTile(){
    damageLevel++;
}

int Tile::getHealth(){
    return health;
}