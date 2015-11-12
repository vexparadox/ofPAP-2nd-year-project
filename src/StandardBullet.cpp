//
//  StandardBullet.cpp
//  LabOF1
//
//  Created by William Meaton on 11/11/2015.
//
//

#include "StandardBullet.hpp"
StandardBullet::StandardBullet(float x, float y, float movementSpeed, bool visible = true):Entity(x, y), movementSpeed(movementSpeed), visible(visible){
    
}

void StandardBullet::moveTo(Creature &c){

}

void StandardBullet::display(){
    if(visible){
        Sprite::getTexture(stdBULLET).draw(position);
    }
}