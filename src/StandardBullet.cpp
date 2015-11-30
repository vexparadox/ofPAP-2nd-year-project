//
//  StandardBullet.cpp
//  LabOF1
//
//  Created by William Meaton on 11/11/2015.
//
//

#include "StandardBullet.hpp"
StandardBullet::StandardBullet(ofPoint position, ofPoint target, float movementSpeed, bool visible = true) : Entity(position.x, position.y, SPRITE_SIZE, SPRITE_SIZE), movementSpeed(movementSpeed), visible(visible), target(target){
    direction = (target - position);
    direction.normalize();
}
//update the bullets position and pull towards the target
void StandardBullet::update(){
    position += direction*(movementSpeed);
}

//display the bullet
void StandardBullet::display(){
    if(visible){
        Texture::getSprite(stdBULLET).draw(position);
    }
}