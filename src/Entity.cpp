//
//  Entity.cpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#include "Entity.hpp"
#include <iostream>



//the Entity class holds the position and visibility of the entity
Entity::Entity(float x, float y, float w, float h){
    //set the position of the entitiy
    position.x = x;
    position.y = y;
    size.x = w;
    size.y = h;
    velocity.x = 0;
    velocity.y = 0;
}

//returns if the Entitiy is on screen or not
bool Entity::onScreen(){
    if(position.x+size.x/2 < 0 || position.y+size.x/2 < 0 || position.x+size.x/2 > ofGetWidth() || position.y+size.y/2 > ofGetHeight()){
        return false;
    }
    return true;
}
//apply
void Entity::gravity(){
    if(worldCollide(0, gravityValue)){
        position.y+=gravityValue;
    }
}

bool Entity::worldCollide(float vx, float vy){
    float xBound, yBound;
    if(vx > 0){
        //if it's going right
        xBound = position.x + vx + size.x;
    }else if(vx < 0){
        //if it's going left
        xBound = position.x - vx;
    }else if (vx == 0){
        //if x is 0, thus no x movement
        xBound = position.x + size.x/2;
    }

    if(vy > 0){
        //if it's going down
        yBound = position.y + vy + size.y;
    }else if (vy < 0){
        //if it's going up
        yBound = position.y - vy;
    } else if (vy == 0){
        //if y is 0, thus no y movement
        yBound = position.y + size.y;
    }
    
    ofPoint gridPos = ofPoint((int)xBound/TILE_SIZE, (int)yBound/TILE_SIZE);
    
    int tileType = World::worldMatrix[gridPos.x + gridPos.y * World::ySize];
    if(gridPos.x < 0 || gridPos.y < 0){
        return false;
    }
    if(!World::tiles[tileType].isSolid()){
        return true;
    }
    return false;
}