//
//  StandardBullet.cpp
//  LabOF1
//
//  Created by William Meaton on 11/11/2015.
//
//

#include "StandardBullet.hpp"
StandardBullet::StandardBullet(ofPoint position, ofPoint target, float movementSpeed, bool visible, float damage = 0) : Bullet(position, target, movementSpeed, visible, damage){
}

//display the bullet
void StandardBullet::display(){
    if(visible){
        Texture::getSprite(stdBULLET).draw(position);
    }
}