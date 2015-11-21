//
//  StandardBullet.cpp
//  LabOF1
//
//  Created by William Meaton on 11/11/2015.
//
//

#include "StandardBullet.hpp"
StandardBullet::StandardBullet(ofPoint position, ofPoint target, float movementSpeed, bool visible = true) : Entity(position.x, position.y, Texture::getSpriteWidth(stdBULLET), Texture::getSpriteHeight(stdBULLET)), movementSpeed(movementSpeed), visible(visible), target(target){

    velocity.x = (target.x - position.x)*movementSpeed;
    velocity.y = (target.y - position.y)*movementSpeed;
}
//update the bullets position and pull towards the target
void StandardBullet::update(){
    position.x += velocity.x;
    position.y += velocity.y;
}

//display the bullet
void StandardBullet::display(){
    if(visible){
        Texture::getSprite(stdBULLET).draw(position);
    }
}