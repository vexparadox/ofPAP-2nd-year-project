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
    
    //set the position of the entitiy
    position.x = this->x;
    position.y = this->y;
    //load the texture of the entitiy
    if(imgPath != ""){
        texture.load(imgPath);
        texture.resize(50,50);
    }
}
//display the texture
void Entity::display(){
    //if it's set to be drawn
    if(visible){
        texture.draw(x, y);
    }
}