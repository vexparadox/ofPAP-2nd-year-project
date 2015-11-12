//
//  StandardBullet.cpp
//  LabOF1
//
//  Created by William Meaton on 11/11/2015.
//
//

#include "StandardBullet.hpp"
StandardBullet::StandardBullet(ofPoint position, ofPoint target, float movementSpeed, bool visible = true):

Entity(position.x, position.y), movementSpeed(movementSpeed), visible(visible){
    
}

void StandardBullet::display(){
    if(visible){
        Sprite::getTexture(stdBULLET).draw(position);
    }
}