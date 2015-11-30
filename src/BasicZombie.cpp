//
//  BasicZombie.cpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#include "BasicZombie.hpp"

BasicZombie::BasicZombie(float x, float y, float movementSpeed, float health, float attackDamage ,bool visible) : Creature(x, y, SPRITE_SIZE, SPRITE_SIZE, movementSpeed, health, visible),  attackDamage(attackDamage){
    
}

//display the item
void BasicZombie::display(){
    if(visible){
        Texture::getSprite(BasicZOMBIE).draw(position);
    }
}




