//
//  Enemy.cpp
//  LabOF1
//
//  Created by William Meaton on 02/12/2015.
//
//

#include "Enemy.hpp"


Enemy::Enemy(ofPoint position, float movementSpeed, float health, bool visible, float attackDamage): Creature(position, movementSpeed, health, visible), attackDamage(attackDamage){
}

float Enemy::getAttackDamage(){
    return attackDamage;
}

//the default for enemy update
//although nothing technically overides this, it can be at a later date
void Enemy::update(){
}

//will move towards an x and y point with the movement speed
void Enemy::moveTo(const ofPoint &target){
    if(!visible){
        return;
    }
    ofPoint direction = target - position;
    direction.normalize();
    
    if(worldCollide(direction*movementSpeed)){
        position += direction*(movementSpeed);
    }else{
        position += direction*(movementSpeed/4);
    }
}
