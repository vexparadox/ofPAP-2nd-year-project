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
Entity::Entity(float x, float y): x(x), y(y){
    //set the position of the entitiy
    position.x = this->x;
    position.y = this->y;
}