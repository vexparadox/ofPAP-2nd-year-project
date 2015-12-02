//
//  BasicZombie.cpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#include "BasicZombie.hpp"

BasicZombie::BasicZombie(ofPoint position, float movementSpeed, float health, bool visible, float attackDamage) : Enemy(position, movementSpeed, health, visible, attackDamage){
    
}

//display the item
void BasicZombie::display(){
    if(visible){
        Texture::getSprite(BasicZOMBIE).draw(position);
    }
}




