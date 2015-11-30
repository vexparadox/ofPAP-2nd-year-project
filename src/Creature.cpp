//
//  Creature.cpp
//  LabOF1
//
//  Created by William Meaton on 16/10/2015.
//
//

#include "Creature.hpp"

//the Creature class holds the Health, Speed, damage etc of the creature
Creature::Creature(float x, float y, float w, float h, float movementSpeed, float health, bool visible):Entity(x, y, w, h, visible), health(health), movementSpeed(movementSpeed){
    
}
//the creature takes damage
void Creature::takeDamage(float dmg){
    health -= dmg;
}

//takes a vector instead of the x and y point
void Creature::moveTo(ofPoint target){
    this -> moveTo(target.x, target.y);
}

//will move towards an x and y point with the movement speed
void Creature::moveTo(float mX, float mY){
    if(!visible){
        return;
    }
    ofPoint target = ofPoint(mX, mY);
    ofPoint direction = target - position;
    direction.normalize();

    if(worldCollide(direction*movementSpeed)){
        position += direction*(movementSpeed);
    }else{
        position += direction*(movementSpeed/4);
    }
}

float Creature::getHealth(){
    return health;
}

void Creature::setHealth(float h){
    health = h;
}

//returns if the creature is dead or not
bool Creature::isDead(){
    if(health <= 0){
        return true;
    }
    return false;
}