//
//  StandardBullet.cpp
//  LabOF1
//
//  Created by William Meaton on 11/11/2015.
//
//

#include "StandardBullet.hpp"
StandardBullet::StandardBullet(ofPoint position, ofPoint target, float movementSpeed, bool visible, float damage = 0) : Entity(position.x, position.y, SPRITE_SIZE, SPRITE_SIZE, visible), movementSpeed(movementSpeed), damage(damage), target(target){
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

float StandardBullet::getDamage(){
    return damage;
}