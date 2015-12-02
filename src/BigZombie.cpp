//
//  BigZombie.cpp
//  LabOF1
//
//  Created by William Meaton on 01/12/2015.
//
//

#include "BigZombie.hpp"


BigZombie::BigZombie(ofPoint position, float movementSpeed, float health, float attackDamage, bool visible): Enemy(position, movementSpeed, health, visible),  attackDamage(attackDamage){
}

void BigZombie::display(){
    if(visible){
        Texture::getSprite(BigZOMBIE).draw(position);
    }
}