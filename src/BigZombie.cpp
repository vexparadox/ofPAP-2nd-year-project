//
//  BigZombie.cpp
//  LabOF1
//
//  Created by William Meaton on 01/12/2015.
//
//

#include "BigZombie.hpp"


BigZombie::BigZombie(float x, float y, float movementSpeed, float health, float attackDamage, bool visible): Creature(x, y, SPRITE_SIZE, SPRITE_SIZE, movementSpeed, health, visible),  attackDamage(attackDamage){

}

void BigZombie::display(){
    if(visible){
        Texture::getSprite(BigZOMBIE).draw(position);
    }
}