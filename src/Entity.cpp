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
Entity::Entity(int x, int y, bool visible, std::string imgPath): x(x), y(y), visible(visible), imgPath(imgPath){
    if(imgPath != ""){
        texture.loadImage(imgPath);
        texture.resize(50,50);
    }
}

void Entity::display(){
    if(visible){
        texture.draw(x, y);
    }
}