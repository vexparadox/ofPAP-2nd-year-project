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

bool Entity::worldCollide(int vx, int vy){
    float xBound, yBound;
    if(vx > 0){
        xBound = position.x + vx + size.x/2;
    }else{
        xBound = position.x - vx -size.x/2;
    }
    if(vy > 0){
        yBound = position.y + vy + size.y/2;
    }else{
        yBound = position.y - vy -size.y/2;
    }
    
    ofPoint gridPos = ofPoint((int)xBound/TILE_SIZE, (int)yBound/TILE_SIZE);
    if(World::tiles[World::worldMatrix[World::xSize * gridPos.x + gridPos.y]].isSolid()){
        return true;
    }
    return false;
}