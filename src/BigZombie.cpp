//
//  BigZombie.cpp
//  LabOF1
//
//  Created by William Meaton on 01/12/2015.
//
//

#include "BigZombie.hpp"


BigZombie::BigZombie(ofPoint position, float movementSpeed, float health, bool visible, float attackDamage): Enemy(position, movementSpeed, health, visible, attackDamage){
}

void BigZombie::display(){
    if(visible){
        Texture::getSprite(BigZOMBIE).draw(position);
    }
}