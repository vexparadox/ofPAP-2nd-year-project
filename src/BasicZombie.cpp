//
//  BasicZombie.cpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#include "BasicZombie.hpp"

BasicZombie::BasicZombie(float x, float y, float movementSpeed, int health, int attackDamage ,bool visible) : Creature(x, y, Texture::getSpriteWidth(BasicZOMBIE), Texture::getSpriteHeight(BasicZOMBIE), movementSpeed, health),  attackDamage(attackDamage), visible(visible){
    
}

void BasicZombie::display(){
    if(visible){
        Texture::getSprite(BasicZOMBIE).draw(position);
    }
}




