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
Entity::Entity(float x, float y, float w, float h): x(x), y(y), w(w), h(h){
    //set the position of the entitiy
    position.x = this->x;
    position.y = this->y;
}

bool Entity::onScreen(){
    if(position.x < 0 || position.y < 0 || position.x > ofGetWidth() || position.y > ofGetHeight()){
        return false;
    }
    return true;
}