//
//  DoubleBullet.cpp
//  LabOF1
//
//  Created by William Meaton on 02/12/2015.
//
//

#include "DoubleBullet.hpp"

DoubleBullet::DoubleBullet(ofPoint position, ofPoint target, float movementSpeed, bool visible, float damage = 0) : Bullet(position, target, movementSpeed, visible, damage){
}

//display the bullet
void DoubleBullet::display(){
    if(visible){
        Texture::getSprite(ddBULLET).draw(position);
    }
}