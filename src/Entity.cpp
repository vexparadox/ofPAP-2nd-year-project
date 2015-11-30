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
Entity::Entity(float x, float y, float w, float h, bool visible): visible(visible) {
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
//apply gravity to the entity with/without checks
void Entity::gravity(bool collision){
    if(collision) {
        if(worldCollide(0, gravityValue)){
            position.y+=gravityValue;
        }
    }
    else{
        position.y+=gravityValue;

    }
}

bool Entity::entityCollide(const Entity &entity){
    //only do the calculations if it's visible
    if(!visible){
        return false;
    }
    
    //do entity collision
    if(entity.position.x+size.x/2 > position.x && entity.position.x+size.x/2 < position.x+size.x
       && entity.position.y+size.y/2 > position.y && entity.position.y+size.y/2 < position.y+size.y){
        return true;
    }
    return false;
}

void Entity::setVisible(bool set){
    visible = set;
}

bool Entity::isVisible(){
    return visible;
}

//calls world collision with a vector
bool Entity::worldCollide(ofPoint velocity){
    return this->worldCollide(velocity.x, velocity.y);
}
//checks world collision at a certain point, use 0, 0 if you want to compare the entitys current position
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
    if(gridPos.x < 0 || gridPos.y < 0){
        return false;
    }
    if(!World::worldMatrix[gridPos.x + gridPos.y*World::getySize()].isSolid()){
        return true;
    }
    return false;
}