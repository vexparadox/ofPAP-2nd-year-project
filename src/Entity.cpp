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
Entity::Entity(float x, float y, float w, float h): x(x), y(y), w(w), h(h), collider(position, size){
    //set the position of the entitiy
    position.x = x;
    position.y = y;
    size.x = w;
    size.y = h;
}

//returns if the Entitiy is on screen or not
bool Entity::onScreen(){
    if(position.x+w/2 < 0 || position.y+h/2 < 0 || position.x+w/2 > ofGetWidth() || position.y+h/2 > ofGetHeight()){
        return false;
    }
    return true;
}

bool Entity::worldCollide(float vx, float vy){
    float xBound, yBound;
    if(vx > 0){
        //if it's going forwards
        xBound = position.x + vx + w;
    }else if(vx < 0){
        //if it's going backwards
        xBound = position.x - vx;
    }else if (vx == 0){
        //if x is 0, thus no x movement
        xBound = position.x + w/2;
    }

    if(vy > 0){
        //if it's going down
        yBound = position.y + vy + h;
    }else if (vy < 0){
        //if it's going up
        yBound = position.y - vy + h;
    } else if (vy == 0){
        //if y is 0, thus no y movement
        yBound = position.y + h;
    }
    
    ofPoint gridPos = ofPoint((int)xBound/TILE_SIZE, (int)yBound/TILE_SIZE);
    std::cout << gridPos << std::endl;
    int tileType = World::worldMatrix[gridPos.x + gridPos.y * World::ySize];
    std::cout << tileType;
 if(!World::tiles[tileType].isSolid()){
        return true;
 }
    return false;
}