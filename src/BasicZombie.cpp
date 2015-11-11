//
//  BasicZombie.cpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#include "BasicZombie.hpp"

BasicZombie::BasicZombie(float x, float y, float movementSpeed, int health, int attackDamage ,bool visible, std::string imgPath = "") : Creature(x, y, movementSpeed, health, visible, imgPath),  attackDamage(attackDamage){
}




